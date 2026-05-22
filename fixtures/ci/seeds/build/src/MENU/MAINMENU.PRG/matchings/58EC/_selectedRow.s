nonmatching _selectedRow

dlabel _selectedRow
    /* 8BD8 801023D8 00000000 */ .word 0x00000000
    /* 8BDC 801023DC */ .byte 0x00
enddlabel _selectedRow

nonmatching D_801023DD

dlabel D_801023DD
    /* 8BDD 801023DD */ .byte 0x00
enddlabel D_801023DD

nonmatching D_801023DE

dlabel D_801023DE
    /* 8BDE 801023DE */ .byte 0x00
enddlabel D_801023DE

nonmatching D_801023DF

dlabel D_801023DF
    /* 8BDF 801023DF */ .byte 0x00
    /* 8BE0 801023E0 */ .byte 0x00
    /* 8BE1 801023E1 */ .byte 0x00
enddlabel D_801023DF

nonmatching D_801023E2

dlabel D_801023E2
    /* 8BE2 801023E2 */ .byte 0x00
enddlabel D_801023E2

nonmatching D_801023E3

dlabel D_801023E3
    /* 8BE3 801023E3 */ .byte 0x00

nonmatching D_801023E4

dlabel D_801023E4
    /* 8BE4 801023E4 0B000000 */ .word 0x0000000B

nonmatching D_801023E8

dlabel D_801023E8
    /* 8BE8 801023E8 009A0F80 */ .word 0x800F9A00
    /* 8BEC 801023EC FC990F80 */ .word 0x800F99FC
    /* 8BF0 801023F0 009A0F80 */ .word 0x800F9A00
    /* 8BF4 801023F4 F8990F80 */ .word 0x800F99F8

nonmatching D_801023F8

dlabel D_801023F8
    /* 8BF8 801023F8 D8000800 */ .word 0x000800D8 /* invalid instruction */
    /* 8BFC 801023FC D2000800 */ .word 0x000800D2 /* invalid instruction */
    /* 8C00 80102400 20010800 */ .word 0x00080120 /* invalid instruction */
    /* 8C04 80102404 1A010800 */ .word 0x0008011A /* invalid instruction */
    /* 8C08 80102408 */ .byte 0x00
enddlabel D_801023E3

nonmatching D_80102409

dlabel D_80102409
    /* 8C09 80102409 */ .byte 0x00
    /* 8C0A 8010240A */ .short 0xF800
    /* 8C0C 8010240C F8F8B138 */ .word 0x38B1F8F8

nonmatching D_80102410

dlabel D_80102410
    /* 8C10 80102410 00000000 */ .word 0x00000000
    /* 8C14 80102414 00000000 */ .word 0x00000000
    /* 8C18 80102418 00000000 */ .word 0x00000000
    /* 8C1C 8010241C 00000000 */ .word 0x00000000
    /* 8C20 80102420 00000000 */ .word 0x00000000
    /* 8C24 80102424 00000000 */ .word 0x00000000
    /* 8C28 80102428 00000000 */ .word 0x00000000
    /* 8C2C 8010242C 00000000 */ .word 0x00000000
    /* 8C30 80102430 00000000 */ .word 0x00000000
    /* 8C34 80102434 00000000 */ .word 0x00000000
    /* 8C38 80102438 00000000 */ .word 0x00000000
    /* 8C3C 8010243C 00000000 */ .word 0x00000000
    /* 8C40 80102440 00000000 */ .word 0x00000000
    /* 8C44 80102444 00000000 */ .word 0x00000000
    /* 8C48 80102448 00000000 */ .word 0x00000000
    /* 8C4C 8010244C 00000000 */ .word 0x00000000

nonmatching D_80102450

dlabel D_80102450
    /* 8C50 80102450 00000000 */ .word 0x00000000
    /* 8C54 80102454 */ .byte 0x00
enddlabel D_80102409

nonmatching D_80102455

dlabel D_80102455
    /* 8C55 80102455 */ .byte 0x00
enddlabel D_80102455

nonmatching D_80102456

dlabel D_80102456
    /* 8C56 80102456 */ .short 0x0000
enddlabel D_80102456
