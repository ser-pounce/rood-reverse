nonmatching func_8007DDD4, 0x24

glabel func_8007DDD4
    /* 155D4 8007DDD4 0F80023C */  lui        $v0, %hi(D_800F1A78)
    /* 155D8 8007DDD8 781A4724 */  addiu      $a3, $v0, %lo(D_800F1A78)
    /* 155DC 8007DDDC 03008388 */  lwl        $v1, 0x3($a0)
    /* 155E0 8007DDE0 00008398 */  lwr        $v1, 0x0($a0)
    /* 155E4 8007DDE4 00000000 */  nop
    /* 155E8 8007DDE8 0300E3A8 */  swl        $v1, 0x3($a3)
    /* 155EC 8007DDEC 0000E3B8 */  swr        $v1, 0x0($a3)
    /* 155F0 8007DDF0 0800E003 */  jr         $ra
    /* 155F4 8007DDF4 00000000 */   nop
endlabel func_8007DDD4
