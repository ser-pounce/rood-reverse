#!/usr/bin/env bash
# Snapshot build/config + build/src for CI (run after a successful make -j check).
set -euo pipefail
root="$(cd "$(dirname "$0")/../.." && pwd)"
seeds="$root/fixtures/ci/seeds"
build="$root/build"

if [[ ! -d "$build/config" || ! -d "$build/src" ]]; then
  echo "error: run a full local build first (make -j check)" >&2
  exit 1
fi

rm -rf "$seeds"
mkdir -p "$seeds"

while IFS= read -r -d '' f; do
  rel="${f#"$root"/}"
  mkdir -p "$seeds/$(dirname "$rel")"
  cp -a "$f" "$seeds/$rel"
done < <(find "$build/config" -name link.d -print0)

while IFS= read -r -d '' f; do
  rel="${f#"$root"/}"
  mkdir -p "$seeds/$(dirname "$rel")"
  cp -a "$f" "$seeds/$rel"
done < <(find "$build/config" -name '*_LBA.txt' -print0)

while IFS= read -r -d '' f; do
  rel="${f#"$root"/}"
  mkdir -p "$seeds/$(dirname "$rel")"
  cp -a "$f" "$seeds/$rel"
done < <(find "$build/src" -type f -print0)

if [[ -d "$build/assets" ]]; then
  while IFS= read -r -d '' f; do
    rel="${f#"$root"/}"
    mkdir -p "$seeds/$(dirname "$rel")"
    cp -a "$f" "$seeds/$rel"
  done < <(find "$build/assets" -type f -print0)
fi

data_seeds="$root/fixtures/ci/data"
rm -rf "$data_seeds"
mkdir -p "$data_seeds"
prgs=(
  SLUS_010.40
  BATTLE/BATTLE.PRG BATTLE/INITBTL.PRG
  TITLE/TITLE.PRG GIM/SCREFF2.PRG ENDING/ENDING.PRG
  MENU/MAINMENU.PRG MENU/MENU0.PRG MENU/MENU1.PRG MENU/MENU2.PRG MENU/MENU3.PRG
  MENU/MENU4.PRG MENU/MENU5.PRG MENU/MENU7.PRG MENU/MENU8.PRG MENU/MENU9.PRG
  MENU/MENUB.PRG MENU/MENUC.PRG MENU/MENUD.PRG MENU/MENUE.PRG MENU/MENUF.PRG
)
for rel in "${prgs[@]}"; do
  src="$root/data/$rel"
  [[ -f "$src" ]] || continue
  dst="$data_seeds/$rel"
  mkdir -p "$(dirname "$dst")"
  python3 - "$src" "$dst" <<'PY'
import sys
from pathlib import Path
src = Path(sys.argv[1]).read_bytes()
# Deterministic non-retail filler (same as setup_fixture.write_zeros).
Path(sys.argv[2]).write_bytes(bytes([i & 0xFF for i in range(len(src))]))
PY
done

echo "seeds updated: $(find "$seeds" -type f | wc -l | tr -d ' ') files under fixtures/ci/seeds"
echo "data fixture: $(find "$data_seeds" -type f | wc -l | tr -d ' ') PRG stubs under fixtures/ci/data"
