nonmatching func_80083F2C, 0x24

glabel func_80083F2C
    /* 1B72C 80083F2C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B730 80083F30 15000424 */  addiu      $a0, $zero, 0x15
    /* 1B734 80083F34 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1B738 80083F38 0804020C */  jal        func_80081020
    /* 1B73C 80083F3C 2128C000 */   addu      $a1, $a2, $zero
    /* 1B740 80083F40 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1B744 80083F44 00000000 */  nop
    /* 1B748 80083F48 0800E003 */  jr         $ra
    /* 1B74C 80083F4C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083F2C
