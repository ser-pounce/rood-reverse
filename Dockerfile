# syntax=docker/dockerfile:1
FROM ubuntu

RUN --mount=type=cache,target=/var/cache/apt \
    --mount=type=cache,target=/var/lib/apt/lists \
    apt-get update && \
    apt-get install -y --no-install-recommends \
        clang-format \
        g++ \
        binutils-mipsel-linux-gnu \
        git \
        make \
        python3 \
        python3-venv \
        unzip \
        wget && \
    rm -rf /var/lib/apt/lists/* && \
    \
    groupadd -g 1001 runner && \
    useradd -m -u 1001 -g runner runner && \
    \
    mkdir -p /github/workspace/disks

COPY disks/SLUS-01040.bin /github/workspace/disks/SLUS-01040.bin

RUN chmod 644 /github/workspace/disks/SLUS-01040.bin

USER runner
WORKDIR /github/workspace
