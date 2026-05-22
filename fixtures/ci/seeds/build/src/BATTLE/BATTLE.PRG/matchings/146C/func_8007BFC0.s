nonmatching func_8007BFC0, 0x38

glabel func_8007BFC0
    /* 137C0 8007BFC0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 137C4 8007BFC4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 137C8 8007BFC8 21800000 */  addu       $s0, $zero, $zero
    /* 137CC 8007BFCC 1400BFAF */  sw         $ra, 0x14($sp)
  .L8007BFD0:
    /* 137D0 8007BFD0 DBEF010C */  jal        func_8007BF6C
    /* 137D4 8007BFD4 21200002 */   addu      $a0, $s0, $zero
    /* 137D8 8007BFD8 01001026 */  addiu      $s0, $s0, 0x1
    /* 137DC 8007BFDC 1000022A */  slti       $v0, $s0, 0x10
    /* 137E0 8007BFE0 FBFF4014 */  bnez       $v0, .L8007BFD0
    /* 137E4 8007BFE4 00000000 */   nop
    /* 137E8 8007BFE8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 137EC 8007BFEC 1000B08F */  lw         $s0, 0x10($sp)
    /* 137F0 8007BFF0 0800E003 */  jr         $ra
    /* 137F4 8007BFF4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007BFC0
