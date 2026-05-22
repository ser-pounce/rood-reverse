nonmatching _dropWeaponRand, 0xE0

glabel _dropWeaponRand
    /* 330C 8006BB0C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 3310 8006BB10 2400B5AF */  sw         $s5, 0x24($sp)
    /* 3314 8006BB14 21A88000 */  addu       $s5, $a0, $zero
    /* 3318 8006BB18 2000B4AF */  sw         $s4, 0x20($sp)
    /* 331C 8006BB1C 21A0A000 */  addu       $s4, $a1, $zero
    /* 3320 8006BB20 FF000424 */  addiu      $a0, $zero, 0xFF
    /* 3324 8006BB24 2800BFAF */  sw         $ra, 0x28($sp)
    /* 3328 8006BB28 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 332C 8006BB2C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3330 8006BB30 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3334 8006BB34 EA09010C */  jal        vs_main_getRand
    /* 3338 8006BB38 1000B0AF */   sw        $s0, 0x10($sp)
    /* 333C 8006BB3C 0C018392 */  lbu        $v1, 0x10C($s4)
    /* 3340 8006BB40 00000000 */  nop
    /* 3344 8006BB44 2A104300 */  slt        $v0, $v0, $v1
    /* 3348 8006BB48 1E004010 */  beqz       $v0, .L8006BBC4
    /* 334C 8006BB4C 0400A426 */   addiu     $a0, $s5, 0x4
    /* 3350 8006BB50 5FAD010C */  jal        vs_battle_copyUiBladeStats
    /* 3354 8006BB54 18008526 */   addiu     $a1, $s4, 0x18
    /* 3358 8006BB58 3000A426 */  addiu      $a0, $s5, 0x30
    /* 335C 8006BB5C ABAD010C */  jal        vs_battle_copyUiGripStats
    /* 3360 8006BB60 48008526 */   addiu     $a1, $s4, 0x48
    /* 3364 8006BB64 21980000 */  addu       $s3, $zero, $zero
    /* 3368 8006BB68 78001224 */  addiu      $s2, $zero, 0x78
    /* 336C 8006BB6C 40001124 */  addiu      $s1, $zero, 0x40
    /* 3370 8006BB70 21808002 */  addu       $s0, $s4, $zero
  .L8006BB74:
    /* 3374 8006BB74 78000296 */  lhu        $v0, 0x78($s0)
    /* 3378 8006BB78 00000000 */  nop
    /* 337C 8006BB7C 03004010 */  beqz       $v0, .L8006BB8C
    /* 3380 8006BB80 2120B102 */   addu      $a0, $s5, $s1
    /* 3384 8006BB84 CAAD010C */  jal        vs_battle_copyUiGemStats
    /* 3388 8006BB88 21289202 */   addu      $a1, $s4, $s2
  .L8006BB8C:
    /* 338C 8006BB8C 30005226 */  addiu      $s2, $s2, 0x30
    /* 3390 8006BB90 1C003126 */  addiu      $s1, $s1, 0x1C
    /* 3394 8006BB94 01007326 */  addiu      $s3, $s3, 0x1
    /* 3398 8006BB98 0300622A */  slti       $v0, $s3, 0x3
    /* 339C 8006BB9C F5FF4014 */  bnez       $v0, .L8006BB74
    /* 33A0 8006BBA0 30001026 */   addiu     $s0, $s0, 0x30
    /* 33A4 8006BBA4 9400A426 */  addiu      $a0, $s5, 0x94
    /* 33A8 8006BBA8 21288002 */  addu       $a1, $s4, $zero
    /* 33AC 8006BBAC 2C24010C */  jal        vs_main_memcpy
    /* 33B0 8006BBB0 18000624 */   addiu     $a2, $zero, 0x18
    /* 33B4 8006BBB4 03000224 */  addiu      $v0, $zero, 0x3
    /* 33B8 8006BBB8 0000A2A2 */  sb         $v0, 0x0($s5)
    /* 33BC 8006BBBC F2AE0108 */  j          .L8006BBC8
    /* 33C0 8006BBC0 01000224 */   addiu     $v0, $zero, 0x1
  .L8006BBC4:
    /* 33C4 8006BBC4 21100000 */  addu       $v0, $zero, $zero
  .L8006BBC8:
    /* 33C8 8006BBC8 2800BF8F */  lw         $ra, 0x28($sp)
    /* 33CC 8006BBCC 2400B58F */  lw         $s5, 0x24($sp)
    /* 33D0 8006BBD0 2000B48F */  lw         $s4, 0x20($sp)
    /* 33D4 8006BBD4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 33D8 8006BBD8 1800B28F */  lw         $s2, 0x18($sp)
    /* 33DC 8006BBDC 1400B18F */  lw         $s1, 0x14($sp)
    /* 33E0 8006BBE0 1000B08F */  lw         $s0, 0x10($sp)
    /* 33E4 8006BBE4 0800E003 */  jr         $ra
    /* 33E8 8006BBE8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _dropWeaponRand
