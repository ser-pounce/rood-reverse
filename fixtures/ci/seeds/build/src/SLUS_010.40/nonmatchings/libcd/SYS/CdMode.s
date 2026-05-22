nonmatching CdMode, 0x10

glabel CdMode
    /* 10BC4 800203C4 0380023C */  lui        $v0, %hi(D_80032218)
    /* 10BC8 800203C8 18224290 */  lbu        $v0, %lo(D_80032218)($v0)
    /* 10BCC 800203CC 0800E003 */  jr         $ra
    /* 10BD0 800203D0 00000000 */   nop
endlabel CdMode
