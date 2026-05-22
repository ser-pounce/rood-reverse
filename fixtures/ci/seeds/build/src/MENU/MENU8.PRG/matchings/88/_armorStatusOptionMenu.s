nonmatching _armorStatusOptionMenu, 0x1AC

glabel _armorStatusOptionMenu
    /* 5BC 80102DBC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 5C0 80102DC0 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 5C4 80102DC4 04008010 */  beqz       $a0, .L80102DD8
    /* 5C8 80102DC8 2800B0AF */   sw        $s0, 0x28($sp)
    /* 5CC 80102DCC 1080023C */  lui        $v0, %hi(D_80105D80)
    /* 5D0 80102DD0 D50B0408 */  j          .L80102F54
    /* 5D4 80102DD4 805D40AC */   sw        $zero, %lo(D_80105D80)($v0)
  .L80102DD8:
    /* 5D8 80102DD8 1080023C */  lui        $v0, %hi(D_80105D80)
    /* 5DC 80102DDC 805D438C */  lw         $v1, %lo(D_80105D80)($v0)
    /* 5E0 80102DE0 01000224 */  addiu      $v0, $zero, 0x1
    /* 5E4 80102DE4 3D006210 */  beq        $v1, $v0, .L80102EDC
    /* 5E8 80102DE8 02006228 */   slti      $v0, $v1, 0x2
    /* 5EC 80102DEC 05004010 */  beqz       $v0, .L80102E04
    /* 5F0 80102DF0 02000224 */   addiu     $v0, $zero, 0x2
    /* 5F4 80102DF4 07006010 */  beqz       $v1, .L80102E14
    /* 5F8 80102DF8 21100000 */   addu      $v0, $zero, $zero
    /* 5FC 80102DFC D60B0408 */  j          .L80102F58
    /* 600 80102E00 00000000 */   nop
  .L80102E04:
    /* 604 80102E04 4C006210 */  beq        $v1, $v0, .L80102F38
    /* 608 80102E08 21100000 */   addu      $v0, $zero, $zero
    /* 60C 80102E0C D60B0408 */  j          .L80102F58
    /* 610 80102E10 00000000 */   nop
  .L80102E14:
    /* 614 80102E14 74EA030C */  jal        vs_mainmenu_ready
    /* 618 80102E18 00000000 */   nop
    /* 61C 80102E1C 4D004010 */  beqz       $v0, .L80102F54
    /* 620 80102E20 21280000 */   addu      $a1, $zero, $zero
    /* 624 80102E24 1080023C */  lui        $v0, %hi(_menuStrings)
    /* 628 80102E28 58554B24 */  addiu      $t3, $v0, %lo(_menuStrings)
    /* 62C 80102E2C 2000AA27 */  addiu      $t2, $sp, 0x20
    /* 630 80102E30 46000924 */  addiu      $t1, $zero, 0x46
    /* 634 80102E34 04000824 */  addiu      $t0, $zero, 0x4
    /* 638 80102E38 1000AC27 */  addiu      $t4, $sp, 0x10
    /* 63C 80102E3C 21388001 */  addu       $a3, $t4, $zero
    /* 640 80102E40 44000624 */  addiu      $a2, $zero, 0x44
  .L80102E44:
    /* 644 80102E44 21182B01 */  addu       $v1, $t1, $t3
    /* 648 80102E48 04002925 */  addiu      $t1, $t1, 0x4
    /* 64C 80102E4C 21208801 */  addu       $a0, $t4, $t0
    /* 650 80102E50 08000825 */  addiu      $t0, $t0, 0x8
    /* 654 80102E54 2110CB00 */  addu       $v0, $a2, $t3
    /* 658 80102E58 0400C624 */  addiu      $a2, $a2, 0x4
    /* 65C 80102E5C 00004294 */  lhu        $v0, 0x0($v0)
    /* 660 80102E60 0100A524 */  addiu      $a1, $a1, 0x1
    /* 664 80102E64 40100200 */  sll        $v0, $v0, 1
    /* 668 80102E68 21104B00 */  addu       $v0, $v0, $t3
    /* 66C 80102E6C 0000E2AC */  sw         $v0, 0x0($a3)
    /* 670 80102E70 00006294 */  lhu        $v0, 0x0($v1)
    /* 674 80102E74 0800E724 */  addiu      $a3, $a3, 0x8
    /* 678 80102E78 40100200 */  sll        $v0, $v0, 1
    /* 67C 80102E7C 21104B00 */  addu       $v0, $v0, $t3
    /* 680 80102E80 000082AC */  sw         $v0, 0x0($a0)
    /* 684 80102E84 000040AD */  sw         $zero, 0x0($t2)
    /* 688 80102E88 0200A228 */  slti       $v0, $a1, 0x2
    /* 68C 80102E8C EDFF4014 */  bnez       $v0, .L80102E44
    /* 690 80102E90 04004A25 */   addiu     $t2, $t2, 0x4
    /* 694 80102E94 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 698 80102E98 01001024 */  addiu      $s0, $zero, 0x1
    /* 69C 80102E9C 2000A727 */  addiu      $a3, $sp, 0x20
    /* 6A0 80102EA0 02000424 */  addiu      $a0, $zero, 0x2
    /* 6A4 80102EA4 20004290 */  lbu        $v0, %lo(vs_main_settings)($v0)
    /* 6A8 80102EA8 1000A627 */  addiu      $a2, $sp, 0x10
    /* 6AC 80102EAC C2110200 */  srl        $v0, $v0, 7
    /* 6B0 80102EB0 23280202 */  subu       $a1, $s0, $v0
    /* 6B4 80102EB4 80180500 */  sll        $v1, $a1, 2
    /* 6B8 80102EB8 2118E300 */  addu       $v1, $a3, $v1
    /* 6BC 80102EBC 0000628C */  lw         $v0, 0x0($v1)
    /* 6C0 80102EC0 49020524 */  addiu      $a1, $zero, 0x249
    /* 6C4 80102EC4 04004234 */  ori        $v0, $v0, 0x4
    /* 6C8 80102EC8 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 6CC 80102ECC 000062AC */   sw        $v0, 0x0($v1)
    /* 6D0 80102ED0 1080023C */  lui        $v0, %hi(D_80105D80)
    /* 6D4 80102ED4 D50B0408 */  j          .L80102F54
    /* 6D8 80102ED8 805D50AC */   sw        $s0, %lo(D_80105D80)($v0)
  .L80102EDC:
    /* 6DC 80102EDC 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 6E0 80102EE0 00000000 */   nop
    /* 6E4 80102EE4 1080033C */  lui        $v1, %hi(D_80105D84)
    /* 6E8 80102EE8 01004424 */  addiu      $a0, $v0, 0x1
    /* 6EC 80102EEC 19008010 */  beqz       $a0, .L80102F54
    /* 6F0 80102EF0 845D64AC */   sw        $a0, %lo(D_80105D84)($v1)
    /* 6F4 80102EF4 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 6F8 80102EF8 09008214 */  bne        $a0, $v0, .L80102F20
    /* 6FC 80102EFC 00000000 */   nop
    /* 700 80102F00 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 704 80102F04 28000424 */   addiu     $a0, $zero, 0x28
    /* 708 80102F08 EAFE030C */  jal        func_800FFBA8
    /* 70C 80102F0C 00000000 */   nop
    /* 710 80102F10 A2FE030C */  jal        func_800FFA88
    /* 714 80102F14 21200000 */   addu      $a0, $zero, $zero
    /* 718 80102F18 CB0B0408 */  j          .L80102F2C
    /* 71C 80102F1C 1080033C */   lui       $v1, %hi(D_80105D80)
  .L80102F20:
    /* 720 80102F20 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 724 80102F24 07000424 */   addiu     $a0, $zero, 0x7
    /* 728 80102F28 1080033C */  lui        $v1, %hi(D_80105D80)
  .L80102F2C:
    /* 72C 80102F2C 02000224 */  addiu      $v0, $zero, 0x2
    /* 730 80102F30 D50B0408 */  j          .L80102F54
    /* 734 80102F34 805D62AC */   sw        $v0, %lo(D_80105D80)($v1)
  .L80102F38:
    /* 738 80102F38 74EA030C */  jal        vs_mainmenu_ready
    /* 73C 80102F3C 00000000 */   nop
    /* 740 80102F40 04004010 */  beqz       $v0, .L80102F54
    /* 744 80102F44 1080023C */   lui       $v0, %hi(D_80105D84)
    /* 748 80102F48 845D428C */  lw         $v0, %lo(D_80105D84)($v0)
    /* 74C 80102F4C D60B0408 */  j          .L80102F58
    /* 750 80102F50 00000000 */   nop
  .L80102F54:
    /* 754 80102F54 21100000 */  addu       $v0, $zero, $zero
  .L80102F58:
    /* 758 80102F58 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 75C 80102F5C 2800B08F */  lw         $s0, 0x28($sp)
    /* 760 80102F60 0800E003 */  jr         $ra
    /* 764 80102F64 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _armorStatusOptionMenu
