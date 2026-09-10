from pathlib import Path

from kaitaistruct import KaitaiStream, BytesIO
from PIL import Image

from tools.kaitai.parsers.lib.img import Img
from tools.libdata.img import encode_rgb555
from tools.splat_ext.img import PSXSegSizedImg


class PSXSegRgb555(PSXSegSizedImg):

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

    @classmethod
    def encode_to_binary(cls, image_path: Path) -> tuple[bytes, list[tuple[str, int]]]:
        img = PSXSegRgb555.load_input_image(image_path)
        data = encode_rgb555(img.tobytes(), False)
        symbol_name = PSXSegRgb555.symbol_name_from_path(image_path)
        return data, [(symbol_name, 0)]


if __name__ == '__main__':
    PSXSegRgb555.run_encoder()
