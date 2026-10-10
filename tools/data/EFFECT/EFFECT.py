import argparse
import re
from io import BytesIO
from pathlib import Path

from kaitaistruct import KaitaiStream
from PIL.PngImagePlugin import PngInfo

from tools.kaitai.parsers.lib.img import Img
from tools.libdata.img import write_indexed_png


TEXTURE_WIDTH = 128
TEXTURE_HEIGHT = 256
CLUT_BANK_SIZE = 512


def decode_effect(directory: Path, effect_id: int, output_path: Path) -> Path:
    if not 0 <= effect_id <= 999:
        raise ValueError(f'effect ID must be between 0 and 999, got {effect_id}')
    if not directory.is_dir():
        raise NotADirectoryError(directory)

    prefix = f'E{effect_id:03d}_'
    texture_files = list(directory.glob(f'{prefix}*.FBT'))
    if not texture_files:
        raise FileNotFoundError(f'No FBT texture files found for effect {effect_id:03d} in {directory}')

    sequence_pattern = re.compile(rf'{re.escape(prefix)}(\d+)\.FBT')
    ordered_textures: list[tuple[int, Path]] = []
    for texture_path in texture_files:
        match = sequence_pattern.fullmatch(texture_path.name)
        if match is None:
            raise ValueError(f'Unexpected texture filename: {texture_path.name}')
        ordered_textures.append((int(match.group(1)), texture_path))
    ordered_textures.sort(key=lambda item: item[0])

    output_width = TEXTURE_WIDTH * len(ordered_textures)
    indices = bytearray(output_width * TEXTURE_HEIGHT)
    for texture_number, (_, texture_path) in enumerate(ordered_textures):
        with texture_path.open('rb') as texture_file:
            texture = Img.Indices(1, KaitaiStream(texture_file))

        texture_indices = bytes(texture.indices)
        expected_size = TEXTURE_WIDTH * TEXTURE_HEIGHT
        if len(texture_indices) != expected_size:
            raise ValueError(
                f'{texture_path} contains {len(texture_indices)} pixels; expected {expected_size}'
            )
        for row in range(TEXTURE_HEIGHT):
            source_start = row * TEXTURE_WIDTH
            target_start = row * output_width + texture_number * TEXTURE_WIDTH
            indices[target_start:target_start + TEXTURE_WIDTH] = texture_indices[
                source_start:source_start + TEXTURE_WIDTH
            ]

    clut_files = list(directory.glob(f'{prefix}*.FBC'))
    if len(clut_files) != 1:
        raise ValueError(
            f'Expected one FBC palette for effect {effect_id:03d} in {directory}, found {len(clut_files)}'
        )

    raw_cluts = clut_files[0].read_bytes()
    if not raw_cluts or len(raw_cluts) % CLUT_BANK_SIZE:
        raise ValueError(
            f'{clut_files[0]} contains {len(raw_cluts)} bytes; expected a non-empty '
            f'multiple of {CLUT_BANK_SIZE} bytes'
        )
    first_clut = Img.Clut(KaitaiStream(BytesIO(raw_cluts[:CLUT_BANK_SIZE])))
    palette = bytes(
        channel
        for color in first_clut.colors
        for channel in (color.r8, color.g8, color.b8)
    )
    info = None
    if len(raw_cluts) > CLUT_BANK_SIZE:
        info = PngInfo()
        info.add(b'clUt', raw_cluts[CLUT_BANK_SIZE:], after_idat=True)

    write_indexed_png(
        bytes(indices),
        output_width,
        TEXTURE_HEIGHT,
        palette,
        output_path,
        info=info,
    )
    return output_path


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description='Decode an EFFECT texture group to PNG')
    parser.add_argument('path', type=Path, help='directory containing the FBT and FBC files')
    parser.add_argument('effect_id', type=int, help='three-digit effect ID')
    parser.add_argument('output', type=Path, help='output PNG path')
    args = parser.parse_args(argv)

    decode_effect(args.path, args.effect_id, args.output)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
