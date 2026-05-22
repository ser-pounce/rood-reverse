nonmatching vs_mainMenu_isLevelledSpell

dlabel vs_mainMenu_isLevelledSpell
    /* 8AD4 801022D4 */ .byte 0x00
enddlabel vs_mainMenu_isLevelledSpell

nonmatching D_801022D5

dlabel D_801022D5
    /* 8AD5 801022D5 */ .byte 0x00
enddlabel D_801022D5

nonmatching D_801022D6

dlabel D_801022D6
    /* 8AD6 801022D6 */ .byte 0x00
    /* 8AD7 801022D7 */ .byte 0x00

nonmatching D_801022D8

dlabel D_801022D8
    /* 8AD8 801022D8 00000000 */ .word 0x00000000
    /* 8ADC 801022DC */ .short 0x0000
enddlabel D_801022D6

nonmatching D_801022DE

dlabel D_801022DE
    /* 8ADE 801022DE */ .short 0xFFFC
    /* 8AE0 801022E0 */ .byte 0x80
    /* 8AE1 801022E1 */ .byte 0x00
enddlabel D_801022DE

nonmatching D_801022E2

dlabel D_801022E2
    /* 8AE2 801022E2 */ .byte 0x00
enddlabel D_801022E2

nonmatching D_801022E3

dlabel D_801022E3
    /* 8AE3 801022E3 */ .byte 0x00

nonmatching D_801022E4

dlabel D_801022E4
    /* 8AE4 801022E4 00000000 */ .word 0x00000000

nonmatching D_801022E8

dlabel D_801022E8
    /* 8AE8 801022E8 00000040 */ .word 0x40000000
    /* 8AEC 801022EC 40406440 */ .word 0x40644040 /* invalid instruction */
    /* 8AF0 801022F0 8440BC40 */ .word 0x40BC4084 /* invalid instruction */
    /* 8AF4 801022F4 004A0000 */ .word 0x00004A00

nonmatching D_801022F8

dlabel D_801022F8
    /* 8AF8 801022F8 00000000 */ .word 0x00000000
    /* 8AFC 801022FC 3E000A00 */ .word D_A003C + 0x2
    /* 8B00 80102300 24000A00 */ .word 0x000A0024
    /* 8B04 80102304 1E000A00 */ .word D_A001C + 0x2
    /* 8B08 80102308 38000A00 */ .word 0x000A0038
    /* 8B0C 8010230C 1E000A00 */ .word D_A001C + 0x2
    /* 8B10 80102310 20000A00 */ .word 0x000A0020
    /* 8B14 80102314 00000000 */ .word 0x00000000
    /* 8B18 80102318 */ .short 0x00F8
enddlabel D_801022E3

nonmatching D_8010231A

dlabel D_8010231A
    /* 8B1A 8010231A */ .short 0x0000
    /* 8B1C 8010231C 00000000 */ .word 0x00000000
    /* 8B20 80102320 00000000 */ .word 0x00000000
    /* 8B24 80102324 00000000 */ .word 0x00000000
    /* 8B28 80102328 00000000 */ .word 0x00000000
    /* 8B2C 8010232C 00000000 */ .word 0x00000000
    /* 8B30 80102330 00000000 */ .word 0x00000000
    /* 8B34 80102334 00000000 */ .word 0x00000000
    /* 8B38 80102338 00000000 */ .word 0x00000000
    /* 8B3C 8010233C 00000000 */ .word 0x00000000
    /* 8B40 80102340 00000000 */ .word 0x00000000
    /* 8B44 80102344 00000000 */ .word 0x00000000
    /* 8B48 80102348 00000000 */ .word 0x00000000
    /* 8B4C 8010234C 00000000 */ .word 0x00000000
    /* 8B50 80102350 00000000 */ .word 0x00000000
    /* 8B54 80102354 00000000 */ .word 0x00000000
    /* 8B58 80102358 00000000 */ .word 0x00000000
    /* 8B5C 8010235C 00000000 */ .word 0x00000000
    /* 8B60 80102360 00000000 */ .word 0x00000000
    /* 8B64 80102364 00000000 */ .word 0x00000000
    /* 8B68 80102368 00000000 */ .word 0x00000000
    /* 8B6C 8010236C 00000000 */ .word 0x00000000
    /* 8B70 80102370 00000000 */ .word 0x00000000
    /* 8B74 80102374 00000000 */ .word 0x00000000
    /* 8B78 80102378 0000E7E7 */ .word 0xE7E70000

nonmatching D_8010237C

dlabel D_8010237C
    /* 8B7C 8010237C 50609060 */ .word 0x60906050
    /* 8B80 80102380 A0607060 */ .word 0x607060A0
    /* 8B84 80102384 8060B060 */ .word 0x60B06080
    /* 8B88 80102388 D0606060 */ .word 0x606060D0
    /* 8B8C 8010238C 30708070 */ .word 0x70807030 /* invalid instruction */
    /* 8B90 80102390 00701070 */ .word 0x70107000 /* invalid instruction */
    /* 8B94 80102394 2070E060 */ .word 0x60E07020
    /* 8B98 80102398 40705070 */ .word 0x70507040 /* invalid instruction */
    /* 8B9C 8010239C 60707070 */ .word 0x70707060 /* invalid instruction */
    /* 8BA0 801023A0 80709070 */ .word 0x70907080 /* invalid instruction */
    /* 8BA4 801023A4 A0702060 */ .word 0x602070A0
    /* 8BA8 801023A8 B0707880 */ .word 0x807870B0
    /* 8BAC 801023AC 88809880 */ .word 0x80988088
    /* 8BB0 801023B0 A880B880 */ .word 0x80B880A8
    /* 8BB4 801023B4 C880D880 */ .word 0x80D880C8
    /* 8BB8 801023B8 E8806080 */ .word 0x806080E8
    /* 8BBC 801023BC */ .short 0x8050
enddlabel D_8010231A

nonmatching D_801023BE

dlabel D_801023BE
    /* 8BBE 801023BE */ .short 0x0008

nonmatching D_801023C0

dlabel D_801023C0
    /* 8BC0 801023C0 80020001 */ .word 0x01000280 /* invalid instruction */
    /* 8BC4 801023C4 2000F000 */ .word 0x00F00020
    /* 8BC8 801023C8 00030001 */ .word 0x01000300 /* invalid instruction */
    /* 8BCC 801023CC 2000F000 */ .word 0x00F00020

nonmatching D_801023D0

dlabel D_801023D0
    /* 8BD0 801023D0 00000000 */ .word 0x00000000

nonmatching D_801023D4

dlabel D_801023D4
    /* 8BD4 801023D4 00000000 */ .word 0x00000000
enddlabel D_801023BE
