SECTIONS
{
    __romPos = 0;
    _gp = 0x80033674;
    _0_ROM_START = __romPos;
    _0_VRAM = ADDR(._0);
    ._0 0x800F9800 : AT(_0_ROM_START) SUBALIGN(4)
    {
        FILL(0x00000000);
        _0_RODATA_START = .;
        build/src/MENU/MAINMENU.PRG/224.o(.rodata);
        build/src/MENU/MAINMENU.PRG/C48.o(.rodata);
        build/src/MENU/MAINMENU.PRG/2D10.o(.rodata);
        build/src/MENU/MAINMENU.PRG/58EC.o(.rodata);
        . = ALIGN(., 4);
        _0_RODATA_END = .;
        _0_RODATA_SIZE = ABSOLUTE(_0_RODATA_END - _0_RODATA_START);
        _0_TEXT_START = .;
        build/src/MENU/MAINMENU.PRG/224.o(.text);
        build/src/MENU/MAINMENU.PRG/C48.o(.text);
        build/src/MENU/MAINMENU.PRG/2D10.o(.text);
        build/src/MENU/MAINMENU.PRG/58EC.o(.text);
        . = ALIGN(., 4);
        _0_TEXT_END = .;
        _0_TEXT_SIZE = ABSOLUTE(_0_TEXT_END - _0_TEXT_START);
        _0_DATA_START = .;
        build/src/MENU/MAINMENU.PRG/224.o(.data);
        build/src/MENU/MAINMENU.PRG/C48.o(.data);
        build/src/MENU/MAINMENU.PRG/2D10.o(.data);
        build/src/MENU/MAINMENU.PRG/58EC.o(.data);
        . = ALIGN(., 4);
        _0_DATA_END = .;
        _0_DATA_SIZE = ABSOLUTE(_0_DATA_END - _0_DATA_START);
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
