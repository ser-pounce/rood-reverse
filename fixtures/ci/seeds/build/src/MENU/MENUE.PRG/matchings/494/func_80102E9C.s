nonmatching func_80102E9C, 0x20

glabel func_80102E9C
    /* 69C 80102E9C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6A0 80102EA0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6A4 80102EA4 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 6A8 80102EA8 08000424 */   addiu     $a0, $zero, 0x8
    /* 6AC 80102EAC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6B0 80102EB0 00000000 */  nop
    /* 6B4 80102EB4 0800E003 */  jr         $ra
    /* 6B8 80102EB8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102E9C
