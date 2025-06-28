import sys

if len(sys.argv) != 2:
    print("Usage: python makexy.py <hex_value>")
    sys.exit(1)

value = int(sys.argv[1], 16)
x = value & 0xFFFF
y = (value >> 16) & 0xFFFF

print(f"MAKEXY({x}, {y})")