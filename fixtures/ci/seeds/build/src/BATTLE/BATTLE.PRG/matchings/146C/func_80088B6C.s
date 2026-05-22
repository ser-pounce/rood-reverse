nonmatching func_80088B6C, 0x20

glabel func_80088B6C
    /* 2036C 80088B6C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 20370 80088B70 1000BFAF */  sw         $ra, 0x10($sp)
    /* 20374 80088B74 5521020C */  jal        func_80088554
    /* 20378 80088B78 00000000 */   nop
    /* 2037C 80088B7C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 20380 80088B80 00000000 */  nop
    /* 20384 80088B84 0800E003 */  jr         $ra
    /* 20388 80088B88 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80088B6C
