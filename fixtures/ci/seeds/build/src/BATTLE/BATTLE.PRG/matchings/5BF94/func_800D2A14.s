nonmatching func_800D2A14, 0x24

glabel func_800D2A14
    /* 6A214 800D2A14 00008294 */  lhu        $v0, 0x0($a0)
    /* 6A218 800D2A18 00000000 */  nop
    /* 6A21C 800D2A1C 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 6A220 800D2A20 04008294 */  lhu        $v0, 0x4($a0)
    /* 6A224 800D2A24 00000000 */  nop
    /* 6A228 800D2A28 0200A2A4 */  sh         $v0, 0x2($a1)
    /* 6A22C 800D2A2C 08008294 */  lhu        $v0, 0x8($a0)
    /* 6A230 800D2A30 0800E003 */  jr         $ra
    /* 6A234 800D2A34 0400A2A4 */   sh        $v0, 0x4($a1)
endlabel func_800D2A14
