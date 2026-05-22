CI_FIXTURE     := fixtures/ci
CI_MANIFEST    := $(CI_FIXTURE)/data-manifest.tsv
CI_EXPECTED    := $(CI_FIXTURE)/expected.sha256
CI_SETUP       := $(VPYTHON) tools/ci/setup_fixture.py
CI_VERIFY      := $(VPYTHON) tools/ci/verify_hashes.py
CI_BINARIES    := $(BINTARGETS)
# Drop relinked PRGs; keep build/src (splat) and build/assets (encoded images).
CI_CLEAN       := rm -Rf $(BUILD)/data

.PHONY: ci-smoke ci-smoke-setup ci-smoke-refresh ci-fixture-manifest ci-fixture-seeds

# Do not run ci-smoke recipes in parallel with each other (use -j on the inner make).
.NOTPARALLEL: ci-smoke ci-smoke-refresh ci-smoke-setup

SKIPSPLAT += ci-smoke ci-smoke-setup ci-smoke-refresh ci-fixture-manifest ci-fixture-seeds

ci-smoke-setup:
	$(CI_SETUP)

ci-fixture-manifest:
	$(VPYTHON) tools/ci/generate_manifest.py

ci-fixture-seeds:
	tools/ci/update_seeds.sh

define CI_SMOKE_BUILD
	$(CI_CLEAN)
	$(CI_SETUP)
	$(MAKE) $(CI_BINARIES) -j
endef

# Maintainer: rebuild fixture baseline hashes after intentional output changes.
ci-smoke-refresh:
	$(CI_SMOKE_BUILD)
	$(CI_VERIFY) --update $(CI_BINARIES)

# CI / PR gate: deterministic smoke build + golden hashes (not retail matching).
ci-smoke:
	$(CI_SMOKE_BUILD)
	$(CI_VERIFY)
