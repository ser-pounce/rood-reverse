nonmatching func_800F9BC0, 0x18

glabel func_800F9BC0
    /* 3C0 800F9BC0 0F80023C */  lui        $v0, %hi(D_800EB9B4)
    /* 3C4 800F9BC4 B4B9428C */  lw         $v0, %lo(D_800EB9B4)($v0)
    /* 3C8 800F9BC8 00000000 */  nop
    /* 3CC 800F9BCC 040044A4 */  sh         $a0, 0x4($v0)
    /* 3D0 800F9BD0 0800E003 */  jr         $ra
    /* 3D4 800F9BD4 060045A4 */   sh        $a1, 0x6($v0)
endlabel func_800F9BC0
