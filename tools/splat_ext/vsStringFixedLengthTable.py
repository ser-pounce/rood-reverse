from pathlib import Path

from splat.segtypes.segment import Segment
from splat.util import options

from tools.dev.dumpFixedLenStrings import decode_strings, format_strings


class PSXSegVsStringFixedLengthTable(Segment):

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        length = self.yaml.get("length") if isinstance(self.yaml, dict) else None
        if length is None:
            raise ValueError(f"Segment '{self.name}' requires a 'length' parameter")
        self.record_length = int(length, 0) if isinstance(length, str) else length
        if self.record_length <= 0:
            raise ValueError(f"Segment '{self.name}': length must be a positive integer")

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.vsStringFixed.yaml"

    def make_path(self) -> Path:
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        return path

    def split(self, rom_bytes: bytes) -> None:
        data = rom_bytes[self.rom_start:self.rom_end]
        lines = format_strings(decode_strings(data, self.record_length))
        self.make_path().write_text("\n".join(lines) + "\n")
