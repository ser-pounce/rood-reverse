nonmatching _svecToVec, 0x24

glabel _svecToVec
    /* 6A1F0 800D29F0 00008284 */  lh         $v0, 0x0($a0)
    /* 6A1F4 800D29F4 00000000 */  nop
    /* 6A1F8 800D29F8 0000A2AC */  sw         $v0, 0x0($a1)
    /* 6A1FC 800D29FC 02008284 */  lh         $v0, 0x2($a0)
    /* 6A200 800D2A00 00000000 */  nop
    /* 6A204 800D2A04 0400A2AC */  sw         $v0, 0x4($a1)
    /* 6A208 800D2A08 04008284 */  lh         $v0, 0x4($a0)
    /* 6A20C 800D2A0C 0800E003 */  jr         $ra
    /* 6A210 800D2A10 0800A2AC */   sw        $v0, 0x8($a1)
endlabel _svecToVec
