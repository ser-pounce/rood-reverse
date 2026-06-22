SECTIONS
{
    __romPos = 0;
    _gp = 0x80033674;
    _0_ROM_START = __romPos;
    _0_VRAM = ADDR(._0);
    ._0 0x80102800 : AT(_0_ROM_START) SUBALIGN(4)
    {
        FILL(0x00000000);
        _0_RODATA_START = .;
        build/src/MENU/MENUC.PRG/168.o(.rodata);
        build/src/MENU/MENUC.PRG/9258.o(.rodata);
        . = ALIGN(., 4);
        _0_RODATA_END = .;
        _0_RODATA_SIZE = ABSOLUTE(_0_RODATA_END - _0_RODATA_START);
        _0_TEXT_START = .;
        build/src/MENU/MENUC.PRG/168.o(.text);
        build/src/MENU/MENUC.PRG/9258.o(.text);
        . = ALIGN(., 4);
        _0_TEXT_END = .;
        _0_TEXT_SIZE = ABSOLUTE(_0_TEXT_END - _0_TEXT_START);
        _0_DATA_START = .;
        build/src/MENU/MENUC.PRG/168.o(.data);
        build/src/MENU/MENUC.PRG/9258.o(.data);
        . = ALIGN(., 4);
        _0_DATA_END = .;
        _0_DATA_SIZE = ABSOLUTE(_0_DATA_END - _0_DATA_START);
        _0_BSS_START = .;
        build/src/MENU/MENUC.PRG/168.o(.bss);
        build/src/MENU/MENUC.PRG/9258.o(.bss);
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
