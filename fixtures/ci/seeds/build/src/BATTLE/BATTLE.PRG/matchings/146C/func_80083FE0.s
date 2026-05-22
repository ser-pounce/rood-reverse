nonmatching func_80083FE0, 0x24

glabel func_80083FE0
    /* 1B7E0 80083FE0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B7E4 80083FE4 1A000424 */  addiu      $a0, $zero, 0x1A
    /* 1B7E8 80083FE8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1B7EC 80083FEC 0804020C */  jal        func_80081020
    /* 1B7F0 80083FF0 2128C000 */   addu      $a1, $a2, $zero
    /* 1B7F4 80083FF4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1B7F8 80083FF8 00000000 */  nop
    /* 1B7FC 80083FFC 0800E003 */  jr         $ra
    /* 1B800 80084000 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083FE0
