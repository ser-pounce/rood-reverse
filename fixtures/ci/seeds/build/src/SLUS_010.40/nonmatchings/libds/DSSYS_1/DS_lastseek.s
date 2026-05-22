nonmatching DS_lastseek, 0x10

glabel DS_lastseek
    /* 1513C 8002493C 0380023C */  lui        $v0, %hi(D_800326AE)
    /* 15140 80024940 AE264290 */  lbu        $v0, %lo(D_800326AE)($v0)
    /* 15144 80024944 0800E003 */  jr         $ra
    /* 15148 80024948 00000000 */   nop
endlabel DS_lastseek
