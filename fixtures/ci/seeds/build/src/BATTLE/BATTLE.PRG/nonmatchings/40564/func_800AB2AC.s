nonmatching func_800AB2AC, 0xAC

glabel func_800AB2AC
    /* 42AAC 800AB2AC 0F80023C */  lui        $v0, %hi(D_800E8F2C)
    /* 42AB0 800AB2B0 2C8F4290 */  lbu        $v0, %lo(D_800E8F2C)($v0)
    /* 42AB4 800AB2B4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 42AB8 800AB2B8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 42ABC 800AB2BC 21988000 */  addu       $s3, $a0, $zero
    /* 42AC0 800AB2C0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 42AC4 800AB2C4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 42AC8 800AB2C8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 42ACC 800AB2CC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 42AD0 800AB2D0 18006216 */  bne        $s3, $v0, .L800AB334
    /* 42AD4 800AB2D4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 42AD8 800AB2D8 21900000 */  addu       $s2, $zero, $zero
    /* 42ADC 800AB2DC FF001424 */  addiu      $s4, $zero, 0xFF
    /* 42AE0 800AB2E0 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 42AE4 800AB2E4 38455124 */  addiu      $s1, $v0, %lo(D_800F4538)
  .L800AB2E8:
    /* 42AE8 800AB2E8 0000308E */  lw         $s0, 0x0($s1)
    /* 42AEC 800AB2EC 00000000 */  nop
    /* 42AF0 800AB2F0 0C000012 */  beqz       $s0, .L800AB324
    /* 42AF4 800AB2F4 21101302 */   addu      $v0, $s0, $s3
    /* 42AF8 800AB2F8 3E184290 */  lbu        $v0, 0x183E($v0)
    /* 42AFC 800AB2FC 00000000 */  nop
    /* 42B00 800AB300 08005410 */  beq        $v0, $s4, .L800AB324
    /* 42B04 800AB304 21200002 */   addu      $a0, $s0, $zero
    /* 42B08 800AB308 21280000 */  addu       $a1, $zero, $zero
    /* 42B0C 800AB30C 26AC020C */  jal        func_800AB098
    /* 42B10 800AB310 2130A000 */   addu      $a2, $a1, $zero
    /* 42B14 800AB314 21200002 */  addu       $a0, $s0, $zero
    /* 42B18 800AB318 01000524 */  addiu      $a1, $zero, 0x1
    /* 42B1C 800AB31C 26AC020C */  jal        func_800AB098
    /* 42B20 800AB320 21300000 */   addu      $a2, $zero, $zero
  .L800AB324:
    /* 42B24 800AB324 01005226 */  addiu      $s2, $s2, 0x1
    /* 42B28 800AB328 1100422A */  slti       $v0, $s2, 0x11
    /* 42B2C 800AB32C EEFF4014 */  bnez       $v0, .L800AB2E8
    /* 42B30 800AB330 04003126 */   addiu     $s1, $s1, 0x4
  .L800AB334:
    /* 42B34 800AB334 2400BF8F */  lw         $ra, 0x24($sp)
    /* 42B38 800AB338 2000B48F */  lw         $s4, 0x20($sp)
    /* 42B3C 800AB33C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 42B40 800AB340 1800B28F */  lw         $s2, 0x18($sp)
    /* 42B44 800AB344 1400B18F */  lw         $s1, 0x14($sp)
    /* 42B48 800AB348 1000B08F */  lw         $s0, 0x10($sp)
    /* 42B4C 800AB34C 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 42B50 800AB350 0800E003 */  jr         $ra
    /* 42B54 800AB354 00000000 */   nop
endlabel func_800AB2AC
