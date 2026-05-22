nonmatching vs_mainMenu_mainCursorXY

dlabel vs_mainMenu_mainCursorXY
    /* 89C4 801021C4 8D000A00 */ .word 0x000A008D
    /* 89C8 801021C8 94001A00 */ .word 0x001A0094 /* invalid instruction */
    /* 89CC 801021CC 94002A00 */ .word 0x002A0094 /* invalid instruction */
    /* 89D0 801021D0 9B003A00 */ .word 0x003A009B /* invalid instruction */
    /* 89D4 801021D4 9B004A00 */ .word 0x004A009B /* invalid instruction */
    /* 89D8 801021D8 9B005A00 */ .word 0x005A009B /* invalid instruction */
    /* 89DC 801021DC B4001800 */ .word 0x001800B4
    /* 89E0 801021E0 C0007E00 */ .word 0x007E00C0 /* invalid instruction */
    /* 89E4 801021E4 C0008800 */ .word 0x008800C0 /* invalid instruction */
    /* 89E8 801021E8 98009200 */ .word 0x00920098 /* invalid instruction */
    /* 89EC 801021EC 98009C00 */ .word 0x009C0098 /* invalid instruction */
    /* 89F0 801021F0 9800A600 */ .word 0x00A60098 /* invalid instruction */

nonmatching D_801021F4

dlabel D_801021F4
    /* 89F4 801021F4 3CD90F80 */ .word func_800FD93C
    /* 89F8 801021F8 04DB0F80 */ .word func_800FDB04
    /* 89FC 801021FC 60DB0F80 */ .word func_800FDB60
    /* 8A00 80102200 ACDB0F80 */ .word func_800FDBAC
    /* 8A04 80102204 D0DC0F80 */ .word func_800FDCD0
    /* 8A08 80102208 D0DC0F80 */ .word func_800FDCD0
    /* 8A0C 8010220C 24DD0F80 */ .word func_800FDD24
    /* 8A10 80102210 */ .byte 0x00
enddlabel vs_mainMenu_mainCursorXY

nonmatching D_80102211

dlabel D_80102211
    /* 8A11 80102211 */ .byte 0x00
    /* 8A12 80102212 */ .short 0x0000

nonmatching D_80102214

dlabel D_80102214
    /* 8A14 80102214 E0E1E2E3 */ .word 0xE3E2E1E0
    /* 8A18 80102218 E4E5E6E7 */ .word 0xE7E6E5E4
    /* 8A1C 8010221C F3F4F5F6 */ .word 0xF6F5F4F3
    /* 8A20 80102220 E8E9EAEB */ .word 0xEBEAE9E8
    /* 8A24 80102224 ECEDEFEE */ .word 0xEEEFEDEC /* invalid instruction */
    /* 8A28 80102228 F0F2F7F8 */ .word 0xF8F7F2F0
    /* 8A2C 8010222C F9FAFBFC */ .word 0xFCFBFAF9
    /* 8A30 80102230 F8F9FAFB */ .word 0xFBFAF9F8
    /* 8A34 80102234 FCF100FE */ .word 0xFE00F1FC
    /* 8A38 80102238 FDFBF4FE */ .word 0xFEF4FBFD
    /* 8A3C 8010223C FBF6F3F3 */ .word 0xF3F3F6FB
    /* 8A40 80102240 FCFDFFFB */ .word 0xFBFFFDFC
    /* 8A44 80102244 F5FEFDFF */ .word 0xFFFDFEF5
    /* 8A48 80102248 FDFDFFFD */ .word 0xFDFFFDFD
    /* 8A4C 8010224C FEFEFFFE */ .word 0xFEFFFEFE
    /* 8A50 80102250 FCFFFD61 */ .word 0x61FDFFFC
    /* 8A54 80102254 62636465 */ .word 0x65646362
    /* 8A58 80102258 66676869 */ .word 0x69686766
    /* 8A5C 8010225C 6A000000 */ .word 0x0000006A /* invalid instruction */
    /* 8A60 80102260 6E000000 */ .word 0x0000006E /* invalid instruction */
    /* 8A64 80102264 72000000 */ .word 0x00000072
    /* 8A68 80102268 76000000 */ .word 0x00000076
    /* 8A6C 8010226C 7A000000 */ .word 0x0000007A
    /* 8A70 80102270 7E000000 */ .word 0x0000007E
    /* 8A74 80102274 82000000 */ .word 0x00000082
    /* 8A78 80102278 5E5F6057 */ .word 0x57605F5E
    /* 8A7C 8010227C 585A5B4D */ .word 0x4D5B5A58 /* invalid instruction */
    /* 8A80 80102280 3C363D37 */ .word 0x373D363C
    /* 8A84 80102284 3E383F39 */ .word 0x393F383E
    /* 8A88 80102288 4B4C5253 */ .word 0x53524C4B
    /* 8A8C 8010228C 554F505C */ .word 0x5C504F55 /* invalid instruction */
    /* 8A90 80102290 5D3A4243 */ .word 0x43423A5D /* invalid instruction */
    /* 8A94 80102294 44454647 */ .word 0x47464544 /* invalid instruction */
    /* 8A98 80102298 48490000 */ .word 0x00004948 /* invalid instruction */
enddlabel D_80102211
