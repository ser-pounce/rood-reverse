nonmatching DecDCTout, 0x20

glabel DecDCTout
    /* 9770 80071F70 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 9774 80071F74 1000BFAF */  sw         $ra, 0x10($sp)
    /* 9778 80071F78 74C8010C */  jal        func_800721D0
    /* 977C 80071F7C 00000000 */   nop
    /* 9780 80071F80 1000BF8F */  lw         $ra, 0x10($sp)
    /* 9784 80071F84 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 9788 80071F88 0800E003 */  jr         $ra
    /* 978C 80071F8C 00000000 */   nop
endlabel DecDCTout
