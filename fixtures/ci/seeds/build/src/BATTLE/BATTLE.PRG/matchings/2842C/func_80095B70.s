nonmatching func_80095B70, 0xC

glabel func_80095B70
    /* 2D370 80095B70 0F80023C */  lui        $v0, %hi(D_800F2270)
    /* 2D374 80095B74 0800E003 */  jr         $ra
    /* 2D378 80095B78 702244A4 */   sh        $a0, %lo(D_800F2270)($v0)
endlabel func_80095B70
