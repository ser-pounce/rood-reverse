nonmatching func_8007F738, 0x20

glabel func_8007F738
    /* 16F38 8007F738 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16F3C 8007F73C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 16F40 8007F740 2CFD010C */  jal        func_8007F4B0
    /* 16F44 8007F744 0A000424 */   addiu     $a0, $zero, 0xA
    /* 16F48 8007F748 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16F4C 8007F74C 0100422C */  sltiu      $v0, $v0, 0x1
    /* 16F50 8007F750 0800E003 */  jr         $ra
    /* 16F54 8007F754 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F738
