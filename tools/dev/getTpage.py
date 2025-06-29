import sys

def decompose_vs_getTpage(val):
    if (val & 0xFF000000) != 0xE1000000:
        raise ValueError("Value does not have the vs_getTpage prefix (0xE1 << 24)")
    tpage = val & 0xFFFF

    dtd = (tpage >> 9) & 1
    tp  = (tpage >> 7) & 0x3
    abr = (tpage >> 5) & 0x3
    x   = (tpage & 0xF) << 6
    y   = (tpage & 0x10) << 4

    return f"vs_getTpage({x}, {y}, {tp}, {abr}, {dtd})"

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 vs_getTpage_from_int.py <hex_value>")
        sys.exit(1)
    val = int(sys.argv[1], 16)
    print(decompose_vs_getTpage(val))