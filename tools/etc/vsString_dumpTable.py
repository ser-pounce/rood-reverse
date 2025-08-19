import sys
from tools.etc.vsString import write_table


if __name__ == '__main__':
    with open(sys.argv[1], "rb") as f:
        data = f.read()
    write_table(data, sys.argv[2], sys.argv[3])
