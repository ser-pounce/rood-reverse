from pathlib import Path
from splat.segtypes.segment import Segment
from splat.util import options
import ctypes, sys
import yaml

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

def ctypes_to_dict(obj):
    if isinstance(obj, ctypes.Array):
        return [ctypes_to_dict(item) for item in obj]
    if hasattr(obj, "_fields_"):
        result = {}
        for field in obj._fields_:
            value = getattr(obj, field[0])
            result[field[0]] = ctypes_to_dict(value)
        return result
    return obj
    
def dict_to_ctypes(data, ctype):
    if issubclass(ctype, ctypes.Array):
        arr = ctype()
        for i, item in enumerate(data):
            arr[i] = dict_to_ctypes(item, ctype._type_)
        return arr
    if hasattr(ctype, "_fields_"):
        inst = ctype()
        for field in ctype._fields_:
            name = field[0]
            value = data[name]
            setattr(inst, name, dict_to_ctypes(value, field[1]))
        return inst
    return data


class PSXSegVsAnimData(Segment):

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.yaml"
    
    def split(self, rom_bytes):

        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
    
        skills = Animations.from_buffer_copy(rom_bytes[self.rom_start:])

        with open(path, "w") as f:
            yaml.dump(ctypes_to_dict(skills), f, sort_keys=False)

if __name__ == "__main__":
    with open(sys.argv[1], "r") as f:
        data = yaml.safe_load(f)

    skills_struct = dict_to_ctypes(data, Animations)

    with open(sys.argv[2], "wb") as f:
        f.write(bytearray(skills_struct))
