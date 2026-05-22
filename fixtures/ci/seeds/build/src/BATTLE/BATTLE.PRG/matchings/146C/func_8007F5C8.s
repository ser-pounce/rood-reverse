nonmatching func_8007F5C8, 0x20

glabel func_8007F5C8
    /* 16DC8 8007F5C8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16DCC 8007F5CC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 16DD0 8007F5D0 2CFD010C */  jal        func_8007F4B0
    /* 16DD4 8007F5D4 05000424 */   addiu     $a0, $zero, 0x5
    /* 16DD8 8007F5D8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16DDC 8007F5DC 0100422C */  sltiu      $v0, $v0, 0x1
    /* 16DE0 8007F5E0 0800E003 */  jr         $ra
    /* 16DE4 8007F5E4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F5C8
