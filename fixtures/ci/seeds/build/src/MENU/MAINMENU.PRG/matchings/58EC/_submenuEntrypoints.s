nonmatching _submenuEntrypoints

dlabel _submenuEntrypoints
    /* 8838 80102038 C8421080 */ .word vs_menu0_exec
    /* 883C 8010203C 70321080 */ .word vs_menu1_exec
    /* 8840 80102040 D4381080 */ .word vs_menu2_exec
    /* 8844 80102044 70891080 */ .word vs_menu3_exec
    /* 8848 80102048 D4641080 */ .word vs_menu4_exec
    /* 884C 8010204C F4301080 */ .word vs_menu5_exec
    /* 8850 80102050 B89E1080 */ .word vs_menu7_dataMenu
    /* 8854 80102054 B4371080 */ .word vs_menu8_exec
    /* 8858 80102058 F82F1080 */ .word vs_menu9_exec
    /* 885C 8010205C DC2E1080 */ .word vs_menuE_exec

nonmatching D_80102060

dlabel D_80102060
    /* 8860 80102060 16121C0C */ .word 0x0C1C1216
    /* 8864 80102064 E70000F8 */ .word 0xF80000E7

nonmatching D_80102068

dlabel D_80102068
    /* 8868 80102068 98980F80 */ .word 0x800F9898
    /* 886C 8010206C 90980F80 */ .word 0x800F9890
    /* 8870 80102070 88980F80 */ .word 0x800F9888
    /* 8874 80102074 7C980F80 */ .word 0x800F987C
    /* 8878 80102078 74980F80 */ .word 0x800F9874
    /* 887C 8010207C 6C980F80 */ .word 0x800F986C
    /* 8880 80102080 00000000 */ .word 0x00000000
    /* 8884 80102084 00000000 */ .word 0x00000000
    /* 8888 80102088 60980F80 */ .word 0x800F9860
    /* 888C 8010208C 58980F80 */ .word 0x800F9858
    /* 8890 80102090 50980F80 */ .word 0x800F9850
    /* 8894 80102094 48980F80 */ .word 0x800F9848
    /* 8898 80102098 40980F80 */ .word 0x800F9840
    /* 889C 8010209C 38980F80 */ .word 0x800F9838
    /* 88A0 801020A0 30980F80 */ .word 0x800F9830
    /* 88A4 801020A4 00000000 */ .word 0x00000000
    /* 88A8 801020A8 28980F80 */ .word 0x800F9828
    /* 88AC 801020AC 20980F80 */ .word 0x800F9820
    /* 88B0 801020B0 14980F80 */ .word 0x800F9814

nonmatching D_801020B4

dlabel D_801020B4
    /* 88B4 801020B4 18738140 */ .word 0x40817318 /* invalid instruction */
    /* 88B8 801020B8 30E0D040 */ .word 0x40D0E030 /* invalid instruction */
    /* 88BC 801020BC 30E0D040 */ .word 0x40D0E030 /* invalid instruction */
    /* 88C0 801020C0 18738140 */ .word 0x40817318 /* invalid instruction */

nonmatching D_801020C4

dlabel D_801020C4
    /* 88C4 801020C4 6E3F6940 */ .word 0x40693F6E /* invalid instruction */
    /* 88C8 801020C8 DC789F40 */ .word 0x409F78DC /* invalid instruction */
    /* 88CC 801020CC DC789F40 */ .word 0x409F78DC /* invalid instruction */
    /* 88D0 801020D0 6E3F6940 */ .word 0x40693F6E /* invalid instruction */

nonmatching D_801020D4

dlabel D_801020D4
    /* 88D4 801020D4 FB000C15 */ .word 0x150C00FB
    /* 88D8 801020D8 0A1C1CFB */ .word 0xFB1C1C0A
    /* 88DC 801020DC 00A1FB00 */ .word 0x00FBA100 /* invalid instruction */
    /* 88E0 801020E0 0A0F0F12 */ .word 0x120F0F0A
    /* 88E4 801020E4 17121D22 */ .word 0x221D1217
    /* 88E8 801020E8 FB00A1FB */ .word 0xFBA100FB
    /* 88EC 801020EC 001D2219 */ .word 0x19221D00 /* invalid instruction */
    /* 88F0 801020F0 0E000000 */ .word 0x0000000E /* invalid instruction */

nonmatching D_801020F4

dlabel D_801020F4
    /* 88F4 801020F4 00000000 */ .word 0x00000000

nonmatching D_801020F8

dlabel D_801020F8
    /* 88F8 801020F8 00000000 */ .word 0x00000000

nonmatching D_801020FC

dlabel D_801020FC
    /* 88FC 801020FC B0980F80 */ .word D_800F98A8 + 0x8
    /* 8900 80102100 A8980F80 */ .word D_800F98A8

nonmatching D_80102104

dlabel D_80102104
    /* 8904 80102104 0C990F80 */ .word D_800F98A8 + 0x64
    /* 8908 80102108 FC980F80 */ .word D_800F98A8 + 0x54
    /* 890C 8010210C F0980F80 */ .word D_800F98A8 + 0x48
    /* 8910 80102110 00000000 */ .word 0x00000000
    /* 8914 80102114 E4980F80 */ .word D_800F98A8 + 0x3C
    /* 8918 80102118 D8980F80 */ .word D_800F98A8 + 0x30
    /* 891C 8010211C F0980F80 */ .word D_800F98A8 + 0x48
    /* 8920 80102120 00000000 */ .word 0x00000000
    /* 8924 80102124 C8980F80 */ .word D_800F98A8 + 0x20
    /* 8928 80102128 B8980F80 */ .word D_800F98A8 + 0x10
    /* 892C 8010212C F0980F80 */ .word D_800F98A8 + 0x48
    /* 8930 80102130 */ .byte 0x00
enddlabel _submenuEntrypoints

nonmatching D_80102131

dlabel D_80102131
    /* 8931 80102131 */ .byte 0x00
enddlabel D_80102131

nonmatching D_80102132

dlabel D_80102132
    /* 8932 80102132 */ .short 0x0000
enddlabel D_80102132
