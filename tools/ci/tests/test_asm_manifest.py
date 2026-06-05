"""Tests for tools/ci/asm_manifest.py — byte-counting + parser round-trip.

The byte sums in `_line_bytes` are load-bearing: if they drift, every stub
.s assembles to the wrong size, downstream addresses shift, and the linker
either silently produces a malformed binary or fails late.
"""
from io import StringIO
from textwrap import dedent

import asm_manifest as M


# ----------------------------- _line_bytes ----------------------------------

def _bytes(line: str) -> int:
    return M._line_bytes(line)


class TestLineBytes:
    def test_word(self):
        assert _bytes(".word 0x1") == 4
        assert _bytes(".word 0x1, 0x2") == 8
        assert _bytes(".word 0x1, 0x2, 0x3, 0x4") == 16

    def test_short_half_hword(self):
        assert _bytes(".short 0x1") == 2
        assert _bytes(".half 0x1, 0x2") == 4
        assert _bytes(".hword 0x1, 0x2, 0x3") == 6

    def test_byte(self):
        assert _bytes(".byte 0x1") == 1
        assert _bytes(".byte 0x1, 0x2, 0x3") == 3

    def test_zero(self):
        assert _bytes(".zero 0x10") == 16
        assert _bytes(".zero 100") == 100
        assert _bytes(".space 8") == 8
        assert _bytes(".skip 12") == 12

    def test_ascii(self):
        assert _bytes('.ascii "abc"') == 3
        assert _bytes('.asciz "abc"') == 4              # null-terminated
        assert _bytes('.ascii ""') == 0
        # Escape sequences count as one byte each.
        assert _bytes('.ascii "a\\nb"') == 3
        assert _bytes('.ascii "\\x00\\x01"') == 2

    def test_quad_and_double(self):
        assert _bytes(".double 1.0") == 8
        assert _bytes(".quad 0x1, 0x2") == 16

    def test_float_single(self):
        assert _bytes(".float 1.0") == 4
        assert _bytes(".single 1.0, 2.0") == 8

    def test_instruction_is_four_bytes(self):
        assert _bytes("addiu $sp, $sp, -0x38") == 4
        assert _bytes("sw    $s6, 0x30($sp)") == 4
        assert _bytes("nop") == 4

    def test_directives_are_zero_bytes(self):
        # Metadata that doesn't produce output bytes.
        for line in [
            ".include \"macro.inc\"",
            ".set noreorder",
            ".type funcX, @function",
            ".size funcX, 0x10",
            ".global funcX",
            ".local funcY",
            ".ent funcX",
            ".end funcX",
            ".file 1 \"foo.c\"",
            ".if 1",
            ".endif",
            "nonmatching funcX, 0x18C",
            "/* comment */",
            ".LBLOCK:",
            "1:",
            "funcX:",
        ]:
            assert _bytes(line) == 0, line


# ----------------------------- _ascii_bytes ---------------------------------

class TestAsciiBytes:
    def test_plain(self):
        assert M._ascii_bytes("hello", terminated=False) == 5
        assert M._ascii_bytes("hello", terminated=True) == 6

    def test_hex_escapes(self):
        assert M._ascii_bytes(r"\x00\x01\x02", terminated=False) == 3

    def test_octal_escapes(self):
        assert M._ascii_bytes(r"\012\377", terminated=False) == 2

    def test_simple_escapes(self):
        # \n \t \\ each are one byte.
        assert M._ascii_bytes(r"a\nb\tc", terminated=False) == 5


# ----------------------------- _apply_align ---------------------------------

class TestApplyAlign:
    def test_align_is_power_of_two(self):
        # .align N in GAS = align to 2^N bytes.
        assert M._apply_align(0, 3, "align") == 0       # already aligned
        assert M._apply_align(1, 3, "align") == 8
        assert M._apply_align(7, 3, "align") == 8
        assert M._apply_align(8, 3, "align") == 8

    def test_balign_is_literal_bytes(self):
        assert M._apply_align(0, 16, "balign") == 0
        assert M._apply_align(1, 16, "balign") == 16
        assert M._apply_align(17, 16, "balign") == 32

    def test_alignment_of_one_is_noop(self):
        assert M._apply_align(5, 0, "align") == 5       # 2^0 = 1


# ----------------------------- parse_s round-trip ---------------------------

def _parse_text(text: str):
    # parse_s takes a Path; cheat by writing to a tmp via StringIO substitution.
    # Easier: just run the same logic against an in-memory StringIO via monkey.
    import tempfile, pathlib
    with tempfile.NamedTemporaryFile("w", suffix=".s", delete=False) as f:
        f.write(text)
        p = pathlib.Path(f.name)
    try:
        return M.parse_s(p)
    finally:
        p.unlink()


