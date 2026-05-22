nonmatching func_80102FB8, 0x20

glabel func_80102FB8
    /* 7B8 80102FB8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7BC 80102FBC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7C0 80102FC0 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 7C4 80102FC4 08000424 */   addiu     $a0, $zero, 0x8
    /* 7C8 80102FC8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7CC 80102FCC 00000000 */  nop
    /* 7D0 80102FD0 0800E003 */  jr         $ra
    /* 7D4 80102FD4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102FB8
