nonmatching func_800BA72C, 0x20

glabel func_800BA72C
    /* 51F2C 800BA72C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51F30 800BA730 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51F34 800BA734 6D13010C */  jal        func_80044DB4
    /* 51F38 800BA738 00000000 */   nop
    /* 51F3C 800BA73C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51F40 800BA740 21100000 */  addu       $v0, $zero, $zero
    /* 51F44 800BA744 0800E003 */  jr         $ra
    /* 51F48 800BA748 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA72C