class TestParseS:
    def test_pure_function(self):
        text = dedent("""\
            nonmatching funcX, 0x10

            glabel funcX
                addiu $sp, $sp, -0x8
                sw    $ra, 0x4($sp)
                lw    $ra, 0x4($sp)
                jr    $ra
        """)
        ops = _parse_text(text)
        # One glabel op with size = 4 instructions * 4 bytes.
        labels = [op for op in ops if op["op"] == "label"]
        assert len(labels) == 1
        assert labels[0]["kind"] == "glabel"
        assert labels[0]["name"] == "funcX"
        assert labels[0]["size"] == 0x10

    def test_data_section_multi_symbol(self):
        text = dedent("""\
            .section .data
            dlabel symA
                .word 0x1, 0x2, 0x3
            enddlabel symA
            dlabel symB
                .byte 0x1
                .byte 0x2
            enddlabel symB
        """)
        ops = _parse_text(text)
        sections = [op for op in ops if op["op"] == "section"]
        labels = [op for op in ops if op["op"] == "label"]
        assert len(sections) == 1 and sections[0]["name"] == ".data"
        assert len(labels) == 2
        assert labels[0]["name"] == "symA" and labels[0]["size"] == 12
        assert labels[1]["name"] == "symB" and labels[1]["size"] == 2

    def test_mixed_rodata_then_text(self):
        text = dedent("""\
            .section .rodata
            .align 3
            dlabel jtbl
                .word 0x1, 0x2, 0x3, 0x4
            enddlabel jtbl

            .section .text
            glabel funcX
                nop
                jr $ra
        """)
        ops = _parse_text(text)
        kinds = [(op["op"], op.get("name") or op.get("kind")) for op in ops]
        assert ("section", ".rodata") in kinds
        assert ("section", ".text") in kinds
        labels = [op for op in ops if op["op"] == "label"]
        assert any(o["name"] == "jtbl" and o["size"] == 16 for o in labels)
        assert any(o["name"] == "funcX" and o["size"] == 8 for o in labels)

    def test_anonymous_section(self):
        # No labels — like header.s.
        text = dedent("""\
            .section .data
            .ascii "PS-X EXE"
            .word 0x0, 0x0, 0x0
        """)
        ops = _parse_text(text)
        zeros = [op for op in ops if op["op"] == "zero"]
        # 8 ascii + 12 word = 20 bytes total, but accumulated under "zero" since no label.
        total = sum(z["size"] for z in zeros)
        assert total == 20


# --------------------------- render round-trip ------------------------------

class TestRenderRoundTrip:
    def test_render_matches_parsed_layout(self):
        """Parse a .s → render its ops → re-parse → ops match."""
        original = dedent("""\
            .section .rodata
            dlabel jtbl
                .word 0x1, 0x2, 0x3
            enddlabel jtbl
            .section .text
            glabel funcX
                addiu $sp, $sp, -0x8
                jr $ra
        """)
        ops1 = _parse_text(original)
        rendered = M.render(ops1)
        ops2 = _parse_text(rendered)
        # Compare layout — sections, labels, sizes — ignoring representation.
        layout = lambda ops: [
            (op["op"], op.get("name") or op.get("kind"), op.get("size"))
            for op in ops if op["op"] != "align"
        ]
        assert layout(ops1) == layout(ops2)


# -------------------- _active_include_asm_names -----------------------------

class TestIncludeAsmScan:
    def test_finds_matching_macros(self, tmp_path, monkeypatch):
        src = tmp_path / "src"
        src.mkdir()
        (src / "a.c").write_text(
            'INCLUDE_ASM("build/src/foo/nonmatchings/A", funcA);\n'
            'INCLUDE_ASM("build/src/foo/nonmatchings/A", funcB);\n'
            '// INCLUDE_ASM("ignore me", funcC) — comments OK, regex doesn\'t care\n'
        )
        (src / "b.c").write_text(
            'INCLUDE_ASM("any/path",funcD);\n'  # no space
        )
        monkeypatch.setattr(M, "ROOT", tmp_path)
        names = M._active_include_asm_names()
        assert names == {"funcA", "funcB", "funcC", "funcD"}

    def test_missing_src_dir(self, tmp_path, monkeypatch):
        monkeypatch.setattr(M, "ROOT", tmp_path)
        assert M._active_include_asm_names() == set()
