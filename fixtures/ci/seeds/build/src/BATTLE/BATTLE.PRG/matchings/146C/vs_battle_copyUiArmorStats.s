nonmatching vs_battle_copyUiArmorStats, 0x34

glabel vs_battle_copyUiArmorStats
    /* 32A8 8006BAA8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 32AC 8006BAAC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 32B0 8006BAB0 0000A294 */  lhu        $v0, 0x0($a1)
    /* 32B4 8006BAB4 00000000 */  nop
    /* 32B8 8006BAB8 04004010 */  beqz       $v0, .L8006BACC
    /* 32BC 8006BABC 00000000 */   nop
    /* 32C0 8006BAC0 3000A294 */  lhu        $v0, 0x30($a1)
    /* 32C4 8006BAC4 EFAD010C */  jal        vs_battle_copyUiEquipmentStats
    /* 32C8 8006BAC8 0800A2A4 */   sh        $v0, 0x8($a1)
  .L8006BACC:
    /* 32CC 8006BACC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 32D0 8006BAD0 00000000 */  nop
    /* 32D4 8006BAD4 0800E003 */  jr         $ra
    /* 32D8 8006BAD8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_copyUiArmorStats
