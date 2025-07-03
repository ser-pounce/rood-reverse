# Rood Reverse

[![Discord server](https://discord.com/api/guilds/927723248962142248/widget.png?style=banner2)](https://discord.gg/yWxsd5gvmW)

A decompilation project for Vagrant Story for PlayStation 1, with a goal of enabling interoperability with modern hardware and fixing bugs in the original game.

This project does not contain any of the original files from the game disk, you must own a copy of the game.

Heavily inspired by the incredible work of the [sotn-decomp](https://github.com/Xeeynamo/sotn-decomp) team.

Thanks also to the following amazing projects (and their dependencies):
- [splat](https://github.com/ethteck/splat)
- [maspsx](https://github.com/mkst/maspsx)
- [decomp.me](https://github.com/decompme/decomp.me)
- [Decomp permuter](https://github.com/simonlindholm/decomp-permuter)
- [Old GCC](https://github.com/decompals/old-gcc)
- [mkpsxiso](https://github.com/Lameguy64/mkpsxiso)

## Status
| Category | Matched Code | Total Code | Percent Matched |
|----------|--------------|------------|-----------------|
| BATTLE.PRG | 10120 | 517400 | 1.96% |
| SLUS_010.40 | 37712 | 158036 | 23.86% |
| TITLE.PRG | 39380 | 40528 | 97.17% |
| MENUC.PRG | 0 | 37304 | 0.00% |
| MAINMENU.PRG | 8 | 34204 | 0.02% |
| MENU7.PRG | 9292 | 30804 | 30.16% |
| MENUB.PRG | 0 | 30752 | 0.00% |
| MENUD.PRG | 0 | 27384 | 0.00% |
| MENU3.PRG | 0 | 27212 | 0.00% |
| MENUF.PRG | 24 | 26144 | 0.09% |
| ENDING.PRG | 996 | 23336 | 4.27% |
| MENU9.PRG | 8 | 23268 | 0.03% |
| MENU5.PRG | 0 | 22304 | 0.00% |
| MENU4.PRG | 0 | 19240 | 0.00% |
| MENU8.PRG | 0 | 11472 | 0.00% |
| MENU0.PRG | 760 | 8660 | 8.78% |
| MENUE.PRG | 0 | 8640 | 0.00% |
| MENU2.PRG | 0 | 7724 | 0.00% |
| INITBTL.PRG | 1060 | 4864 | 21.79% |
| MENU1.PRG | 0 | 3144 | 0.00% |
| SCREFF2.PRG | 944 | 2324 | 40.62% |
| **Total** | **100304** | **1064744** | **9.42%** |

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
