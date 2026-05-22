nonmatching func_8007F718, 0x20

glabel func_8007F718
    /* 16F18 8007F718 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16F1C 8007F71C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 16F20 8007F720 2CFD010C */  jal        func_8007F4B0
    /* 16F24 8007F724 08000424 */   addiu     $a0, $zero, 0x8
    /* 16F28 8007F728 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16F2C 8007F72C 0100422C */  sltiu      $v0, $v0, 0x1
    /* 16F30 8007F730 0800E003 */  jr         $ra
    /* 16F34 8007F734 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F718
