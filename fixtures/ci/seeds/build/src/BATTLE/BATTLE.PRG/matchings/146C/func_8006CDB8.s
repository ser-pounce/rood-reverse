nonmatching func_8006CDB8, 0x20

glabel func_8006CDB8
    /* 45B8 8006CDB8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 45BC 8006CDBC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 45C0 8006CDC0 1576020C */  jal        func_8009D854
    /* 45C4 8006CDC4 00000000 */   nop
    /* 45C8 8006CDC8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 45CC 8006CDCC 00000000 */  nop
    /* 45D0 8006CDD0 0800E003 */  jr         $ra
    /* 45D4 8006CDD4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006CDB8
