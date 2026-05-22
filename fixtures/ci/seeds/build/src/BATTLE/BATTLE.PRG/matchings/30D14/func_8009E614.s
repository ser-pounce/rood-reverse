nonmatching func_8009E614, 0x20

glabel func_8009E614
    /* 35E14 8009E614 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35E18 8009E618 1000BFAF */  sw         $ra, 0x10($sp)
    /* 35E1C 8009E61C C079020C */  jal        func_8009E700
    /* 35E20 8009E620 06000524 */   addiu     $a1, $zero, 0x6
    /* 35E24 8009E624 1000BF8F */  lw         $ra, 0x10($sp)
    /* 35E28 8009E628 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 35E2C 8009E62C 0800E003 */  jr         $ra
    /* 35E30 8009E630 00000000 */   nop
endlabel func_8009E614
