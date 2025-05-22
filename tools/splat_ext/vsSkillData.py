import sys
import ctypes
from tools.splat_ext.yamlSegment import YamlSegment
from tools.splat_ext.vsString import vsString


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

class PSXSegVsSkillData(YamlSegment):
    rootType = Skills

if __name__ == "__main__":
    PSXSegVsSkillData.to_bytes(sys.argv[1], sys.argv[2])
