nonmatching func_80012B78, 0x20

glabel func_80012B78
    /* 3378 80012B78 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 337C 80012B7C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3380 80012B80 0C63000C */  jal        func_80018C30
    /* 3384 80012B84 F0000424 */   addiu     $a0, $zero, 0xF0
    /* 3388 80012B88 1000BF8F */  lw         $ra, 0x10($sp)
    /* 338C 80012B8C 00000000 */  nop
    /* 3390 80012B90 0800E003 */  jr         $ra
    /* 3394 80012B94 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012B78
