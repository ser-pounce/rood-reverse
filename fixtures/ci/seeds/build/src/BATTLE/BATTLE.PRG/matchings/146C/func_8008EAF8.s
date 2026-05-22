nonmatching func_8008EAF8, 0xC

glabel func_8008EAF8
    /* 262F8 8008EAF8 0F80023C */  lui        $v0, %hi(D_800F1DC9)
    /* 262FC 8008EAFC 0800E003 */  jr         $ra
    /* 26300 8008EB00 C91D44A0 */   sb        $a0, %lo(D_800F1DC9)($v0)
endlabel func_8008EAF8
