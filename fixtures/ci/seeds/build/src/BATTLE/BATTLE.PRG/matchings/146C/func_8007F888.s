nonmatching func_8007F888, 0x20

glabel func_8007F888
    /* 17088 8007F888 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1708C 8007F88C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 17090 8007F890 2CFD010C */  jal        func_8007F4B0
    /* 17094 8007F894 0D000424 */   addiu     $a0, $zero, 0xD
    /* 17098 8007F898 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1709C 8007F89C 0100422C */  sltiu      $v0, $v0, 0x1
    /* 170A0 8007F8A0 0800E003 */  jr         $ra
    /* 170A4 8007F8A4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F888
