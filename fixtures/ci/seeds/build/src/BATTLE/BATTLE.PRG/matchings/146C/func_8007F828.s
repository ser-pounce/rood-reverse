nonmatching func_8007F828, 0x20

glabel func_8007F828
    /* 17028 8007F828 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1702C 8007F82C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 17030 8007F830 2CFD010C */  jal        func_8007F4B0
    /* 17034 8007F834 0C000424 */   addiu     $a0, $zero, 0xC
    /* 17038 8007F838 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1703C 8007F83C 0100422C */  sltiu      $v0, $v0, 0x1
    /* 17040 8007F840 0800E003 */  jr         $ra
    /* 17044 8007F844 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F828
