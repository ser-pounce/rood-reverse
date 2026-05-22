nonmatching vs_mainMenu_clearMenuExcept, 0x4C

glabel vs_mainMenu_clearMenuExcept
    /* 10E0 800FA8E0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 10E4 800FA8E4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 10E8 800FA8E8 21888000 */  addu       $s1, $a0, $zero
    /* 10EC 800FA8EC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 10F0 800FA8F0 21800000 */  addu       $s0, $zero, $zero
    /* 10F4 800FA8F4 1800BFAF */  sw         $ra, 0x18($sp)
  .L800FA8F8:
    /* 10F8 800FA8F8 03001112 */  beq        $s0, $s1, .L800FA908
    /* 10FC 800FA8FC 00000000 */   nop
    /* 1100 800FA900 28EA030C */  jal        vs_mainMenu_menuItemFlyoutRight
    /* 1104 800FA904 21200002 */   addu      $a0, $s0, $zero
  .L800FA908:
    /* 1108 800FA908 01001026 */  addiu      $s0, $s0, 0x1
    /* 110C 800FA90C 2000022A */  slti       $v0, $s0, 0x20
    /* 1110 800FA910 F9FF4014 */  bnez       $v0, .L800FA8F8
    /* 1114 800FA914 00000000 */   nop
    /* 1118 800FA918 1800BF8F */  lw         $ra, 0x18($sp)
    /* 111C 800FA91C 1400B18F */  lw         $s1, 0x14($sp)
    /* 1120 800FA920 1000B08F */  lw         $s0, 0x10($sp)
    /* 1124 800FA924 0800E003 */  jr         $ra
    /* 1128 800FA928 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_mainMenu_clearMenuExcept
