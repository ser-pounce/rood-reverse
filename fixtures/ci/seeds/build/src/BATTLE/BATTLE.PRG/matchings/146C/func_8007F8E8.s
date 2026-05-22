nonmatching func_8007F8E8, 0x20

glabel func_8007F8E8
    /* 170E8 8007F8E8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 170EC 8007F8EC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 170F0 8007F8F0 2CFD010C */  jal        func_8007F4B0
    /* 170F4 8007F8F4 10000424 */   addiu     $a0, $zero, 0x10
    /* 170F8 8007F8F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 170FC 8007F8FC 0100422C */  sltiu      $v0, $v0, 0x1
    /* 17100 8007F900 0800E003 */  jr         $ra
    /* 17104 8007F904 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F8E8
