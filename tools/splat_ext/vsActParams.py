import sys
import ctypes
from tools.splat_ext.yamlSegment import YamlSegment


class Params(ctypes.LittleEndianStructure):
     _fields_ = [
         ("D_8004A504", ctypes.c_uint8 * 24),
         ("_actParams", ctypes.c_uint8 * 20),
     ]

__symbols__ = {
    'D_8004A504': 0,
    '_actParams': ctypes.sizeof(ctypes.c_uint8 * 24),
}

class PSXSegVsActParams(YamlSegment):
    rootType = Params

if __name__ == "__main__":
    PSXSegVsActParams.to_bytes(sys.argv[1], sys.argv[2])
