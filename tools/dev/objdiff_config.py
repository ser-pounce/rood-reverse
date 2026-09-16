import argparse
import json
from pathlib import Path


def load_categories(categories_path: Path):
    with open(categories_path, "r") as f:
        categories = json.load(f)

    category_mappings = None
    complete_units = set()
    excluded_names = set()
    excluded_suffixes = ()
    filtered_categories = []

    for item in categories:
        if "category_mappings" in item:
            category_mappings = item["category_mappings"]
        elif "complete_units" in item:
            complete_units = set(item["complete_units"])
        elif "exclusions" in item:
            excluded_names = set(item["exclusions"].get("names", []))
            excluded_suffixes = tuple(item["exclusions"].get("suffixes", []))
        else:
            filtered_categories.append(item)

    if category_mappings is None:
        raise ValueError("No category_mappings found in categories.json")

    return category_mappings, complete_units, excluded_names, excluded_suffixes, filtered_categories


def get_name_and_categories(base_path: Path, category_mappings: dict):
    for i, part in enumerate(base_path.parts):
        if part in category_mappings:
            name = Path(*base_path.parts[i:]).with_suffix("")
            new_category = category_mappings[part]
            supercategory = new_category.split(".", 1)[0]
            return name, [supercategory, new_category]
    raise ValueError(f"No recognized category in path: {base_path}")


def build_unit(base_path: Path, basepath: Path, targetpath: Path,
                category_mappings: dict, complete_units: set,
                excluded_names: set, excluded_suffixes: tuple):
    name, progress_categories = get_name_and_categories(base_path, category_mappings)
    target_path = targetpath / base_path.relative_to(basepath)

    unit = {
        "name": str(name),
        "target_path": str(target_path),
        "metadata": {
            "progress_categories": progress_categories,
            "complete": str(name) in complete_units,
        },
    }

    if base_path.name not in excluded_names and not base_path.name.endswith(excluded_suffixes):
        unit["base_path"] = str(base_path)

    return unit


def main(basepath: Path, targetpath: Path, categories_path: Path, output_path: Path):
    (category_mappings, complete_units, excluded_names,
     excluded_suffixes, filtered_categories) = load_categories(categories_path)

    o_files = sorted((basepath / "src").rglob("*.o"))
    units = [
        build_unit(base_path, basepath, targetpath, category_mappings,
                   complete_units, excluded_names, excluded_suffixes)
        for base_path in o_files
    ]

    with open(output_path, "w") as f:
        json.dump({"units": units, "progress_categories": filtered_categories}, f, indent=2)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate objdiff.json from .o files and a categories file.")
    parser.add_argument("basepath", type=Path)
    parser.add_argument("targetpath", type=Path)
    parser.add_argument("categories", type=Path)
    parser.add_argument("-o", "--output", type=Path, default=Path("objdiff.json"))
    args = parser.parse_args()

    main(args.basepath, args.targetpath, args.categories, args.output)
