import sys
import ctypes
from tools.splat_ext.yamlSegment import YamlSegment


class D_8004EDDC(ctypes.Array):
    _type_ = ctypes.c_uint8
    _length_ = 30

class PSXSegVsD_8004EDDC(YamlSegment):
    rootType = D_8004EDDC * 8

if __name__ == "__main__":
    PSXSegVsD_8004EDDC.to_bytes(sys.argv[1], sys.argv[2])
