nonmatching func_800CB560, 0xC

glabel func_800CB560
    /* 62D60 800CB560 0F80023C */  lui        $v0, %hi(D_800F4E90)
    /* 62D64 800CB564 0800E003 */  jr         $ra
    /* 62D68 800CB568 904E40A0 */   sb        $zero, %lo(D_800F4E90)($v0)
endlabel func_800CB560
