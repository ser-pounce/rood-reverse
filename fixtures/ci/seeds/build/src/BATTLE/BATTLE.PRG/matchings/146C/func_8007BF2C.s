nonmatching func_8007BF2C, 0x20

glabel func_8007BF2C
    /* 1372C 8007BF2C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 13730 8007BF30 1000BFAF */  sw         $ra, 0x10($sp)
    /* 13734 8007BF34 E02A020C */  jal        func_8008AB80
    /* 13738 8007BF38 21200000 */   addu      $a0, $zero, $zero
    /* 1373C 8007BF3C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 13740 8007BF40 00000000 */  nop
    /* 13744 8007BF44 0800E003 */  jr         $ra
    /* 13748 8007BF48 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007BF2C
