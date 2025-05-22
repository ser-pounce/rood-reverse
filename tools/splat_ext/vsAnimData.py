import sys
import ctypes
from tools.splat_ext.yamlSegment import YamlSegment


class Anim16(ctypes.Array):
    _type_ = ctypes.c_uint8
    _length_ = 16

class Anim8(ctypes.Array):
    _type_ = ctypes.c_uint8
    _length_ = 8

class Anim4(ctypes.Array):
    _type_ = ctypes.c_uint8
    _length_ = 4

class Anim2(ctypes.Array):
    _type_ = ctypes.c_uint8
    _length_ = 2

class Animations(ctypes.LittleEndianStructure):
     _fields_ = [
         ("anim16", Anim16 * 63),
         ("anim8", Anim8 * 63),
         ("anim4", Anim4 * 63),
         ("anim2", Anim2 * 63),
     ]

__symbols__ = {
    '_animOffset16': 0,
	'_animOffset8': ctypes.sizeof(Anim16) * 63,
	'_animOffset4': ctypes.sizeof(Anim8) * 63,
	'_animOffset2': ctypes.sizeof(Anim4) * 63,
}

__symbols__['_animOffset4'] += __symbols__['_animOffset8']
__symbols__['_animOffset2'] += __symbols__['_animOffset4']


class PSXSegVsAnimData(YamlSegment):
    rootType = Animations

if __name__ == "__main__":
    PSXSegVsAnimData.to_bytes(sys.argv[1], sys.argv[2])
