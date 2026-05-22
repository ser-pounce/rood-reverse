nonmatching func_80018434, 0x1C

glabel func_80018434
    /* 8C34 80018434 00008280 */  lb         $v0, 0x0($a0)
    /* 8C38 80018438 0380033C */  lui        $v1, %hi(D_80036780)
    /* 8C3C 8001843C 806760A4 */  sh         $zero, %lo(D_80036780)($v1)
    /* 8C40 80018440 0480033C */  lui        $v1, %hi(g_Sound_MasterPitchScaleQ16_16)
    /* 8C44 80018444 00140200 */  sll        $v0, $v0, 16
    /* 8C48 80018448 0800E003 */  jr         $ra
    /* 8C4C 8001844C EC9A62AC */   sw        $v0, %lo(g_Sound_MasterPitchScaleQ16_16)($v1)
endlabel func_80018434
