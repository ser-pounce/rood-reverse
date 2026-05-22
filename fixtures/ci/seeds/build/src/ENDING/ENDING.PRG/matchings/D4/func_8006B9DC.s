nonmatching func_8006B9DC, 0x20

glabel func_8006B9DC
    /* 31DC 8006B9DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 31E0 8006B9E0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 31E4 8006B9E4 8E12010C */  jal        vs_main_checkStreamXaEnd
    /* 31E8 8006B9E8 00000000 */   nop
    /* 31EC 8006B9EC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 31F0 8006B9F0 00000000 */  nop
    /* 31F4 8006B9F4 0800E003 */  jr         $ra
    /* 31F8 8006B9F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006B9DC
