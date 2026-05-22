nonmatching func_800BA3E4, 0x20

glabel func_800BA3E4
    /* 51BE4 800BA3E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51BE8 800BA3E8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51BEC 800BA3EC 7017010C */  jal        func_80045DC0
    /* 51BF0 800BA3F0 00000000 */   nop
    /* 51BF4 800BA3F4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51BF8 800BA3F8 21100000 */  addu       $v0, $zero, $zero
    /* 51BFC 800BA3FC 0800E003 */  jr         $ra
    /* 51C00 800BA400 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA3E4
