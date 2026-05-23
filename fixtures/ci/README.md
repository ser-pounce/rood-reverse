# CI smoke fixture

Non-retail inputs for GitHub Actions: proves the build graph runs end-to-end
without shipping any game data. Pass = the build doesn't break.

- `data-manifest.tsv` — paths and byte sizes only (no game content)
- `seeds/build/` — frozen `config/*/link.d`, `src/**`, and `assets/**`
  (≈45MB; skips splat/disk/asset re-extract)
- `seeds/include/` — splat-generated headers that splat writes at split time

Setup generates `data/` at build time (deterministic `0..255` filler, not
SLUS bytes). No output hashing — byte-perfect verification would require
shipping the retail disk, which we don't. CI just confirms `make` exits 0
and every PRG links.

## Maintainer

After changing splat config or anything else that affects splat outputs:

```bash
make -j                    # full build with your disk (once)
make ci-fixture-manifest   # refresh sizes if data/ layout changed
make ci-fixture-seeds      # snapshot build/config + build/src
```

## CI

`make ci-smoke` — setup fixture, build all PRGs. Green = pipeline ok.
