nonmatching func_8007F6D8, 0x20

glabel func_8007F6D8
    /* 16ED8 8007F6D8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16EDC 8007F6DC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 16EE0 8007F6E0 2CFD010C */  jal        func_8007F4B0
    /* 16EE4 8007F6E4 04000424 */   addiu     $a0, $zero, 0x4
    /* 16EE8 8007F6E8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16EEC 8007F6EC 0100422C */  sltiu      $v0, $v0, 0x1
    /* 16EF0 8007F6F0 0800E003 */  jr         $ra
    /* 16EF4 8007F6F4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F6D8
