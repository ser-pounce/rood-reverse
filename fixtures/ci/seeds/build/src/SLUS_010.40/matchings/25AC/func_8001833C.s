nonmatching func_8001833C, 0x1C

glabel func_8001833C
    /* 8B3C 8001833C 00008280 */  lb         $v0, 0x0($a0)
    /* 8B40 80018340 0380033C */  lui        $v1, %hi(D_80036782)
    /* 8B44 80018344 826760A4 */  sh         $zero, %lo(D_80036782)($v1)
    /* 8B48 80018348 0480033C */  lui        $v1, %hi(g_Sound_TempoMultiplier)
    /* 8B4C 8001834C 00140200 */  sll        $v0, $v0, 16
    /* 8B50 80018350 0800E003 */  jr         $ra
    /* 8B54 80018354 F09A62AC */   sw        $v0, %lo(g_Sound_TempoMultiplier)($v1)
endlabel func_8001833C
