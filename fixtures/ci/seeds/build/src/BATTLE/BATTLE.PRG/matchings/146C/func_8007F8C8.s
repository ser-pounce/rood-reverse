nonmatching func_8007F8C8, 0x20

glabel func_8007F8C8
    /* 170C8 8007F8C8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 170CC 8007F8CC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 170D0 8007F8D0 2CFD010C */  jal        func_8007F4B0
    /* 170D4 8007F8D4 0F000424 */   addiu     $a0, $zero, 0xF
    /* 170D8 8007F8D8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 170DC 8007F8DC 0100422C */  sltiu      $v0, $v0, 0x1
    /* 170E0 8007F8E0 0800E003 */  jr         $ra
    /* 170E4 8007F8E4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F8C8
