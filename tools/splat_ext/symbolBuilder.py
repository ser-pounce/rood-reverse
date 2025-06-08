import sys
import importlib

if __name__ == "__main__":
    module = importlib.import_module(sys.argv[1])
    for attr in module.__symbols__:
        print(f"--add-symbol {sys.argv[2]}_{attr}=.data:{module.__symbols__[attr]}", end=' ')