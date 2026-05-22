SECTIONS
{
    __romPos = 0;
    _gp = 0x80033674;
    _0_ROM_START = __romPos;
    _0_VRAM = ADDR(._0);
    ._0 0x800F9800 : AT(_0_ROM_START) SUBALIGN(2)
    {
        FILL(0x00000000);
        _0_RODATA_START = .;
        build/src/BATTLE/INITBTL.PRG/18.o(.rodata);
        build/src/BATTLE/INITBTL.PRG/FB0.o(.rodata);
        build/src/BATTLE/INITBTL.PRG/12AC.o(.rodata);
        . = ALIGN(., 4);
        _0_RODATA_END = .;
        _0_RODATA_SIZE = ABSOLUTE(_0_RODATA_END - _0_RODATA_START);
        _0_TEXT_START = .;
        build/src/BATTLE/INITBTL.PRG/18.o(.text);
        build/src/BATTLE/INITBTL.PRG/FB0.o(.text);
        build/src/BATTLE/INITBTL.PRG/12AC.o(.text);
        . = ALIGN(., 4);
        _0_TEXT_END = .;
        _0_TEXT_SIZE = ABSOLUTE(_0_TEXT_END - _0_TEXT_START);
        _0_DATA_START = .;
        build/src/BATTLE/INITBTL.PRG/18.o(.data);
        build/src/BATTLE/INITBTL.PRG/FB0.o(.data);
        build/src/BATTLE/INITBTL.PRG/12AC.o(.data);
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
