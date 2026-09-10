from pathlib import Path

from kaitaistruct import KaitaiStream, BytesIO

from tools.splat_ext.img import PSXSegSizedImg
from tools.libdata.img import decode_highcolor, encode_highColor
from tools.libdata.rle import rle_compress
from tools.kaitai.parsers.lib.img import Img


class PSXSegRleRgb555(PSXSegSizedImg):

    def split(self, rom_bytes: bytes) -> None:
        data = rom_bytes[self.rom_start:self.rom_end]
        parsed = Img.RleRgb5(KaitaiStream(BytesIO(data)))
        decode_highcolor(self.width, self.height, parsed.raw_indices.colors, self.make_path())

    @classmethod
    def encode_to_binary(cls, image_path: Path) -> tuple[bytes, list[tuple[str, int]]]:
        img = PSXSegRleRgb555.load_input_image(image_path)
        data = rle_compress(encode_highColor(img), fill_value=0x80008000)
        symbol_name = PSXSegRleRgb555.symbol_name_from_path(image_path)
        return data, [(symbol_name, 0)]


if __name__ == '__main__':
    PSXSegRleRgb555.run_encoder()
