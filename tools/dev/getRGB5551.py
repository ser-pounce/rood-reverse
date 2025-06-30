import sys


def invert_vs_getRGB5551(rgb555):
    r = rgb555 & 0x1F
    g = (rgb555 >> 5) & 0x1F
    b = (rgb555 >> 10) & 0x1F
    a = (rgb555 >> 15) & 0x01
    return r, g, b, a

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 getRGB5551.py <hex_value1,hex_value2,...>")
        sys.exit(1)
    values = sys.argv[1].split(',')
    results = []
    for val_str in values:
        val = int(val_str.strip(), 16)
        results.append(f"vs_getRGB5551{invert_vs_getRGB5551(val)}")
    print(','.join(results))