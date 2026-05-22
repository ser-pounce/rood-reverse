nonmatching func_8006C480, 0x24

glabel func_8006C480
    /* 3C80 8006C480 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3C84 8006C484 21300000 */  addu       $a2, $zero, $zero
    /* 3C88 8006C488 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3C8C 8006C48C EA3D030C */  jal        func_800CF7A8
    /* 3C90 8006C490 2138C000 */   addu      $a3, $a2, $zero
    /* 3C94 8006C494 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3C98 8006C498 00000000 */  nop
    /* 3C9C 8006C49C 0800E003 */  jr         $ra
    /* 3CA0 8006C4A0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006C480
