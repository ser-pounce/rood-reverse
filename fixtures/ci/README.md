# CI smoke fixture

Non-retail inputs for GitHub Actions: proves the build graph runs and outputs stay deterministic.

- `data-manifest.tsv` — paths and byte sizes only (no game content)
- `seeds/build/` — frozen `config/*/link.d`, `src/**`, and `assets/**` (≈45MB; skips splat/disk/asset re-extract)
- `expected.sha256` — golden SHA-256 of `build/data/*` PRG outputs under the fixture

Setup generates `data/` at build time (deterministic `0..255` filler, not SLUS bytes).

## Maintainer

After changing splat config or intentional build output:

```bash
make -j                    # full build with your disk (once)
make ci-fixture-manifest   # refresh sizes if data/ layout changed
make ci-fixture-seeds      # snapshot build/config + build/src
make ci-smoke-refresh -j   # rebuild with fixture + update expected.sha256
```

## CI

`make ci-smoke` — setup fixture, build all PRGs, verify hashes.
