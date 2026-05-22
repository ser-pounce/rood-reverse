nonmatching func_800D6E24, 0x20

glabel func_800D6E24
    /* 6E624 800D6E24 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6E628 800D6E28 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6E62C 800D6E2C 915B030C */  jal        func_800D6E44
    /* 6E630 800D6E30 00000000 */   nop
    /* 6E634 800D6E34 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6E638 800D6E38 00000000 */  nop
    /* 6E63C 800D6E3C 0800E003 */  jr         $ra
    /* 6E640 800D6E40 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D6E24
