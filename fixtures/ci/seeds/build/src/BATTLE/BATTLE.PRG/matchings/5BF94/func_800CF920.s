nonmatching func_800CF920, 0xC

glabel func_800CF920
    /* 67120 800CF920 0F80023C */  lui        $v0, %hi(D_800F522C)
    /* 67124 800CF924 0800E003 */  jr         $ra
    /* 67128 800CF928 2C5240A0 */   sb        $zero, %lo(D_800F522C)($v0)
endlabel func_800CF920
