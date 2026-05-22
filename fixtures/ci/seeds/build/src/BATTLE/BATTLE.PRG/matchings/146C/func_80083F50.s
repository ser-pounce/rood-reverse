nonmatching func_80083F50, 0x24

glabel func_80083F50
    /* 1B750 80083F50 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B754 80083F54 16000424 */  addiu      $a0, $zero, 0x16
    /* 1B758 80083F58 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1B75C 80083F5C 0804020C */  jal        func_80081020
    /* 1B760 80083F60 2128C000 */   addu      $a1, $a2, $zero
    /* 1B764 80083F64 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1B768 80083F68 00000000 */  nop
    /* 1B76C 80083F6C 0800E003 */  jr         $ra
    /* 1B770 80083F70 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083F50
