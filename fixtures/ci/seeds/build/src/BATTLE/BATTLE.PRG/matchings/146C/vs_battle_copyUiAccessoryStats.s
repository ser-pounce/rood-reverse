nonmatching vs_battle_copyUiAccessoryStats, 0x30

glabel vs_battle_copyUiAccessoryStats
    /* 32DC 8006BADC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 32E0 8006BAE0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 32E4 8006BAE4 0000A294 */  lhu        $v0, 0x0($a1)
    /* 32E8 8006BAE8 00000000 */  nop
    /* 32EC 8006BAEC 03004010 */  beqz       $v0, .L8006BAFC
    /* 32F0 8006BAF0 00000000 */   nop
    /* 32F4 8006BAF4 EFAD010C */  jal        vs_battle_copyUiEquipmentStats
    /* 32F8 8006BAF8 00000000 */   nop
  .L8006BAFC:
    /* 32FC 8006BAFC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3300 8006BB00 00000000 */  nop
    /* 3304 8006BB04 0800E003 */  jr         $ra
    /* 3308 8006BB08 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_copyUiAccessoryStats
