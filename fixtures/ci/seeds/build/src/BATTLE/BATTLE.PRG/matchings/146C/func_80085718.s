nonmatching func_80085718, 0x34

glabel func_80085718
    /* 1CF18 80085718 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1CF1C 8008571C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1CF20 80085720 21808000 */  addu       $s0, $a0, $zero
    /* 1CF24 80085724 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1CF28 80085728 4424010C */  jal        vs_main_bzero
    /* 1CF2C 8008572C 44000524 */   addiu     $a1, $zero, 0x44
    /* 1CF30 80085730 06000224 */  addiu      $v0, $zero, 0x6
    /* 1CF34 80085734 030002A2 */  sb         $v0, 0x3($s0)
    /* 1CF38 80085738 1C0000AE */  sw         $zero, 0x1C($s0)
    /* 1CF3C 8008573C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1CF40 80085740 1000B08F */  lw         $s0, 0x10($sp)
    /* 1CF44 80085744 0800E003 */  jr         $ra
    /* 1CF48 80085748 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80085718
