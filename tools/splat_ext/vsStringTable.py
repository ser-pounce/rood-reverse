import yaml
from pathlib import Path

from kaitaistruct import KaitaiStream, BytesIO
from splat.segtypes.segment import Segment
from splat.util import options

from tools.etc.vsString_dumpTable import vsString_dumpTable
from tools.kaitai.parsers.lib.string_table import StringTable


class PSXSegVsStringTable(Segment):

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.vsString.yaml"


    def make_path(self) -> Path:
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        return path


    def split(self, rom_bytes: bytes) -> None:

        keys_path = (
            options.opts.asset_path
            / self.dir
            / f"{self.name}.yaml"
        ).relative_to(options.opts.build_path)

        vsString_dumpTable(rom_bytes[self.rom_start:self.rom_end], keys_path, self.make_path())
