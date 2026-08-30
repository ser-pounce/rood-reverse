# The MENUE code supports 4bpp indexed sprites as well as 8bpp,
# but this isn't used in the HF files so the following code assumes 8bpp only.

import argparse
import struct
import yaml
from pathlib import Path
from typing import Any

import numpy as np
from PIL import Image

from tools.etc.vsString import decode, encode
from tools.kaitai.parsers.data.SMALL.help_hf0 import HelpHf0
from tools.kaitai.parsers.data.SMALL.help_hf1 import HelpHf1
from tools.libdata.img import encode_rgb555
from tools.libdata.util import align, build_offset_table
from tools.libdata.yaml import configure_yaml, dump


BLOCK_WIDTH = 8
BLOCK_HEIGHT = 16
CLUTS_PER_LINE = 16

ANIMATION_STRUCT = struct.Struct("<hHhhhhhxx")
SPRITE_STRUCT = struct.Struct("<hhhhhhh")
LINE_STRUCT = struct.Struct("<hhhhBBBx")
HF0_HEADER_STRUCT = struct.Struct("<IIII")
HF1_HEADER_STRUCT = struct.Struct("<II")


def parse_animation(animation: HelpHf0.Animation) -> dict[str, Any] | None:
    if not animation.enabled:
        return None

    return {
        "frameMask": format(animation.frame_mask, "016b"),
        "frameDuration": animation.frame_duration,
        "repeat": animation.repeat,
    }


def parse_sprite(sprite: HelpHf0.SpriteData) -> dict[str, Any]:
    result = {"x": sprite.x, "y": sprite.y}
    if animation := parse_animation(sprite.animation):
        result["animation"] = animation
    return result


def parse_line(line: HelpHf0.LineData) -> dict[str, Any]:
    result = {
        "start": {"x": line.x0, "y": line.y0},
        "end": {"x": line.x1, "y": line.y1},
        "color": {"r": line.r, "g": line.g, "b": line.b},
    }
    if animation := parse_animation(line.animation):
        result["animation"] = animation
    return result


def parse_hf0(data: HelpHf0) -> dict[str, Any]:
    return {
        "strings": [decode(list(ref.text)) for ref in data.help_text.string_refs],
        "sprites": [
            parse_sprite(ref.sprite) for ref in data.sprite_table.sprite_refs
        ],
        "lines": [parse_line(line) for line in data.line_table.lines],
    }


def render_pixels(
    framebuffer: HelpHf1,
    sprite: HelpHf0.SpriteData,
) -> np.ndarray:
    blocks_per_row = (sprite.w + BLOCK_WIDTH - 1) // BLOCK_WIDTH
    blocks_per_col = (sprite.h + BLOCK_HEIGHT - 1) // BLOCK_HEIGHT
    canvas = np.zeros((blocks_per_col * BLOCK_HEIGHT, blocks_per_row * BLOCK_WIDTH), dtype=np.uint8)

    for block_index, block_id in enumerate(sprite.sprites):
        if not 0 <= block_id < len(framebuffer.blocks):
            raise ValueError(f"Block ID {block_id} out of range")

        block = np.frombuffer(framebuffer.blocks[block_id], dtype=np.uint8).reshape(BLOCK_HEIGHT, BLOCK_WIDTH)
        grid_y, grid_x = divmod(block_index, blocks_per_row)
        canvas[
            grid_y * BLOCK_HEIGHT : (grid_y + 1) * BLOCK_HEIGHT,
            grid_x * BLOCK_WIDTH : (grid_x + 1) * BLOCK_WIDTH,
        ] = block

    cropped = canvas[: sprite.h, : sprite.w].astype(np.uint16)
    return ((cropped + sprite.clut_x) % 256).astype(np.uint8)


def build_palette(framebuffer: HelpHf1, clut_y: int) -> list[int]:
    start = clut_y * CLUTS_PER_LINE
    end = start + CLUTS_PER_LINE
    if start < 0 or end > len(framebuffer.cluts):
        raise ValueError(f"CLUT line {clut_y} out of range")

    return [
        channel
        for clut in framebuffer.cluts[start:end]
        for color in clut.colors
        for channel in (color.r8, color.g8, color.b8)
    ]


