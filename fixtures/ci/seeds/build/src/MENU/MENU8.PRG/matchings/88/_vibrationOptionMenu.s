nonmatching _vibrationOptionMenu, 0x1B8

glabel _vibrationOptionMenu
    /* DFC 801035FC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* E00 80103600 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* E04 80103604 04008010 */  beqz       $a0, .L80103618
    /* E08 80103608 2800B0AF */   sw        $s0, 0x28($sp)
    /* E0C 8010360C 1080023C */  lui        $v0, %hi(D_80105DA8)
    /* E10 80103610 E80D0408 */  j          .L801037A0
    /* E14 80103614 A85D40AC */   sw        $zero, %lo(D_80105DA8)($v0)
  .L80103618:
    /* E18 80103618 1080023C */  lui        $v0, %hi(D_80105DA8)
    /* E1C 8010361C A85D508C */  lw         $s0, %lo(D_80105DA8)($v0)
    /* E20 80103620 01000224 */  addiu      $v0, $zero, 0x1
    /* E24 80103624 3C000212 */  beq        $s0, $v0, .L80103718
    /* E28 80103628 0200022A */   slti      $v0, $s0, 0x2
    /* E2C 8010362C 05004010 */  beqz       $v0, .L80103644
    /* E30 80103630 02000224 */   addiu     $v0, $zero, 0x2
    /* E34 80103634 07000012 */  beqz       $s0, .L80103654
    /* E38 80103638 21100000 */   addu      $v0, $zero, $zero
    /* E3C 8010363C E90D0408 */  j          .L801037A4
    /* E40 80103640 00000000 */   nop
  .L80103644:
    /* E44 80103644 4F000212 */  beq        $s0, $v0, .L80103784
    /* E48 80103648 21100000 */   addu      $v0, $zero, $zero
    /* E4C 8010364C E90D0408 */  j          .L801037A4
    /* E50 80103650 00000000 */   nop
  .L80103654:
    /* E54 80103654 74EA030C */  jal        vs_mainmenu_ready
    /* E58 80103658 00000000 */   nop
    /* E5C 8010365C 50004010 */  beqz       $v0, .L801037A0
    /* E60 80103660 21280000 */   addu      $a1, $zero, $zero
    /* E64 80103664 1080023C */  lui        $v0, %hi(_menuStrings)
    /* E68 80103668 58554B24 */  addiu      $t3, $v0, %lo(_menuStrings)
    /* E6C 8010366C 2000AA27 */  addiu      $t2, $sp, 0x20
    /* E70 80103670 6E000924 */  addiu      $t1, $zero, 0x6E
    /* E74 80103674 04000824 */  addiu      $t0, $zero, 0x4
    /* E78 80103678 1000AC27 */  addiu      $t4, $sp, 0x10
    /* E7C 8010367C 21388001 */  addu       $a3, $t4, $zero
    /* E80 80103680 6C000624 */  addiu      $a2, $zero, 0x6C
  .L80103684:
    /* E84 80103684 21182B01 */  addu       $v1, $t1, $t3
    /* E88 80103688 04002925 */  addiu      $t1, $t1, 0x4
    /* E8C 8010368C 21208801 */  addu       $a0, $t4, $t0
    /* E90 80103690 08000825 */  addiu      $t0, $t0, 0x8
    /* E94 80103694 2110CB00 */  addu       $v0, $a2, $t3
    /* E98 80103698 0400C624 */  addiu      $a2, $a2, 0x4
    /* E9C 8010369C 00004294 */  lhu        $v0, 0x0($v0)
    /* EA0 801036A0 0100A524 */  addiu      $a1, $a1, 0x1
    /* EA4 801036A4 40100200 */  sll        $v0, $v0, 1
    /* EA8 801036A8 21104B00 */  addu       $v0, $v0, $t3
    /* EAC 801036AC 0000E2AC */  sw         $v0, 0x0($a3)
    /* EB0 801036B0 00006294 */  lhu        $v0, 0x0($v1)
    /* EB4 801036B4 0800E724 */  addiu      $a3, $a3, 0x8
    /* EB8 801036B8 40100200 */  sll        $v0, $v0, 1
    /* EBC 801036BC 21104B00 */  addu       $v0, $v0, $t3
    /* EC0 801036C0 000082AC */  sw         $v0, 0x0($a0)
    /* EC4 801036C4 000040AD */  sw         $zero, 0x0($t2)
    /* EC8 801036C8 0200A228 */  slti       $v0, $a1, 0x2
    /* ECC 801036CC EDFF4014 */  bnez       $v0, .L80103684
    /* ED0 801036D0 04004A25 */   addiu     $t2, $t2, 0x4
    /* ED4 801036D4 0680023C */  lui        $v0, %hi(D_8006002B)
    /* ED8 801036D8 01001024 */  addiu      $s0, $zero, 0x1
    /* EDC 801036DC 2000A727 */  addiu      $a3, $sp, 0x20
    /* EE0 801036E0 02000424 */  addiu      $a0, $zero, 0x2
    /* EE4 801036E4 2B004290 */  lbu        $v0, %lo(D_8006002B)($v0)
    /* EE8 801036E8 1000A627 */  addiu      $a2, $sp, 0x10
    /* EEC 801036EC 23280202 */  subu       $a1, $s0, $v0
    /* EF0 801036F0 80180500 */  sll        $v1, $a1, 2
    /* EF4 801036F4 2118E300 */  addu       $v1, $a3, $v1
    /* EF8 801036F8 0000628C */  lw         $v0, 0x0($v1)
    /* EFC 801036FC 4E020524 */  addiu      $a1, $zero, 0x24E
    /* F00 80103700 04004234 */  ori        $v0, $v0, 0x4
    /* F04 80103704 7801040C */  jal        vs_mainmenu_setMenuRows
    /* F08 80103708 000062AC */   sw        $v0, 0x0($v1)
    /* F0C 8010370C 1080023C */  lui        $v0, %hi(D_80105DA8)
    /* F10 80103710 E80D0408 */  j          .L801037A0
    /* F14 80103714 A85D50AC */   sw        $s0, %lo(D_80105DA8)($v0)
  .L80103718:
    /* F18 80103718 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* F1C 8010371C 00000000 */   nop
    /* F20 80103720 1080033C */  lui        $v1, %hi(D_80105DAC)
    /* F24 80103724 01004424 */  addiu      $a0, $v0, 0x1
    /* F28 80103728 1D008010 */  beqz       $a0, .L801037A0
    /* F2C 8010372C AC5D64AC */   sw        $a0, %lo(D_80105DAC)($v1)
    /* F30 80103730 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* F34 80103734 09008214 */  bne        $a0, $v0, .L8010375C
    /* F38 80103738 00000000 */   nop
    /* F3C 8010373C 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* F40 80103740 28000424 */   addiu     $a0, $zero, 0x28
    /* F44 80103744 EAFE030C */  jal        func_800FFBA8
    /* F48 80103748 00000000 */   nop
    /* F4C 8010374C A2FE030C */  jal        func_800FFA88
    /* F50 80103750 21200000 */   addu      $a0, $zero, $zero
    /* F54 80103754 DE0D0408 */  j          .L80103778
    /* F58 80103758 1080033C */   lui       $v1, %hi(D_80105DA8)
  .L8010375C:
    /* F5C 8010375C 03009014 */  bne        $a0, $s0, .L8010376C
    /* F60 80103760 00000000 */   nop
    /* F64 80103764 320E010C */  jal        func_800438C8
    /* F68 80103768 21200000 */   addu      $a0, $zero, $zero
  .L8010376C:
    /* F6C 8010376C 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* F70 80103770 07000424 */   addiu     $a0, $zero, 0x7
    /* F74 80103774 1080033C */  lui        $v1, %hi(D_80105DA8)
  .L80103778:
    /* F78 80103778 02000224 */  addiu      $v0, $zero, 0x2
    /* F7C 8010377C E80D0408 */  j          .L801037A0
    /* F80 80103780 A85D62AC */   sw        $v0, %lo(D_80105DA8)($v1)
  .L80103784:
    /* F84 80103784 74EA030C */  jal        vs_mainmenu_ready
    /* F88 80103788 00000000 */   nop
    /* F8C 8010378C 04004010 */  beqz       $v0, .L801037A0
    /* F90 80103790 1080023C */   lui       $v0, %hi(D_80105DAC)
    /* F94 80103794 AC5D428C */  lw         $v0, %lo(D_80105DAC)($v0)
    /* F98 80103798 E90D0408 */  j          .L801037A4
    /* F9C 8010379C 00000000 */   nop
  .L801037A0:
    /* FA0 801037A0 21100000 */  addu       $v0, $zero, $zero
  .L801037A4:
    /* FA4 801037A4 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* FA8 801037A8 2800B08F */  lw         $s0, 0x28($sp)
    /* FAC 801037AC 0800E003 */  jr         $ra
    /* FB0 801037B0 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _vibrationOptionMenu
