nonmatching func_8007BBB8, 0x20

glabel func_8007BBB8
    /* 133B8 8007BBB8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 133BC 8007BBBC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 133C0 8007BBC0 7BA7010C */  jal        func_80069DEC
    /* 133C4 8007BBC4 00000000 */   nop
    /* 133C8 8007BBC8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 133CC 8007BBCC 00000000 */  nop
    /* 133D0 8007BBD0 0800E003 */  jr         $ra
    /* 133D4 8007BBD4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007BBB8
