nonmatching func_80108098, 0x30

glabel func_80108098
    /* 5898 80108098 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 589C 8010809C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 58A0 801080A0 EC73020C */  jal        func_8009CFB0
    /* 58A4 801080A4 01000424 */   addiu     $a0, $zero, 0x1
    /* 58A8 801080A8 EC73020C */  jal        func_8009CFB0
    /* 58AC 801080AC 10000424 */   addiu     $a0, $zero, 0x10
    /* 58B0 801080B0 3921040C */  jal        func_801084E4
    /* 58B4 801080B4 00000000 */   nop
    /* 58B8 801080B8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 58BC 801080BC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 58C0 801080C0 0800E003 */  jr         $ra
    /* 58C4 801080C4 00000000 */   nop
endlabel func_80108098
