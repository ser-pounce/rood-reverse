nonmatching func_8007D03C, 0x50

glabel func_8007D03C
    /* 1483C 8007D03C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14840 8007D040 1000B0AF */  sw         $s0, 0x10($sp)
    /* 14844 8007D044 1400BFAF */  sw         $ra, 0x14($sp)
    /* 14848 8007D048 5594030C */  jal        func_800E5154
    /* 1484C 8007D04C 21808000 */   addu      $s0, $a0, $zero
    /* 14850 8007D050 03004010 */  beqz       $v0, .L8007D060
    /* 14854 8007D054 02004238 */   xori      $v0, $v0, 0x2
    /* 14858 8007D058 1FF40108 */  j          .L8007D07C
    /* 1485C 8007D05C 0100422C */   sltiu     $v0, $v0, 0x1
  .L8007D060:
    /* 14860 8007D060 9D82020C */  jal        func_800A0A74
    /* 14864 8007D064 21200002 */   addu      $a0, $s0, $zero
    /* 14868 8007D068 21200002 */  addu       $a0, $s0, $zero
    /* 1486C 8007D06C FDFF0524 */  addiu      $a1, $zero, -0x3
    /* 14870 8007D070 8782020C */  jal        func_800A0A1C
    /* 14874 8007D074 24284500 */   and       $a1, $v0, $a1
    /* 14878 8007D078 01000224 */  addiu      $v0, $zero, 0x1
  .L8007D07C:
    /* 1487C 8007D07C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 14880 8007D080 1000B08F */  lw         $s0, 0x10($sp)
    /* 14884 8007D084 0800E003 */  jr         $ra
    /* 14888 8007D088 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007D03C
