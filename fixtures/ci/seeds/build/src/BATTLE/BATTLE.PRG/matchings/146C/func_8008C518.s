nonmatching func_8008C518, 0x20

glabel func_8008C518
    /* 23D18 8008C518 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 23D1C 8008C51C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 23D20 8008C520 2731020C */  jal        func_8008C49C
    /* 23D24 8008C524 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 23D28 8008C528 1000BF8F */  lw         $ra, 0x10($sp)
    /* 23D2C 8008C52C 00000000 */  nop
    /* 23D30 8008C530 0800E003 */  jr         $ra
    /* 23D34 8008C534 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008C518
