nonmatching func_8002A2D4, 0x24

glabel func_8002A2D4
    /* 1AAD4 8002A2D4 0380023C */  lui        $v0, %hi(D_8003354C)
    /* 1AAD8 8002A2D8 4C35428C */  lw         $v0, %lo(D_8003354C)($v0)
    /* 1AADC 8002A2DC 00000000 */  nop
    /* 1AAE0 8002A2E0 000044AC */  sw         $a0, 0x0($v0)
    /* 1AAE4 8002A2E4 02160400 */  srl        $v0, $a0, 24
    /* 1AAE8 8002A2E8 0480013C */  lui        $at, %hi(D_8003E2F8)
    /* 1AAEC 8002A2EC 21082200 */  addu       $at, $at, $v0
    /* 1AAF0 8002A2F0 0800E003 */  jr         $ra
    /* 1AAF4 8002A2F4 F8E224A0 */   sb        $a0, %lo(D_8003E2F8)($at)
endlabel func_8002A2D4
