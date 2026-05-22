nonmatching func_80102F8C, 0x20

glabel func_80102F8C
    /* 78C 80102F8C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 790 80102F90 1000BFAF */  sw         $ra, 0x10($sp)
    /* 794 80102F94 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 798 80102F98 05000424 */   addiu     $a0, $zero, 0x5
    /* 79C 80102F9C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7A0 80102FA0 00000000 */  nop
    /* 7A4 80102FA4 0800E003 */  jr         $ra
    /* 7A8 80102FA8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102F8C
