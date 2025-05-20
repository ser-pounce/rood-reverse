import sys
from pathlib import Path
import ctypes
import yaml
from splat.segtypes.segment import Segment
from splat.util import options
from tools.splat_ext.ctypesUtil import ctypes_to_dict, dict_to_ctypes


class SoundFileMap(ctypes.Array):
    _type_ = ctypes.c_uint8
    _length_ = 200

class PSXSegVsSoundFileMap(Segment):

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.yaml"
    
    def split(self, rom_bytes):

        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
    
        anims = SoundFileMap.from_buffer_copy(rom_bytes[self.rom_start:])

        with open(path, "w") as f:
            yaml.dump(ctypes_to_dict(anims), f, sort_keys=False)

if __name__ == "__main__":
    with open(sys.argv[1], "r") as f:
        data = yaml.safe_load(f)

    anims = dict_to_ctypes(data, SoundFileMap)

    with open(sys.argv[2], "wb") as f:
        f.write(bytearray(anims))
