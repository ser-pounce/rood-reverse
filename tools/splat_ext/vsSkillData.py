from pathlib import Path
from splat.segtypes.segment import Segment
from splat.util import options
import ctypes, sys
import yaml

class vsString(ctypes.Array):
    _type_ = ctypes.c_ubyte
    _length_ = 24

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
        ("name", vsString),
    ]

class Skills(ctypes.Array):
    _type_ = Skill
    _length_ = 256

utf8_table = [
    '0', '1', '2', '3', '4', '5', '6', '7', # 0x00
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', # 0x10
    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', # 0x20
    'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', # 0x30
    'u', 'v', 'w', 'x', 'y', 'z', '', '',
    'Ć', 'Â', 'Ä', 'Ç', 'È', 'É', 'Ê', 'Ë', # 0x40
    'Ì', 'ő', 'Î', 'í', 'Ò', 'Ó', 'Ô', 'Ö',
    'Ù', 'Ú', 'Û', 'Ü', 'ß', 'æ', 'à', 'á', # 0x50
    'â', 'ä', 'ç', 'è', 'é', 'ê', 'ë', 'ì',
    'í', 'î', 'ï', 'ð', 'ñ', 'ò', 'ó', 'ô', # 0x60
    'ú', 'û', 'ü', '', '', '', '', '',
    '', '', '', '', '', '', '', '',         # 0x70
    '', '', '', '', '', '', '', '',
    '', '', '', '', '', '', '', '‼',        # 0x80
    '≠', '≦', '≧', '÷', '–', '—', '⋯', '',
    '!', '"', '#', '$', '%', '&', '\'', '(',# 0x90
    ')', '{', '}', '[', ']', ';', ':', ',',
    '.', '/', '\\', '<', '>', '?', '_', '-',# 0xA0
    '+', '*', '', '{', '}', '♪', '', '',
    '', '', '', '', '', '', 'Lv.', '',      # 0xB0
    '', '', '', '', '', '', '', '',
    '', '', '', '', '', '', '', '',         # 0xC0
    '', '', '', '', '', '', '', '',
    '', '', '', '', '', '', '', '',         # 0xD0
    '', '', '', '', '', '', '', '',
    '', '', '', '', '', '', '', '\\0',      # 0xE0
    '\\n', '', '', '', '', '', '', '',
    '', '', '', '', '', '', '', '',         # 0xF0
    '', '', '', '', '', '', '', '',
]

utf8_shift_table = [
    '', '', '', '', '', '', ' '
]

def decode_str(s):
    str = ""
    shift = False
    for b in s:
        if b == 0xFA:
            shift = True
        elif shift:
            str += utf8_shift_table[b]
            shift = False
        else:
            str += utf8_table[b]
    return str

def encode_str(s):
    result = []
    i = 0
    while i < len(s):
        if s[i] == '\\':
            c = utf8_table.index(s[i:i+2])
            i += 2
        elif s[i:i+3] == "Lv.":
            c = utf8_table.index("Lv.")
            i += 3
        else:
            try:
                c = utf8_table.index(s[i])
            except ValueError:
                c = utf8_shift_table.index(s[i])
                result.append(0xFA)
            i += 1
        result.append(c)
    return bytes(result)

def ctypes_to_dict(obj):
    if isinstance(obj, vsString):
        return decode_str(obj)
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
    if issubclass(ctype, vsString):
        return ctype(*encode_str(data))
    elif issubclass(ctype, ctypes.Array):
        arr = ctype()
        for i, item in enumerate(data):
            arr[i] = dict_to_ctypes(item, ctype._type_)
        return arr
    elif hasattr(ctype, "_fields_"):
        inst = ctype()
        for field in ctype._fields_:
            name = field[0]
            value = data[name]
            setattr(inst, name, dict_to_ctypes(value, field[1]))
        return inst
    return data


class PSXSegVsSkillData(Segment):

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.yaml"
    
    def split(self, rom_bytes):

        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
    
        skills = Skills.from_buffer_copy(rom_bytes[self.rom_start:self.rom_end])

        with open(path, "w") as f:
            yaml.dump(ctypes_to_dict(skills), f, sort_keys=False)

if __name__ == "__main__":
    with open(sys.argv[1], "r") as f:
        data = yaml.safe_load(f)

    skills_struct = dict_to_ctypes(data, Skills)

    with open(sys.argv[2], "wb") as f:
        f.write(bytearray(skills_struct))
