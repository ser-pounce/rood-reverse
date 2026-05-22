nonmatching _shamanMagicMenu, 0x344

glabel _shamanMagicMenu
    /* C64 80103464 80FFBD27 */  addiu      $sp, $sp, -0x80
    /* C68 80103468 21188000 */  addu       $v1, $a0, $zero
    /* C6C 8010346C 7C00BFAF */  sw         $ra, 0x7C($sp)
    /* C70 80103470 7800BEAF */  sw         $fp, 0x78($sp)
    /* C74 80103474 7400B7AF */  sw         $s7, 0x74($sp)
    /* C78 80103478 7000B6AF */  sw         $s6, 0x70($sp)
    /* C7C 8010347C 6C00B5AF */  sw         $s5, 0x6C($sp)
    /* C80 80103480 6800B4AF */  sw         $s4, 0x68($sp)
    /* C84 80103484 6400B3AF */  sw         $s3, 0x64($sp)
    /* C88 80103488 6000B2AF */  sw         $s2, 0x60($sp)
    /* C8C 8010348C 5C00B1AF */  sw         $s1, 0x5C($sp)
    /* C90 80103490 0C006010 */  beqz       $v1, .L801034C4
    /* C94 80103494 5800B0AF */   sw        $s0, 0x58($sp)
    /* C98 80103498 01000424 */  addiu      $a0, $zero, 0x1
    /* C9C 8010349C 21288000 */  addu       $a1, $a0, $zero
    /* CA0 801034A0 1080023C */  lui        $v0, %hi(D_801068FC)
    /* CA4 801034A4 02006338 */  xori       $v1, $v1, 0x2
    /* CA8 801034A8 2B186400 */  sltu       $v1, $v1, $a0
    /* CAC 801034AC 4BEA030C */  jal        func_800FA92C
    /* CB0 801034B0 FC6843AC */   sw        $v1, %lo(D_801068FC)($v0)
    /* CB4 801034B4 21100000 */  addu       $v0, $zero, $zero
    /* CB8 801034B8 1080033C */  lui        $v1, %hi(D_801068F4)
    /* CBC 801034BC DE0D0408 */  j          .L80103778
    /* CC0 801034C0 F46860AC */   sw        $zero, %lo(D_801068F4)($v1)
  .L801034C4:
    /* CC4 801034C4 1080023C */  lui        $v0, %hi(D_801068F4)
    /* CC8 801034C8 F468438C */  lw         $v1, %lo(D_801068F4)($v0)
    /* CCC 801034CC 01000224 */  addiu      $v0, $zero, 0x1
    /* CD0 801034D0 6E006210 */  beq        $v1, $v0, .L8010368C
    /* CD4 801034D4 02006228 */   slti      $v0, $v1, 0x2
    /* CD8 801034D8 05004010 */  beqz       $v0, .L801034F0
    /* CDC 801034DC 02000224 */   addiu     $v0, $zero, 0x2
    /* CE0 801034E0 07006010 */  beqz       $v1, .L80103500
    /* CE4 801034E4 21100000 */   addu      $v0, $zero, $zero
    /* CE8 801034E8 DE0D0408 */  j          .L80103778
    /* CEC 801034EC 00000000 */   nop
  .L801034F0:
    /* CF0 801034F0 99006210 */  beq        $v1, $v0, .L80103758
    /* CF4 801034F4 21100000 */   addu      $v0, $zero, $zero
    /* CF8 801034F8 DE0D0408 */  j          .L80103778
    /* CFC 801034FC 00000000 */   nop
  .L80103500:
    /* D00 80103500 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* D04 80103504 6A4E4290 */  lbu        $v0, %lo(vs_battle_shortcutInvoked)($v0)
    /* D08 80103508 00000000 */  nop
    /* D0C 8010350C 05004014 */  bnez       $v0, .L80103524
    /* D10 80103510 21980000 */   addu      $s3, $zero, $zero
    /* D14 80103514 74EA030C */  jal        vs_mainmenu_ready
    /* D18 80103518 00000000 */   nop
    /* D1C 8010351C 96004010 */  beqz       $v0, .L80103778
    /* D20 80103520 21100000 */   addu      $v0, $zero, $zero
  .L80103524:
    /* D24 80103524 21906002 */  addu       $s2, $s3, $zero
    /* D28 80103528 1080023C */  lui        $v0, %hi(_baseStrings)
    /* D2C 8010352C 584A5E24 */  addiu      $fp, $v0, %lo(_baseStrings)
    /* D30 80103530 3C001624 */  addiu      $s6, $zero, 0x3C
    /* D34 80103534 04001524 */  addiu      $s5, $zero, 0x4
    /* D38 80103538 1000B727 */  addiu      $s7, $sp, 0x10
    /* D3C 8010353C 21A0E002 */  addu       $s4, $s7, $zero
  .L80103540:
    /* D40 80103540 0F80083C */  lui        $t0, %hi(vs_battle_shamanSpellIds)
    /* D44 80103544 84BD0825 */  addiu      $t0, $t0, %lo(vs_battle_shamanSpellIds)
    /* D48 80103548 21104802 */  addu       $v0, $s2, $t0
    /* D4C 8010354C 0580083C */  lui        $t0, %hi(vs_main_skills)
    /* D50 80103550 00005190 */  lbu        $s1, 0x0($v0)
    /* D54 80103554 DCB90825 */  addiu      $t0, $t0, %lo(vs_main_skills)
    /* D58 80103558 40101100 */  sll        $v0, $s1, 1
    /* D5C 8010355C 21105100 */  addu       $v0, $v0, $s1
    /* D60 80103560 80100200 */  sll        $v0, $v0, 2
    /* D64 80103564 21105100 */  addu       $v0, $v0, $s1
    /* D68 80103568 80180200 */  sll        $v1, $v0, 2
    /* D6C 8010356C 21106800 */  addu       $v0, $v1, $t0
    /* D70 80103570 0C00428C */  lw         $v0, 0xC($v0)
    /* D74 80103574 00000000 */  nop
    /* D78 80103578 C2130200 */  srl        $v0, $v0, 15
    /* D7C 8010357C 01004230 */  andi       $v0, $v0, 0x1
    /* D80 80103580 1E004010 */  beqz       $v0, .L801035FC
    /* D84 80103584 21200000 */   addu      $a0, $zero, $zero
    /* D88 80103588 21282002 */  addu       $a1, $s1, $zero
    /* D8C 8010358C 0580083C */  lui        $t0, %hi(D_8004B9F8)
    /* D90 80103590 F8B90825 */  addiu      $t0, $t0, %lo(D_8004B9F8)
    /* D94 80103594 21106800 */  addu       $v0, $v1, $t0
    /* D98 80103598 000082AE */  sw         $v0, 0x0($s4)
    /* D9C 8010359C 2110DE02 */  addu       $v0, $s6, $fp
    /* DA0 801035A0 00004294 */  lhu        $v0, 0x0($v0)
    /* DA4 801035A4 2118F502 */  addu       $v1, $s7, $s5
    /* DA8 801035A8 40100200 */  sll        $v0, $v0, 1
    /* DAC 801035AC 21105E00 */  addu       $v0, $v0, $fp
    /* DB0 801035B0 000062AC */  sw         $v0, 0x0($v1)
    /* DB4 801035B4 80181300 */  sll        $v1, $s3, 2
    /* DB8 801035B8 4000A227 */  addiu      $v0, $sp, 0x40
    /* DBC 801035BC 21804300 */  addu       $s0, $v0, $v1
    /* DC0 801035C0 7429020C */  jal        vs_battle_getSkillFlags
    /* DC4 801035C4 000000AE */   sw        $zero, 0x0($s0)
    /* DC8 801035C8 06004010 */  beqz       $v0, .L801035E4
    /* DCC 801035CC 1080023C */   lui       $v0, %hi(_availableShamanSpells)
    /* DD0 801035D0 0000028E */  lw         $v0, 0x0($s0)
    /* DD4 801035D4 00000000 */  nop
    /* DD8 801035D8 01004234 */  ori        $v0, $v0, 0x1
    /* DDC 801035DC 000002AE */  sw         $v0, 0x0($s0)
    /* DE0 801035E0 1080023C */  lui        $v0, %hi(_availableShamanSpells)
  .L801035E4:
    /* DE4 801035E4 50694224 */  addiu      $v0, $v0, %lo(_availableShamanSpells)
    /* DE8 801035E8 21106202 */  addu       $v0, $s3, $v0
    /* DEC 801035EC 000051A0 */  sb         $s1, 0x0($v0)
    /* DF0 801035F0 0800B526 */  addiu      $s5, $s5, 0x8
    /* DF4 801035F4 08009426 */  addiu      $s4, $s4, 0x8
    /* DF8 801035F8 01007326 */  addiu      $s3, $s3, 0x1
  .L801035FC:
    /* DFC 801035FC 01005226 */  addiu      $s2, $s2, 0x1
    /* E00 80103600 0600422A */  slti       $v0, $s2, 0x6
    /* E04 80103604 CEFF4014 */  bnez       $v0, .L80103540
    /* E08 80103608 0200D626 */   addiu     $s6, $s6, 0x2
    /* E0C 8010360C 0F80023C */  lui        $v0, %hi(D_800F4EA0)
    /* E10 80103610 A04E428C */  lw         $v0, %lo(D_800F4EA0)($v0)
    /* E14 80103614 00000000 */  nop
    /* E18 80103618 B7004230 */  andi       $v0, $v0, 0xB7
    /* E1C 8010361C 09004010 */  beqz       $v0, .L80103644
    /* E20 80103620 21900000 */   addu      $s2, $zero, $zero
    /* E24 80103624 4000A327 */  addiu      $v1, $sp, 0x40
  .L80103628:
    /* E28 80103628 0000628C */  lw         $v0, 0x0($v1)
    /* E2C 8010362C 01005226 */  addiu      $s2, $s2, 0x1
    /* E30 80103630 01004234 */  ori        $v0, $v0, 0x1
    /* E34 80103634 000062AC */  sw         $v0, 0x0($v1)
    /* E38 80103638 0600422A */  slti       $v0, $s2, 0x6
    /* E3C 8010363C FAFF4014 */  bnez       $v0, .L80103628
    /* E40 80103640 04006324 */   addiu     $v1, $v1, 0x4
  .L80103644:
    /* E44 80103644 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* E48 80103648 20005024 */  addiu      $s0, $v0, %lo(vs_main_settings)
    /* E4C 8010364C 1080023C */  lui        $v0, %hi(D_801068FC)
    /* E50 80103650 FC68428C */  lw         $v0, %lo(D_801068FC)($v0)
    /* E54 80103654 01001292 */  lbu        $s2, 0x1($s0)
    /* E58 80103658 02004010 */  beqz       $v0, .L80103664
    /* E5C 8010365C 01000224 */   addiu     $v0, $zero, 0x1
    /* E60 80103660 010002A2 */  sb         $v0, 0x1($s0)
  .L80103664:
    /* E64 80103664 21206002 */  addu       $a0, $s3, $zero
    /* E68 80103668 08020524 */  addiu      $a1, $zero, 0x208
    /* E6C 8010366C 1000A627 */  addiu      $a2, $sp, 0x10
    /* E70 80103670 7801040C */  jal        vs_mainmenu_setMenuRows
    /* E74 80103674 4000A727 */   addiu     $a3, $sp, 0x40
    /* E78 80103678 1080033C */  lui        $v1, %hi(D_801068F4)
    /* E7C 8010367C 01000224 */  addiu      $v0, $zero, 0x1
    /* E80 80103680 010012A2 */  sb         $s2, 0x1($s0)
    /* E84 80103684 DD0D0408 */  j          .L80103774
    /* E88 80103688 F46862AC */   sw        $v0, %lo(D_801068F4)($v1)
  .L8010368C:
    /* E8C 8010368C 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* E90 80103690 1080103C */   lui       $s0, %hi(D_801068F8)
    /* E94 80103694 01004424 */  addiu      $a0, $v0, 0x1
    /* E98 80103698 26008010 */  beqz       $a0, .L80103734
    /* E9C 8010369C F86804AE */   sw        $a0, %lo(D_801068F8)($s0)
    /* EA0 801036A0 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* EA4 801036A4 6A4E4390 */  lbu        $v1, %lo(vs_battle_shortcutInvoked)($v0)
    /* EA8 801036A8 1080023C */  lui        $v0, %hi(vs_mainMenu_isLevelledSpell)
    /* EAC 801036AC 06006010 */  beqz       $v1, .L801036C8
    /* EB0 801036B0 D42240A0 */   sb        $zero, %lo(vs_mainMenu_isLevelledSpell)($v0)
    /* EB4 801036B4 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* EB8 801036B8 0B008214 */  bne        $a0, $v0, .L801036E8
    /* EBC 801036BC 1080043C */   lui       $a0, %hi(D_801068F8)
    /* EC0 801036C0 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* EC4 801036C4 F86802AE */  sw         $v0, %lo(D_801068F8)($s0)
  .L801036C8:
    /* EC8 801036C8 F868038E */  lw         $v1, %lo(D_801068F8)($s0)
    /* ECC 801036CC FFFF0224 */  addiu      $v0, $zero, -0x1
    /* ED0 801036D0 05006214 */  bne        $v1, $v0, .L801036E8
    /* ED4 801036D4 1080043C */   lui       $a0, %hi(D_801068F8)
    /* ED8 801036D8 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* EDC 801036DC 21200000 */   addu      $a0, $zero, $zero
    /* EE0 801036E0 CA0D0408 */  j          .L80103728
    /* EE4 801036E4 1080033C */   lui       $v1, %hi(D_801068F4)
  .L801036E8:
    /* EE8 801036E8 F868838C */  lw         $v1, %lo(D_801068F8)($a0)
    /* EEC 801036EC 00000000 */  nop
    /* EF0 801036F0 06006018 */  blez       $v1, .L8010370C
    /* EF4 801036F4 1080023C */   lui       $v0, %hi(_availableShamanSpells)
    /* EF8 801036F8 50694224 */  addiu      $v0, $v0, %lo(_availableShamanSpells)
    /* EFC 801036FC 21106200 */  addu       $v0, $v1, $v0
    /* F00 80103700 FFFF4290 */  lbu        $v0, -0x1($v0)
    /* F04 80103704 00000000 */  nop
    /* F08 80103708 F86882AC */  sw         $v0, %lo(D_801068F8)($a0)
  .L8010370C:
    /* F0C 8010370C 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* F10 80103710 28000424 */   addiu     $a0, $zero, 0x28
    /* F14 80103714 EAFE030C */  jal        func_800FFBA8
    /* F18 80103718 00000000 */   nop
    /* F1C 8010371C A2FE030C */  jal        func_800FFA88
    /* F20 80103720 21200000 */   addu      $a0, $zero, $zero
    /* F24 80103724 1080033C */  lui        $v1, %hi(D_801068F4)
  .L80103728:
    /* F28 80103728 02000224 */  addiu      $v0, $zero, 0x2
    /* F2C 8010372C DD0D0408 */  j          .L80103774
    /* F30 80103730 F46862AC */   sw        $v0, %lo(D_801068F4)($v1)
  .L80103734:
    /* F34 80103734 1080103C */  lui        $s0, %hi(_availableShamanSpells)
    /* F38 80103738 2C02040C */  jal        func_801008B0
    /* F3C 8010373C 50691026 */   addiu     $s0, $s0, %lo(_availableShamanSpells)
    /* F40 80103740 21105000 */  addu       $v0, $v0, $s0
    /* F44 80103744 00004490 */  lbu        $a0, 0x0($v0)
    /* F48 80103748 210A040C */  jal        _setMPCost
    /* F4C 8010374C 00000000 */   nop
    /* F50 80103750 DE0D0408 */  j          .L80103778
    /* F54 80103754 21100000 */   addu      $v0, $zero, $zero
  .L80103758:
    /* F58 80103758 74EA030C */  jal        vs_mainmenu_ready
    /* F5C 8010375C 00000000 */   nop
    /* F60 80103760 04004010 */  beqz       $v0, .L80103774
    /* F64 80103764 1080023C */   lui       $v0, %hi(D_801068F8)
    /* F68 80103768 F868428C */  lw         $v0, %lo(D_801068F8)($v0)
    /* F6C 8010376C DE0D0408 */  j          .L80103778
    /* F70 80103770 00000000 */   nop
  .L80103774:
    /* F74 80103774 21100000 */  addu       $v0, $zero, $zero
  .L80103778:
    /* F78 80103778 7C00BF8F */  lw         $ra, 0x7C($sp)
    /* F7C 8010377C 7800BE8F */  lw         $fp, 0x78($sp)
    /* F80 80103780 7400B78F */  lw         $s7, 0x74($sp)
    /* F84 80103784 7000B68F */  lw         $s6, 0x70($sp)
    /* F88 80103788 6C00B58F */  lw         $s5, 0x6C($sp)
    /* F8C 8010378C 6800B48F */  lw         $s4, 0x68($sp)
    /* F90 80103790 6400B38F */  lw         $s3, 0x64($sp)
    /* F94 80103794 6000B28F */  lw         $s2, 0x60($sp)
    /* F98 80103798 5C00B18F */  lw         $s1, 0x5C($sp)
    /* F9C 8010379C 5800B08F */  lw         $s0, 0x58($sp)
    /* FA0 801037A0 0800E003 */  jr         $ra
    /* FA4 801037A4 8000BD27 */   addiu     $sp, $sp, 0x80
endlabel _shamanMagicMenu
