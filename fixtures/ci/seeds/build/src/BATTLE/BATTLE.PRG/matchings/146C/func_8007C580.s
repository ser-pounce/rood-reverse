nonmatching func_8007C580, 0x40

glabel func_8007C580
    /* 13D80 8007C580 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 13D84 8007C584 2000BFAF */  sw         $ra, 0x20($sp)
    /* 13D88 8007C588 38F1010C */  jal        func_8007C4E0
    /* 13D8C 8007C58C 00000000 */   nop
    /* 13D90 8007C590 21200000 */  addu       $a0, $zero, $zero
    /* 13D94 8007C594 4284020C */  jal        func_800A1108
    /* 13D98 8007C598 1000A527 */   addiu     $a1, $sp, 0x10
    /* 13D9C 8007C59C 1000A493 */  lbu        $a0, 0x10($sp)
    /* 13DA0 8007C5A0 1200A593 */  lbu        $a1, 0x12($sp)
    /* 13DA4 8007C5A4 1100A693 */  lbu        $a2, 0x11($sp)
    /* 13DA8 8007C5A8 582E020C */  jal        func_8008B960
    /* 13DAC 8007C5AC 00000000 */   nop
    /* 13DB0 8007C5B0 2000BF8F */  lw         $ra, 0x20($sp)
    /* 13DB4 8007C5B4 00000000 */  nop
    /* 13DB8 8007C5B8 0800E003 */  jr         $ra
    /* 13DBC 8007C5BC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8007C580
