# Rood Reverse

A decompilation project for Vagrant Story for PlayStation 1, with a goal of enabling interoperability with modern hardware and fixing bugs in the original game.

This project does not contain any of the original files from the game disk, you must own a copy of the game.

Many thanks to the [Chrono Cross Decompilation](https://github.com/jdperos/chrono-cross-decomp) for much of the sound library code.

Heavily inspired by and indebted to the incredible work of the [sotn-decomp](https://github.com/Xeeynamo/sotn-decomp) team and the [PS1/PS2 decompilation](https://discord.gg/hKx3FJJgrV) Discord server.

Grateful to the authors of Data Crystal’s [Vagrant Story](https://datacrystal.tcrf.net/wiki/Vagrant_Story) page for their excellent work and insights.

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
![SLUS_010.40 progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=lib.SLUS_010.40)

### Main game engine
![BATTLE.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=battle.BATTLE.PRG)
![INITBTL.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=battle.INITBTL.PRG&color=%2332a934)
![SCREFF2.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=battle.SCREFF2.PRG)

### Effects
![Total effects progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects)


![EFFPURGE.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.EFFPURGE.BIN&color=%2332a934)
![PLG005.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG005.BIN)
![PLG044.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG044.BIN)
![PLG045.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG045.BIN)
![PLG047.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG047.BIN)
![PLG049.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG049.BIN)
![PLG050.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG050.BIN)
![PLG051.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG051.BIN)
![PLG053.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG053.BIN)
![PLG057.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG057.BIN)
![PLG061.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG061.BIN)
![PLG065.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG065.BIN)
![PLG065.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG069.BIN)
![PLG073.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG073.BIN)
![PLG077.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG077.BIN)
![PLG081.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG081.BIN)
![PLG082.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG082.BIN)
![PLG085.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG085.BIN)
![PLG086.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG086.BIN)
![PLG087.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG087.BIN)
![PLG114.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG114.BIN)
![PLG128.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG128.BIN)
![PLG129.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG129.BIN)
![PLG134.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG134.BIN)
![PLG135.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG135.BIN)
![PLG137.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG137.BIN)
![PLG138.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG138.BIN)
![PLG139.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG139.BIN)
![PLG141.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG141.BIN)
![PLG142.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG142.BIN)
![PLG143.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG143.BIN)
![PLG146.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG146.BIN)
![PLG147.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG147.BIN)
![PLG148.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG148.BIN)
![PLG149.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG149.BIN)
![PLG150.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG150.BIN)
![PLG152.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG152.BIN)
![PLG153.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG153.BIN)
![PLG154.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG154.BIN)
![PLG156.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG156.BIN)
![PLG158.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG158.BIN)
![PLG160.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG160.BIN)
![PLG161.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG161.BIN)
![PLG162.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG162.BIN)
![PLG165.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG165.BIN)
![PLG166.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG166.BIN)
![PLG167.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG167.BIN)
![PLG167.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG168.BIN)
![PLG167.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG169.BIN)
![PLG167.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG180.BIN)
![PLG198.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG198.BIN)
![PLG224.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG224.BIN)
![PLG232.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG232.BIN)
![PLG232.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG236.BIN)
![PLG242.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG242.BIN)
![PLG246.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG246.BIN)
![PLG250.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG250.BIN)
![PLG255.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG255.BIN)
![PLG260.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG260.BIN)
![PLG263.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG263.BIN)
![PLG265.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG265.BIN)
![PLG265.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG266.BIN)
![PLG272.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG272.BIN)
![PLG273.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG273.BIN)
![PLG291.BIN progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=effects.PLG291.BIN)

### Menus
![Total menu progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus&color=%2332a934)


![MAINMENU.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MAINMENU.PRG&color=%2332a934)
![MENU0.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU0.PRG&color=%2332a934)
![MENU1.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU1.PRG&color=%2332a934)
![MENU2.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU2.PRG&color=%2332a934)
![MENU3.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU3.PRG&color=%2332a934)
![MENU4.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU4.PRG&color=%2332a934)
![MENU5.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU5.PRG&color=%2332a934)
![MENU7.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU7.PRG&color=%2332a934)
![MENU8.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU8.PRG&color=%2332a934)
![MENU9.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU9.PRG&color=%2332a934)
![MENUB.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENUB.PRG&color=%2332a934)
![MENUC.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENUC.PRG&color=%2332a934)
![MENUD.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENUD.PRG&color=%2332a934)
![MENUE.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENUE.PRG&color=%2332a934)
![MENUF.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENUF.PRG&color=%2332a934)

### Title and Ending Sequence
![TITLE.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=title.TITLE.PRG&color=%2332a934)
![ENDING.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=ending.ENDING.PRG)

## Editable content
The entirety of the game's menu code and data is decompiled, including all files in `MENU` and `SMALL`, with the exceptions of `MENU/MCDATA.BIN`, `MENU/OPMCIMG1.BIN` and `MENU/OPMCIMG2.BIN`.

Much of the menu code has been refactored and is readable, and the menu executables are completely relocatable. It should be possible to rewrite the menu code arbitrarily, the method and data addresses in other modules will be relinked appropriately.

Due to the presence of a large number of empty sectors at the start of each directory on the disk, it should also be possible to rebuild the disk without affecting sector-based data loading in `BATTLE.PRG`, as long as the number of dummy sectors is adjusted accordingly.

## (Naive) Quickstart
0. n.b.: You may want to consider limiting the jobs spawned by make to something sensible like `-j8`.
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
- Make sure the following packages are installed, older versions may also work but this is not tested. This configuration works as-is on Ubuntu 26.04 on WSL; depending on your distro you may need additional packages.

| Package                      | Minimum Version |
|------------------------------|-----------------|
| clang-format                 | 21.1.8          |
| g++                          | 15.2.0          |
| binutils-mipsel-linux-gnu    | 2.45.90         |
| make                         | 4.4.            |
| python3                      | 3.14.4          |
| python3-venv                 | 3.14.4          |
| unzip                        | 6.00            |
| wget                         | 1.25.0          |

Take a look at `./Dockerfile` for a minimal setup on Ubuntu
- Dump your original disk to `disks/SLUS-01040.bin`
- Run `make -j` to finish installation and perform an initial build

## Build targets
- `make -j` should be all that is needed most of the time. The first execution will configure the remaining dependencies in the `tools` directory and extract the files from the disk; from then on it will perform a minimal rebuild. 
- `make decompme TARGET=path/to/nonmatchings/source.s` uploads the target function to a new decomp.me scratch.
- `make permute TARGET=path/to/nonmatchings/source.s` invokes the permuter for the target assembly file. 
- `make remake -j` will delete and re-split the targets; this can be necessary if the dependency management has failed to identify everything that needs rebuilding (in which case a bug report is appreciated!), or if the configuration has changed enough to be no longer valid (e.g. orphaned .d files). It's good practice to run this before submitting a pull request to make sure everything still works.
- `make format` formats the source files and symbol addresses for consistency. Please run this before submitting a PR.
- `make clean` simply deletes the `build` and `nonmatchings` directories
- `make clean-all` will completely reset the project, including dropping any source changes and data files (but not the disk image). Use with caution.
