import yaml
from pathlib import Path
from splat.segtypes.segment import Segment
from splat.util import options
from tools.etc.vsString import decode


class LiteralString(str): 
    pass

def literal_representer(dumper, data):
    return dumper.represent_scalar("tag:yaml.org,2002:str", str(data), style="|")

yaml.add_representer(LiteralString, literal_representer)


class PSXSegVsStringTable(Segment):

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.vsString.segment.yaml"
    
    def make_path(self) -> Path:
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        return path

    def split(self, rom_bytes: bytes) -> None:
        count = int.from_bytes(
            rom_bytes[self.rom_start:self.rom_start+2], "little"
        )

        offsets = [
            int.from_bytes(
                rom_bytes[self.rom_start + 2*i : self.rom_start + 2*i + 2],
                "little"
            )
            for i in range(count)
        ]

        keys_path = (
            options.opts.asset_path
            / self.dir
            / f"{self.name}.yaml"
        ).relative_to(options.opts.build_path)

        with open(keys_path, "r", encoding="utf-8") as f:
            keys = yaml.safe_load(f)

        keys = list(keys.keys())

        strings = [
            LiteralString(s) if "\n" in (s := decode(
                rom_bytes[self.rom_start + off*2 : self.rom_end]
            )) else s
            for off in offsets
        ]

        result = dict(zip(keys, strings))

        out_path = self.make_path()
        with open(out_path, "w", encoding="utf-8") as f:
            yaml.dump(result, f, allow_unicode=True, sort_keys=False, width=1000)
