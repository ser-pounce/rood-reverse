nonmatching vs_mainMenu_menuItemFlyoutLeft, 0x44

glabel vs_mainMenu_menuItemFlyoutLeft
    /* 1010 800FA810 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1014 800FA814 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1018 800FA818 9223030C */  jal        vs_battle_getMenuItem
    /* 101C 800FA81C 20008424 */   addiu     $a0, $a0, 0x20
    /* 1020 800FA820 21204000 */  addu       $a0, $v0, $zero
    /* 1024 800FA824 00008290 */  lbu        $v0, 0x0($a0)
    /* 1028 800FA828 00000000 */  nop
    /* 102C 800FA82C 05004010 */  beqz       $v0, .L800FA844
    /* 1030 800FA830 05000324 */   addiu     $v1, $zero, 0x5
    /* 1034 800FA834 01008290 */  lbu        $v0, 0x1($a0)
    /* 1038 800FA838 000083A0 */  sb         $v1, 0x0($a0)
    /* 103C 800FA83C 23100200 */  negu       $v0, $v0
    /* 1040 800FA840 180082A4 */  sh         $v0, 0x18($a0)
  .L800FA844:
    /* 1044 800FA844 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1048 800FA848 00000000 */  nop
    /* 104C 800FA84C 0800E003 */  jr         $ra
    /* 1050 800FA850 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_mainMenu_menuItemFlyoutLeft
