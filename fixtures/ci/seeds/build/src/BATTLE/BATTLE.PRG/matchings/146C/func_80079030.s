nonmatching func_80079030, 0x20

glabel func_80079030
    /* 10830 80079030 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 10834 80079034 1000BFAF */  sw         $ra, 0x10($sp)
    /* 10838 80079038 E3C4010C */  jal        func_8007138C
    /* 1083C 8007903C 00000000 */   nop
    /* 10840 80079040 1000BF8F */  lw         $ra, 0x10($sp)
    /* 10844 80079044 00000000 */  nop
    /* 10848 80079048 0800E003 */  jr         $ra
    /* 1084C 8007904C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80079030
