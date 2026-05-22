nonmatching func_80084004, 0x24

glabel func_80084004
    /* 1B804 80084004 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B808 80084008 1B000424 */  addiu      $a0, $zero, 0x1B
    /* 1B80C 8008400C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1B810 80084010 0804020C */  jal        func_80081020
    /* 1B814 80084014 2128C000 */   addu      $a1, $a2, $zero
    /* 1B818 80084018 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1B81C 8008401C 00000000 */  nop
    /* 1B820 80084020 0800E003 */  jr         $ra
    /* 1B824 80084024 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80084004
