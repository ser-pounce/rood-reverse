nonmatching func_8004550C, 0x20

glabel func_8004550C
    /* 35D0C 8004550C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35D10 80045510 1000BFAF */  sw         $ra, 0x10($sp)
    /* 35D14 80045514 2E15010C */  jal        func_800454B8
    /* 35D18 80045518 00000000 */   nop
    /* 35D1C 8004551C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 35D20 80045520 00000000 */  nop
    /* 35D24 80045524 0800E003 */  jr         $ra
    /* 35D28 80045528 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004550C
