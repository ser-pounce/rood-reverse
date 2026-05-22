nonmatching ER_active, 0x10

glabel ER_active
    /* 16F9C 8002679C 0380023C */  lui        $v0, %hi(D_80032824)
    /* 16FA0 800267A0 2428428C */  lw         $v0, %lo(D_80032824)($v0)
    /* 16FA4 800267A4 0800E003 */  jr         $ra
    /* 16FA8 800267A8 00000000 */   nop
endlabel ER_active
