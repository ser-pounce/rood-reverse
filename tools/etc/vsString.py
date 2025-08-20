import ctypes
import yaml


class vsStringBase():
    _type_ = ctypes.c_ubyte

def vsString(length):
    class vsString(ctypes.Array, vsStringBase):
        _length_ = length
    vsString.__name__ = f"vsString_{length}"
    return vsString

table = [
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
    '\n', '', '', '', '', '', '', '239', #
    '', '', '', '', '', '', '|x', '',         # 0xF0
    '|!', '', '|>', '|F', '', '', '', '|$',
]

# This isn't the only encoding used in the game, occasionally
# ASCII can be found, where digits are seemingly prefixed with #

# Upon decoding, functions are denoted by enclosing within ||, 
# as it's the only common symbol not represented in the default text table.

# String functions, 1-byte argument
# 0xF6 -> |xn|: No known function currently, possibly debug
# 0xF8 -> |!n|: Sets the character chunking size to n, where 0 = process entire string
# 0xFA -> |>n|: Advances the next glyph position by n pixels
# 0xFB -> |Fn|: Manipulate font table. n = 0-3 sets the color, n = 4 justifies the text,
#               n = 5 or 6 set font table 1 and 0 respectively.
# 0xFF -> |$n|: Inserts a previously stored string with ID n

def decode(s):
    result = ""
    i = 0
    while i < len(s):
        match s[i]:
            case 0xE7:
                return result
            case 0xEB:  # 2-byte alignment, ignored
                i += 1
            case 0xF6 | 0xF8 | 0xFA | 0xFB | 0xFF:
                result += f"{table[s[i]]}{s[i + 1]}|"
                i += 2
            case _:
                if table[s[i]] == '':
                    raise ValueError(f"Invalid byte {s[i]} in vsString")
                result += table[s[i]]
                i += 1
    return result

def encode_raw(s):
    result = []
    i = 0
    while i < len(s):
        if s[i] == '|':
            end = s.find('|', i + 3)
            if end == -1:
                print(s)
                raise ValueError("Unterminated control")
            result.extend([table.index(s[i:i+2]), int(s[i+2:end].strip())])
            i = end + 1
        elif s[i:i+3] == "Lv.":
            result.append(table.index("Lv."))
            i += 3
        else:
            result.append(table.index(s[i]))
            i += 1
    return bytes(result)

def encode(s, padding=0xEB):
    result = list(encode_raw(s))
    result.append(0xE7)
    if len(result) % 2 == 1:
        result.append(padding)
    return bytes(result)


class LiteralString(str): 
    pass

def literal_representer(dumper, data):
    return dumper.represent_scalar("tag:yaml.org,2002:str", str(data), style="|")

yaml.add_representer(LiteralString, literal_representer)

def assign_strings(template, strings, idx=0):
    if isinstance(template, dict):
        result = {}
        for k, v in template.items():
            result[k], idx = assign_strings(v, strings, idx)
        return result, idx

    elif isinstance(template, list):
        result = []
        for v in template:
            new_v, idx = assign_strings(v, strings, idx)
            result.append(new_v)
        return result, idx

    else:
        if idx >= len(strings):
            raise ValueError("Not enough strings for keys template")
        return strings[idx], idx + 1

def write_table(data, keys_file, out_path):
    count = int.from_bytes(data[0:2], "little")

    offsets = [
        int.from_bytes(data[2*i:2*i + 2], "little")
        for i in range(count)
    ]

    with open(keys_file, "r", encoding="utf-8") as f:
        keys_yaml = yaml.safe_load(f)

    strings = []
    for off in offsets:
        s = decode(data[off*2:])
        if "\n" in s:
            s = LiteralString(s)
        strings.append(s)

    result, used = assign_strings(keys_yaml, strings)

    if used != len(strings):
        raise ValueError(
            f"Not all strings were consumed (used {used}, have {len(strings)})"
        )

    with open(out_path, "w", encoding="utf-8") as f:
        yaml.dump(result, f, allow_unicode=True, sort_keys=False, width=1000)
