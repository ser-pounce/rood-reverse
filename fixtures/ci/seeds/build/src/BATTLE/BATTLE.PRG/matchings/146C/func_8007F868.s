nonmatching func_8007F868, 0x20

glabel func_8007F868
    /* 17068 8007F868 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1706C 8007F86C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 17070 8007F870 2CFD010C */  jal        func_8007F4B0
    /* 17074 8007F874 11000424 */   addiu     $a0, $zero, 0x11
    /* 17078 8007F878 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1707C 8007F87C 0100422C */  sltiu      $v0, $v0, 0x1
    /* 17080 8007F880 0800E003 */  jr         $ra
    /* 17084 8007F884 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F868
