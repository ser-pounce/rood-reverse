from io import BytesIO
from pathlib import Path
from typing import Any

from kaitaistruct import KaitaiStream
from splat.segtypes.segment import Segment
from splat.util import options

from tools.kaitai.parsers.lib.img import Img
from tools.libdata.img import decode_tim


def dump_tim(
    data: bytes,
    output_path: Path
) -> None:
    tim = Img.Tim(KaitaiStream(BytesIO(data)))
    output_path.parent.mkdir(parents=True, exist_ok=True)
    decode_tim(tim, output_path)


class PSXSegTim(Segment):

    def out_path(self) -> Path:
        type_extension = f".{self.type}" if options.opts.image_type_in_extension else ""
        return options.opts.asset_path / self.dir / f"{self.name}{type_extension}.png"

    def make_path(self) -> Path:
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        return path

    def split(self, rom_bytes: bytes) -> None:
        dump_tim(
            rom_bytes[self.rom_start:self.rom_end],
            self.make_path()
        )
