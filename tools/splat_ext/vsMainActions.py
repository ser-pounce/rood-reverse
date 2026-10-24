from pathlib import Path

from splat.segtypes.segment import Segment
from splat.util import options

from tools.data.SLUS_010_40.vs_main_actions import dump_actions


class PSXSegVsMainActions(Segment):
    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.h"

    def make_path(self) -> Path:
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        return path

    def split(self, rom_bytes: bytes) -> None:
        data = rom_bytes[self.rom_start:self.rom_end]
        with self.make_path().open("w", encoding="utf-8") as file:
            file.write(dump_actions(data))
