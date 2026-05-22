nonmatching func_80083F74, 0x24

glabel func_80083F74
    /* 1B774 80083F74 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B778 80083F78 17000424 */  addiu      $a0, $zero, 0x17
    /* 1B77C 80083F7C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1B780 80083F80 0804020C */  jal        func_80081020
    /* 1B784 80083F84 2128C000 */   addu      $a1, $a2, $zero
    /* 1B788 80083F88 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1B78C 80083F8C 00000000 */  nop
    /* 1B790 80083F90 0800E003 */  jr         $ra
    /* 1B794 80083F94 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083F74
