# syntax=docker/dockerfile:1
FROM ubuntu:latest

RUN --mount=type=cache,target=/var/cache/apt \
    --mount=type=cache,target=/var/lib/apt/lists \
    apt-get update && apt-get install -y --no-install-recommends \
    clang-format \
    g++ \
    binutils-mipsel-linux-gnu \
    git \
    make \
    python3 \
    python3-venv \
    unzip \
    wget

COPY disks/SLUS-01040.bin /SLUS-01040.bin
