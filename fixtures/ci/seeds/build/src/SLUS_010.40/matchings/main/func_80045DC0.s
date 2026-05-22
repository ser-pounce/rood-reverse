nonmatching func_80045DC0, 0x20

glabel func_80045DC0
    /* 365C0 80045DC0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 365C4 80045DC4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 365C8 80045DC8 E64A000C */  jal        func_80012B98
    /* 365CC 80045DCC 00000000 */   nop
    /* 365D0 80045DD0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 365D4 80045DD4 00000000 */  nop
    /* 365D8 80045DD8 0800E003 */  jr         $ra
    /* 365DC 80045DDC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80045DC0
