nonmatching DS_lastcom, 0x10

glabel DS_lastcom
    /* 15110 80024910 0380023C */  lui        $v0, %hi(D_800326A8)
    /* 15114 80024914 A8264290 */  lbu        $v0, %lo(D_800326A8)($v0)
    /* 15118 80024918 0800E003 */  jr         $ra
    /* 1511C 8002491C 00000000 */   nop
endlabel DS_lastcom
