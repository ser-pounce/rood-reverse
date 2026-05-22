nonmatching func_8007C348, 0x24

glabel func_8007C348
    /* 13B48 8007C348 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 13B4C 8007C34C 2130A000 */  addu       $a2, $a1, $zero
    /* 13B50 8007C350 1000BFAF */  sw         $ra, 0x10($sp)
    /* 13B54 8007C354 C57C020C */  jal        func_8009F314
    /* 13B58 8007C358 21280000 */   addu      $a1, $zero, $zero
    /* 13B5C 8007C35C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 13B60 8007C360 00000000 */  nop
    /* 13B64 8007C364 0800E003 */  jr         $ra
    /* 13B68 8007C368 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007C348
