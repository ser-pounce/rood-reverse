nonmatching func_800B9F4C, 0x24

glabel func_800B9F4C
    /* 5174C 800B9F4C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51750 800B9F50 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51754 800B9F54 01008490 */  lbu        $a0, 0x1($a0)
    /* 51758 800B9F58 F33B020C */  jal        func_8008EFCC
    /* 5175C 800B9F5C 00000000 */   nop
    /* 51760 800B9F60 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51764 800B9F64 21100000 */  addu       $v0, $zero, $zero
    /* 51768 800B9F68 0800E003 */  jr         $ra
    /* 5176C 800B9F6C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9F4C
