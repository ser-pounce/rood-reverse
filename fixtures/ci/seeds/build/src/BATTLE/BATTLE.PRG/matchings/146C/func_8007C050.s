nonmatching func_8007C050, 0x38

glabel func_8007C050
    /* 13850 8007C050 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 13854 8007C054 1000B0AF */  sw         $s0, 0x10($sp)
    /* 13858 8007C058 21800000 */  addu       $s0, $zero, $zero
    /* 1385C 8007C05C 1400BFAF */  sw         $ra, 0x14($sp)
  .L8007C060:
    /* 13860 8007C060 FEEF010C */  jal        func_8007BFF8
    /* 13864 8007C064 21200002 */   addu      $a0, $s0, $zero
    /* 13868 8007C068 01001026 */  addiu      $s0, $s0, 0x1
    /* 1386C 8007C06C 1000022A */  slti       $v0, $s0, 0x10
    /* 13870 8007C070 FBFF4014 */  bnez       $v0, .L8007C060
    /* 13874 8007C074 00000000 */   nop
    /* 13878 8007C078 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1387C 8007C07C 1000B08F */  lw         $s0, 0x10($sp)
    /* 13880 8007C080 0800E003 */  jr         $ra
    /* 13884 8007C084 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007C050
