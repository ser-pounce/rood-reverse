CI_FIXTURE     := fixtures/ci
CI_MANIFEST    := $(CI_FIXTURE)/data-manifest.tsv
CI_SETUP       := $(VPYTHON) tools/ci/setup_fixture.py
CI_BINARIES    := $(BINTARGETS)

.PHONY: ci-smoke ci-smoke-setup ci-fixture-manifest ci-fixture-seeds

.NOTPARALLEL: ci-smoke ci-smoke-setup

SKIPSPLAT += ci-smoke ci-smoke-setup ci-fixture-manifest ci-fixture-seeds

ci-smoke-setup:
	$(CI_SETUP)

ci-fixture-manifest:
	$(VPYTHON) tools/ci/generate_manifest.py

ci-fixture-seeds:
	tools/ci/update_seeds.sh

# "Build doesn't break" smoke: link every PRG against synthetic inputs.
# No byte-verification — the linked output depends on disk-derived .s for
# every INCLUDE_ASM, so the hash would shift on every decomp commit.
ci-smoke: ci-smoke-setup
	$(MAKE) ROOD_CI=1 tools/.sysdeps tools/python/.requirements.stamp
	$(MAKE) ROOD_CI=1 $(CI_BINARIES) -j
