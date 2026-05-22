nonmatching func_800B7A98, 0xC0

glabel func_800B7A98
    /* 4F298 800B7A98 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 4F29C 800B7A9C 2400B1AF */  sw         $s1, 0x24($sp)
    /* 4F2A0 800B7AA0 21888000 */  addu       $s1, $a0, $zero
    /* 4F2A4 800B7AA4 01002426 */  addiu      $a0, $s1, 0x1
    /* 4F2A8 800B7AA8 2800BFAF */  sw         $ra, 0x28($sp)
    /* 4F2AC 800B7AAC 80FF020C */  jal        vs_battle_getShort
    /* 4F2B0 800B7AB0 2000B0AF */   sw        $s0, 0x20($sp)
    /* 4F2B4 800B7AB4 94FF020C */  jal        func_800BFE50
    /* 4F2B8 800B7AB8 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4F2BC 800B7ABC 03002392 */  lbu        $v1, 0x3($s1)
    /* 4F2C0 800B7AC0 21804000 */  addu       $s0, $v0, $zero
    /* 4F2C4 800B7AC4 1000A3A3 */  sb         $v1, 0x10($sp)
    /* 4F2C8 800B7AC8 04002392 */  lbu        $v1, 0x4($s1)
    /* 4F2CC 800B7ACC 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 4F2D0 800B7AD0 1100A3A3 */  sb         $v1, 0x11($sp)
    /* 4F2D4 800B7AD4 05002492 */  lbu        $a0, 0x5($s1)
    /* 4F2D8 800B7AD8 FF000324 */  addiu      $v1, $zero, 0xFF
    /* 4F2DC 800B7ADC 1300A3A3 */  sb         $v1, 0x13($sp)
    /* 4F2E0 800B7AE0 2C4C4390 */  lbu        $v1, %lo(D_800F4C2C)($v0)
    /* 4F2E4 800B7AE4 02000224 */  addiu      $v0, $zero, 0x2
    /* 4F2E8 800B7AE8 05006214 */  bne        $v1, $v0, .L800B7B00
    /* 4F2EC 800B7AEC 1200A4A3 */   sb        $a0, 0x12($sp)
    /* 4F2F0 800B7AF0 FFFF0432 */  andi       $a0, $s0, 0xFFFF
    /* 4F2F4 800B7AF4 1000A527 */  addiu      $a1, $sp, 0x10
    /* 4F2F8 800B7AF8 C7DE0208 */  j          .L800B7B1C
    /* 4F2FC 800B7AFC 21300000 */   addu      $a2, $zero, $zero
  .L800B7B00:
    /* 4F300 800B7B00 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 4F304 800B7B04 06002392 */  lbu        $v1, 0x6($s1)
    /* 4F308 800B7B08 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 4F30C 800B7B0C 02006210 */  beq        $v1, $v0, .L800B7B18
    /* 4F310 800B7B10 FFFF0432 */   andi      $a0, $s0, 0xFFFF
    /* 4F314 800B7B14 21306000 */  addu       $a2, $v1, $zero
  .L800B7B18:
    /* 4F318 800B7B18 1000A527 */  addiu      $a1, $sp, 0x10
  .L800B7B1C:
    /* 4F31C 800B7B1C 15A7020C */  jal        func_800A9C54
    /* 4F320 800B7B20 FFFF1032 */   andi      $s0, $s0, 0xFFFF
    /* 4F324 800B7B24 2377020C */  jal        func_8009DC8C
    /* 4F328 800B7B28 21200002 */   addu      $a0, $s0, $zero
    /* 4F32C 800B7B2C 0F80023C */  lui        $v0, %hi(D_800F4B70)
    /* 4F330 800B7B30 704B4224 */  addiu      $v0, $v0, %lo(D_800F4B70)
    /* 4F334 800B7B34 21800202 */  addu       $s0, $s0, $v0
    /* 4F338 800B7B38 01000224 */  addiu      $v0, $zero, 0x1
    /* 4F33C 800B7B3C 000002A2 */  sb         $v0, 0x0($s0)
    /* 4F340 800B7B40 2800BF8F */  lw         $ra, 0x28($sp)
    /* 4F344 800B7B44 2400B18F */  lw         $s1, 0x24($sp)
    /* 4F348 800B7B48 2000B08F */  lw         $s0, 0x20($sp)
    /* 4F34C 800B7B4C 21100000 */  addu       $v0, $zero, $zero
    /* 4F350 800B7B50 0800E003 */  jr         $ra
    /* 4F354 800B7B54 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800B7A98
