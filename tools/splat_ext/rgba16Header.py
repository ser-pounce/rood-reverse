import argparse
import struct
from pathlib import Path

from kaitaistruct import KaitaiStream, BytesIO
from PIL import Image

from tools.splat_ext.img import PSXSegImg
from tools.libdata.img import decode_highcolor, encode_highColor
from tools.kaitai.parsers.lib.img import Img


HEADER_SIZE = struct.calcsize('<HH')


class PSXSegRgba16Header(PSXSegImg):
    def split(self, rom_bytes: bytes) -> None:
        data = rom_bytes[self.rom_start:self.rom_end]
        parsed = Img.Rgba16Header(KaitaiStream(BytesIO(data)))

        decode_highcolor(parsed.w, parsed.h, parsed.colors, self.make_path())


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('input',  type=Path, help='Input PNG file')
    parser.add_argument('output', type=Path, help='Output file')
    args = parser.parse_args()

    img = Image.open(args.input)
    img.load()

    data = struct.pack('<HH', img.width, img.height) + encode_highColor(img)
    symbol_name = args.input.name.split('.')[0]
    
    PSXSegRgba16Header.write_object_file(
        data,
        args.output,
        [(f'{symbol_name}_header', 0),
            (f'{symbol_name}_data',   HEADER_SIZE)],
        *PSXSegRgba16Header.objcopy_from_env(),
    )
