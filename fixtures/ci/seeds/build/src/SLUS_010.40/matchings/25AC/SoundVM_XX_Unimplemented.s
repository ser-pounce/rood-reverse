nonmatching SoundVM_XX_Unimplemented, 0x20

glabel SoundVM_XX_Unimplemented
    /* D52C 8001CD2C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* D530 8001CD30 1000BFAF */  sw         $ra, 0x10($sp)
    /* D534 8001CD34 4E6C000C */  jal        SoundVM_A0_FinishChannel
    /* D538 8001CD38 00000000 */   nop
    /* D53C 8001CD3C 1000BF8F */  lw         $ra, 0x10($sp)
    /* D540 8001CD40 00000000 */  nop
    /* D544 8001CD44 0800E003 */  jr         $ra
    /* D548 8001CD48 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SoundVM_XX_Unimplemented
