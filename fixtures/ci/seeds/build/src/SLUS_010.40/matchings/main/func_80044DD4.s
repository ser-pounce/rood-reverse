nonmatching func_80044DD4, 0x20

glabel func_80044DD4
    /* 355D4 80044DD4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 355D8 80044DD8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 355DC 80044DDC 1A49000C */  jal        func_80012468
    /* 355E0 80044DE0 00000000 */   nop
    /* 355E4 80044DE4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 355E8 80044DE8 00000000 */  nop
    /* 355EC 80044DEC 0800E003 */  jr         $ra
    /* 355F0 80044DF0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80044DD4
