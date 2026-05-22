nonmatching CdReady, 0x20

glabel CdReady
    /* 10D18 80020518 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 10D1C 8002051C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 10D20 80020520 6A84000C */  jal        CD_ready
    /* 10D24 80020524 00000000 */   nop
    /* 10D28 80020528 1000BF8F */  lw         $ra, 0x10($sp)
    /* 10D2C 8002052C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 10D30 80020530 0800E003 */  jr         $ra
    /* 10D34 80020534 00000000 */   nop
endlabel CdReady
