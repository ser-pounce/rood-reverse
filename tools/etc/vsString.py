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
    'u', 'v', 'w', 'x', 'y', 'z', 'Œ', 'À',
    'Á', 'Â', 'Ä', 'Ç', 'È', 'É', 'Ê', 'Ë', # 0x40
    'Ì', 'Í', 'Î', 'Ï', 'Ò', 'Ó', 'Ô', 'Ö',
    'Ù', 'Ú', 'Û', 'Ü', 'ß', 'œ', 'à', 'á', # 0x50
    'â', 'ä', 'ç', 'è', 'é', 'ê', 'ë', 'ì',
    'í', 'î', 'ï', 'ò', 'ó', 'ô', 'ö', 'ù', # 0x60
    'ú', 'û', 'ü', '', '', '', '', '',
    '', '', '', '', '', '', '', '',         # 0x70
    '', '', '', '', '', '', '', '',
    '', '', '', '', '', '', '„', '‼',        # 0x80
    '≠', '≦', '≧', '÷', '·', '—', '⋯', ' ',
    '!', '"', '#', '$', '%', '&', '\'', '(',# 0x90
    ')', '=', '@', '[', ']', ';', ':', ',',
    '.', '/', '\\', '<', '>', '?', '_', '-',# 0xA0
    '+', '*', '`', '{', '}', '♪', '△', '□',
    '○', '×', '←', '→', '↑', '↓', 'Lv.', '★', # 0xB0
    '◼', '~', '', '', '', '', '', '',
    '', '', '', '', '', '', '', '',         # 0xC0
    '', '', '', '', '', '', '', '',
    '', '', '', '', '', '', '', '',         # 0xD0
    '', '', '', '', '', '', '', '',
    '', '', '', '', '', '', '▼', '\0',      # 0xE0
    '\n', '', '', '', '', '', '', '\uE0EF', #
    '', '', '', '', '', '', '\uE0F6', '',         # 0xF0
    '\uE0F8', '', '\uE0FA', '', '', '', '', '\uE0FF',
]


def decode(s):
    result = ""
    i = 0
    while i < len(s):
        if s[i] == 0xEB: # Alignment
            i += 1
        elif s[i] == 0xFA: # Advance glyph position
            result += f"|>{s[i + 1]}|"
            i += 2
        elif s[i] == 0xFF: # Insert reference
            result += f"|${s[i + 1]}|"
            i += 2
        else:
            if utf8_table[s[i]] == '':
                raise ValueError(f"Invalid byte {s[i]} in vsString")
            result += utf8_table[s[i]]
            i += 1
    return result

def encode_raw(s):
    result = []
    i = 0
    while i < len(s):
        if s[i:i+2] == '|>':
            i += 2
            end = s.find('|', i)
            if end == -1:
                raise ValueError("Unterminated control")
            result.extend([0xFA, int(s[i:end].strip())])
            i += (end - i) + 1
        elif s[i:i+2] == '|$':
            i += 2
            end = s.find('|', i)
            if end == -1:
                raise ValueError("Unterminated control")
            result.extend([0xFF, int(s[i:end].strip())])
            i += (end - i) + 1
        elif s[i:i+3] == "Lv.":
            result.append(utf8_table.index("Lv."))
            i += 3
        else:
            try:
                result.append(utf8_table.index(s[i]))
                i += 1
            except ValueError:
                raise ValueError(s)
    return bytes(result)

def encode(s):
    result = list(encode_raw(s))
    result.append(0xE7)
    if len(result) % 2 == 1:
        result.append(0xEB)
    return bytes(result)
