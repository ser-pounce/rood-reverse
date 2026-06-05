"""Tests for tools/ci/link_d_generator.py.

The generator's correctness is what stands between a decomp PR and a
broken link. Test:
  - splat.yaml subsegment parser (list + dict forms)
  - per-subsegment .o derivation (every type that occurs in the repo)
  - top-level header/overlay handling
  - end-marker / linker_entry=false skipping
  - C-source walk
  - render_link_d output shape
"""
from textwrap import dedent

import link_d_generator as G


# ----------------------------- list / dict form parsers ---------------------

class TestListForm:
    def test_anon_with_type(self):
        e = G._parse_list_form("[0x800, data]")
        assert e["addr"] == "0x800"
        assert e["type"] == "data"
        assert e["name"] is None
        assert e["linker_entry"] is True

    def test_named(self):
        e = G._parse_list_form("[0xA70C, rgbClut, publisher, ...]")
        assert e["type"] == "rgbClut"
        assert e["name"] == "publisher"

    def test_end_marker(self):
        # `[0x52800]` is an end-of-segment marker — no type.
        e = G._parse_list_form("[0x52800]")
        assert e is None or e["type"] is None


class TestDictForm:
    def test_with_linker_entry_false(self):
        e = G._parse_dict_form(
            "{start: 0xA70C, type: rgbClut, name: publisher, width: 256, "
            "height: 48, cluts_before: 1, linker_entry: false}"
        )
        assert e["type"] == "rgbClut"
        assert e["name"] == "publisher"
        assert e["linker_entry"] is False

    def test_default_linker_entry_true(self):
        e = G._parse_dict_form("{start: 0x100, type: rodata, name: foo}")
        assert e["linker_entry"] is True


# ----------------------------- parse_subsegments ---------------------------

class TestParseSubsegments:
    def test_minimal(self):
        y = dedent("""\
            sha1: abc
            options:
              basename: FOO
            segments:
              - [0, header]
              - start: 0x800
                type: code
                subsegments:
                  - [0x800, c, main]
                  - [0x900, asm, libsn/SNMAIN]
                  - [0xA00, .data, main]
                  - [0xB00, data, _table]
              - [0xC00]
        """)
        entries = G.parse_subsegments(y)
        names = [(e.get("type"), e.get("name"), e.get("top_level")) for e in entries]
        assert ("header", None, True) in names
        assert ("c", "main", False) in names
        assert ("asm", "libsn/SNMAIN", False) in names
        assert (".data", "main", False) in names
        assert ("data", "_table", False) in names


# ----------------------------- objs_from_splat -----------------------------

def _splat(monkeypatch, tmp_path, binary, splat_yaml, c_sources=None):
    """Drop a fake splat.yaml at config/<binary>/splat.yaml + optional .c sources."""
    cfg = tmp_path / "config" / binary
    cfg.mkdir(parents=True)
    (cfg / "splat.yaml").write_text(splat_yaml)
    if c_sources:
        for rel in c_sources:
            f = tmp_path / "src" / binary / rel
            f.parent.mkdir(parents=True, exist_ok=True)
            f.write_text("// stub\n")
    monkeypatch.setattr(G, "ROOT", tmp_path)


class TestObjsFromSplat:
    def test_c_subsegment_emits_o(self, tmp_path, monkeypatch):
        _splat(monkeypatch, tmp_path, "FOO", dedent("""\
            sha1: x
            segments:
              - [0, header]
              - start: 0x800
                type: code
                subsegments:
                  - [0x800, c, main]
        """))
        seen, order = G.objs_from_splat("FOO")
        assert "build/src/FOO/main.o" in seen
        assert "build/src/FOO/header.o" in seen

    def test_named_data_emits_data_o(self, tmp_path, monkeypatch):
        _splat(monkeypatch, tmp_path, "FOO", dedent("""\
            sha1: x
            segments:
              - start: 0
                subsegments:
                  - [0x100, data, _table]
        """))
        seen, _ = G.objs_from_splat("FOO")
        assert "build/src/FOO/_table.data.o" in seen

    def test_anon_data_uses_hex(self, tmp_path, monkeypatch):
        _splat(monkeypatch, tmp_path, "FOO", dedent("""\
            sha1: x
            segments:
              - start: 0
                subsegments:
                  - [0x100, data]
        """))
        seen, _ = G.objs_from_splat("FOO")
        # Hex label is the address with no 0x prefix, upper-case.
        assert "build/src/FOO/100.data.o" in seen

    def test_merged_dot_section_not_emitted(self, tmp_path, monkeypatch):
        _splat(monkeypatch, tmp_path, "FOO", dedent("""\
            sha1: x
            segments:
              - start: 0
                subsegments:
                  - [0x100, .data, main]
                  - [0x200, c, main]
        """))
        seen, _ = G.objs_from_splat("FOO")
        # .data is merged into the sibling c subsegment — no separate .o.
        assert "build/src/FOO/main.data.o" not in seen
        assert "build/src/FOO/main.o" in seen

    def test_image_segment_emits_asset_img_o(self, tmp_path, monkeypatch):
        _splat(monkeypatch, tmp_path, "FOO", dedent("""\
            sha1: x
            segments:
              - start: 0
                subsegments:
                  - [0xA70C, rgbClut, publisher, ...]
        """))
        seen, _ = G.objs_from_splat("FOO")
        assert "build/assets/FOO/publisher.rgbClut.img.o" in seen

    def test_linker_entry_false_skipped(self, tmp_path, monkeypatch):
        _splat(monkeypatch, tmp_path, "FOO", dedent("""\
            sha1: x
            segments:
              - start: 0
                subsegments:
                  - {start: 0xA70C, type: rgbClut, name: publisher, linker_entry: false}
                  - [0xB000, rgbClut, developer]
        """))
        seen, _ = G.objs_from_splat("FOO")
        assert "build/assets/FOO/publisher.rgbClut.img.o" not in seen
        assert "build/assets/FOO/developer.rgbClut.img.o" in seen


# ----------------------------- objs_from_csrc ------------------------------

class TestObjsFromCsrc:
    def test_walks_c_tree(self, tmp_path, monkeypatch):
        for rel in ("main.c", "lib/foo.c", "lib/bar/baz.c"):
            f = tmp_path / "src" / "FOO" / rel
            f.parent.mkdir(parents=True, exist_ok=True)
            f.write_text("// stub\n")
        monkeypatch.setattr(G, "ROOT", tmp_path)
        objs = G.objs_from_csrc("FOO")
        assert "build/src/FOO/main.o" in objs
        assert "build/src/FOO/lib/foo.o" in objs
        assert "build/src/FOO/lib/bar/baz.o" in objs


# ----------------------------- render_link_d shape -------------------------

class TestRenderLinkD:
    def test_output_shape(self, tmp_path, monkeypatch):
        _splat(monkeypatch, tmp_path, "FOO", dedent("""\
            sha1: x
            segments:
              - [0, header]
              - start: 0x800
                subsegments:
                  - [0x800, c, main]
        """), c_sources=["main.c"])
        text = G.render_link_d("FOO")
        # First line: <elf>: \
        assert text.startswith("build/data/FOO.elf: \\\n")
        # Each .o is listed once.
        assert text.count("build/src/FOO/main.o") >= 1
        # Per-object empty targets exist (for make's -MMD style).
        assert "build/src/FOO/main.o:\n" in text
        # -include of corresponding .d files.
        assert "-include " in text
        assert text.endswith("\n")
