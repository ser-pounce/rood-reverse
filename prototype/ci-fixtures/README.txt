DELETE THIS FILE (and the prototype/ci-fixtures/ tree) before merging CI smoke
work to main or opening a production PR.

This branch is a local experiment: run the full PRG link pipeline in GitHub
Actions without retail SLUS-01040 disk assets.

Approach
--------

1. Synthetic inputs (fixtures/ci/data/)
   - 21 PRG-sized files filled with a deterministic 0..255 byte pattern.
   - Not retail game bytes; safe to commit.

2. Frozen build state (fixtures/ci/seeds/build/)
   - Snapshot of link.d, src/ (incl. splat asm), assets/, lbas.h, LBA table.
   - CI skips splat re-split and vsString re-extract (which would fail on stubs).
   - ~45MB in git; .gitignore whitelists fixtures/ci/seeds/build/**.

3. Golden hashes (fixtures/ci/expected.sha256)
   - SHA-256 of each build/data/*.PRG after a fixture build.
   - make ci-smoke rebuilds PRGs and compares; no build/data/ blobs in git.

4. Makefile targets
   - make ci-smoke          — CI gate (setup + build + verify)
   - make ci-smoke-refresh  — maintainer: rebuild + update expected.sha256
   - make ci-fixture-seeds  — snapshot seeds from make -j check (needs disk)
   - make ci-fixture-manifest — refresh data-manifest.tsv sizes from data/

What this does NOT prove
------------------------

- Byte match to Vagrant Story (use make check locally with your dump).
- Correctness of decomp; only “toolchain + link graph still reproducible”.

Maintainer refresh (when splat/assets layout changes)
-----------------------------------------------------

  make -j check
  make ci-fixture-seeds
  make ci-smoke-refresh

GitHub Actions: .github/workflows/ci.yml runs make ci-smoke after make format.
