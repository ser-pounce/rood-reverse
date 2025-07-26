import sys
from tools.etc.vsString import decode


if len(sys.argv) != 4:
    print("Usage: python decode_vsstring.py <binary_file> <start_offset> <end_offset>")
    sys.exit(1)

bin_path = sys.argv[1]
start = int(sys.argv[2], 0)
end = int(sys.argv[3], 0)

with open(bin_path, "rb") as f:
    f.seek(start)
    data = f.read(end - start)

decoded = decode(data)
print(decoded)
