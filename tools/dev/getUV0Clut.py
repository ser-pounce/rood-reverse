import sys

def decompose_vs_getUV0Clut(val):
    uv = val & 0xFFFF
    clut = (val >> 16) & 0xFFFF

    u = uv & 0xFF
    v = (uv >> 8) & 0xFF

    y = (clut >> 6) & 0x3FF
    x = (clut & 0x3F) << 4

    return f"vs_getUV0Clut({u}, {v}, {x}, {y})"

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 vs_getUV0Clut_from_int.py <hex_value>")
        sys.exit(1)
    val = int(sys.argv[1], 16)
    print(decompose_vs_getUV0Clut(val))