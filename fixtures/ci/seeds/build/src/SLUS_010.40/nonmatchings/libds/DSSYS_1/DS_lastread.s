nonmatching DS_lastread, 0x10

glabel DS_lastread
    /* 1514C 8002494C 0380023C */  lui        $v0, %hi(D_800326AF)
    /* 15150 80024950 AF264290 */  lbu        $v0, %lo(D_800326AF)($v0)
    /* 15154 80024954 0800E003 */  jr         $ra
    /* 15158 80024958 00000000 */   nop
endlabel DS_lastread
