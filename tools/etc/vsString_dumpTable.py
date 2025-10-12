import sys
from tools.etc.vsString import write_table


if __name__ == '__main__':
    with open(sys.argv[1], "rb") as f:
        data = f.read()
    
    count = int.from_bytes(data[0:2], "little")

    offsets = [
        int.from_bytes(data[2*i:2*i + 2], "little")
        for i in range(count)
    ]
    
    write_table(data, offsets, sys.argv[2], sys.argv[3])
