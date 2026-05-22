nonmatching func_80084028, 0x24

glabel func_80084028
    /* 1B828 80084028 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B82C 8008402C 1C000424 */  addiu      $a0, $zero, 0x1C
    /* 1B830 80084030 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1B834 80084034 0804020C */  jal        func_80081020
    /* 1B838 80084038 2128C000 */   addu      $a1, $a2, $zero
    /* 1B83C 8008403C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1B840 80084040 00000000 */  nop
    /* 1B844 80084044 0800E003 */  jr         $ra
    /* 1B848 80084048 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80084028
