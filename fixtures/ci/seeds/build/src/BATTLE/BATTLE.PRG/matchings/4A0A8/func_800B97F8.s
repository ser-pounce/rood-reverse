nonmatching func_800B97F8, 0x20

glabel func_800B97F8
    /* 50FF8 800B97F8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 50FFC 800B97FC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51000 800B9800 C7F0010C */  jal        func_8007C31C
    /* 51004 800B9804 00000000 */   nop
    /* 51008 800B9808 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5100C 800B980C 21100000 */  addu       $v0, $zero, $zero
    /* 51010 800B9810 0800E003 */  jr         $ra
    /* 51014 800B9814 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B97F8
