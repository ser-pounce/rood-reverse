import ctypes


class vsStringBase():
    _type_ = ctypes.c_ubyte

def vsString(length):
    class vsString(ctypes.Array, vsStringBase):
        _length_ = length
    vsString.__name__ = f"vsString_{length}"
    return vsString

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
    '', '', '', '', '', '', '', '\0',      # 0xE0
    '\n', '', '', '', '', '', '', '',
    '', '', '', '', '', '', '', '',         # 0xF0
    '', '', '', '', '', '', '', '',
]

utf8_shift_table = [
    '', '', '', '', '', '', ' '
]

def decode(s):
    result = ""
    shift = False
    for b in s:
        if b == 0xFA:
            shift = True
        elif shift:
            result += utf8_shift_table[b]
            shift = False
        else:
            result += utf8_table[b]
    return result

def encode(s):
    result = []
    i = 0
    while i < len(s):
        if s[i:i+3] == "Lv.":
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
