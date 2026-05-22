nonmatching _copyWeaponToInventory, 0x10C

glabel _copyWeaponToInventory
    /* 5610 80107E10 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 5614 80107E14 1180023C */  lui        $v0, %hi(_inventory)
    /* 5618 80107E18 1400B1AF */  sw         $s1, 0x14($sp)
    /* 561C 80107E1C A8A6518C */  lw         $s1, %lo(_inventory)($v0)
    /* 5620 80107E20 2400B5AF */  sw         $s5, 0x24($sp)
    /* 5624 80107E24 21A88000 */  addu       $s5, $a0, $zero
    /* 5628 80107E28 2800BFAF */  sw         $ra, 0x28($sp)
    /* 562C 80107E2C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 5630 80107E30 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 5634 80107E34 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5638 80107E38 1000B0AF */  sw         $s0, 0x10($sp)
    /* 563C 80107E3C 01002292 */  lbu        $v0, 0x1($s1)
    /* 5640 80107E40 00000000 */  nop
    /* 5644 80107E44 0B004010 */  beqz       $v0, .L80107E74
    /* 5648 80107E48 01001324 */   addiu     $s3, $zero, 0x1
    /* 564C 80107E4C 08000324 */  addiu      $v1, $zero, 0x8
    /* 5650 80107E50 20003126 */  addiu      $s1, $s1, 0x20
  .L80107E54:
    /* 5654 80107E54 01007326 */  addiu      $s3, $s3, 0x1
    /* 5658 80107E58 27006312 */  beq        $s3, $v1, .L80107EF8
    /* 565C 80107E5C 21100000 */   addu      $v0, $zero, $zero
    /* 5660 80107E60 01002292 */  lbu        $v0, 0x1($s1)
    /* 5664 80107E64 00000000 */  nop
    /* 5668 80107E68 FAFF4014 */  bnez       $v0, .L80107E54
    /* 566C 80107E6C 20003126 */   addiu     $s1, $s1, 0x20
    /* 5670 80107E70 E0FF3126 */  addiu      $s1, $s1, -0x20
  .L80107E74:
    /* 5674 80107E74 21202002 */  addu       $a0, $s1, $zero
    /* 5678 80107E78 0733030C */  jal        vs_battle_rMemzero
    /* 567C 80107E7C 20000524 */   addiu     $a1, $zero, 0x20
    /* 5680 80107E80 0400A426 */  addiu      $a0, $s5, 0x4
    /* 5684 80107E84 21286002 */  addu       $a1, $s3, $zero
    /* 5688 80107E88 151F040C */  jal        _copyBladeToInventory
    /* 568C 80107E8C 000033A2 */   sb        $s3, 0x0($s1)
    /* 5690 80107E90 3000A426 */  addiu      $a0, $s5, 0x30
    /* 5694 80107E94 21286002 */  addu       $a1, $s3, $zero
    /* 5698 80107E98 3A1F040C */  jal        _copyGripToInventory
    /* 569C 80107E9C 010022A2 */   sb        $v0, 0x1($s1)
    /* 56A0 80107EA0 21800000 */  addu       $s0, $zero, $zero
    /* 56A4 80107EA4 40001424 */  addiu      $s4, $zero, 0x40
    /* 56A8 80107EA8 2190A002 */  addu       $s2, $s5, $zero
    /* 56AC 80107EAC 020022A2 */  sb         $v0, 0x2($s1)
  .L80107EB0:
    /* 56B0 80107EB0 40004296 */  lhu        $v0, 0x40($s2)
    /* 56B4 80107EB4 00000000 */  nop
    /* 56B8 80107EB8 05004010 */  beqz       $v0, .L80107ED0
    /* 56BC 80107EBC 2120B402 */   addu      $a0, $s5, $s4
    /* 56C0 80107EC0 5F1F040C */  jal        _copyGemToInventory
    /* 56C4 80107EC4 21286002 */   addu      $a1, $s3, $zero
    /* 56C8 80107EC8 21183002 */  addu       $v1, $s1, $s0
    /* 56CC 80107ECC 040062A0 */  sb         $v0, 0x4($v1)
  .L80107ED0:
    /* 56D0 80107ED0 1C009426 */  addiu      $s4, $s4, 0x1C
    /* 56D4 80107ED4 01001026 */  addiu      $s0, $s0, 0x1
    /* 56D8 80107ED8 0300022A */  slti       $v0, $s0, 0x3
    /* 56DC 80107EDC F4FF4014 */  bnez       $v0, .L80107EB0
    /* 56E0 80107EE0 1C005226 */   addiu     $s2, $s2, 0x1C
    /* 56E4 80107EE4 08002426 */  addiu      $a0, $s1, 0x8
    /* 56E8 80107EE8 9400A526 */  addiu      $a1, $s5, 0x94
    /* 56EC 80107EEC 0D33030C */  jal        vs_battle_rMemcpy
    /* 56F0 80107EF0 18000624 */   addiu     $a2, $zero, 0x18
    /* 56F4 80107EF4 21106002 */  addu       $v0, $s3, $zero
  .L80107EF8:
    /* 56F8 80107EF8 2800BF8F */  lw         $ra, 0x28($sp)
    /* 56FC 80107EFC 2400B58F */  lw         $s5, 0x24($sp)
    /* 5700 80107F00 2000B48F */  lw         $s4, 0x20($sp)
    /* 5704 80107F04 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 5708 80107F08 1800B28F */  lw         $s2, 0x18($sp)
    /* 570C 80107F0C 1400B18F */  lw         $s1, 0x14($sp)
    /* 5710 80107F10 1000B08F */  lw         $s0, 0x10($sp)
    /* 5714 80107F14 0800E003 */  jr         $ra
    /* 5718 80107F18 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _copyWeaponToInventory
