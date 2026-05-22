nonmatching func_8007D15C, 0x4C

glabel func_8007D15C
    /* 1495C 8007D15C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 14960 8007D160 1400B1AF */  sw         $s1, 0x14($sp)
    /* 14964 8007D164 21888000 */  addu       $s1, $a0, $zero
    /* 14968 8007D168 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1496C 8007D16C 01001024 */  addiu      $s0, $zero, 0x1
    /* 14970 8007D170 1800BFAF */  sw         $ra, 0x18($sp)
    /* 14974 8007D174 21200002 */  addu       $a0, $s0, $zero
  .L8007D178:
    /* 14978 8007D178 23F4010C */  jal        func_8007D08C
    /* 1497C 8007D17C 21282002 */   addu      $a1, $s1, $zero
    /* 14980 8007D180 01001026 */  addiu      $s0, $s0, 0x1
    /* 14984 8007D184 1000022A */  slti       $v0, $s0, 0x10
    /* 14988 8007D188 FBFF4014 */  bnez       $v0, .L8007D178
    /* 1498C 8007D18C 21200002 */   addu      $a0, $s0, $zero
    /* 14990 8007D190 21102002 */  addu       $v0, $s1, $zero
    /* 14994 8007D194 1800BF8F */  lw         $ra, 0x18($sp)
    /* 14998 8007D198 1400B18F */  lw         $s1, 0x14($sp)
    /* 1499C 8007D19C 1000B08F */  lw         $s0, 0x10($sp)
    /* 149A0 8007D1A0 0800E003 */  jr         $ra
    /* 149A4 8007D1A4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007D15C
