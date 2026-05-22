nonmatching vs_mainMenu_unequipAllWeapons, 0x40

glabel vs_mainMenu_unequipAllWeapons
    /* 4B60 800FE360 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4B64 800FE364 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4B68 800FE368 CEAC010C */  jal        vs_battle_equipWeapon
    /* 4B6C 800FE36C 21200000 */   addu      $a0, $zero, $zero
    /* 4B70 800FE370 07000324 */  addiu      $v1, $zero, 0x7
    /* 4B74 800FE374 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 4B78 800FE378 68014224 */  addiu      $v0, $v0, %lo(vs_battle_inventory)
    /* 4B7C 800FE37C E0004224 */  addiu      $v0, $v0, 0xE0
  .L800FE380:
    /* 4B80 800FE380 030040A0 */  sb         $zero, 0x3($v0)
    /* 4B84 800FE384 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 4B88 800FE388 FDFF6104 */  bgez       $v1, .L800FE380
    /* 4B8C 800FE38C E0FF4224 */   addiu     $v0, $v0, -0x20
    /* 4B90 800FE390 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4B94 800FE394 00000000 */  nop
    /* 4B98 800FE398 0800E003 */  jr         $ra
    /* 4B9C 800FE39C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_mainMenu_unequipAllWeapons
