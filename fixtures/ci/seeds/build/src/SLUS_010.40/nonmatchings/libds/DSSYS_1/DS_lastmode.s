nonmatching DS_lastmode, 0x10

glabel DS_lastmode
    /* 15120 80024920 0380023C */  lui        $v0, %hi(D_800326A9)
    /* 15124 80024924 A9264290 */  lbu        $v0, %lo(D_800326A9)($v0)
    /* 15128 80024928 0800E003 */  jr         $ra
    /* 1512C 8002492C 00000000 */   nop
endlabel DS_lastmode
