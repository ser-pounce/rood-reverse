nonmatching func_80044D94, 0x20

glabel func_80044D94
    /* 35594 80044D94 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35598 80044D98 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3559C 80044D9C E447000C */  jal        func_80011F90
    /* 355A0 80044DA0 00000000 */   nop
    /* 355A4 80044DA4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 355A8 80044DA8 00000000 */  nop
    /* 355AC 80044DAC 0800E003 */  jr         $ra
    /* 355B0 80044DB0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80044D94
