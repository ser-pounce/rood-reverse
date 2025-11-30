# Rood Reverse

A decompilation project for Vagrant Story for PlayStation 1, with a goal of enabling interoperability with modern hardware and fixing bugs in the original game.

This project does not contain any of the original files from the game disk, you must own a copy of the game.

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
![INITBTL.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=battle.INITBTL.PRG)

### Menus
![Total menu progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus)


![MAINMENU.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MAINMENU.PRG)
![MENU0.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU0.PRG&color=%2332a934)
![MENU1.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU1.PRG&color=%2332a934)
![MENU2.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU2.PRG&color=%2332a934)
![MENU3.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU3.PRG)
![MENU4.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU4.PRG&color=%2332a934)
![MENU5.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU5.PRG&color=%2332a934)
![MENU7.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU7.PRG)
![MENU8.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU8.PRG&color=%2332a934)
![MENU9.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU9.PRG)
![MENUB.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENUB.PRG)
![MENUC.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENUC.PRG)
![MENUD.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENUD.PRG)
![MENUE.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENUE.PRG&color=%2332a934)
![MENUF.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENUF.PRG)

### Title and Ending Sequence
![TITLE.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=title.TITLE.PRG)
![ENDING.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=ending.ENDING.PRG)
![SCREFF2.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=ending.SCREFF2.PRG)

### Editable content
The following files can be freely edited*, either as source code or by editing the dumped .yaml or .obj formats
```
data/MENU/
    MENU0.PRG
    MENU1.PRG
    MENU2.PRG
    MENU4.PRG
    MENU5.PRG
    MENU8.PRG
    MENUE.PRG
    MCMAN.BIN 
    SPMCIMG.BIN 
    MAPBG.BIN 
    ITEMNAME.BIN 
    ITEMHELP.BIN 
    MENU12.BIN

data/SMALL/
    DUMMY.ARM
    SCEN001.ARM - SCEN031.ARM
    HELP01.HF0 - HELP14.HF0
    HELP01.HF1 - HELP14.HF1

data/TITLE/
    TITLE.PRG
```
(*n.b. until all of the loading code has been decompiled, if a file's sector size changes on disk then bad things will ensue)

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
- Make sure the following packages are installed, older versions may also work but this is not tested:

| Package                 | Minimum Version |
|-------------------------|----------------|
| clang-format            | 18.1.3         |
| cmake                   | 3.28.3         |
| docker-buildx           | 28.2.2         |
| g++                     | 13.3.0         |
| gcc                     | 13.3.0         |
| gcc-mipsel-linux-gnu    | 12.4.0         |
| make                    | 4.3            |
| python3                 | 3.12.3         |
| python3-pip             | 24.0           |
| python3-venv            | 3.12.3         |
- If you do not use your own docker configuration, set docker permissions with `sudo usermod -aG docker $USER`
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
