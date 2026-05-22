nonmatching func_80083FBC, 0x24

glabel func_80083FBC
    /* 1B7BC 80083FBC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B7C0 80083FC0 19000424 */  addiu      $a0, $zero, 0x19
    /* 1B7C4 80083FC4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1B7C8 80083FC8 0804020C */  jal        func_80081020
    /* 1B7CC 80083FCC 2128C000 */   addu      $a1, $a2, $zero
    /* 1B7D0 80083FD0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1B7D4 80083FD4 00000000 */  nop
    /* 1B7D8 80083FD8 0800E003 */  jr         $ra
    /* 1B7DC 80083FDC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083FBC
