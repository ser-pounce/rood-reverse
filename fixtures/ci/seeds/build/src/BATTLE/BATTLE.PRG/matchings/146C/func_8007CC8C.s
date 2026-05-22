nonmatching func_8007CC8C, 0x20

glabel func_8007CC8C
    /* 1448C 8007CC8C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14490 8007CC90 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14494 8007CC94 E873020C */  jal        func_8009CFA0
    /* 14498 8007CC98 00000000 */   nop
    /* 1449C 8007CC9C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 144A0 8007CCA0 00000000 */  nop
    /* 144A4 8007CCA4 0800E003 */  jr         $ra
    /* 144A8 8007CCA8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007CC8C
