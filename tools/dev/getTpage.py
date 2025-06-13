import sys

def decompose_vs_getTpage(val):
    # Remove the 0xE1 << 24 prefix
    if (val & 0xFF000000) != 0xE1000000:
        raise ValueError("Value does not have the vs_getTpage prefix (0xE1 << 24)")
    tpage = val & 0xFFFF

    # Extract dtd (bit 9)
    dtd = (tpage >> 9) & 1

    # Remove dtd bit for getTPage
    getTPage_val = tpage & ~(1 << 9)

    # Reverse getTPage
    tp   = (getTPage_val >> 7) & 0x3
    abr  = (getTPage_val >> 5) & 0x3
    x    = ((getTPage_val & 0x1F) << 6)
    x   |= 0  # lower 6 bits are zeroed by macro
    y    = ((getTPage_val & 0x200) << 1) | ((getTPage_val & 0x10) << 4)
    # y bits: ((y)&0x100)>>4 is bit 8 at bit 4, ((y)&0x200)<<2 is bit 9 at bit 11
    y   |= 0  # lower bits are zeroed by macro

    # Try to reconstruct y more accurately
    y = 0
    if getTPage_val & 0x10:
        y |= 0x100
    if getTPage_val & 0x200:
        y |= 0x200

    return f"vs_getTpage({x}, {y}, {tp}, {abr}, {dtd})"

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 vs_getTpage_from_int.py <hex_value>")
        sys.exit(1)
    val = int(sys.argv[1], 16)
    print(decompose_vs_getTpage(val))