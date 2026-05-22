nonmatching func_8006B910, 0x20

glabel func_8006B910
    /* 3110 8006B910 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3114 8006B914 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3118 8006B918 D8AD010C */  jal        func_8006B760
    /* 311C 8006B91C 00000000 */   nop
    /* 3120 8006B920 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3124 8006B924 00000000 */  nop
    /* 3128 8006B928 0800E003 */  jr         $ra
    /* 312C 8006B92C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006B910
