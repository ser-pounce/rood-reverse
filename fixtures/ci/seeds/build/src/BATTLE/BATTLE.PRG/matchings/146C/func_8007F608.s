nonmatching func_8007F608, 0x20

glabel func_8007F608
    /* 16E08 8007F608 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16E0C 8007F60C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 16E10 8007F610 2CFD010C */  jal        func_8007F4B0
    /* 16E14 8007F614 09000424 */   addiu     $a0, $zero, 0x9
    /* 16E18 8007F618 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16E1C 8007F61C 0100422C */  sltiu      $v0, $v0, 0x1
    /* 16E20 8007F620 0800E003 */  jr         $ra
    /* 16E24 8007F624 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F608
