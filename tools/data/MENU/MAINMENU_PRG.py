import sys

def patch_file(path):
    patches = {
        0x8C0B: bytes([0xF8, 0xF8, 0xF8, 0xB1, 0x38]),
        0x8C75: bytes([0xD2]),
        0x8D47: bytes([0xF8]),
    }

    with open(path, "r+b") as f:
        for addr, data in patches.items():
            f.seek(addr)
            f.write(data)

    print(f"Patched {path} at addresses: {', '.join(hex(a) for a in patches)}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python patch.py <path_to_binary>")
        sys.exit(1)

    patch_file(sys.argv[1])
