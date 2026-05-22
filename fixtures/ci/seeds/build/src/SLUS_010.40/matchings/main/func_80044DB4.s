nonmatching func_80044DB4, 0x20

glabel func_80044DB4
    /* 355B4 80044DB4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 355B8 80044DB8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 355BC 80044DBC 0148000C */  jal        func_80012004
    /* 355C0 80044DC0 00000000 */   nop
    /* 355C4 80044DC4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 355C8 80044DC8 00000000 */  nop
    /* 355CC 80044DCC 0800E003 */  jr         $ra
    /* 355D0 80044DD0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80044DB4
