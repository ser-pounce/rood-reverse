nonmatching vs_mainMenu_menuItemFlyoutRight, 0x40

glabel vs_mainMenu_menuItemFlyoutRight
    /* 10A0 800FA8A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 10A4 800FA8A4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 10A8 800FA8A8 9223030C */  jal        vs_battle_getMenuItem
    /* 10AC 800FA8AC 00000000 */   nop
    /* 10B0 800FA8B0 21184000 */  addu       $v1, $v0, $zero
    /* 10B4 800FA8B4 00006290 */  lbu        $v0, 0x0($v1)
    /* 10B8 800FA8B8 00000000 */  nop
    /* 10BC 800FA8BC 04004010 */  beqz       $v0, .L800FA8D0
    /* 10C0 800FA8C0 02000224 */   addiu     $v0, $zero, 0x2
    /* 10C4 800FA8C4 000062A0 */  sb         $v0, 0x0($v1)
    /* 10C8 800FA8C8 40010224 */  addiu      $v0, $zero, 0x140
    /* 10CC 800FA8CC 180062A4 */  sh         $v0, 0x18($v1)
  .L800FA8D0:
    /* 10D0 800FA8D0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 10D4 800FA8D4 00000000 */  nop
    /* 10D8 800FA8D8 0800E003 */  jr         $ra
    /* 10DC 800FA8DC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_mainMenu_menuItemFlyoutRight
