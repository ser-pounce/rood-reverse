import yaml
from pathlib import Path
from splat.segtypes.segment import Segment
from splat.util import options
from tools.etc.vsString import write_table


class LiteralString(str): 
    pass

def literal_representer(dumper, data):
    return dumper.represent_scalar("tag:yaml.org,2002:str", str(data), style="|")

yaml.add_representer(LiteralString, literal_representer)


class PSXSegVsStringTable(Segment):

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.vsString.yaml"
    
    def make_path(self) -> Path:
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        return path

    def split(self, rom_bytes: bytes) -> None:

        data = rom_bytes[self.rom_start:self.rom_end]

        keys_path = (
            options.opts.asset_path
            / self.dir
            / f"{self.name}.yaml"
        ).relative_to(options.opts.build_path)
        out_path = self.make_path()

        count = int.from_bytes(data[0:2], "little")

        offsets = [
            int.from_bytes(data[2*i:2*i + 2], "little")
            for i in range(count)
        ]

        write_table(data, offsets, keys_path, out_path)
