# syntax=docker/dockerfile:1
FROM ubuntu

RUN apt-get update && apt-get install -y --no-install-recommends \
        clang-format \
        g++ \
        binutils-mipsel-linux-gnu \
        git \
        make \
        python3 \
        python3-venv \
        unzip \
        wget \
    && rm -rf /var/lib/apt/lists/* \
    && git config --system --add safe.directory /github/workspace
