CI_FIXTURE     := fixtures/ci
CI_DATA        := $(CI_FIXTURE)/data-manifest.tsv
CI_ASM         := $(CI_FIXTURE)/asm-manifest.json
CI_SETUP        = $(VPYTHON) tools/ci/setup_fixture.py
CI_VERIFY       = $(VPYTHON) tools/ci/verify_function_hashes.py
CI_BINARIES    := $(BINTARGETS)

.PHONY: ci-smoke ci-fixture-manifest ci-fixture-asm-manifest ci-fixture-asm-manifest-with-hashes ci-test

.NOTPARALLEL: ci-smoke

SKIPSPLAT += ci-smoke ci-fixture-manifest ci-fixture-asm-manifest ci-fixture-asm-manifest-with-hashes ci-test \
             tools/.sysdeps tools/python/.requirements.stamp

# Refresh the data-size manifest (paths + sizes only, no content).
ci-fixture-manifest:
	$(VPYTHON) tools/ci/generate_manifest.py

# Refresh the asm layout manifest by parsing build/src/**.s (no disk needed
# if build/ already exists from a prior `make check`).
ci-fixture-asm-manifest:
	$(VPYTHON) tools/ci/asm_manifest.py --build

# Unit tests for the CI tooling itself (parsers, bundles, filters).
ci-test:
	$(MAKE) ROOD_CI=1 tools/python/.requirements.stamp
	$(VPYTHON) -m pytest tools/ci/tests/ -q

# "Build doesn't break" smoke: render stub .s from the asm manifest, write
# synthetic data/, copy linker/include seeds, link every PRG under ROOD_CI=1.
ci-smoke:
	$(MAKE) ROOD_CI=1 tools/.sysdeps tools/python/.requirements.stamp
	$(CI_SETUP)
	$(MAKE) ROOD_CI=1 $(CI_BINARIES) -j
	$(CI_VERIFY)

# Maintainer: rebuild asm-manifest with per-function sha256 hashes from a
# fresh `make check` run against a real disk. Run after intentional output
# changes (decomp commit, refactor, etc.) — only the affected function's
# hash in the manifest shifts; the rest stay byte-stable.
ci-fixture-asm-manifest-with-hashes:
	$(VPYTHON) tools/ci/asm_manifest.py --build
