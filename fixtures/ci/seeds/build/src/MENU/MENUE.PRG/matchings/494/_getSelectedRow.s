nonmatching _getSelectedRow, 0x58

glabel _getSelectedRow
    /* 5F0 80102DF0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5F4 80102DF4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5F8 80102DF8 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 5FC 80102DFC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 600 80102E00 21804000 */  addu       $s0, $v0, $zero
    /* 604 80102E04 FFFF022A */  slti       $v0, $s0, -0x1
    /* 608 80102E08 05004010 */  beqz       $v0, .L80102E20
    /* 60C 80102E0C 00000000 */   nop
    /* 610 80102E10 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 614 80102E14 05000424 */   addiu     $a0, $zero, 0x5
    /* 618 80102E18 8E0B0408 */  j          .L80102E38
    /* 61C 80102E1C 21100002 */   addu      $v0, $s0, $zero
  .L80102E20:
    /* 620 80102E20 04000006 */  bltz       $s0, .L80102E34
    /* 624 80102E24 0F80023C */   lui       $v0, %hi(D_800F4EE8 + 0x4)
    /* 628 80102E28 EC4E4490 */  lbu        $a0, %lo(D_800F4EE8 + 0x4)($v0)
    /* 62C 80102E2C 4BEA030C */  jal        func_800FA92C
    /* 630 80102E30 01000524 */   addiu     $a1, $zero, 0x1
  .L80102E34:
    /* 634 80102E34 21100002 */  addu       $v0, $s0, $zero
  .L80102E38:
    /* 638 80102E38 1400BF8F */  lw         $ra, 0x14($sp)
    /* 63C 80102E3C 1000B08F */  lw         $s0, 0x10($sp)
    /* 640 80102E40 0800E003 */  jr         $ra
    /* 644 80102E44 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _getSelectedRow
