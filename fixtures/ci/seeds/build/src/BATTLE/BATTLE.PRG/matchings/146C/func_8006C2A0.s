nonmatching func_8006C2A0, 0x5C

glabel func_8006C2A0
    /* 3AA0 8006C2A0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3AA4 8006C2A4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3AA8 8006C2A8 21800000 */  addu       $s0, $zero, $zero
    /* 3AAC 8006C2AC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3AB0 8006C2B0 FBFF1124 */  addiu      $s1, $zero, -0x5
    /* 3AB4 8006C2B4 1800BFAF */  sw         $ra, 0x18($sp)
  .L8006C2B8:
    /* 3AB8 8006C2B8 F882020C */  jal        func_800A0BE0
    /* 3ABC 8006C2BC 21200002 */   addu      $a0, $s0, $zero
    /* 3AC0 8006C2C0 21284000 */  addu       $a1, $v0, $zero
    /* 3AC4 8006C2C4 0400A230 */  andi       $v0, $a1, 0x4
    /* 3AC8 8006C2C8 03004010 */  beqz       $v0, .L8006C2D8
    /* 3ACC 8006C2CC 21200002 */   addu      $a0, $s0, $zero
    /* 3AD0 8006C2D0 1F82020C */  jal        func_800A087C
    /* 3AD4 8006C2D4 2428B100 */   and       $a1, $a1, $s1
  .L8006C2D8:
    /* 3AD8 8006C2D8 01001026 */  addiu      $s0, $s0, 0x1
    /* 3ADC 8006C2DC 1000022A */  slti       $v0, $s0, 0x10
    /* 3AE0 8006C2E0 F5FF4014 */  bnez       $v0, .L8006C2B8
    /* 3AE4 8006C2E4 00000000 */   nop
    /* 3AE8 8006C2E8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3AEC 8006C2EC 1400B18F */  lw         $s1, 0x14($sp)
    /* 3AF0 8006C2F0 1000B08F */  lw         $s0, 0x10($sp)
    /* 3AF4 8006C2F4 0800E003 */  jr         $ra
    /* 3AF8 8006C2F8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006C2A0
