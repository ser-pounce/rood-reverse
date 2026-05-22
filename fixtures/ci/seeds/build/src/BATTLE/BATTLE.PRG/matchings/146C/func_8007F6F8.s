nonmatching func_8007F6F8, 0x20

glabel func_8007F6F8
    /* 16EF8 8007F6F8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16EFC 8007F6FC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 16F00 8007F700 2CFD010C */  jal        func_8007F4B0
    /* 16F04 8007F704 06000424 */   addiu     $a0, $zero, 0x6
    /* 16F08 8007F708 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16F0C 8007F70C 0100422C */  sltiu      $v0, $v0, 0x1
    /* 16F10 8007F710 0800E003 */  jr         $ra
    /* 16F14 8007F714 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F6F8
