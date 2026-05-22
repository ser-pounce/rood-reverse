nonmatching GetGraphDebug, 0x10

glabel GetGraphDebug
    /* 18D48 80028548 0380023C */  lui        $v0, %hi(D_80033446)
    /* 18D4C 8002854C 46344290 */  lbu        $v0, %lo(D_80033446)($v0)
    /* 18D50 80028550 0800E003 */  jr         $ra
    /* 18D54 80028554 00000000 */   nop
endlabel GetGraphDebug
