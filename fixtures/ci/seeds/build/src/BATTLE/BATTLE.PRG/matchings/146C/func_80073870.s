nonmatching func_80073870, 0x28

glabel func_80073870
    /* B070 80073870 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B074 80073874 1000BFAF */  sw         $ra, 0x10($sp)
    /* B078 80073878 0CFB020C */  jal        func_800BEC30
    /* B07C 8007387C 00000000 */   nop
    /* B080 80073880 C6CD010C */  jal        func_80073718
    /* B084 80073884 00000000 */   nop
    /* B088 80073888 1000BF8F */  lw         $ra, 0x10($sp)
    /* B08C 8007388C 00000000 */  nop
    /* B090 80073890 0800E003 */  jr         $ra
    /* B094 80073894 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80073870
