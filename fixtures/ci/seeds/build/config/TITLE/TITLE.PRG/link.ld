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
        build/src/TITLE/TITLE.PRG/22C.o(.rodata);
        build/src/TITLE/TITLE.PRG/libpress/LIBPRESS.o(.rodata);
        build/src/TITLE/TITLE.PRG/libpress/VLC_C.o(.rodata);
        build/src/TITLE/TITLE.PRG/libpress/BUILD.o(.rodata);
        . = ALIGN(., 4);
        _0_RODATA_END = .;
        _0_RODATA_SIZE = ABSOLUTE(_0_RODATA_END - _0_RODATA_START);
        _0_TEXT_START = .;
        build/src/TITLE/TITLE.PRG/22C.o(.text);
        build/src/TITLE/TITLE.PRG/libpress/LIBPRESS.o(.text);
        build/src/TITLE/TITLE.PRG/libpress/VLC_C.o(.text);
        build/src/TITLE/TITLE.PRG/libpress/BUILD.o(.text);
        . = ALIGN(., 4);
        _0_TEXT_END = .;
        _0_TEXT_SIZE = ABSOLUTE(_0_TEXT_END - _0_TEXT_START);
        _0_DATA_START = .;
        build/src/TITLE/TITLE.PRG/22C.o(.data);
        build/src/TITLE/TITLE.PRG/libpress/LIBPRESS.o(.data);
        build/src/TITLE/TITLE.PRG/libpress/VLC_C.o(.data);
        build/src/TITLE/TITLE.PRG/libpress/BUILD.o(.data);
        build/assets/TITLE/TITLE.PRG/_titleScreenBg.rgba16Compressed.img.o(.data);
        build/assets/TITLE/TITLE.PRG/_menuCopyright.rgba16.img.o(.data);
        build/assets/TITLE/TITLE.PRG/_fontTable.rgbClut.img.o(.data);
        build/assets/TITLE/TITLE.PRG/_fontTable1.rgbClut.img.o(.data);
        build/assets/TITLE/TITLE.PRG/_debugFont.rgbClut.img.o(.data);
        build/assets/TITLE/TITLE.PRG/_uiTable.rgbClut.img.o(.data);
        build/assets/TITLE/TITLE.PRG/_saveMenuBg.rgbClut.img.o(.data);
        . = ALIGN(., 4);
        _0_DATA_END = .;
        _0_DATA_SIZE = ABSOLUTE(_0_DATA_END - _0_DATA_START);
        _0_BSS_START = .;
        build/src/TITLE/TITLE.PRG/22C.o(.bss);
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
