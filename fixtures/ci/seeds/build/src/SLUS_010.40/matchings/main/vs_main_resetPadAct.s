nonmatching vs_main_resetPadAct, 0x4C

glabel vs_main_resetPadAct
    /* 33E68 80043668 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 33E6C 8004366C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 33E70 80043670 F70B010C */  jal        vs_main_padDisconnectAll
    /* 33E74 80043674 00000000 */   nop
    /* 33E78 80043678 21200000 */  addu       $a0, $zero, $zero
    /* 33E7C 8004367C 0580023C */  lui        $v0, %hi(_padAct)
    /* 33E80 80043680 18014324 */  addiu      $v1, $v0, %lo(_padAct)
  .L80043684:
    /* 33E84 80043684 0C0060AC */  sw         $zero, 0xC($v1)
    /* 33E88 80043688 2C0060AC */  sw         $zero, 0x2C($v1)
    /* 33E8C 8004368C 140060AC */  sw         $zero, 0x14($v1)
    /* 33E90 80043690 080060A4 */  sh         $zero, 0x8($v1)
    /* 33E94 80043694 01008424 */  addiu      $a0, $a0, 0x1
    /* 33E98 80043698 02008228 */  slti       $v0, $a0, 0x2
    /* 33E9C 8004369C F9FF4014 */  bnez       $v0, .L80043684
    /* 33EA0 800436A0 38006324 */   addiu     $v1, $v1, 0x38
    /* 33EA4 800436A4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 33EA8 800436A8 00000000 */  nop
    /* 33EAC 800436AC 0800E003 */  jr         $ra
    /* 33EB0 800436B0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_main_resetPadAct
