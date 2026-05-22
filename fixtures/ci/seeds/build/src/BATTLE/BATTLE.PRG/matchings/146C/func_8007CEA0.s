nonmatching func_8007CEA0, 0x20

glabel func_8007CEA0
    /* 146A0 8007CEA0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 146A4 8007CEA4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 146A8 8007CEA8 7179020C */  jal        func_8009E5C4
    /* 146AC 8007CEAC 00000000 */   nop
    /* 146B0 8007CEB0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 146B4 8007CEB4 00000000 */  nop
    /* 146B8 8007CEB8 0800E003 */  jr         $ra
    /* 146BC 8007CEBC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007CEA0
