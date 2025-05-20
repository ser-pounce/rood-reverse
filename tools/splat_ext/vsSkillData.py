import sys
from pathlib import Path
import ctypes
import yaml
from splat.segtypes.segment import Segment
from splat.util import options
from tools.splat_ext.vsString import vsString
from tools.splat_ext.ctypesUtil import ctypes_to_dict, dict_to_ctypes


class HitParams(ctypes.LittleEndianStructure):
    _fields_ = [
        ("effect", ctypes.c_uint32, 7),
        ("hitrateFlags", ctypes.c_uint32, 6),
        ("hitrateAdj", ctypes.c_uint32, 3),
        ("damage", ctypes.c_uint32, 6),
        ("mult", ctypes.c_uint32, 5),
        ("type", ctypes.c_uint32, 2),
        ("affinity", ctypes.c_uint32, 3),
    ]

class Skill(ctypes.LittleEndianStructure):
    _fields_ = [
        ("id", ctypes.c_uint8),
        ("effect", ctypes.c_uint8),
        ("unk2_0", ctypes.c_uint8, 1),
        ("type", ctypes.c_uint8, 3),
        ("target", ctypes.c_uint8, 4),
        ("cost", ctypes.c_uint8),
        ("rangeX", ctypes.c_uint8),
        ("rangeY", ctypes.c_uint8),
        ("rangeZ", ctypes.c_uint8),
        ("shape", ctypes.c_uint8, 3),
        ("angle", ctypes.c_uint8, 5),
        ("aoe", ctypes.c_int32),
        ("wait", ctypes.c_uint16, 8),
        ("pad", ctypes.c_uint16, 7),
        ("learned", ctypes.c_uint16, 1),
        ("unkD", ctypes.c_uint8),
        ("unkE", ctypes.c_uint8),
        ("unkF", ctypes.c_uint32),
        ("hitParams", HitParams * 2),
        ("name", vsString(24)),
    ]

class Skills(ctypes.Array):
    _type_ = Skill
    _length_ = 256

class PSXSegVsSkillData(Segment):

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.yaml"
    
    def split(self, rom_bytes):

        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
    
        skills = Skills.from_buffer_copy(rom_bytes[self.rom_start:])

        with open(path, "w") as f:
            yaml.dump(ctypes_to_dict(skills), f, sort_keys=False)

if __name__ == "__main__":
    with open(sys.argv[1], "r") as f:
        data = yaml.safe_load(f)

    skills = dict_to_ctypes(data, Skills)

    with open(sys.argv[2], "wb") as f:
        f.write(bytearray(skills))
