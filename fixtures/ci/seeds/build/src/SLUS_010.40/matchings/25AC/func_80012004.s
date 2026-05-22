nonmatching func_80012004, 0x20

glabel func_80012004
    /* 2804 80012004 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2808 80012008 1000BFAF */  sw         $ra, 0x10($sp)
    /* 280C 8001200C 0C63000C */  jal        func_80018C30
    /* 2810 80012010 40000424 */   addiu     $a0, $zero, 0x40
    /* 2814 80012014 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2818 80012018 00000000 */  nop
    /* 281C 8001201C 0800E003 */  jr         $ra
    /* 2820 80012020 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012004
