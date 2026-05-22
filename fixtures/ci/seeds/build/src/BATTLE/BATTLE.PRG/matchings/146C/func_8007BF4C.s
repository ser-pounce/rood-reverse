nonmatching func_8007BF4C, 0x20

glabel func_8007BF4C
    /* 1374C 8007BF4C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 13750 8007BF50 1000BFAF */  sw         $ra, 0x10($sp)
    /* 13754 8007BF54 EE2A020C */  jal        func_8008ABB8
    /* 13758 8007BF58 21200000 */   addu      $a0, $zero, $zero
    /* 1375C 8007BF5C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 13760 8007BF60 00000000 */  nop
    /* 13764 8007BF64 0800E003 */  jr         $ra
    /* 13768 8007BF68 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007BF4C
