nonmatching func_800AA600, 0x20

glabel func_800AA600
    /* 41E00 800AA600 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 41E04 800AA604 1000BFAF */  sw         $ra, 0x10($sp)
    /* 41E08 800AA608 A6A9020C */  jal        func_800AA698
    /* 41E0C 800AA60C 00000000 */   nop
    /* 41E10 800AA610 1000BF8F */  lw         $ra, 0x10($sp)
    /* 41E14 800AA614 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 41E18 800AA618 0800E003 */  jr         $ra
    /* 41E1C 800AA61C 00000000 */   nop
endlabel func_800AA600
