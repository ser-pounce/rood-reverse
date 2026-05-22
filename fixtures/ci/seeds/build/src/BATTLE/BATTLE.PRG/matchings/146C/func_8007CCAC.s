nonmatching func_8007CCAC, 0x20

glabel func_8007CCAC
    /* 144AC 8007CCAC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 144B0 8007CCB0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 144B4 8007CCB4 6C65020C */  jal        vs_battle_getEmptyObjectDataSlot
    /* 144B8 8007CCB8 00000000 */   nop
    /* 144BC 8007CCBC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 144C0 8007CCC0 00000000 */  nop
    /* 144C4 8007CCC4 0800E003 */  jr         $ra
    /* 144C8 8007CCC8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007CCAC
