nonmatching _copyArmorToInventory, 0x80

glabel _copyArmorToInventory
    /* 571C 80107F1C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5720 80107F20 1180023C */  lui        $v0, %hi(_inventory)
    /* 5724 80107F24 A8A6428C */  lw         $v0, %lo(_inventory)($v0)
    /* 5728 80107F28 21288000 */  addu       $a1, $a0, $zero
    /* 572C 80107F2C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5730 80107F30 01001124 */  addiu      $s1, $zero, 0x1
    /* 5734 80107F34 1800BFAF */  sw         $ra, 0x18($sp)
    /* 5738 80107F38 1000B0AF */  sw         $s0, 0x10($sp)
    /* 573C 80107F3C 40064390 */  lbu        $v1, 0x640($v0)
    /* 5740 80107F40 00000000 */  nop
    /* 5744 80107F44 0B006010 */  beqz       $v1, .L80107F74
    /* 5748 80107F48 40065024 */   addiu     $s0, $v0, 0x640
    /* 574C 80107F4C 10000324 */  addiu      $v1, $zero, 0x10
    /* 5750 80107F50 28001026 */  addiu      $s0, $s0, 0x28
  .L80107F54:
    /* 5754 80107F54 01003126 */  addiu      $s1, $s1, 0x1
    /* 5758 80107F58 0B002312 */  beq        $s1, $v1, .L80107F88
    /* 575C 80107F5C 21100000 */   addu      $v0, $zero, $zero
    /* 5760 80107F60 00000292 */  lbu        $v0, 0x0($s0)
    /* 5764 80107F64 00000000 */  nop
    /* 5768 80107F68 FAFF4014 */  bnez       $v0, .L80107F54
    /* 576C 80107F6C 28001026 */   addiu     $s0, $s0, 0x28
    /* 5770 80107F70 D8FF1026 */  addiu      $s0, $s0, -0x28
  .L80107F74:
    /* 5774 80107F74 21200002 */  addu       $a0, $s0, $zero
    /* 5778 80107F78 7000030C */  jal        vs_battle_copyAligned
    /* 577C 80107F7C 28000624 */   addiu     $a2, $zero, 0x28
    /* 5780 80107F80 270011A2 */  sb         $s1, 0x27($s0)
    /* 5784 80107F84 21102002 */  addu       $v0, $s1, $zero
  .L80107F88:
    /* 5788 80107F88 1800BF8F */  lw         $ra, 0x18($sp)
    /* 578C 80107F8C 1400B18F */  lw         $s1, 0x14($sp)
    /* 5790 80107F90 1000B08F */  lw         $s0, 0x10($sp)
    /* 5794 80107F94 0800E003 */  jr         $ra
    /* 5798 80107F98 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _copyArmorToInventory