def render_sprite(
    framebuffer: HelpHf1,
    sprite: HelpHf0.SpriteData,
    output_path: Path,
) -> None:
    rows = render_pixels(framebuffer, sprite)
    image = Image.fromarray(rows, mode="P")
    image.putpalette(build_palette(framebuffer, sprite.clut_y))
    image.save(output_path)


def decode_hf(hf0_path: Path, hf1_path: Path, output_dir: Path) -> None:
    configure_yaml()

    hf0 = HelpHf0.from_file(str(hf0_path))
    hf1 = HelpHf1.from_file(str(hf1_path))
    sprites = [ref.sprite for ref in hf0.sprite_table.sprite_refs]
    seen: dict[tuple, str] = {}
    sprite_files: list[str] = []

    for sprite in sprites:
        signature = (tuple(sprite.sprites), sprite.w, sprite.h, sprite.clut_x, sprite.clut_y)
        if signature not in seen:
            filename = f"sprite_{len(seen):03d}.png"
            render_sprite(hf1, sprite, output_dir / filename)
            seen[signature] = filename
        sprite_files.append(seen[signature])

    hf0_data = parse_hf0(hf0)
    hf0_data["sprites"] = [
        {
            "position": {"x": sprite["x"], "y": sprite["y"]},
            "file": filename,
            **({"animation": sprite["animation"]} if "animation" in sprite else {}),
        }
        for sprite, filename in zip(hf0_data["sprites"], sprite_files)
    ]

    with (output_dir / "help_data.yaml").open("w", encoding="utf-8") as file:
        dump(hf0_data, file)


class BlockExtractor:
    def __init__(self):
        self.blocks: dict[tuple[int, ...], int] = {}

    def extract_blocks(self, image: Image.Image) -> list[int]:
        arr = np.array(image, dtype=np.uint8)
        pad_h = -arr.shape[0] % BLOCK_HEIGHT
        pad_w = -arr.shape[1] % BLOCK_WIDTH
        arr = np.pad(arr, ((0, pad_h), (0, pad_w)))

        rows = arr.shape[0] // BLOCK_HEIGHT
        cols = arr.shape[1] // BLOCK_WIDTH
        blocks = (
            arr.reshape(rows, BLOCK_HEIGHT, cols, BLOCK_WIDTH)
            .transpose(0, 2, 1, 3)
            .reshape(rows * cols, BLOCK_HEIGHT * BLOCK_WIDTH)
        )
        return [self.add_block(row.tolist()) for row in blocks]

    def add_block(self, block: list[int]) -> int:
        return self.blocks.setdefault(tuple(block), len(self.blocks))

    @property
    def unique_blocks(self) -> list[tuple[int, ...]]:
        return list(self.blocks.keys())


class PaletteManager:
    def __init__(self):
        self.palettes: dict[tuple[int, ...], int] = {}

    def add_palette(self, raw_palette: list[int]) -> int:
        return self.palettes.setdefault(tuple(raw_palette), len(self.palettes))

    @property
    def unique_palettes(self) -> list[tuple[int, ...]]:
        return list(self.palettes.keys())


def pack_animation(animation: dict[str, Any]) -> bytes:
    frame_mask = int(animation["frameMask"], 2)
    enabled = int(any((frame_mask, animation["frameDuration"], animation["repeat"])))
    return ANIMATION_STRUCT.pack(
        enabled,
        frame_mask,
        animation["frameDuration"],
        animation["repeat"],
        0,
        0,
        0,
    )


DEFAULT_ANIMATION = {
    "frameMask": "0000000000000000",
    "frameDuration": 0,
    "repeat": 0,
}


def pack_sprite(sprite: dict[str, Any]) -> bytes:
    animation = sprite.get("animation", DEFAULT_ANIMATION)
    block_ids = sprite["sprites"]
    clut_packed = (sprite["clutY"] << 4) | sprite["clutX"]
    return b"".join(
        (
            pack_animation(animation),
            SPRITE_STRUCT.pack(
                sprite["x"],
                sprite["y"],
                sprite["w"],
                sprite["h"],
                len(block_ids),
                256,
                clut_packed,
            ),
            struct.pack(f"<{len(block_ids)}h", *block_ids),
        )
    )


