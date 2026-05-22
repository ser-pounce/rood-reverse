nonmatching _getSelectedRow, 0x58

glabel _getSelectedRow
    /* 70C 80102F0C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 710 80102F10 1400BFAF */  sw         $ra, 0x14($sp)
    /* 714 80102F14 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 718 80102F18 1000B0AF */   sw        $s0, 0x10($sp)
    /* 71C 80102F1C 21804000 */  addu       $s0, $v0, $zero
    /* 720 80102F20 FFFF022A */  slti       $v0, $s0, -0x1
    /* 724 80102F24 05004010 */  beqz       $v0, .L80102F3C
    /* 728 80102F28 00000000 */   nop
    /* 72C 80102F2C 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 730 80102F30 05000424 */   addiu     $a0, $zero, 0x5
    /* 734 80102F34 D50B0408 */  j          .L80102F54
    /* 738 80102F38 21100002 */   addu      $v0, $s0, $zero
  .L80102F3C:
    /* 73C 80102F3C 04000006 */  bltz       $s0, .L80102F50
    /* 740 80102F40 0F80023C */   lui       $v0, %hi(D_800F4EE8 + 0x2)
    /* 744 80102F44 EA4E4490 */  lbu        $a0, %lo(D_800F4EE8 + 0x2)($v0)
    /* 748 80102F48 4BEA030C */  jal        func_800FA92C
    /* 74C 80102F4C 01000524 */   addiu     $a1, $zero, 0x1
  .L80102F50:
    /* 750 80102F50 21100002 */  addu       $v0, $s0, $zero
  .L80102F54:
    /* 754 80102F54 1400BF8F */  lw         $ra, 0x14($sp)
    /* 758 80102F58 1000B08F */  lw         $s0, 0x10($sp)
    /* 75C 80102F5C 0800E003 */  jr         $ra
    /* 760 80102F60 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _getSelectedRow
