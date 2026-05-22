nonmatching PadStopCom, 0x20

glabel PadStopCom
    /* 1C024 8002B824 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C028 8002B828 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1C02C 8002B82C 30B0000C */  jal        _padStopCom
    /* 1C030 8002B830 00000000 */   nop
    /* 1C034 8002B834 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1C038 8002B838 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1C03C 8002B83C 0800E003 */  jr         $ra
    /* 1C040 8002B840 00000000 */   nop
endlabel PadStopCom
