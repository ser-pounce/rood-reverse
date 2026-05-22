nonmatching func_8007CBBC, 0x20

glabel func_8007CBBC
    /* 143BC 8007CBBC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 143C0 8007CBC0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 143C4 8007CBC4 0873020C */  jal        func_8009CC20
    /* 143C8 8007CBC8 01000524 */   addiu     $a1, $zero, 0x1
    /* 143CC 8007CBCC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 143D0 8007CBD0 00000000 */  nop
    /* 143D4 8007CBD4 0800E003 */  jr         $ra
    /* 143D8 8007CBD8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007CBBC
