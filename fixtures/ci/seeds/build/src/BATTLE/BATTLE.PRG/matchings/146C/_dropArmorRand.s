nonmatching _dropArmorRand, 0x8C

glabel _dropArmorRand
    /* 3514 8006BD14 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3518 8006BD18 1000B0AF */  sw         $s0, 0x10($sp)
    /* 351C 8006BD1C 21808000 */  addu       $s0, $a0, $zero
    /* 3520 8006BD20 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3524 8006BD24 2188A000 */  addu       $s1, $a1, $zero
    /* 3528 8006BD28 FF000424 */  addiu      $a0, $zero, 0xFF
    /* 352C 8006BD2C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 3530 8006BD30 EA09010C */  jal        vs_main_getRand
    /* 3534 8006BD34 1800B2AF */   sw        $s2, 0x18($sp)
    /* 3538 8006BD38 98002392 */  lbu        $v1, 0x98($s1)
    /* 353C 8006BD3C 00000000 */  nop
    /* 3540 8006BD40 2A104300 */  slt        $v0, $v0, $v1
    /* 3544 8006BD44 0F004010 */  beqz       $v0, .L8006BD84
    /* 3548 8006BD48 03001224 */   addiu     $s2, $zero, 0x3
    /* 354C 8006BD4C 21180000 */  addu       $v1, $zero, $zero
  .L8006BD50:
    /* 3550 8006BD50 04000292 */  lbu        $v0, 0x4($s0)
    /* 3554 8006BD54 00000000 */  nop
    /* 3558 8006BD58 07004014 */  bnez       $v0, .L8006BD78
    /* 355C 8006BD5C 01006324 */   addiu     $v1, $v1, 0x1
    /* 3560 8006BD60 04000426 */  addiu      $a0, $s0, 0x4
    /* 3564 8006BD64 EFAD010C */  jal        vs_battle_copyUiEquipmentStats
    /* 3568 8006BD68 21282002 */   addu      $a1, $s1, $zero
    /* 356C 8006BD6C 000012A2 */  sb         $s2, 0x0($s0)
    /* 3570 8006BD70 62AF0108 */  j          .L8006BD88
    /* 3574 8006BD74 01000224 */   addiu     $v0, $zero, 0x1
  .L8006BD78:
    /* 3578 8006BD78 02006228 */  slti       $v0, $v1, 0x2
    /* 357C 8006BD7C F4FF4014 */  bnez       $v0, .L8006BD50
    /* 3580 8006BD80 2C001026 */   addiu     $s0, $s0, 0x2C
  .L8006BD84:
    /* 3584 8006BD84 21100000 */  addu       $v0, $zero, $zero
  .L8006BD88:
    /* 3588 8006BD88 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 358C 8006BD8C 1800B28F */  lw         $s2, 0x18($sp)
    /* 3590 8006BD90 1400B18F */  lw         $s1, 0x14($sp)
    /* 3594 8006BD94 1000B08F */  lw         $s0, 0x10($sp)
    /* 3598 8006BD98 0800E003 */  jr         $ra
    /* 359C 8006BD9C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _dropArmorRand
