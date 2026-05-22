nonmatching func_8006C4A4, 0x20

glabel func_8006C4A4
    /* 3CA4 8006C4A4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3CA8 8006C4A8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3CAC 8006C4AC 0C3E030C */  jal        func_800CF830
    /* 3CB0 8006C4B0 00000000 */   nop
    /* 3CB4 8006C4B4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3CB8 8006C4B8 00000000 */  nop
    /* 3CBC 8006C4BC 0800E003 */  jr         $ra
    /* 3CC0 8006C4C0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006C4A4
