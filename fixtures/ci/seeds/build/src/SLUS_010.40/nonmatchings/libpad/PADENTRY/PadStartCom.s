nonmatching PadStartCom, 0x20

glabel PadStartCom
    /* 1C004 8002B804 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C008 8002B808 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1C00C 8002B80C FDAF000C */  jal        _padStartCom
    /* 1C010 8002B810 00000000 */   nop
    /* 1C014 8002B814 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1C018 8002B818 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1C01C 8002B81C 0800E003 */  jr         $ra
    /* 1C020 8002B820 00000000 */   nop
endlabel PadStartCom
