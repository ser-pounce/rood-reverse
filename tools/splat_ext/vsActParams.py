import sys
import ctypes
from tools.splat_ext.yamlSegment import YamlSegment


class Params(ctypes.LittleEndianStructure):
     _fields_ = [
         ("D_8004A504", ctypes.c_uint8 * 24),
         ("_actParams", ctypes.c_uint8 * 16),
         ("D_8004A52C", ctypes.c_uint32),
     ]

__symbols__ = {
    'D_8004A504': 0,
    '_actParams': ctypes.sizeof(ctypes.c_uint8 * 24),
    'D_8004A52C': ctypes.sizeof(ctypes.c_uint8 * 16),
}

__symbols__['D_8004A52C'] += __symbols__['_actParams']

class PSXSegVsActParams(YamlSegment):
    rootType = Params

if __name__ == "__main__":
    PSXSegVsActParams.to_bytes(sys.argv[1], sys.argv[2])
