nonmatching CdLastCom, 0x10

glabel CdLastCom
    /* 10BD4 800203D4 0380023C */  lui        $v0, %hi(D_80032219)
    /* 10BD8 800203D8 19224290 */  lbu        $v0, %lo(D_80032219)($v0)
    /* 10BDC 800203DC 0800E003 */  jr         $ra
    /* 10BE0 800203E0 00000000 */   nop
endlabel CdLastCom
