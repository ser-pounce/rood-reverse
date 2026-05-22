nonmatching func_80102ED8, 0x58

glabel func_80102ED8
    /* 6D8 80102ED8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6DC 80102EDC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6E0 80102EE0 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 6E4 80102EE4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6E8 80102EE8 21804000 */  addu       $s0, $v0, $zero
    /* 6EC 80102EEC FFFF022A */  slti       $v0, $s0, -0x1
    /* 6F0 80102EF0 05004010 */  beqz       $v0, .L80102F08
    /* 6F4 80102EF4 00000000 */   nop
    /* 6F8 80102EF8 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 6FC 80102EFC 05000424 */   addiu     $a0, $zero, 0x5
    /* 700 80102F00 C80B0408 */  j          .L80102F20
    /* 704 80102F04 21100002 */   addu      $v0, $s0, $zero
  .L80102F08:
    /* 708 80102F08 04000006 */  bltz       $s0, .L80102F1C
    /* 70C 80102F0C 0F80023C */   lui       $v0, %hi(D_800F4EE8)
    /* 710 80102F10 E84E4490 */  lbu        $a0, %lo(D_800F4EE8)($v0)
    /* 714 80102F14 4BEA030C */  jal        func_800FA92C
    /* 718 80102F18 01000524 */   addiu     $a1, $zero, 0x1
  .L80102F1C:
    /* 71C 80102F1C 21100002 */  addu       $v0, $s0, $zero
  .L80102F20:
    /* 720 80102F20 1400BF8F */  lw         $ra, 0x14($sp)
    /* 724 80102F24 1000B08F */  lw         $s0, 0x10($sp)
    /* 728 80102F28 0800E003 */  jr         $ra
    /* 72C 80102F2C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102ED8
