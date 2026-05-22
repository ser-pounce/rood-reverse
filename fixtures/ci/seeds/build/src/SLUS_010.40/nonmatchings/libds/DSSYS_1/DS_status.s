nonmatching DS_status, 0x10

glabel DS_status
    /* 1515C 8002495C 0380023C */  lui        $v0, %hi(D_80032694)
    /* 15160 80024960 94264290 */  lbu        $v0, %lo(D_80032694)($v0)
    /* 15164 80024964 0800E003 */  jr         $ra
    /* 15168 80024968 00000000 */   nop
endlabel DS_status
