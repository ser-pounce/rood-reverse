nonmatching func_80012B98, 0x20

glabel func_80012B98
    /* 3398 80012B98 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 339C 80012B9C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 33A0 80012BA0 0C63000C */  jal        func_80018C30
    /* 33A4 80012BA4 F1000424 */   addiu     $a0, $zero, 0xF1
    /* 33A8 80012BA8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 33AC 80012BAC 00000000 */  nop
    /* 33B0 80012BB0 0800E003 */  jr         $ra
    /* 33B4 80012BB4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012B98
