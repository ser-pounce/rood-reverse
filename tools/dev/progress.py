import json
from collections import defaultdict

with open("progress.json") as f:
    data = json.load(f)

category_totals = defaultdict(lambda: {"total_code": 0, "matched_code": 0})

for unit in data["units"]:
    measures = unit.get("measures", {})
    total_code = int(measures.get("total_code", 0))
    matched_code = int(measures.get("matched_code", 0))
    categories = unit.get("metadata", {}).get("progress_categories", [])
    for category in categories:
        category_totals[category]["total_code"] += total_code
        category_totals[category]["matched_code"] += matched_code

sorted_categories = sorted(
    category_totals.items(),
    key=lambda item: item[1]["total_code"],
    reverse=True
)

# Calculate column widths - strip supercategory prefix for display
display_names = []
for category, _ in sorted_categories:
    # Remove supercategory prefix (everything before and including the dot)
    display_name = category.split(".", 1)[1] if "." in category else category
    display_names.append(display_name)

max_category_width = max(len(name) for name in display_names) if display_names else 10
max_category_width = max(max_category_width, len("Executable"), len("Total"))

total_matched = 0
total_code = 0
rows = []

for i, (category, stats) in enumerate(sorted_categories):
    matched = stats["matched_code"]
    total = stats["total_code"]
    percent = (matched / total * 100) if total else 0
    rows.append((display_names[i], matched, total, percent))
    total_matched += matched
    total_code += total

total_percent = (total_matched / total_code * 100) if total_code else 0

# Calculate max widths for numeric columns
max_matched_width = max(len(str(row[1])) for row in rows + [("", total_matched, 0, 0)])
max_total_width = max(len(str(row[2])) for row in rows + [("", 0, total_code, 0)])
max_percent_width = max(len(f"{row[3]:.2f}%") for row in rows + [("", 0, 0, total_percent)])

# Ensure minimum widths for headers
max_matched_width = max(max_matched_width, len("Matched Code"))
max_total_width = max(max_total_width, len("Total Code"))
max_percent_width = max(max_percent_width, len("Percent Matched"))

# Print header
header_format = f"{{:<{max_category_width}}} {{:>{max_matched_width}}} {{:>{max_total_width}}} {{:>{max_percent_width}}}"
separator_format = f"{{:-<{max_category_width}}} {{:->{max_matched_width}}} {{:->{max_total_width}}} {{:->{max_percent_width}}}"

print(header_format.format("Executable", "Matched Code", "Total Code", "Percent Matched"))
print(separator_format.format("", "", "", ""))

# Print data rows
row_format = f"{{:<{max_category_width}}} {{:>{max_matched_width}}} {{:>{max_total_width}}} {{:>{max_percent_width}}}"
for category, matched, total, percent in rows:
    print(row_format.format(category, matched, total, f"{percent:.2f}%"))

# Print separator and total
print(separator_format.format("", "", "", ""))
print(row_format.format("Total", total_matched, total_code, f"{total_percent:.2f}%"))