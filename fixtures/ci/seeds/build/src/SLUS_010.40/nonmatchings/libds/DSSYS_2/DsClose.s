nonmatching DsClose, 0x20

glabel DsClose
    /* 14314 80023B14 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14318 80023B18 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1431C 80023B1C 0392000C */  jal        func_8002480C
    /* 14320 80023B20 00000000 */   nop
    /* 14324 80023B24 1000BF8F */  lw         $ra, 0x10($sp)
    /* 14328 80023B28 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1432C 80023B2C 0800E003 */  jr         $ra
    /* 14330 80023B30 00000000 */   nop
endlabel DsClose
