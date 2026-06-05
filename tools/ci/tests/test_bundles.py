"""Tests for the simple bundlers: yaml_bundle.py and undefined_bundle.py.

Both are near-identical: walk a tree of source files, write a JSON
map {path: content}, render back. Test the round-trip is byte-identical.
"""
import yaml_bundle
import undefined_bundle


def _round_trip(monkeypatch, tmp_path, module, source_files, source_dir_name, file_glob):
    """Generic: write source files at fixtures/ci/seeds/<source_dir>/<rel>,
    build bundle, render into a fresh root, verify byte-identical."""
    # Stash sources under tmp/fixtures/ci/seeds/<source_dir>/ so the
    # module's `seeds_prefix` strip logic produces clean relative paths.
    seeds_root = tmp_path / "fixtures" / "ci" / "seeds" / source_dir_name
    seeds_root.mkdir(parents=True)
    for rel, content in source_files.items():
        f = seeds_root / rel
        f.parent.mkdir(parents=True, exist_ok=True)
        f.write_text(content)

    bundle_path = tmp_path / "bundle.json"
    monkeypatch.setattr(module, "ROOT", tmp_path)
    monkeypatch.setattr(module, "SEEDS_ROOT", seeds_root)
    monkeypatch.setattr(module, "BUNDLE", bundle_path)

    assert module.build_bundle(seeds_root) == 0
    assert bundle_path.is_file()

    # Render into a fresh ROOT — files land at <render_root>/<source_dir>/<rel>.
    render_root = tmp_path / "render"
    render_root.mkdir()
    monkeypatch.setattr(module, "ROOT", render_root)
    assert module.render_stubs() == 0

    for rel, content in source_files.items():
        rendered = render_root / source_dir_name / rel
        assert rendered.is_file(), f"missing render: {rendered}"
        assert rendered.read_text() == content


class TestYamlBundle:
    def test_round_trip(self, tmp_path, monkeypatch):
        _round_trip(
            monkeypatch, tmp_path, yaml_bundle,
            source_files={
                "BATTLE/menuStrings.yaml": "magic: MAGIC\nfoo: bar\n",
                "MENU/items.yaml": "items:\n  - sword\n  - shield\n",
            },
            source_dir_name="build/assets",
            file_glob="*.yaml",
        )

    def test_empty_tree_produces_empty_bundle(self, tmp_path, monkeypatch):
        seeds = tmp_path / "seeds" / "build" / "assets"
        seeds.mkdir(parents=True)
        bundle = tmp_path / "bundle.json"
        monkeypatch.setattr(yaml_bundle, "ROOT", tmp_path)
        monkeypatch.setattr(yaml_bundle, "BUNDLE", bundle)
        assert yaml_bundle.build_bundle(seeds) == 0
        assert bundle.read_text().strip() == "{}"


class TestUndefinedBundle:
    def test_round_trip(self, tmp_path, monkeypatch):
        _round_trip(
            monkeypatch, tmp_path, undefined_bundle,
            source_files={
                "SLUS_010.40/undefined_funcs_auto.txt": "funcX = 0x80010000;\n",
                "SLUS_010.40/undefined_syms_auto.txt": "D_80000000 = 0x80000000;\n",
                "BATTLE/BATTLE.PRG/undefined_funcs_auto.txt": "funcY = 0x80020000;\n",
            },
            source_dir_name="build/config",
            file_glob="undefined_*.txt",
        )
