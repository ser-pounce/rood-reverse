CI_FIXTURE     := fixtures/ci
CI_DATA        := $(CI_FIXTURE)/data-manifest.tsv
CI_ASM         := $(CI_FIXTURE)/asm-manifest.json
CI_SETUP        = $(VPYTHON) tools/ci/setup_fixture.py
CI_VERIFY       = $(VPYTHON) tools/ci/verify_hashes.py
CI_BINARIES    := $(BINTARGETS)

.PHONY: ci-smoke ci-fixture-manifest ci-fixture-asm-manifest ci-test

.NOTPARALLEL: ci-smoke

SKIPSPLAT += ci-smoke ci-fixture-manifest ci-fixture-asm-manifest ci-test \
             tools/.sysdeps tools/python/.requirements.stamp

# Refresh the data-size manifest (paths + sizes only, no content).
ci-fixture-manifest:
	$(VPYTHON) tools/ci/generate_manifest.py

# Refresh the asm layout manifest, attaching retail bytes per label.
# Run locally after `make check` (which proves the build's bytes match
# retail) — the resulting manifest renders byte-identical .elf output
# whether a given function is INCLUDE_ASM-stubbed or C-decompiled, so
# ci-smoke's per-PRG hashes stay stable across decomp commits.
ci-fixture-asm-manifest:
	$(VPYTHON) tools/ci/asm_manifest.py --build --bytes-from build/src

# Unit tests for the CI tooling itself (parsers, bundles, filters).
ci-test:
	$(MAKE) ROOD_CI=1 tools/python/.requirements.stamp
	$(VPYTHON) -m pytest tools/ci/tests/ -q

# "Build doesn't break" smoke: render stub .s (with retail bytes from the
# manifest) from the asm manifest, write synthetic data/, copy linker/include
# seeds, link every PRG under ROOD_CI=1, verify per-PRG hash.
ci-smoke:
	$(MAKE) ROOD_CI=1 tools/.sysdeps tools/python/.requirements.stamp
	$(CI_SETUP)
	$(MAKE) ROOD_CI=1 $(CI_BINARIES) -j
	$(CI_VERIFY)
