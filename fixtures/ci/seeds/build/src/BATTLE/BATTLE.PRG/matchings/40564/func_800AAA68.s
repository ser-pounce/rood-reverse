nonmatching func_800AAA68, 0x20

glabel func_800AAA68
    /* 42268 800AAA68 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4226C 800AAA6C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 42270 800AAA70 A2AA020C */  jal        func_800AAA88
    /* 42274 800AAA74 00000000 */   nop
    /* 42278 800AAA78 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4227C 800AAA7C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 42280 800AAA80 0800E003 */  jr         $ra
    /* 42284 800AAA84 00000000 */   nop
endlabel func_800AAA68
