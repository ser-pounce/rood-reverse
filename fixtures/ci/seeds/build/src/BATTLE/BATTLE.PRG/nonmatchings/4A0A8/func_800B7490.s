nonmatching func_800B7490, 0xE4

glabel func_800B7490
    /* 4EC90 800B7490 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 4EC94 800B7494 2000B0AF */  sw         $s0, 0x20($sp)
    /* 4EC98 800B7498 21808000 */  addu       $s0, $a0, $zero
    /* 4EC9C 800B749C 01000426 */  addiu      $a0, $s0, 0x1
    /* 4ECA0 800B74A0 2800BFAF */  sw         $ra, 0x28($sp)
    /* 4ECA4 800B74A4 80FF020C */  jal        vs_battle_getShort
    /* 4ECA8 800B74A8 2400B1AF */   sw        $s1, 0x24($sp)
    /* 4ECAC 800B74AC 21884000 */  addu       $s1, $v0, $zero
    /* 4ECB0 800B74B0 80FF020C */  jal        vs_battle_getShort
    /* 4ECB4 800B74B4 03000426 */   addiu     $a0, $s0, 0x3
    /* 4ECB8 800B74B8 21804000 */  addu       $s0, $v0, $zero
    /* 4ECBC 800B74BC 00102232 */  andi       $v0, $s1, 0x1000
    /* 4ECC0 800B74C0 0A004010 */  beqz       $v0, .L800B74EC
    /* 4ECC4 800B74C4 00000000 */   nop
    /* 4ECC8 800B74C8 1F003132 */  andi       $s1, $s1, 0x1F
    /* 4ECCC 800B74CC D9F3010C */  jal        func_8007CF64
    /* 4ECD0 800B74D0 21202002 */   addu      $a0, $s1, $zero
    /* 4ECD4 800B74D4 10004014 */  bnez       $v0, .L800B7518
    /* 4ECD8 800B74D8 FFFF2432 */   andi      $a0, $s1, 0xFFFF
    /* 4ECDC 800B74DC 00241000 */  sll        $a0, $s0, 16
    /* 4ECE0 800B74E0 03240400 */  sra        $a0, $a0, 16
    /* 4ECE4 800B74E4 55DD0208 */  j          .L800B7554
    /* 4ECE8 800B74E8 FF000524 */   addiu     $a1, $zero, 0xFF
  .L800B74EC:
    /* 4ECEC 800B74EC C6F3010C */  jal        func_8007CF18
    /* 4ECF0 800B74F0 FFFF2432 */   andi      $a0, $s1, 0xFFFF
    /* 4ECF4 800B74F4 21884000 */  addu       $s1, $v0, $zero
    /* 4ECF8 800B74F8 FFFF2332 */  andi       $v1, $s1, 0xFFFF
    /* 4ECFC 800B74FC 01000224 */  addiu      $v0, $zero, 0x1
    /* 4ED00 800B7500 05006214 */  bne        $v1, $v0, .L800B7518
    /* 4ED04 800B7504 FFFF2432 */   andi      $a0, $s1, 0xFFFF
    /* 4ED08 800B7508 00241000 */  sll        $a0, $s0, 16
    /* 4ED0C 800B750C 03240400 */  sra        $a0, $a0, 16
    /* 4ED10 800B7510 55DD0208 */  j          .L800B7554
    /* 4ED14 800B7514 FF000524 */   addiu     $a1, $zero, 0xFF
  .L800B7518:
    /* 4ED18 800B7518 4284020C */  jal        func_800A1108
    /* 4ED1C 800B751C 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4ED20 800B7520 00241000 */  sll        $a0, $s0, 16
    /* 4ED24 800B7524 1000A593 */  lbu        $a1, 0x10($sp)
    /* 4ED28 800B7528 05FB020C */  jal        vs_battle_setStateFlag
    /* 4ED2C 800B752C 03240400 */   sra       $a0, $a0, 16
    /* 4ED30 800B7530 01000426 */  addiu      $a0, $s0, 0x1
    /* 4ED34 800B7534 00240400 */  sll        $a0, $a0, 16
    /* 4ED38 800B7538 1100A593 */  lbu        $a1, 0x11($sp)
    /* 4ED3C 800B753C 05FB020C */  jal        vs_battle_setStateFlag
    /* 4ED40 800B7540 03240400 */   sra       $a0, $a0, 16
    /* 4ED44 800B7544 02000426 */  addiu      $a0, $s0, 0x2
    /* 4ED48 800B7548 00240400 */  sll        $a0, $a0, 16
    /* 4ED4C 800B754C 1200A593 */  lbu        $a1, 0x12($sp)
    /* 4ED50 800B7550 03240400 */  sra        $a0, $a0, 16
  .L800B7554:
    /* 4ED54 800B7554 05FB020C */  jal        vs_battle_setStateFlag
    /* 4ED58 800B7558 00000000 */   nop
    /* 4ED5C 800B755C 21100000 */  addu       $v0, $zero, $zero
    /* 4ED60 800B7560 2800BF8F */  lw         $ra, 0x28($sp)
    /* 4ED64 800B7564 2400B18F */  lw         $s1, 0x24($sp)
    /* 4ED68 800B7568 2000B08F */  lw         $s0, 0x20($sp)
    /* 4ED6C 800B756C 0800E003 */  jr         $ra
    /* 4ED70 800B7570 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800B7490
