nonmatching func_8007F808, 0x20

glabel func_8007F808
    /* 17008 8007F808 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1700C 8007F80C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 17010 8007F810 2CFD010C */  jal        func_8007F4B0
    /* 17014 8007F814 0B000424 */   addiu     $a0, $zero, 0xB
    /* 17018 8007F818 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1701C 8007F81C 0100422C */  sltiu      $v0, $v0, 0x1
    /* 17020 8007F820 0800E003 */  jr         $ra
    /* 17024 8007F824 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F808
