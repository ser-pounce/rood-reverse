import sys
import json
from pathlib import Path

def get_name_and_category(base_path: Path):
    parts = base_path.parts
    for i, part in enumerate(parts):
        if part.endswith(".PRG") or part == "SLUS_010.40":
            return Path(*parts[i:]).with_suffix(""), part
    raise ValueError(f"No valid category in path: {base_path}")

def main(basepath: Path, targetpath: Path, categories_path: Path):
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
        if (
            base_path.name not in {"32154.o", "2EA3C.o", "38C1C.o", "6E644.o"}
            and not base_path.name.endswith((".data.o", ".rodata.o", ".bss.o"))
        ):
            unit["base_path"] = str(base_path)
        units.append(unit)
    with open(categories_path, "r") as cat_file:
        categories = json.load(cat_file)
    with open("objdiff.json", "w") as f:
        json.dump({"units": units, "progress_categories": categories}, f, indent=2)

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python find_o_files.py <basepath> <targetpath> <categories.json>")
        sys.exit(1)
    main(Path(sys.argv[1]), Path(sys.argv[2]), Path(sys.argv[3]))