nonmatching func_800CB660, 0xC

glabel func_800CB660
    /* 62E60 800CB660 0F80023C */  lui        $v0, %hi(D_800EB9CC)
    /* 62E64 800CB664 0800E003 */  jr         $ra
    /* 62E68 800CB668 CCB944A0 */   sb        $a0, %lo(D_800EB9CC)($v0)
endlabel func_800CB660
