nonmatching func_800A9F64, 0x6C

glabel func_800A9F64
    /* 41764 800A9F64 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 41768 800A9F68 2138C000 */  addu       $a3, $a2, $zero
    /* 4176C 800A9F6C 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 41770 800A9F70 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 41774 800A9F74 80180400 */  sll        $v1, $a0, 2
    /* 41778 800A9F78 21186200 */  addu       $v1, $v1, $v0
    /* 4177C 800A9F7C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 41780 800A9F80 1800BFAF */  sw         $ra, 0x18($sp)
    /* 41784 800A9F84 1400B1AF */  sw         $s1, 0x14($sp)
    /* 41788 800A9F88 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4178C 800A9F8C 0000718C */  lw         $s1, 0x0($v1)
    /* 41790 800A9F90 0500E214 */  bne        $a3, $v0, .L800A9FA8
    /* 41794 800A9F94 FFFF0624 */   addiu     $a2, $zero, -0x1
    /* 41798 800A9F98 A2AA020C */  jal        func_800AAA88
    /* 4179C 800A9F9C 21304000 */   addu      $a2, $v0, $zero
    /* 417A0 800A9FA0 EEA70208 */  j          .L800A9FB8
    /* 417A4 800A9FA4 00000000 */   nop
  .L800A9FA8:
    /* 417A8 800A9FA8 C0053096 */  lhu        $s0, 0x5C0($s1)
    /* 417AC 800A9FAC A2AA020C */  jal        func_800AAA88
    /* 417B0 800A9FB0 C00527A6 */   sh        $a3, 0x5C0($s1)
    /* 417B4 800A9FB4 C00530A6 */  sh         $s0, 0x5C0($s1)
  .L800A9FB8:
    /* 417B8 800A9FB8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 417BC 800A9FBC 1400B18F */  lw         $s1, 0x14($sp)
    /* 417C0 800A9FC0 1000B08F */  lw         $s0, 0x10($sp)
    /* 417C4 800A9FC4 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 417C8 800A9FC8 0800E003 */  jr         $ra
    /* 417CC 800A9FCC 00000000 */   nop
endlabel func_800A9F64
