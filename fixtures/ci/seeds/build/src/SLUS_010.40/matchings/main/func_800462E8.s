nonmatching func_800462E8, 0x28

glabel func_800462E8
    /* 36AE8 800462E8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 36AEC 800462EC 7F000224 */  addiu      $v0, $zero, 0x7F
    /* 36AF0 800462F0 80000724 */  addiu      $a3, $zero, 0x80
    /* 36AF4 800462F4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 36AF8 800462F8 7318010C */  jal        func_800461CC
    /* 36AFC 800462FC 1000A2AF */   sw        $v0, 0x10($sp)
    /* 36B00 80046300 1800BF8F */  lw         $ra, 0x18($sp)
    /* 36B04 80046304 00000000 */  nop
    /* 36B08 80046308 0800E003 */  jr         $ra
    /* 36B0C 8004630C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800462E8
