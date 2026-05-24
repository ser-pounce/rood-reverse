"""Tests for tools/ci/png_manifest.py — build + render round-trip.

The interesting cases are around PNG bitdepth handling (4/8/16) and the
clut-count metadata being preserved.
"""
import json
import sys
from pathlib import Path

import png_manifest as P

# Ensure the project's psx_img is importable for write_png.
ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT))


def _write_test_png(path: Path, w: int, h: int, bd: int, nb: int = 0, na: int = 0):
    """Use the project's own psx_img helper so the encoded PNG round-trips
    through read_png (same path the manifest builder uses)."""
    from tools.etc import psx_img
    path.parent.mkdir(parents=True, exist_ok=True)
    if bd == 16:
        pixels = bytes(w * h * 4)
        psx_img.write_png(path, pixels, w, h, 16, [], [])
    else:
        pixels = bytes(w * h)
        zero_pal = [(0, 0, 0, 0)] * (16 if bd == 4 else 256)
        psx_img.write_png(path, pixels, w, h, bd,
                          [zero_pal] * nb, [zero_pal] * na)


class TestPngManifestBuild:
    def test_8bpp_with_clut(self, tmp_path, monkeypatch):
        seeds = tmp_path / "fixtures" / "ci" / "seeds" / "build" / "assets"
        _write_test_png(seeds / "MENU" / "GAMEOVER.png", 96, 128, 8, nb=1)

        manifest_path = tmp_path / "manifest.json"
        monkeypatch.setattr(P, "ROOT", tmp_path)
        monkeypatch.setattr(P, "MANIFEST", manifest_path)
        P.build_manifest(seeds)
        m = json.loads(manifest_path.read_text())
        key = "build/assets/MENU/GAMEOVER.png"
        assert m[key]["w"] == 96
        assert m[key]["h"] == 128
        assert m[key]["bd"] == 8
        assert m[key]["nb"] == 1
        assert m[key]["na"] == 0

    def test_16bpp_no_clut(self, tmp_path, monkeypatch):
        seeds = tmp_path / "fixtures" / "ci" / "seeds" / "build" / "assets"
        _write_test_png(seeds / "TITLE" / "bg.png", 64, 32, 16)
        manifest_path = tmp_path / "manifest.json"
        monkeypatch.setattr(P, "ROOT", tmp_path)
        monkeypatch.setattr(P, "MANIFEST", manifest_path)
        P.build_manifest(seeds)
        m = json.loads(manifest_path.read_text())
        entry = m["build/assets/TITLE/bg.png"]
        assert entry["bd"] == 16
        assert "nb" not in entry  # 16bpp doesn't carry clut counts
        assert "na" not in entry


class TestPngManifestRender:
    def test_round_trip_preserves_shape(self, tmp_path, monkeypatch):
        # Build manifest from a seeded PNG, render in a fresh ROOT, re-read.
        seeds = tmp_path / "fixtures" / "ci" / "seeds" / "build" / "assets"
        _write_test_png(seeds / "MENU" / "img.png", 48, 24, 4, nb=2, na=1)
        manifest_path = tmp_path / "manifest.json"
        monkeypatch.setattr(P, "ROOT", tmp_path)
        monkeypatch.setattr(P, "MANIFEST", manifest_path)
        P.build_manifest(seeds)

        # Move ROOT for render.
        render_root = tmp_path / "out"
        render_root.mkdir()
        monkeypatch.setattr(P, "ROOT", render_root)
        P.render_stubs()

        # Re-read the rendered PNG.
        from tools.etc import psx_img
        rendered = render_root / "build/assets/MENU/img.png"
        assert rendered.is_file()
        _, w, h, bd, cb, ca, _, _ = psx_img.read_png(rendered)
        assert (w, h, bd) == (48, 24, 4)
        assert len(cb) == 2
        assert len(ca) == 1
