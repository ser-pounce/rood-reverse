from pathlib import Path

from splat.segtypes.segment import Segment
from splat.util import options

from tools.data.ENDING.ENDING_PRG.credits import dump_credits


class PSXSegCredits(Segment):
    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.yaml"

    def make_path(self) -> Path:
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        return path

    def split(self, rom_bytes: bytes) -> None:
        data = rom_bytes[self.rom_start:self.rom_end]
        self.make_path().write_text(dump_credits(data), encoding="utf-8")
