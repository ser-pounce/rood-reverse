nonmatching CdStatus, 0x10

glabel CdStatus
    /* 10BB4 800203B4 0380023C */  lui        $v0, %hi(D_80032208)
    /* 10BB8 800203B8 08224290 */  lbu        $v0, %lo(D_80032208)($v0)
    /* 10BBC 800203BC 0800E003 */  jr         $ra
    /* 10BC0 800203C0 00000000 */   nop
endlabel CdStatus
