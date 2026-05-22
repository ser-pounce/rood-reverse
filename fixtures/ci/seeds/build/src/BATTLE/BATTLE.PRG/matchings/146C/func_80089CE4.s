nonmatching func_80089CE4, 0x20

glabel func_80089CE4
    /* 214E4 80089CE4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 214E8 80089CE8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 214EC 80089CEC 6EA1000C */  jal        SetDispMask
    /* 214F0 80089CF0 01000424 */   addiu     $a0, $zero, 0x1
    /* 214F4 80089CF4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 214F8 80089CF8 00000000 */  nop
    /* 214FC 80089CFC 0800E003 */  jr         $ra
    /* 21500 80089D00 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80089CE4
