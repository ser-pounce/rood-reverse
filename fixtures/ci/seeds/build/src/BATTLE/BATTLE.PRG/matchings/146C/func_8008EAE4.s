nonmatching func_8008EAE4, 0x14

glabel func_8008EAE4
    /* 262E4 8008EAE4 0F80023C */  lui        $v0, %hi(D_800F1DB8)
    /* 262E8 8008EAE8 B81D44A4 */  sh         $a0, %lo(D_800F1DB8)($v0)
    /* 262EC 8008EAEC 0F80023C */  lui        $v0, %hi(D_800F1DBA)
    /* 262F0 8008EAF0 0800E003 */  jr         $ra
    /* 262F4 8008EAF4 BA1D45A4 */   sh        $a1, %lo(D_800F1DBA)($v0)
endlabel func_8008EAE4
