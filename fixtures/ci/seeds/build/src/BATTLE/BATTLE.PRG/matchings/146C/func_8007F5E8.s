nonmatching func_8007F5E8, 0x20

glabel func_8007F5E8
    /* 16DE8 8007F5E8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16DEC 8007F5EC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 16DF0 8007F5F0 2CFD010C */  jal        func_8007F4B0
    /* 16DF4 8007F5F4 07000424 */   addiu     $a0, $zero, 0x7
    /* 16DF8 8007F5F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16DFC 8007F5FC 0100422C */  sltiu      $v0, $v0, 0x1
    /* 16E00 8007F600 0800E003 */  jr         $ra
    /* 16E04 8007F604 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F5E8
