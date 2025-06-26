import sys
from tools.etc.vsString import decode

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python decode_vsstring.py <input_file>")
        sys.exit(1)

    with open(sys.argv[1], "rb") as f:
        f.seek(0x112)
        data = f.read()

    try:
        decoded = decode(data)
        print(decoded)
    except Exception as e:
        print(f"Error decoding: {e}")