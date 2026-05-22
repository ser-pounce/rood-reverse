nonmatching _shieldDetailsPage, 0x25C

glabel _shieldDetailsPage
    /* D38 80103538 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* D3C 8010353C 21288000 */  addu       $a1, $a0, $zero
    /* D40 80103540 2800BFAF */  sw         $ra, 0x28($sp)
    /* D44 80103544 2400B1AF */  sw         $s1, 0x24($sp)
    /* D48 80103548 1100A010 */  beqz       $a1, .L80103590
    /* D4C 8010354C 2000B0AF */   sw        $s0, 0x20($sp)
    /* D50 80103550 1180033C */  lui        $v1, %hi(D_8010A5FC)
    /* D54 80103554 03120500 */  sra        $v0, $a1, 8
    /* D58 80103558 FCA562A0 */  sb         $v0, %lo(D_8010A5FC)($v1)
    /* D5C 8010355C FF004430 */  andi       $a0, $v0, 0xFF
    /* D60 80103560 1180033C */  lui        $v1, %hi(D_8010A5FD)
    /* D64 80103564 FFFFA224 */  addiu      $v0, $a1, -0x1
    /* D68 80103568 140B040C */  jal        func_80102C50
    /* D6C 8010356C FDA562A0 */   sb        $v0, %lo(D_8010A5FD)($v1)
    /* D70 80103570 21100000 */  addu       $v0, $zero, $zero
    /* D74 80103574 1180033C */  lui        $v1, %hi(D_8010A5FE)
    /* D78 80103578 FEA560A0 */  sb         $zero, %lo(D_8010A5FE)($v1)
    /* D7C 8010357C 1180033C */  lui        $v1, %hi(D_8010A5FB)
    /* D80 80103580 FBA560A0 */  sb         $zero, %lo(D_8010A5FB)($v1)
    /* D84 80103584 1180033C */  lui        $v1, %hi(D_8010A5FA)
    /* D88 80103588 E00D0408 */  j          .L80103780
    /* D8C 8010358C FAA560A0 */   sb        $zero, %lo(D_8010A5FA)($v1)
  .L80103590:
    /* D90 80103590 1180103C */  lui        $s0, %hi(D_8010A5FA)
    /* D94 80103594 FAA50392 */  lbu        $v1, %lo(D_8010A5FA)($s0)
    /* D98 80103598 01001124 */  addiu      $s1, $zero, 0x1
    /* D9C 8010359C 20007110 */  beq        $v1, $s1, .L80103620
    /* DA0 801035A0 02006228 */   slti      $v0, $v1, 0x2
    /* DA4 801035A4 05004010 */  beqz       $v0, .L801035BC
    /* DA8 801035A8 02000224 */   addiu     $v0, $zero, 0x2
    /* DAC 801035AC 09006010 */  beqz       $v1, .L801035D4
    /* DB0 801035B0 21100000 */   addu      $v0, $zero, $zero
    /* DB4 801035B4 E00D0408 */  j          .L80103780
    /* DB8 801035B8 00000000 */   nop
  .L801035BC:
    /* DBC 801035BC 33006210 */  beq        $v1, $v0, .L8010368C
    /* DC0 801035C0 03000224 */   addiu     $v0, $zero, 0x3
    /* DC4 801035C4 69006210 */  beq        $v1, $v0, .L8010376C
    /* DC8 801035C8 21100000 */   addu      $v0, $zero, $zero
    /* DCC 801035CC E00D0408 */  j          .L80103780
    /* DD0 801035D0 00000000 */   nop
  .L801035D4:
    /* DD4 801035D4 74EA030C */  jal        vs_mainmenu_ready
    /* DD8 801035D8 00000000 */   nop
    /* DDC 801035DC 67004010 */  beqz       $v0, .L8010377C
    /* DE0 801035E0 1180023C */   lui       $v0, %hi(D_8010A5FC)
    /* DE4 801035E4 FCA54490 */  lbu        $a0, %lo(D_8010A5FC)($v0)
    /* DE8 801035E8 470B040C */  jal        _initMenuLayout
    /* DEC 801035EC 07000524 */   addiu     $a1, $zero, 0x7
    /* DF0 801035F0 0680033C */  lui        $v1, %hi(vs_main_inventoryIndices)
    /* DF4 801035F4 1180023C */  lui        $v0, %hi(D_8010A5FD)
    /* DF8 801035F8 FDA54290 */  lbu        $v0, %lo(D_8010A5FD)($v0)
    /* DFC 801035FC D8196324 */  addiu      $v1, $v1, %lo(vs_main_inventoryIndices)
    /* E00 80103600 21104300 */  addu       $v0, $v0, $v1
    /* E04 80103604 28004490 */  lbu        $a0, 0x28($v0)
    /* E08 80103608 68F5030C */  jal        vs_mainMenu_setShieldStats
    /* E0C 8010360C 00000000 */   nop
    /* E10 80103610 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* E14 80103614 03000424 */   addiu     $a0, $zero, 0x3
    /* E18 80103618 DF0D0408 */  j          .L8010377C
    /* E1C 8010361C FAA511A2 */   sb        $s1, %lo(D_8010A5FA)($s0)
  .L80103620:
    /* E20 80103620 1180043C */  lui        $a0, %hi(D_8010A5FB)
    /* E24 80103624 FBA58390 */  lbu        $v1, %lo(D_8010A5FB)($a0)
    /* E28 80103628 00000000 */  nop
    /* E2C 8010362C 0A00622C */  sltiu      $v0, $v1, 0xA
    /* E30 80103630 10004010 */  beqz       $v0, .L80103674
    /* E34 80103634 01006224 */   addiu     $v0, $v1, 0x1
    /* E38 80103638 FBA582A0 */  sb         $v0, %lo(D_8010A5FB)($a0)
    /* E3C 8010363C FF004230 */  andi       $v0, $v0, 0xFF
    /* E40 80103640 0400422C */  sltiu      $v0, $v0, 0x4
    /* E44 80103644 4D004010 */  beqz       $v0, .L8010377C
    /* E48 80103648 0680023C */   lui       $v0, %hi(vs_main_inventoryIndices)
    /* E4C 8010364C 1180033C */  lui        $v1, %hi(D_8010A5FD)
    /* E50 80103650 D8194224 */  addiu      $v0, $v0, %lo(vs_main_inventoryIndices)
    /* E54 80103654 FDA56390 */  lbu        $v1, %lo(D_8010A5FD)($v1)
    /* E58 80103658 FBA58490 */  lbu        $a0, %lo(D_8010A5FB)($a0)
    /* E5C 8010365C 21186200 */  addu       $v1, $v1, $v0
    /* E60 80103660 28006590 */  lbu        $a1, 0x28($v1)
    /* E64 80103664 C1F1030C */  jal        vs_mainMenu_initSetShieldGemMenu
    /* E68 80103668 01000624 */   addiu     $a2, $zero, 0x1
    /* E6C 8010366C E00D0408 */  j          .L80103780
    /* E70 80103670 21100000 */   addu      $v0, $zero, $zero
  .L80103674:
    /* E74 80103674 74EA030C */  jal        vs_mainmenu_ready
    /* E78 80103678 00000000 */   nop
    /* E7C 8010367C 3F004010 */  beqz       $v0, .L8010377C
    /* E80 80103680 02000224 */   addiu     $v0, $zero, 0x2
    /* E84 80103684 DF0D0408 */  j          .L8010377C
    /* E88 80103688 FAA502A2 */   sb        $v0, %lo(D_8010A5FA)($s0)
  .L8010368C:
    /* E8C 8010368C 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* E90 80103690 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* E94 80103694 00000000 */  nop
    /* E98 80103698 50004230 */  andi       $v0, $v0, 0x50
    /* E9C 8010369C 06004010 */  beqz       $v0, .L801036B8
    /* EA0 801036A0 00000000 */   nop
    /* EA4 801036A4 950B040C */  jal        _initMenuLeave
    /* EA8 801036A8 01000424 */   addiu     $a0, $zero, 0x1
    /* EAC 801036AC 03000224 */  addiu      $v0, $zero, 0x3
    /* EB0 801036B0 DF0D0408 */  j          .L8010377C
    /* EB4 801036B4 FAA502A2 */   sb        $v0, %lo(D_8010A5FA)($s0)
  .L801036B8:
    /* EB8 801036B8 1180103C */  lui        $s0, %hi(D_8010A5FD)
    /* EBC 801036BC FDA50592 */  lbu        $a1, %lo(D_8010A5FD)($s0)
    /* EC0 801036C0 980A040C */  jal        _handleItemPaging
    /* EC4 801036C4 03000424 */   addiu     $a0, $zero, 0x3
    /* EC8 801036C8 FDA50392 */  lbu        $v1, %lo(D_8010A5FD)($s0)
    /* ECC 801036CC 21884000 */  addu       $s1, $v0, $zero
    /* ED0 801036D0 2A002312 */  beq        $s1, $v1, .L8010377C
    /* ED4 801036D4 03000424 */   addiu     $a0, $zero, 0x3
    /* ED8 801036D8 21282002 */  addu       $a1, $s1, $zero
    /* EDC 801036DC 820B040C */  jal        _getItemIndex
    /* EE0 801036E0 FDA511A2 */   sb        $s1, %lo(D_8010A5FD)($s0)
    /* EE4 801036E4 21804000 */  addu       $s0, $v0, $zero
    /* EE8 801036E8 40101000 */  sll        $v0, $s0, 1
    /* EEC 801036EC 21105000 */  addu       $v0, $v0, $s0
    /* EF0 801036F0 00110200 */  sll        $v0, $v0, 4
    /* EF4 801036F4 0680043C */  lui        $a0, %hi(D_80060238)
    /* EF8 801036F8 38028424 */  addiu      $a0, $a0, %lo(D_80060238)
    /* EFC 801036FC 21204400 */  addu       $a0, $v0, $a0
    /* F00 80103700 1000A527 */  addiu      $a1, $sp, 0x10
    /* F04 80103704 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* F08 80103708 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* F0C 8010370C 90F3030C */  jal        vs_mainMenu_initUiShield
    /* F10 80103710 1800A627 */   addiu     $a2, $sp, 0x18
    /* F14 80103714 68F5030C */  jal        vs_mainMenu_setShieldStats
    /* F18 80103718 21200002 */   addu      $a0, $s0, $zero
    /* F1C 8010371C 1000A527 */  addiu      $a1, $sp, 0x10
    /* F20 80103720 21382002 */  addu       $a3, $s1, $zero
    /* F24 80103724 1180023C */  lui        $v0, %hi(D_8010A5FC)
    /* F28 80103728 FCA54490 */  lbu        $a0, %lo(D_8010A5FC)($v0)
    /* F2C 8010372C 1800A68F */  lw         $a2, 0x18($sp)
    /* F30 80103730 5B0B040C */  jal        _setSubMenu
    /* F34 80103734 01001024 */   addiu     $s0, $zero, 0x1
    /* F38 80103738 0680023C */  lui        $v0, %hi(vs_main_inventoryIndices)
    /* F3C 8010373C D8194224 */  addiu      $v0, $v0, %lo(vs_main_inventoryIndices)
    /* F40 80103740 21882202 */  addu       $s1, $s1, $v0
    /* F44 80103744 21200002 */  addu       $a0, $s0, $zero
  .L80103748:
    /* F48 80103748 28002592 */  lbu        $a1, 0x28($s1)
    /* F4C 8010374C 21300000 */  addu       $a2, $zero, $zero
    /* F50 80103750 C1F1030C */  jal        vs_mainMenu_initSetShieldGemMenu
    /* F54 80103754 01001026 */   addiu     $s0, $s0, 0x1
    /* F58 80103758 0400022A */  slti       $v0, $s0, 0x4
    /* F5C 8010375C FAFF4014 */  bnez       $v0, .L80103748
    /* F60 80103760 21200002 */   addu      $a0, $s0, $zero
    /* F64 80103764 E00D0408 */  j          .L80103780
    /* F68 80103768 21100000 */   addu      $v0, $zero, $zero
  .L8010376C:
    /* F6C 8010376C 74EA030C */  jal        vs_mainmenu_ready
    /* F70 80103770 00000000 */   nop
    /* F74 80103774 E00D0408 */  j          .L80103780
    /* F78 80103778 00000000 */   nop
  .L8010377C:
    /* F7C 8010377C 21100000 */  addu       $v0, $zero, $zero
  .L80103780:
    /* F80 80103780 2800BF8F */  lw         $ra, 0x28($sp)
    /* F84 80103784 2400B18F */  lw         $s1, 0x24($sp)
    /* F88 80103788 2000B08F */  lw         $s0, 0x20($sp)
    /* F8C 8010378C 0800E003 */  jr         $ra
    /* F90 80103790 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _shieldDetailsPage
