CI_FIXTURE     := fixtures/ci
CI_MANIFEST    := $(CI_FIXTURE)/data-manifest.tsv
CI_EXPECTED    := $(CI_FIXTURE)/expected.sha256
CI_SETUP       := $(VPYTHON) tools/ci/setup_fixture.py
CI_VERIFY      := $(VPYTHON) tools/ci/verify_hashes.py
CI_BINARIES    := $(BINTARGETS)
CI_CLEAN       := rm -Rf $(BUILD)/data

.PHONY: ci-smoke ci-smoke-setup ci-smoke-refresh ci-fixture-manifest ci-fixture-seeds

.NOTPARALLEL: ci-smoke ci-smoke-refresh ci-smoke-setup

SKIPSPLAT += ci-smoke ci-smoke-setup ci-smoke-refresh ci-fixture-manifest ci-fixture-seeds

ci-smoke-setup:
	$(CI_SETUP)

ci-fixture-manifest:
	$(VPYTHON) tools/ci/generate_manifest.py

ci-fixture-seeds:
	tools/ci/update_seeds.sh

# Incremental rebuild + golden hashes (not retail matching).
ci-smoke: ci-smoke-setup
	$(MAKE) ROOD_CI=1 tools/.sysdeps tools/python/.requirements.stamp
	$(MAKE) ROOD_CI=1 $(CI_BINARIES) -j
	$(CI_VERIFY)

# Full relink + update expected.sha256 (maintainer).
ci-smoke-refresh: ci-smoke-setup
	$(CI_CLEAN)
	$(MAKE) ROOD_CI=1 tools/.sysdeps tools/python/.requirements.stamp
	$(MAKE) ROOD_CI=1 $(CI_BINARIES) -j
	$(CI_VERIFY) --update $(CI_BINARIES)
