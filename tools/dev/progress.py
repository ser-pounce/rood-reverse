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

print("| Executable | Matched Code | Total Code | Percent Matched |")
print("|----------|--------------|------------|-----------------|")

total_matched = 0
total_code = 0

for category, stats in sorted_categories:
    matched = stats["matched_code"]
    total = stats["total_code"]
    percent = (matched / total * 100) if total else 0
    print(f"| {category} | {matched} | {total} | {percent:.2f}% |")
    total_matched += matched
    total_code += total

total_percent = (total_matched / total_code * 100) if total_code else 0
print(f"| **Total** | **{total_matched}** | **{total_code}** | **{total_percent:.2f}%** |")