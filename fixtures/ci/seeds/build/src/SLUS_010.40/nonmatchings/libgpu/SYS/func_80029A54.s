nonmatching func_80029A54, 0x1C

glabel func_80029A54
    /* 1A254 80029A54 FF07A530 */  andi       $a1, $a1, 0x7FF
    /* 1A258 80029A58 C02A0500 */  sll        $a1, $a1, 11
    /* 1A25C 80029A5C FF078230 */  andi       $v0, $a0, 0x7FF
    /* 1A260 80029A60 00E5033C */  lui        $v1, (0xE5000000 >> 16)
    /* 1A264 80029A64 25104300 */  or         $v0, $v0, $v1
    /* 1A268 80029A68 0800E003 */  jr         $ra
    /* 1A26C 80029A6C 2510A200 */   or        $v0, $a1, $v0
endlabel func_80029A54
