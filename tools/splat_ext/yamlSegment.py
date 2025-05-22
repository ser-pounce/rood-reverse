import yaml
from pathlib import Path
from splat.segtypes.segment import Segment
from splat.util import options
from tools.splat_ext.ctypesUtil import ctypes_to_dict, dict_to_ctypes


class YamlSegment(Segment):

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.yaml"

    def split(self, rom_bytes):

        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
    
        root_t = self.rootType.from_buffer_copy(rom_bytes[self.rom_start:])

        with open(path, "w") as f:
            yaml.dump(ctypes_to_dict(root_t), f, sort_keys=False)

    @classmethod
    def to_bytes(cls, input_path, output_path):
        with open(input_path, "r") as f:
            data = yaml.safe_load(f)

        root_t = dict_to_ctypes(data, cls.rootType)

        with open(output_path, "wb") as f:
            f.write(bytearray(root_t))