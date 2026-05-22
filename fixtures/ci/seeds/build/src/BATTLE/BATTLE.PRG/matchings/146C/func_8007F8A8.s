nonmatching func_8007F8A8, 0x20

glabel func_8007F8A8
    /* 170A8 8007F8A8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 170AC 8007F8AC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 170B0 8007F8B0 2CFD010C */  jal        func_8007F4B0
    /* 170B4 8007F8B4 0E000424 */   addiu     $a0, $zero, 0xE
    /* 170B8 8007F8B8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 170BC 8007F8BC 0100422C */  sltiu      $v0, $v0, 0x1
    /* 170C0 8007F8C0 0800E003 */  jr         $ra
    /* 170C4 8007F8C4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F8A8
