nonmatching func_80103D50, 0x1C

glabel func_80103D50
    /* 1550 80103D50 1180023C */  lui        $v0, %hi(D_80109A7B)
    /* 1554 80103D54 7B9A44A0 */  sb         $a0, %lo(D_80109A7B)($v0)
    /* 1558 80103D58 1180023C */  lui        $v0, %hi(D_80109A7C)
    /* 155C 80103D5C 7C9A44A0 */  sb         $a0, %lo(D_80109A7C)($v0)
    /* 1560 80103D60 1180023C */  lui        $v0, %hi(D_80109A7D)
    /* 1564 80103D64 0800E003 */  jr         $ra
    /* 1568 80103D68 7D9A44A0 */   sb        $a0, %lo(D_80109A7D)($v0)
endlabel func_80103D50
