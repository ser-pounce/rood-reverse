# Rood Reverse

[![Discord server](https://discord.com/api/guilds/927723248962142248/widget.png?style=banner2)](https://discord.gg/yWxsd5gvmW)

A decompilation project for Vagrant Story for PlayStation 1, with a goal of enabling interoperability with modern hardware and fixing bugs in the original game.

This project does not include any of the content from the game's disk.

Heavily inspired by the incredible work of the [sotn-decomp](https://github.com/Xeeynamo/sotn-decomp) team.

Thanks also to the following amazing projects (and their dependencies):
- [splat](https://github.com/ethteck/splat)
- [maspsx](https://github.com/mkst/maspsx)
- [decomp.me](https://github.com/decompme/decomp.me)
- [Decomp permuter](https://github.com/simonlindholm/decomp-permuter)
- [Old GCC](https://github.com/decompals/old-gcc)
- [mkpsxiso](https://github.com/Lameguy64/mkpsxiso)

## Status
A significant portion of the main exectuable, including most of the code that handles broad transitions between the game modules, disk and file management, and memory management, has been [decompiled](https://github.com/ser-pounce/rood-reverse/blob/main/src/SLUS_010.40/3264C.c).
Some progress has also been made in the game's [sound module](https://github.com/ser-pounce/rood-reverse/blob/main/src/SLUS_010.40/25AC.c), and the [title screen](https://github.com/ser-pounce/rood-reverse/blob/main/src/TITLE/TITLE.PRG/22C.c).

## (Naive) Quickstart
1. Fork the project
2. Install system dependencies and copy disk image (see "Setup" below)
3. Run `make -j` to perform an initial split & build
4. Pick a function to decompile, use `make decompme` to create a scratch on decomp.me
5. Claim and decompile the scratch
6. Copy the decompiled code where it belongs 
7. Optionally use `make permute` if needed
8. Run `make remake -j`, and finally `make format` if the code compiles successfully
9. Open a PR

## Setup
The project is mostly self-configuring but requires a minimal amount of setup.
- Make sure the following system packages are installed:
    - make
    - cmake
    - g++
    - python3
    - pip
    - gcc-mips-linux-gnu
    - docker-buildx
    - clang-format
- Dump your original disk to `disks/SLUS-01040.bin`
- Run `make -j` to finish installation and perform an initial build

## Build targets
- `make -j` should be all that is needed most of the time. The first execution will configure the remaining dependencies in the `tools` directory and extract the files from the disk; from then on it will perform a minimal rebuild depending on what has changed. 
- `make decompme TARGET=path/to/nonmatchings/source.asm` uploads the target function to a new decomp.me scratch.
- `make permute TARGET=path/to/nonmatchings/source.asm` invokes the permuter for the target assembly file. 
- `make remake -j` will delete and re-split the targets; this can be necessary if the dependency management has failed to identify everything that needs rebuilding (in which case a bug report is appreciated!), or if the configuration has changed enough to be no longer valid (e.g. orphaned .d files). It's good practice to run this before submitting a pull request to make sure everything still works.
- `make format` formats the source files and symbol addresses for consistency. Please run this before submitting a PR.
- `make clean` simply deletes the `build` directory
- `make clean-all` will completely reset the project, including dropping any source changes and data files (but not the disk image). Use with caution.
