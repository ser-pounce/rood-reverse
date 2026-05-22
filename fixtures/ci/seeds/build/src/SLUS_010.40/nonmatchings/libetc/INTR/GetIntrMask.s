nonmatching GetIntrMask, 0x18

glabel GetIntrMask
    /* 10238 8001FA38 0380023C */  lui        $v0, %hi(D_800320DC)
    /* 1023C 8001FA3C DC20428C */  lw         $v0, %lo(D_800320DC)($v0)
    /* 10240 8001FA40 00000000 */  nop
    /* 10244 8001FA44 00004294 */  lhu        $v0, 0x0($v0)
    /* 10248 8001FA48 0800E003 */  jr         $ra
    /* 1024C 8001FA4C 00000000 */   nop
endlabel GetIntrMask
