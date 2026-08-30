import argparse
from pathlib import Path

from kaitaistruct import KaitaiStream, BytesIO
from PIL import Image

from tools.kaitai.parsers.lib.img import Img
from tools.libdata.img import encode_rgb555
from tools.splat_ext.img import PSXSegImg

class PSXSegRgba16(PSXSegImg):

    def split(self, rom_bytes: bytes) -> None:
        data = rom_bytes[self.rom_start : self.rom_end]
        indices = Img.Indices(2, KaitaiStream(BytesIO(data)))

        pixels = bytes(
            channel
            for color in indices.indices
            for channel in (color.r8, color.g8, color.b8)
        )

        img = Image.frombytes('RGB', (self.width, self.height), pixels)
        img.save(self.make_path())


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('input',  type=Path, help='Input PNG file')
    parser.add_argument('output', type=Path, help='Output file')
    args = parser.parse_args()

    img = Image.open(args.input)
    img.load()

    data = encode_rgb555(img.tobytes(), False)
    symbol_name = args.input.name.split('.')[0]
    
    PSXSegRgba16.write_object_file(
        data,
        args.output,
        [(symbol_name, 0)],
        *PSXSegRgba16.objcopy_from_env(),
    )
