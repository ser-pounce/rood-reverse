nonmatching _dropAccessoryRand, 0x64

glabel _dropAccessoryRand
    /* 34B0 8006BCB0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 34B4 8006BCB4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 34B8 8006BCB8 21888000 */  addu       $s1, $a0, $zero
    /* 34BC 8006BCBC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 34C0 8006BCC0 2180A000 */  addu       $s0, $a1, $zero
    /* 34C4 8006BCC4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 34C8 8006BCC8 EA09010C */  jal        vs_main_getRand
    /* 34CC 8006BCCC FF000424 */   addiu     $a0, $zero, 0xFF
    /* 34D0 8006BCD0 36000392 */  lbu        $v1, 0x36($s0)
    /* 34D4 8006BCD4 00000000 */  nop
    /* 34D8 8006BCD8 2A104300 */  slt        $v0, $v0, $v1
    /* 34DC 8006BCDC 03004014 */  bnez       $v0, .L8006BCEC
    /* 34E0 8006BCE0 04002426 */   addiu     $a0, $s1, 0x4
    /* 34E4 8006BCE4 40AF0108 */  j          .L8006BD00
    /* 34E8 8006BCE8 21100000 */   addu      $v0, $zero, $zero
  .L8006BCEC:
    /* 34EC 8006BCEC EFAD010C */  jal        vs_battle_copyUiEquipmentStats
    /* 34F0 8006BCF0 21280002 */   addu      $a1, $s0, $zero
    /* 34F4 8006BCF4 03000224 */  addiu      $v0, $zero, 0x3
    /* 34F8 8006BCF8 000022A2 */  sb         $v0, 0x0($s1)
    /* 34FC 8006BCFC 01000224 */  addiu      $v0, $zero, 0x1
  .L8006BD00:
    /* 3500 8006BD00 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3504 8006BD04 1400B18F */  lw         $s1, 0x14($sp)
    /* 3508 8006BD08 1000B08F */  lw         $s0, 0x10($sp)
    /* 350C 8006BD0C 0800E003 */  jr         $ra
    /* 3510 8006BD10 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _dropAccessoryRand
