nonmatching func_8007BF0C, 0x20

glabel func_8007BF0C
    /* 1370C 8007BF0C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 13710 8007BF10 1000BFAF */  sw         $ra, 0x10($sp)
    /* 13714 8007BF14 AF3B030C */  jal        func_800CEEBC
    /* 13718 8007BF18 00000000 */   nop
    /* 1371C 8007BF1C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 13720 8007BF20 2B100200 */  sltu       $v0, $zero, $v0
    /* 13724 8007BF24 0800E003 */  jr         $ra
    /* 13728 8007BF28 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007BF0C
