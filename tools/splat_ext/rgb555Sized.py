import struct
from pathlib import Path

from kaitaistruct import KaitaiStream, BytesIO

from tools.splat_ext.img import PSXSegImg
from tools.libdata.img import decode_highcolor, encode_highColor
from tools.kaitai.parsers.lib.img import Img


class PSXSegRgb555Sized(PSXSegImg):

    def split(self, rom_bytes: bytes) -> None:
        data = rom_bytes[self.rom_start:self.rom_end]
        parsed = Img.Rgba16Header(KaitaiStream(BytesIO(data)))

        decode_highcolor(parsed.w, parsed.h, parsed.colors, self.make_path())

    @classmethod
    def encode_to_binary(cls, image_path: Path) -> tuple[bytes, list[tuple[str, int]]]:
        img = PSXSegRgb555Sized.load_input_image(image_path)
        data = struct.pack('<HH', img.width, img.height) + encode_highColor(img)
        symbol_name = PSXSegRgb555Sized.symbol_name_from_path(image_path)
        return data, [
            (f'{symbol_name}_header', 0),
            (f'{symbol_name}_data', struct.calcsize('<HH')),
        ]


if __name__ == '__main__':
    PSXSegRgb555Sized.run_encoder()
