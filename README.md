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

### Menus
![Total menu progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus)


![MAINMENU.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MAINMENU.PRG&color=%2332a934)
![MENU0.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU0.PRG&color=%2332a934)
![MENU1.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU1.PRG&color=%2332a934)
![MENU2.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU2.PRG&color=%2332a934)
![MENU3.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU3.PRG&color=%2332a934)
![MENU4.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU4.PRG&color=%2332a934)
![MENU5.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU5.PRG&color=%2332a934)
![MENU7.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU7.PRG&color=%2332a934)
![MENU8.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU8.PRG&color=%2332a934)
![MENU9.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENU9.PRG)
![MENUB.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENUB.PRG&color=%2332a934)
![MENUC.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENUC.PRG&color=%2332a934)
![MENUD.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENUD.PRG&color=%2332a934)
![MENUE.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENUE.PRG&color=%2332a934)
![MENUF.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=menus.MENUF.PRG)

### Title and Ending Sequence
![TITLE.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=title.TITLE.PRG)
![ENDING.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=ending.ENDING.PRG)
![SCREFF2.PRG progress](https://decomp.dev/ser-pounce/rood-reverse.svg?mode=shield&category=ending.SCREFF2.PRG)

### Editable content
The following files can be freely edited*, either as source code or by editing the dumped .yaml or .obj formats
```
data/BATTLE/
    INITBTL.PRG

data/MENU/
    ARMOR.SYD
    BLADE.SYD
    SHIELD.SYD
    ITEMNAME.BIN
    ITEMHELP.BIN
    MAPBG.BIN
    MCMAN.BIN
    MAINMENU.PRG
    MENU0.PRG
    MENU1.PRG
    MENU2.PRG
    MENU3.PRG
    MENU4.PRG
    MENU5.PRG
    MENU7.PRG
    MENU8.PRG
    MENUB.PRG
    MENUC.PRG
    MENUD.PRG
    MENUE.PRG
    MENU12.BIN
    SPMCIMG.BIN

data/SMALL/
    HELP01.HF0 - HELP14.HF0
    HELP01.HF1 - HELP14.HF1
    DUMMY.ARM
    SCEN001.ARM - SCEN031.ARM
    MON.BIN
    ATTACK.DIS
    END.DIS
    ENDSCR00 - ENDSCR15.DIS
    ESC.DIS
    IQ.DIS
    RANK.DIS
    TIME.DIS

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

There are two supported ways to set up a dev environment. Pick one.

### Option A — Nix (recommended; works on Linux and macOS)

The flake pins every part of the toolchain to an exact store hash, so the build is reproducible byte-for-byte across machines. This is the only path that works on macOS.

1. Install Nix with flakes enabled (e.g. via the [Determinate Systems installer](https://github.com/DeterminateSystems/nix-installer)).
2. Optionally install [direnv](https://direnv.net/) — then `direnv allow` in the repo and the shell is set up automatically on `cd`. Without direnv, run `nix develop` to enter the dev shell.
3. Dump your original disk to `disks/SLUS-01040.bin`.
4. Run `make -j` to finish installation and perform an initial build.

The first `nix develop` on macOS may take ~30–60 min if the cross-cpp closure isn't in the [rood-reverse cachix](https://app.cachix.org/cache/rood-reverse) yet. Subsequent runs and Linux runs are instant. The cache is read-public — no auth needed.

### Option B — Native Ubuntu (legacy)

Works only on Ubuntu 24.04 (or WSL). Other Linux distros may need additional packages; macOS is not supported via this path.

| Package                 | Minimum Version |
|-------------------------|----------------|
| clang-format            | 18.1.3         |
| cmake                   | 3.28.3         |
| docker-buildx           | 29.1.3         |
| g++                     | 13.3.0         |
| gcc-mipsel-linux-gnu    | 12.4.0         |
| make                    | 4.3            |
| python3                 | 3.12.3         |
| python3-venv            | 3.12.3         |
| rustup                  | 1.26.0         |

- If you do not use your own docker configuration, set docker permissions with `sudo usermod -aG docker $USER`, then log out and back in again
- Run `rustup default stable` if you do not already have a local rust environment set up
- Dump your original disk to `disks/SLUS-01040.bin`
- Run `make -j` to finish installation and perform an initial build

> **Important:** install `gcc-mipsel-linux-gnu` at exactly major version 12 — newer versions emit subtly different preprocessed output that breaks `make check` even though everything appears to build cleanly. The Nix path pins this for you and uses the same toolchain as CI, so what passes locally passes upstream.

## Build targets
- `make -j` should be all that is needed most of the time. The first execution will configure the remaining dependencies in the `tools` directory and extract the files from the disk; from then on it will perform a minimal rebuild. 
- `make decompme TARGET=path/to/nonmatchings/source.s` uploads the target function to a new decomp.me scratch.
- `make permute TARGET=path/to/nonmatchings/source.s` invokes the permuter for the target assembly file. 
- `make remake -j` will delete and re-split the targets; this can be necessary if the dependency management has failed to identify everything that needs rebuilding (in which case a bug report is appreciated!), or if the configuration has changed enough to be no longer valid (e.g. orphaned .d files). It's good practice to run this before submitting a pull request to make sure everything still works.
- `make format` formats the source files and symbol addresses for consistency. Please run this before submitting a PR.
- `make clean` simply deletes the `build` and `nonmatchings` directories
- `make clean-all` will completely reset the project, including dropping any source changes and data files (but not the disk image). Use with caution.
