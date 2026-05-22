nonmatching func_8007CC4C, 0x20

glabel func_8007CC4C
    /* 1444C 8007CC4C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14450 8007CC50 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14454 8007CC54 8274020C */  jal        func_8009D208
    /* 14458 8007CC58 00000000 */   nop
    /* 1445C 8007CC5C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 14460 8007CC60 00000000 */  nop
    /* 14464 8007CC64 0800E003 */  jr         $ra
    /* 14468 8007CC68 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007CC4C
