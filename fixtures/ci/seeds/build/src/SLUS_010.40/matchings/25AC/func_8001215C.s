nonmatching func_8001215C, 0x20

glabel func_8001215C
    /* 295C 8001215C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2960 80012160 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2964 80012164 0C63000C */  jal        func_80018C30
    /* 2968 80012168 17000424 */   addiu     $a0, $zero, 0x17
    /* 296C 8001216C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2970 80012170 00000000 */  nop
    /* 2974 80012174 0800E003 */  jr         $ra
    /* 2978 80012178 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001215C
