nonmatching func_8007F848, 0x20

glabel func_8007F848
    /* 17048 8007F848 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1704C 8007F84C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 17050 8007F850 2CFD010C */  jal        func_8007F4B0
    /* 17054 8007F854 12000424 */   addiu     $a0, $zero, 0x12
    /* 17058 8007F858 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1705C 8007F85C 0100422C */  sltiu      $v0, $v0, 0x1
    /* 17060 8007F860 0800E003 */  jr         $ra
    /* 17064 8007F864 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F848
