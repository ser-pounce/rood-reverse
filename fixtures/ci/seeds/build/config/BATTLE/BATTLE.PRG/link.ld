SECTIONS
{
    __romPos = 0;
    _gp = 0x80033674;
    _0_ROM_START = __romPos;
    _0_VRAM = ADDR(._0);
    ._0 0x80068800 : AT(_0_ROM_START) SUBALIGN(2)
    {
        FILL(0x00000000);
        _0_RODATA_START = .;
        build/src/BATTLE/BATTLE.PRG/146C.o(.rodata);
        build/src/BATTLE/BATTLE.PRG/2842C.o(.rodata);
        build/src/BATTLE/BATTLE.PRG/30D14.o(.rodata);
        build/src/BATTLE/BATTLE.PRG/3A1A0.o(.rodata);
        build/src/BATTLE/BATTLE.PRG/40564.o(.rodata);
        build/src/BATTLE/BATTLE.PRG/44F14.o(.rodata);
        build/src/BATTLE/BATTLE.PRG/4A0A8.o(.rodata);
        build/src/BATTLE/BATTLE.PRG/573B8.o(.rodata);
        build/src/BATTLE/BATTLE.PRG/58578.o(.rodata);
        build/src/BATTLE/BATTLE.PRG/5BF94.o(.rodata);
        build/src/BATTLE/BATTLE.PRG/6E644.rodata.o(.rodata);
        build/src/BATTLE/BATTLE.PRG/2EA3C.o(.rodata);
        build/src/BATTLE/BATTLE.PRG/38C1C.o(.rodata);
        . = ALIGN(., 4);
        _0_RODATA_END = .;
        _0_RODATA_SIZE = ABSOLUTE(_0_RODATA_END - _0_RODATA_START);
        _0_TEXT_START = .;
        build/src/BATTLE/BATTLE.PRG/146C.o(.text);
        build/src/BATTLE/BATTLE.PRG/2842C.o(.text);
        build/src/BATTLE/BATTLE.PRG/2EA3C.o(.text);
        build/src/BATTLE/BATTLE.PRG/30D14.o(.text);
        build/src/BATTLE/BATTLE.PRG/38C1C.o(.text);
        build/src/BATTLE/BATTLE.PRG/3A1A0.o(.text);
        build/src/BATTLE/BATTLE.PRG/40564.o(.text);
        build/src/BATTLE/BATTLE.PRG/44F14.o(.text);
        build/src/BATTLE/BATTLE.PRG/4A0A8.o(.text);
        build/src/BATTLE/BATTLE.PRG/573B8.o(.text);
        build/src/BATTLE/BATTLE.PRG/58578.o(.text);
        build/src/BATTLE/BATTLE.PRG/5BF94.o(.text);
        build/src/BATTLE/BATTLE.PRG/6E644.o(.text);
        . = ALIGN(., 4);
        _0_TEXT_END = .;
        _0_TEXT_SIZE = ABSOLUTE(_0_TEXT_END - _0_TEXT_START);
        _0_DATA_START = .;
        build/src/BATTLE/BATTLE.PRG/146C.o(.data);
        build/src/BATTLE/BATTLE.PRG/2842C.o(.data);
        build/src/BATTLE/BATTLE.PRG/30D14.o(.data);
        build/src/BATTLE/BATTLE.PRG/3A1A0.o(.data);
        build/src/BATTLE/BATTLE.PRG/40564.o(.data);
        build/src/BATTLE/BATTLE.PRG/44F14.o(.data);
        build/src/BATTLE/BATTLE.PRG/4A0A8.o(.data);
        build/src/BATTLE/BATTLE.PRG/573B8.o(.data);
        build/src/BATTLE/BATTLE.PRG/58578.o(.data);
        build/src/BATTLE/BATTLE.PRG/5BF94.o(.data);
        build/src/BATTLE/BATTLE.PRG/6E644.o(.data);
        build/src/BATTLE/BATTLE.PRG/2EA3C.o(.data);
        build/src/BATTLE/BATTLE.PRG/38C1C.o(.data);
        build/src/BATTLE/BATTLE.PRG/7F984.data.o(.data);
        build/src/BATTLE/BATTLE.PRG/menuLbas.o(.data);
        build/src/BATTLE/BATTLE.PRG/gimLbas.o(.data);
        build/src/BATTLE/BATTLE.PRG/82F08.data.o(.data);
        build/assets/BATTLE/BATTLE.PRG/menuStrings.vsString.o(.data);
        build/src/BATTLE/BATTLE.PRG/833B8.data.o(.data);
        . = ALIGN(., 4);
        _0_DATA_END = .;
        _0_DATA_SIZE = ABSOLUTE(_0_DATA_END - _0_DATA_START);
        _0_BSS_START = .;
        build/src/BATTLE/BATTLE.PRG/89058.bss.o(.bss);
        . = ALIGN(., 4);
        _0_BSS_END = .;
        _0_BSS_SIZE = ABSOLUTE(_0_BSS_END - _0_BSS_START);
    }
    __romPos += SIZEOF(._0);
    __romPos = ALIGN(__romPos, 4);
    . = ALIGN(., 4);
    _0_ROM_END = __romPos;
    _0_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
