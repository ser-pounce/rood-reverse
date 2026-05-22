nonmatching func_8007FD08, 0x20

glabel func_8007FD08
    /* 17508 8007FD08 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1750C 8007FD0C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 17510 8007FD10 2CFD010C */  jal        func_8007F4B0
    /* 17514 8007FD14 1D000424 */   addiu     $a0, $zero, 0x1D
    /* 17518 8007FD18 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1751C 8007FD1C 0100422C */  sltiu      $v0, $v0, 0x1
    /* 17520 8007FD20 0800E003 */  jr         $ra
    /* 17524 8007FD24 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007FD08
