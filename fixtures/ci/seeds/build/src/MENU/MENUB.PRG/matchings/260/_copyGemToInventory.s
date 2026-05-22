nonmatching _copyGemToInventory, 0x94

glabel _copyGemToInventory
    /* 557C 80107D7C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5580 80107D80 1180023C */  lui        $v0, %hi(_inventory)
    /* 5584 80107D84 A8A6428C */  lw         $v0, %lo(_inventory)($v0)
    /* 5588 80107D88 21308000 */  addu       $a2, $a0, $zero
    /* 558C 80107D8C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5590 80107D90 2190A000 */  addu       $s2, $a1, $zero
    /* 5594 80107D94 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5598 80107D98 01001124 */  addiu      $s1, $zero, 0x1
    /* 559C 80107D9C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 55A0 80107DA0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 55A4 80107DA4 C0084394 */  lhu        $v1, 0x8C0($v0)
    /* 55A8 80107DA8 00000000 */  nop
    /* 55AC 80107DAC 0B006010 */  beqz       $v1, .L80107DDC
    /* 55B0 80107DB0 C0085024 */   addiu     $s0, $v0, 0x8C0
    /* 55B4 80107DB4 30000324 */  addiu      $v1, $zero, 0x30
    /* 55B8 80107DB8 1C001026 */  addiu      $s0, $s0, 0x1C
  .L80107DBC:
    /* 55BC 80107DBC 01003126 */  addiu      $s1, $s1, 0x1
    /* 55C0 80107DC0 0D002312 */  beq        $s1, $v1, .L80107DF8
    /* 55C4 80107DC4 21100000 */   addu      $v0, $zero, $zero
    /* 55C8 80107DC8 00000296 */  lhu        $v0, 0x0($s0)
    /* 55CC 80107DCC 00000000 */  nop
    /* 55D0 80107DD0 FAFF4014 */  bnez       $v0, .L80107DBC
    /* 55D4 80107DD4 1C001026 */   addiu     $s0, $s0, 0x1C
    /* 55D8 80107DD8 E4FF1026 */  addiu      $s0, $s0, -0x1C
  .L80107DDC:
    /* 55DC 80107DDC 21200002 */  addu       $a0, $s0, $zero
    /* 55E0 80107DE0 2128C000 */  addu       $a1, $a2, $zero
    /* 55E4 80107DE4 7000030C */  jal        vs_battle_copyAligned
    /* 55E8 80107DE8 1C000624 */   addiu     $a2, $zero, 0x1C
    /* 55EC 80107DEC 21102002 */  addu       $v0, $s1, $zero
    /* 55F0 80107DF0 180012A6 */  sh         $s2, 0x18($s0)
    /* 55F4 80107DF4 1A0002A6 */  sh         $v0, 0x1A($s0)
  .L80107DF8:
    /* 55F8 80107DF8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 55FC 80107DFC 1800B28F */  lw         $s2, 0x18($sp)
    /* 5600 80107E00 1400B18F */  lw         $s1, 0x14($sp)
    /* 5604 80107E04 1000B08F */  lw         $s0, 0x10($sp)
    /* 5608 80107E08 0800E003 */  jr         $ra
    /* 560C 80107E0C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _copyGemToInventory
