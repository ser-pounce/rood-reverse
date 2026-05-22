nonmatching func_8007C424, 0x20

glabel func_8007C424
    /* 13C24 8007C424 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 13C28 8007C428 1000BFAF */  sw         $ra, 0x10($sp)
    /* 13C2C 8007C42C 4127020C */  jal        func_80089D04
    /* 13C30 8007C430 00000000 */   nop
    /* 13C34 8007C434 1000BF8F */  lw         $ra, 0x10($sp)
    /* 13C38 8007C438 00000000 */  nop
    /* 13C3C 8007C43C 0800E003 */  jr         $ra
    /* 13C40 8007C440 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007C424
