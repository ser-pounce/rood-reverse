nonmatching func_800BB33C, 0x20

glabel func_800BB33C
    /* 52B3C 800BB33C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52B40 800BB340 1000BFAF */  sw         $ra, 0x10($sp)
    /* 52B44 800BB344 E8F8020C */  jal        func_800BE3A0
    /* 52B48 800BB348 00000000 */   nop
    /* 52B4C 800BB34C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 52B50 800BB350 21100000 */  addu       $v0, $zero, $zero
    /* 52B54 800BB354 0800E003 */  jr         $ra
    /* 52B58 800BB358 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BB33C
