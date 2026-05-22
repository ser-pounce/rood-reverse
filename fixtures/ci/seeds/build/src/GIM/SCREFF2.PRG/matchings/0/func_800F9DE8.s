nonmatching func_800F9DE8, 0x10

glabel func_800F9DE8
    /* 5E8 800F9DE8 0F80023C */  lui        $v0, %hi(D_800EB9B4)
    /* 5EC 800F9DEC B4B9428C */  lw         $v0, %lo(D_800EB9B4)($v0)
    /* 5F0 800F9DF0 0800E003 */  jr         $ra
    /* 5F4 800F9DF4 080044AC */   sw        $a0, 0x8($v0)
endlabel func_800F9DE8
