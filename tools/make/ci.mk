CI_FIXTURE     := fixtures/ci
CI_DATA        := $(CI_FIXTURE)/data-manifest.tsv
CI_ASM         := $(CI_FIXTURE)/asm-manifest.json
CI_SETUP        = $(VPYTHON) tools/ci/setup_fixture.py
CI_BINARIES    := $(BINTARGETS)

.PHONY: ci-smoke ci-fixture-manifest ci-fixture-asm-manifest

.NOTPARALLEL: ci-smoke

SKIPSPLAT += ci-smoke ci-fixture-manifest ci-fixture-asm-manifest

# Refresh the data-size manifest (paths + sizes only, no content).
ci-fixture-manifest:
	$(VPYTHON) tools/ci/generate_manifest.py

# Refresh the asm layout manifest by parsing build/src/**.s (no disk needed
# if build/ already exists from a prior `make check`).
ci-fixture-asm-manifest:
	$(VPYTHON) tools/ci/asm_manifest.py --build

# "Build doesn't break" smoke: render stub .s from the asm manifest, write
# synthetic data/, copy linker/include seeds, link every PRG under ROOD_CI=1.
ci-smoke:
	$(CI_SETUP)
	$(MAKE) ROOD_CI=1 tools/.sysdeps tools/python/.requirements.stamp
	$(MAKE) ROOD_CI=1 $(CI_BINARIES) -j
