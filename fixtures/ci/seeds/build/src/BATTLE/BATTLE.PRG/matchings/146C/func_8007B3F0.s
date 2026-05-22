nonmatching func_8007B3F0, 0x20

glabel func_8007B3F0
    /* 12BF0 8007B3F0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 12BF4 8007B3F4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 12BF8 8007B3F8 B41C010C */  jal        func_800472D0
    /* 12BFC 8007B3FC 00000000 */   nop
    /* 12C00 8007B400 1000BF8F */  lw         $ra, 0x10($sp)
    /* 12C04 8007B404 00000000 */  nop
    /* 12C08 8007B408 0800E003 */  jr         $ra
    /* 12C0C 8007B40C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007B3F0
