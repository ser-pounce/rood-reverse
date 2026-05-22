nonmatching func_80083D08, 0x24

glabel func_80083D08
    /* 1B508 80083D08 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B50C 80083D0C 12000424 */  addiu      $a0, $zero, 0x12
    /* 1B510 80083D10 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1B514 80083D14 0804020C */  jal        func_80081020
    /* 1B518 80083D18 2128C000 */   addu      $a1, $a2, $zero
    /* 1B51C 80083D1C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1B520 80083D20 00000000 */  nop
    /* 1B524 80083D24 0800E003 */  jr         $ra
    /* 1B528 80083D28 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083D08
