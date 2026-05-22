nonmatching func_8007BEE4, 0x20

glabel func_8007BEE4
    /* 136E4 8007BEE4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 136E8 8007BEE8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 136EC 8007BEEC 233D030C */  jal        func_800CF48C
    /* 136F0 8007BEF0 00000000 */   nop
    /* 136F4 8007BEF4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 136F8 8007BEF8 00000000 */  nop
    /* 136FC 8007BEFC 0800E003 */  jr         $ra
    /* 13700 8007BF00 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007BEE4
