nonmatching func_80046578, 0x24

glabel func_80046578
    /* 36D78 80046578 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 36D7C 8004657C 80000524 */  addiu      $a1, $zero, 0x80
    /* 36D80 80046580 1000BFAF */  sw         $ra, 0x10($sp)
    /* 36D84 80046584 3F19010C */  jal        func_800464FC
    /* 36D88 80046588 7F000624 */   addiu     $a2, $zero, 0x7F
    /* 36D8C 8004658C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 36D90 80046590 00000000 */  nop
    /* 36D94 80046594 0800E003 */  jr         $ra
    /* 36D98 80046598 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80046578
