import sys
import json
from pathlib import Path

def load_category_mappings(categories_path: Path):
    with open(categories_path, "r") as cat_file:
        categories = json.load(cat_file)
    
    # Extract the category_mappings object from the categories list
    for item in categories:
        if "category_mappings" in item:
            return item["category_mappings"]
    
    raise ValueError("No category_mappings found in categories.json")

def get_name_and_category(base_path: Path, category_mappings: dict):
    parts = base_path.parts
    for i, part in enumerate(parts):
        if part.endswith(".PRG") or part == "SLUS_010.40":
            name = Path(*parts[i:]).with_suffix("")
            # Map the old category to the new prefixed category
            progress_category = category_mappings.get(part, part)
            return name, progress_category
    raise ValueError(f"No valid category in path: {base_path}")

def main(basepath: Path, targetpath: Path, categories_path: Path):
    category_mappings = load_category_mappings(categories_path)
    
    units = []
    for base_path in (basepath / "src").rglob("*.o"):
        name, progress_category = get_name_and_category(base_path, category_mappings)
        target_path = targetpath / base_path.relative_to(basepath)
        unit = {
            "name": str(name),
            "target_path": str(target_path),
            "metadata": {
                "progress_categories": [str(progress_category)],
                "complete": str(name) in {    
                    "SLUS_010.40/overlay",
                    "MENU0.PRG/84",
                    "MENU1.PRG/30",
                    "MENU2.PRG/64",
                    "MENU2.PRG/143C",
                    "MENU4.PRG/120",
                    "MENU5.PRG/4D8",
                    "MENU8.PRG/88",
                    "MENU8.PRG/21A0",
                    "MENUE.PRG/494",
                    "TITLE.PRG/22C",
                    "TITLE.PRG/libpress/VLC_C",
                    "TITLE.PRG/libpress/BUILD"
                }
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
    
    # Filter out category_mappings from the output
    filtered_categories = [item for item in categories if "category_mappings" not in item]
    
    with open("objdiff.json", "w") as f:
        json.dump({"units": units, "progress_categories": filtered_categories}, f, indent=2)

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python find_o_files.py <basepath> <targetpath> <categories.json>")
        sys.exit(1)
    main(Path(sys.argv[1]), Path(sys.argv[2]), Path(sys.argv[3]))