def pack_line(line: dict[str, Any]) -> bytes:
    animation = line.get("animation", DEFAULT_ANIMATION)
    start = line["start"]
    end = line["end"]
    color = line["color"]
    return pack_animation(animation) + LINE_STRUCT.pack(
        start["x"],
        start["y"],
        end["x"],
        end["y"],
        color["r"],
        color["g"],
        color["b"],
    )


def load_png(path: Path) -> Image.Image:
    image = Image.open(path)
    if image.mode != "P":
        raise ValueError(f"{path}: Not an indexed PNG file")
    return image


def process_sprites(sprites: list[dict[str, Any]], sprites_dir: Path, block_extractor: BlockExtractor, palette_manager: PaletteManager) -> dict[str, dict[str, Any]]:
    processed_sprites = {}

    for sprite in sprites:
        filename = sprite["file"]
        if filename in processed_sprites:
            continue
        image = load_png(sprites_dir / filename)
        processed_sprites[filename] = {
            "w": image.width,
            "h": image.height,
            "sprites": block_extractor.extract_blocks(image),
            "clutX": 0,
            "clutY": palette_manager.add_palette(image.getpalette()),
        }

    return processed_sprites


def build_sprite_records(sprites: list[dict[str, Any]], processed_sprites: dict[str, dict[str, Any]]) -> list[dict[str, Any]]:
    records = []
    for sprite in sprites:
        rendered = processed_sprites[sprite["file"]]
        position = sprite["position"]
        records.append(
            {
                "x": position["x"],
                "y": position["y"],
                **rendered,
                **({"animation": sprite["animation"]} if "animation" in sprite else {}),
            }
        )
    return records


def write_hf0(output_dir: Path, help_name: str, data: dict[str, Any], processed_sprites: dict[str, dict[str, Any]]) -> None:
    blocks = (
        align(
            struct.pack("<H", len(data["strings"]))
            + build_offset_table(
                [encode(string, padding=0) for string in data["strings"]],
                offset=2,
            )
        ),
        align(
            struct.pack("<H", len(data["sprites"]))
            + build_offset_table(
                [pack_sprite(sprite) for sprite in build_sprite_records(data["sprites"], processed_sprites)],
                offset=2,
            )
        ),
        align(
            struct.pack("<H", len(data["lines"]))
            + b"".join(pack_line(line) for line in data["lines"])
        ),
        b"", # Either an unused block, or the header offsets are padded to 0x10
    )
    output = HF0_HEADER_STRUCT.pack(*(len(block) for block in blocks)) + b"".join(blocks)
    (output_dir / f"{help_name}.HF0").write_bytes(output)


def write_hf1(output_dir: Path, help_name: str, block_extractor: BlockExtractor, palette_manager: PaletteManager) -> None:
    palettes = [encode_rgb555(raw_palette, False) for raw_palette in palette_manager.unique_palettes]
    num_cluts = len(palettes) * CLUTS_PER_LINE
    output = b"".join(
        (
            HF1_HEADER_STRUCT.pack(len(block_extractor.unique_blocks), num_cluts),
            b"".join(bytes(block) for block in block_extractor.unique_blocks),
            b"".join(palettes),
        )
    )
    (output_dir / f"{help_name}.HF1").write_bytes(output)


def encode_hf(yaml_path: Path, output_dir: Path) -> None:
    data = yaml.safe_load(yaml_path.read_text(encoding="utf-8"))
    block_extractor = BlockExtractor()
    palette_manager = PaletteManager()
    processed_sprites = process_sprites(data["sprites"], yaml_path.parent, block_extractor, palette_manager)

    write_hf0(output_dir, yaml_path.parent.name, data, processed_sprites)
    write_hf1(output_dir, yaml_path.parent.name, block_extractor, palette_manager)


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description="Decode or encode HELP HF0/HF1 files")
    parser.add_argument("input", type=Path)
    parser.add_argument("output_dir", type=Path)
    args = parser.parse_args(argv)

    suffix = args.input.suffix.lower()
    if suffix == ".hf0":
        decode_hf(args.input, args.input.with_suffix(".HF1"), args.output_dir)
    elif suffix in {".yaml", ".yml"}:
        encode_hf(args.input, args.output_dir)
    else:
        parser.error("Could not infer mode from input file extension; expected .HF0 or .yaml")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())