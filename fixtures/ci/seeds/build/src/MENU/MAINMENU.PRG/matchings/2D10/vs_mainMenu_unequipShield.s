nonmatching vs_mainMenu_unequipShield, 0x40

glabel vs_mainMenu_unequipShield
    /* 4BA0 800FE3A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4BA4 800FE3A4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4BA8 800FE3A8 18AD010C */  jal        vs_battle_equipShield
    /* 4BAC 800FE3AC 21200000 */   addu      $a0, $zero, $zero
    /* 4BB0 800FE3B0 07000324 */  addiu      $v1, $zero, 0x7
    /* 4BB4 800FE3B4 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 4BB8 800FE3B8 68014224 */  addiu      $v0, $v0, %lo(vs_battle_inventory)
    /* 4BBC 800FE3BC 50014224 */  addiu      $v0, $v0, 0x150
  .L800FE3C0:
    /* 4BC0 800FE3C0 010140A0 */  sb         $zero, 0x101($v0)
    /* 4BC4 800FE3C4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 4BC8 800FE3C8 FDFF6104 */  bgez       $v1, .L800FE3C0
    /* 4BCC 800FE3CC D0FF4224 */   addiu     $v0, $v0, -0x30
    /* 4BD0 800FE3D0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4BD4 800FE3D4 00000000 */  nop
    /* 4BD8 800FE3D8 0800E003 */  jr         $ra
    /* 4BDC 800FE3DC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_mainMenu_unequipShield
