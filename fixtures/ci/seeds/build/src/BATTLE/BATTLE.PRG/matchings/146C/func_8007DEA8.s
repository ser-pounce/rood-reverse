nonmatching func_8007DEA8, 0x24

glabel func_8007DEA8
    /* 156A8 8007DEA8 0F80023C */  lui        $v0, %hi(D_800F1A78)
    /* 156AC 8007DEAC 781A4724 */  addiu      $a3, $v0, %lo(D_800F1A78)
    /* 156B0 8007DEB0 0300E388 */  lwl        $v1, 0x3($a3)
    /* 156B4 8007DEB4 0000E398 */  lwr        $v1, 0x0($a3)
    /* 156B8 8007DEB8 00000000 */  nop
    /* 156BC 8007DEBC 030083A8 */  swl        $v1, 0x3($a0)
    /* 156C0 8007DEC0 000083B8 */  swr        $v1, 0x0($a0)
    /* 156C4 8007DEC4 0800E003 */  jr         $ra
    /* 156C8 8007DEC8 00000000 */   nop
endlabel func_8007DEA8
