nonmatching func_800B784C, 0xE0

glabel func_800B784C
    /* 4F04C 800B784C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 4F050 800B7850 2000B0AF */  sw         $s0, 0x20($sp)
    /* 4F054 800B7854 21808000 */  addu       $s0, $a0, $zero
    /* 4F058 800B7858 01000426 */  addiu      $a0, $s0, 0x1
    /* 4F05C 800B785C 2800BFAF */  sw         $ra, 0x28($sp)
    /* 4F060 800B7860 80FF020C */  jal        vs_battle_getShort
    /* 4F064 800B7864 2400B1AF */   sw        $s1, 0x24($sp)
    /* 4F068 800B7868 94FF020C */  jal        func_800BFE50
    /* 4F06C 800B786C FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4F070 800B7870 03000392 */  lbu        $v1, 0x3($s0)
    /* 4F074 800B7874 00000000 */  nop
    /* 4F078 800B7878 1000A3A3 */  sb         $v1, 0x10($sp)
    /* 4F07C 800B787C 04000392 */  lbu        $v1, 0x4($s0)
    /* 4F080 800B7880 00000000 */  nop
    /* 4F084 800B7884 1100A3A3 */  sb         $v1, 0x11($sp)
    /* 4F088 800B7888 05000392 */  lbu        $v1, 0x5($s0)
    /* 4F08C 800B788C 21884000 */  addu       $s1, $v0, $zero
    /* 4F090 800B7890 1200A3A3 */  sb         $v1, 0x12($sp)
    /* 4F094 800B7894 06000392 */  lbu        $v1, 0x6($s0)
    /* 4F098 800B7898 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 4F09C 800B789C 1300A3A3 */  sb         $v1, 0x13($sp)
    /* 4F0A0 800B78A0 2C4C4390 */  lbu        $v1, %lo(D_800F4C2C)($v0)
    /* 4F0A4 800B78A4 02000224 */  addiu      $v0, $zero, 0x2
    /* 4F0A8 800B78A8 06006214 */  bne        $v1, $v0, .L800B78C4
    /* 4F0AC 800B78AC FFFF0624 */   addiu     $a2, $zero, -0x1
    /* 4F0B0 800B78B0 FFFF2432 */  andi       $a0, $s1, 0xFFFF
    /* 4F0B4 800B78B4 1000A527 */  addiu      $a1, $sp, 0x10
    /* 4F0B8 800B78B8 21300000 */  addu       $a2, $zero, $zero
    /* 4F0BC 800B78BC 3CDE0208 */  j          .L800B78F0
    /* 4F0C0 800B78C0 2138C000 */   addu      $a3, $a2, $zero
  .L800B78C4:
    /* 4F0C4 800B78C4 07000292 */  lbu        $v0, 0x7($s0)
    /* 4F0C8 800B78C8 FF000324 */  addiu      $v1, $zero, 0xFF
    /* 4F0CC 800B78CC 02004310 */  beq        $v0, $v1, .L800B78D8
    /* 4F0D0 800B78D0 FFFF2432 */   andi      $a0, $s1, 0xFFFF
    /* 4F0D4 800B78D4 21304000 */  addu       $a2, $v0, $zero
  .L800B78D8:
    /* 4F0D8 800B78D8 08000292 */  lbu        $v0, 0x8($s0)
    /* 4F0DC 800B78DC 00000000 */  nop
    /* 4F0E0 800B78E0 02004310 */  beq        $v0, $v1, .L800B78EC
    /* 4F0E4 800B78E4 FFFF0724 */   addiu     $a3, $zero, -0x1
    /* 4F0E8 800B78E8 21384000 */  addu       $a3, $v0, $zero
  .L800B78EC:
    /* 4F0EC 800B78EC 1000A527 */  addiu      $a1, $sp, 0x10
  .L800B78F0:
    /* 4F0F0 800B78F0 FBA5020C */  jal        func_800A97EC
    /* 4F0F4 800B78F4 FFFF3032 */   andi      $s0, $s1, 0xFFFF
    /* 4F0F8 800B78F8 2377020C */  jal        func_8009DC8C
    /* 4F0FC 800B78FC 21200002 */   addu      $a0, $s0, $zero
    /* 4F100 800B7900 0F80023C */  lui        $v0, %hi(D_800F4B70)
    /* 4F104 800B7904 704B4224 */  addiu      $v0, $v0, %lo(D_800F4B70)
    /* 4F108 800B7908 21800202 */  addu       $s0, $s0, $v0
    /* 4F10C 800B790C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4F110 800B7910 000002A2 */  sb         $v0, 0x0($s0)
    /* 4F114 800B7914 2800BF8F */  lw         $ra, 0x28($sp)
    /* 4F118 800B7918 2400B18F */  lw         $s1, 0x24($sp)
    /* 4F11C 800B791C 2000B08F */  lw         $s0, 0x20($sp)
    /* 4F120 800B7920 21100000 */  addu       $v0, $zero, $zero
    /* 4F124 800B7924 0800E003 */  jr         $ra
    /* 4F128 800B7928 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800B784C
