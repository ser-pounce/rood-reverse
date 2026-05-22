nonmatching func_800BA90C, 0x40

glabel func_800BA90C
    /* 5210C 800BA90C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52110 800BA910 1000BFAF */  sw         $ra, 0x10($sp)
    /* 52114 800BA914 01008490 */  lbu        $a0, 0x1($a0)
    /* 52118 800BA918 B1EF010C */  jal        func_8007BEC4
    /* 5211C 800BA91C 00000000 */   nop
    /* 52120 800BA920 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 52124 800BA924 2C4C4390 */  lbu        $v1, %lo(D_800F4C2C)($v0)
    /* 52128 800BA928 02000224 */  addiu      $v0, $zero, 0x2
    /* 5212C 800BA92C 03006214 */  bne        $v1, $v0, .L800BA93C
    /* 52130 800BA930 00000000 */   nop
    /* 52134 800BA934 6A3C030C */  jal        func_800CF1A8
    /* 52138 800BA938 00000000 */   nop
  .L800BA93C:
    /* 5213C 800BA93C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 52140 800BA940 21100000 */  addu       $v0, $zero, $zero
    /* 52144 800BA944 0800E003 */  jr         $ra
    /* 52148 800BA948 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA90C
