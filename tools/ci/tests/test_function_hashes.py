"""Tests for the per-function hash verifier and the manifest's hash attachment.

The ELF-reading internals (`_load_elf_symbol_bytes`) are best exercised by
the integration test (`make ci-smoke`) — they need a real built tree. Here
we cover the pure-function pieces: path → binary derivation, the active
INCLUDE_ASM filter (cross-checked with the asm_manifest version), and the
end-to-end verify() shape against a synthetic manifest.
"""
import hashlib
import json

import asm_manifest as M
import verify_function_hashes as V


class TestBinaryFromPath:
    def test_top_level_binary(self):
        assert M._binary_from_path("build/src/SLUS_010.40/header.s") == "SLUS_010.40"
        assert V._binary_from_manifest_path("build/src/SLUS_010.40/header.s") == "SLUS_010.40"

    def test_prg_overlay(self):
        # MENU/MENU0.PRG is two path segments.
        assert M._binary_from_path("build/src/MENU/MENU0.PRG/foo/bar.s") == "MENU/MENU0.PRG"
        assert V._binary_from_manifest_path("build/src/MENU/MENU0.PRG/foo/bar.s") == "MENU/MENU0.PRG"

    def test_battle_prg(self):
        assert M._binary_from_path("build/src/BATTLE/BATTLE.PRG/x.s") == "BATTLE/BATTLE.PRG"

    def test_rejects_non_build_src(self):
        assert M._binary_from_path("config/SLUS_010.40/splat.yaml") is None
        assert V._binary_from_manifest_path("src/SLUS_010.40/main.c") is None
        assert V._binary_from_manifest_path("foo") is None


class TestActiveIncludeAsmConsistency:
    """Both asm_manifest and verify_function_hashes have their own
    _active_include_asm_names — they must agree byte-for-byte, since the
    verifier uses the same set the manifest renderer uses to skip stubs."""

    def test_agree_on_same_src_tree(self, tmp_path, monkeypatch):
        src = tmp_path / "src"
        src.mkdir()
        (src / "a.c").write_text(
            'INCLUDE_ASM("p/q", funcA);\n'
            'INCLUDE_ASM("p/q",funcB);\n'
        )
        monkeypatch.setattr(M, "ROOT", tmp_path)
        monkeypatch.setattr(V, "ROOT", tmp_path)
        assert M._active_include_asm_names() == V._active_include_asm_names()
        assert M._active_include_asm_names() == {"funcA", "funcB"}


class TestVerifyShape:
    def test_no_hashes_skip(self, tmp_path, monkeypatch):
        """A manifest with no sha256 fields produces a benign no-op pass."""
        manifest = tmp_path / "asm-manifest.json"
        manifest.write_text(json.dumps({
            "build/src/FOO/x.s": [{"op": "label", "kind": "glabel", "name": "funcX", "size": 4}]
        }))
        (tmp_path / "src").mkdir()
        monkeypatch.setattr(V, "ASM_MANIFEST", manifest)
        monkeypatch.setattr(V, "ROOT", tmp_path)
        assert V.verify() == 0

    def test_stubbed_funcs_skipped(self, tmp_path, monkeypatch):
        """Active INCLUDE_ASM → manifest hash isn't checked (stub bytes)."""
        manifest = tmp_path / "asm-manifest.json"
        manifest.write_text(json.dumps({
            "build/src/FOO/nonmatchings/X/funcX.s": [
                {"op": "label", "kind": "glabel", "name": "funcX",
                 "size": 4, "sha256": "deadbeef" * 8}
            ]
        }))
        src = tmp_path / "src"
        src.mkdir()
        (src / "x.c").write_text('INCLUDE_ASM("any/path", funcX);\n')
        monkeypatch.setattr(V, "ASM_MANIFEST", manifest)
        monkeypatch.setattr(V, "ROOT", tmp_path)
        # No .elf needed — funcX is filtered out before the .elf is touched.
        assert V.verify() == 0

    def test_missing_elf_for_decompiled_func(self, tmp_path, monkeypatch):
        """Decompiled funcX (no INCLUDE_ASM) but no .elf to verify against
        → reported as 'missing .elf' and verify returns non-zero."""
        manifest = tmp_path / "asm-manifest.json"
        manifest.write_text(json.dumps({
            "build/src/FOO/main.s": [
                {"op": "label", "kind": "glabel", "name": "funcX",
                 "size": 4, "sha256": "deadbeef" * 8}
            ]
        }))
        (tmp_path / "src").mkdir()  # no INCLUDE_ASM macros — funcX is "decompiled"
        monkeypatch.setattr(V, "ASM_MANIFEST", manifest)
        monkeypatch.setattr(V, "ROOT", tmp_path)
        assert V.verify() != 0
