import sys
import json
from pathlib import Path

def get_name_and_category(base_path: Path):
    parts = base_path.parts
    for i, part in enumerate(parts):
        if part.endswith(".PRG") or part == "SLUS_010.40":
            return Path(*parts[i:]).with_suffix(""), part
    raise ValueError(f"No valid category in path: {base_path}")

def main(basepath: Path, targetpath: Path):
    skip_files = {"2842C.o", "6E644.o", "32154.o"}
    units = []
    for base_path in (basepath / "src").rglob("*.o"):
        name, progress_category = get_name_and_category(base_path)
        target_path = targetpath / base_path.relative_to(basepath)
        unit = {
            "name": str(name),
            "target_path": str(target_path),
            "metadata": {
                "progress_categories": [str(progress_category)]
            }
        }
        if base_path.name not in skip_files:
            unit["base_path"] = str(base_path)
        units.append(unit)
    with open("objdiff.json", "w") as f:
        json.dump({"units": units}, f, indent=2)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python find_o_files.py <basepath> <targetpath>")
        sys.exit(1)
    main(Path(sys.argv[1]), Path(sys.argv[2]))