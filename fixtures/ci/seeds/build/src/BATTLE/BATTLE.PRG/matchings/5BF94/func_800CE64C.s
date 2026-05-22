nonmatching func_800CE64C, 0x30

glabel func_800CE64C
    /* 65E4C 800CE64C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 65E50 800CE650 1000BFAF */  sw         $ra, 0x10($sp)
    /* 65E54 800CE654 9F39030C */  jal        func_800CE67C
    /* 65E58 800CE658 00000000 */   nop
    /* 65E5C 800CE65C 055E030C */  jal        func_800D7814
    /* 65E60 800CE660 00000000 */   nop
    /* 65E64 800CE664 A349030C */  jal        func_800D268C
    /* 65E68 800CE668 00000000 */   nop
    /* 65E6C 800CE66C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 65E70 800CE670 00000000 */  nop
    /* 65E74 800CE674 0800E003 */  jr         $ra
    /* 65E78 800CE678 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CE64C
