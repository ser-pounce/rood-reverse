nonmatching _copyBladeToInventory, 0x94

glabel _copyBladeToInventory
    /* 5454 80107C54 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5458 80107C58 1180023C */  lui        $v0, %hi(_inventory)
    /* 545C 80107C5C A8A6428C */  lw         $v0, %lo(_inventory)($v0)
    /* 5460 80107C60 21308000 */  addu       $a2, $a0, $zero
    /* 5464 80107C64 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5468 80107C68 2190A000 */  addu       $s2, $a1, $zero
    /* 546C 80107C6C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5470 80107C70 01001124 */  addiu      $s1, $zero, 0x1
    /* 5474 80107C74 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 5478 80107C78 1000B0AF */  sw         $s0, 0x10($sp)
    /* 547C 80107C7C 80024390 */  lbu        $v1, 0x280($v0)
    /* 5480 80107C80 00000000 */  nop
    /* 5484 80107C84 0B006010 */  beqz       $v1, .L80107CB4
    /* 5488 80107C88 80025024 */   addiu     $s0, $v0, 0x280
    /* 548C 80107C8C 10000324 */  addiu      $v1, $zero, 0x10
    /* 5490 80107C90 2C001026 */  addiu      $s0, $s0, 0x2C
  .L80107C94:
    /* 5494 80107C94 01003126 */  addiu      $s1, $s1, 0x1
    /* 5498 80107C98 0D002312 */  beq        $s1, $v1, .L80107CD0
    /* 549C 80107C9C 21100000 */   addu      $v0, $zero, $zero
    /* 54A0 80107CA0 00000292 */  lbu        $v0, 0x0($s0)
    /* 54A4 80107CA4 00000000 */  nop
    /* 54A8 80107CA8 FAFF4014 */  bnez       $v0, .L80107C94
    /* 54AC 80107CAC 2C001026 */   addiu     $s0, $s0, 0x2C
    /* 54B0 80107CB0 D4FF1026 */  addiu      $s0, $s0, -0x2C
  .L80107CB4:
    /* 54B4 80107CB4 21200002 */  addu       $a0, $s0, $zero
    /* 54B8 80107CB8 2128C000 */  addu       $a1, $a2, $zero
    /* 54BC 80107CBC 7000030C */  jal        vs_battle_copyAligned
    /* 54C0 80107CC0 2C000624 */   addiu     $a2, $zero, 0x2C
    /* 54C4 80107CC4 21102002 */  addu       $v0, $s1, $zero
    /* 54C8 80107CC8 2A0012A2 */  sb         $s2, 0x2A($s0)
    /* 54CC 80107CCC 2B0002A2 */  sb         $v0, 0x2B($s0)
  .L80107CD0:
    /* 54D0 80107CD0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 54D4 80107CD4 1800B28F */  lw         $s2, 0x18($sp)
    /* 54D8 80107CD8 1400B18F */  lw         $s1, 0x14($sp)
    /* 54DC 80107CDC 1000B08F */  lw         $s0, 0x10($sp)
    /* 54E0 80107CE0 0800E003 */  jr         $ra
    /* 54E4 80107CE4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _copyBladeToInventory
