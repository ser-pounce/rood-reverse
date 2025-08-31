# Rood Reverse

A decompilation project for Vagrant Story for PlayStation 1, with a goal of enabling interoperability with modern hardware and fixing bugs in the original game.

This project does not contain any of the original files from the game disk, you must own a copy of the game.

Heavily inspired by and indebted to the incredible work of the [sotn-decomp](https://github.com/Xeeynamo/sotn-decomp) team and the [PS1/PS2 decompilation](https://discord.gg/hKx3FJJgrV) Discord server.

Thanks also to the following amazing projects (and their dependencies):
- [splat](https://github.com/ethteck/splat)
- [maspsx](https://github.com/mkst/maspsx)
- [decomp.me](https://github.com/decompme/decomp.me)
- [Decomp permuter](https://github.com/simonlindholm/decomp-permuter)
- [Old GCC](https://github.com/decompals/old-gcc)
- [mkpsxiso](https://github.com/Lameguy64/mkpsxiso)
- [objdiff](https://github.com/encounter/objdiff)
- [decomp.dev](https://decomp.dev/)

## Status

![Overall progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&label=Overall+progress)

### Core libraries
![SLUS_010.40 progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=SLUS_010.40)

### Main game engine
![BATTLE.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=BATTLE.PRG)
![INITBTL.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=INITBTL.PRG)

### Menus
![MAINMENU.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=MAINMENU.PRG)
![MENU0.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=MENU0.PRG&color=%2332a934)
![MENU1.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=MENU1.PRG&color=%2332a934)
![MENU2.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=MENU2.PRG&color=%2332a934)
![MENU3.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=MENU3.PRG)
![MENU4.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=MENU4.PRG)
![MENU5.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=MENU5.PRG)
![MENU7.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=MENU7.PRG)
![MENU8.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=MENU8.PRG)
![MENU9.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=MENU9.PRG)
![MENUB.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=MENUB.PRG)
![MENUC.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=MENUC.PRG)
![MENUD.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=MENUD.PRG)
![MENUE.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=MENUE.PRG&color=%2332a934)
![MENUF.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=MENUF.PRG)

### Title and Ending Sequence
![TITLE.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=TITLE.PRG)
![ENDING.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=ENDING.PRG)
![SCREFF2.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=SCREFF2.PRG)

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
