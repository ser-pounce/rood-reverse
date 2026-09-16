DOCKER   ?= docker
GHCR_TAG ?= ghcr.io/ser-pounce/rood-reverse:main

.PHONY: docker-build docker-push
SKIPSPLAT += docker-build docker-push

docker-build:
	$(DOCKER) build -t $(GHCR_TAG) .

docker-push: docker-build
	$(DOCKER) push $(GHCR_TAG)
