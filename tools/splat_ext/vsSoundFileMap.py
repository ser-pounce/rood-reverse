import sys
import ctypes
from tools.splat_ext.yamlSegment import YamlSegment


class SoundFileMap(ctypes.Array):
    _type_ = ctypes.c_uint8
    _length_ = 200

class PSXSegVsSoundFileMap(YamlSegment):
    rootType = SoundFileMap
    objcopyflags = "--add-symbol _soundFileMap=.data:0"

if __name__ == "__main__":
    PSXSegVsSoundFileMap.to_bytes(sys.argv[1], sys.argv[2])
