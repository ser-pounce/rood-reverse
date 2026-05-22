nonmatching SetIntrMask, 0x18

glabel SetIntrMask
    /* 10250 8001FA50 0380033C */  lui        $v1, %hi(D_800320DC)
    /* 10254 8001FA54 DC20638C */  lw         $v1, %lo(D_800320DC)($v1)
    /* 10258 8001FA58 00000000 */  nop
    /* 1025C 8001FA5C 00006294 */  lhu        $v0, 0x0($v1)
    /* 10260 8001FA60 0800E003 */  jr         $ra
    /* 10264 8001FA64 000064A4 */   sh        $a0, 0x0($v1)
endlabel SetIntrMask
