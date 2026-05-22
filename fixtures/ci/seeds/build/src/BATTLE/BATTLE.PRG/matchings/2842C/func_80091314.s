nonmatching func_80091314, 0xC

glabel func_80091314
    /* 28B14 80091314 0F80023C */  lui        $v0, %hi(D_800F1DCB)
    /* 28B18 80091318 0800E003 */  jr         $ra
    /* 28B1C 8009131C CB1D44A0 */   sb        $a0, %lo(D_800F1DCB)($v0)
endlabel func_80091314
