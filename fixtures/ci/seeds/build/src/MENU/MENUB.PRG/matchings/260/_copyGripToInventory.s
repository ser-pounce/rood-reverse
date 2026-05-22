nonmatching _copyGripToInventory, 0x94

glabel _copyGripToInventory
    /* 54E8 80107CE8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 54EC 80107CEC 1180023C */  lui        $v0, %hi(_inventory)
    /* 54F0 80107CF0 A8A6428C */  lw         $v0, %lo(_inventory)($v0)
    /* 54F4 80107CF4 21308000 */  addu       $a2, $a0, $zero
    /* 54F8 80107CF8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 54FC 80107CFC 2190A000 */  addu       $s2, $a1, $zero
    /* 5500 80107D00 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5504 80107D04 01001124 */  addiu      $s1, $zero, 0x1
    /* 5508 80107D08 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 550C 80107D0C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5510 80107D10 40054394 */  lhu        $v1, 0x540($v0)
    /* 5514 80107D14 00000000 */  nop
    /* 5518 80107D18 0B006010 */  beqz       $v1, .L80107D48
    /* 551C 80107D1C 40055024 */   addiu     $s0, $v0, 0x540
    /* 5520 80107D20 10000324 */  addiu      $v1, $zero, 0x10
    /* 5524 80107D24 10001026 */  addiu      $s0, $s0, 0x10
  .L80107D28:
    /* 5528 80107D28 01003126 */  addiu      $s1, $s1, 0x1
    /* 552C 80107D2C 0D002312 */  beq        $s1, $v1, .L80107D64
    /* 5530 80107D30 21100000 */   addu      $v0, $zero, $zero
    /* 5534 80107D34 00000296 */  lhu        $v0, 0x0($s0)
    /* 5538 80107D38 00000000 */  nop
    /* 553C 80107D3C FAFF4014 */  bnez       $v0, .L80107D28
    /* 5540 80107D40 10001026 */   addiu     $s0, $s0, 0x10
    /* 5544 80107D44 F0FF1026 */  addiu      $s0, $s0, -0x10
  .L80107D48:
    /* 5548 80107D48 21200002 */  addu       $a0, $s0, $zero
    /* 554C 80107D4C 2128C000 */  addu       $a1, $a2, $zero
    /* 5550 80107D50 7000030C */  jal        vs_battle_copyAligned
    /* 5554 80107D54 10000624 */   addiu     $a2, $zero, 0x10
    /* 5558 80107D58 21102002 */  addu       $v0, $s1, $zero
    /* 555C 80107D5C 0C0012A6 */  sh         $s2, 0xC($s0)
    /* 5560 80107D60 0E0002A6 */  sh         $v0, 0xE($s0)
  .L80107D64:
    /* 5564 80107D64 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 5568 80107D68 1800B28F */  lw         $s2, 0x18($sp)
    /* 556C 80107D6C 1400B18F */  lw         $s1, 0x14($sp)
    /* 5570 80107D70 1000B08F */  lw         $s0, 0x10($sp)
    /* 5574 80107D74 0800E003 */  jr         $ra
    /* 5578 80107D78 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _copyGripToInventory
