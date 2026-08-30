import argparse
from pathlib import Path
from typing import Any

from kaitaistruct import KaitaiStream, BytesIO
from PIL import Image

from tools.splat_ext.img import PSXSegImg
from tools.libdata.img import decode_highcolor, encode_highColor
from tools.libdata.rle import rle_compress
from tools.kaitai.parsers.lib.img import Img


TRANSPARENT_WORD = 0x80008000


class PSXSegRgba16Compressed(PSXSegImg):

    def __init__(self, **kwargs: Any) -> None:
        super().__init__(**kwargs)
        if len(kwargs['yaml']) < 5:
            raise ValueError('PSXSegRgba16Compressed requires width and height')

    def split(self, rom_bytes: bytes) -> None:
        data = rom_bytes[self.rom_start:self.rom_end]
        parsed = Img.RleRgb5(KaitaiStream(BytesIO(data)))

        decode_highcolor(self.width, self.height, parsed.raw_indices.colors, self.make_path())


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('input',  type=Path, help='Input PNG file')
    parser.add_argument('output', type=Path, help='Output file')
    args = parser.parse_args()

    img = Image.open(args.input)
    img.load()
    binary      = rle_compress(encode_highColor(img), fill_value=TRANSPARENT_WORD)
    symbol_name = args.input.name.split('.')[0]

    PSXSegRgba16Compressed.write_object_file(
        binary,
        args.output,
        [(symbol_name, 0)],
        *PSXSegRgba16Compressed.objcopy_from_env(),
    )
