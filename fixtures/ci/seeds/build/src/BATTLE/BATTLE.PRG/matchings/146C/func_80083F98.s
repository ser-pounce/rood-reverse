nonmatching func_80083F98, 0x24

glabel func_80083F98
    /* 1B798 80083F98 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B79C 80083F9C 18000424 */  addiu      $a0, $zero, 0x18
    /* 1B7A0 80083FA0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1B7A4 80083FA4 0804020C */  jal        func_80081020
    /* 1B7A8 80083FA8 2128C000 */   addu      $a1, $a2, $zero
    /* 1B7AC 80083FAC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1B7B0 80083FB0 00000000 */  nop
    /* 1B7B4 80083FB4 0800E003 */  jr         $ra
    /* 1B7B8 80083FB8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083F98
