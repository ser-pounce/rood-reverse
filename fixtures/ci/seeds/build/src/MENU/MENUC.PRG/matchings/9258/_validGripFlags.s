nonmatching _validGripFlags

dlabel _validGripFlags
    /* 9324 8010BB24 00000E00 */ .word 0x000E0000
    /* 9328 8010BB28 F0000001 */ .word 0x010000F0
    /* 932C 8010BB2C */ .short 0x0200
enddlabel _validGripFlags

nonmatching D_8010BB2E

dlabel D_8010BB2E
    /* 932E 8010BB2E */ .short 0x0000

nonmatching D_8010BB30

dlabel D_8010BB30
    /* 9330 8010BB30 000E1838 */ .word 0x38180E00
    /* 9334 8010BB34 C03EFE00 */ .word 0x00FE3EC0 /* invalid instruction */

nonmatching D_8010BB38

dlabel D_8010BB38
    /* 9338 8010BB38 8D000A00 */ .word 0x000A008D
    /* 933C 8010BB3C 94001A00 */ .word 0x001A0094 /* invalid instruction */
    /* 9340 8010BB40 94002A00 */ .word 0x002A0094 /* invalid instruction */
    /* 9344 8010BB44 9B003A00 */ .word 0x003A009B /* invalid instruction */
    /* 9348 8010BB48 9B004A00 */ .word 0x004A009B /* invalid instruction */
    /* 934C 8010BB4C 9B005A00 */ .word 0x005A009B /* invalid instruction */
    /* 9350 8010BB50 9B006A00 */ .word 0x006A009B /* invalid instruction */
    /* 9354 8010BB54 */ .byte 0x00
enddlabel D_8010BB2E

nonmatching D_8010BB55

dlabel D_8010BB55
    /* 9355 8010BB55 */ .byte 0x00
enddlabel D_8010BB55

nonmatching D_8010BB56

dlabel D_8010BB56
    /* 9356 8010BB56 */ .byte 0x00
enddlabel D_8010BB56

nonmatching D_8010BB57

dlabel D_8010BB57
    /* 9357 8010BB57 */ .byte 0x00
enddlabel D_8010BB57
