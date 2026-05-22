nonmatching _defenseAbilityMenu, 0x174

glabel _defenseAbilityMenu
    /* E70 80103670 78FFBD27 */  addiu      $sp, $sp, -0x88
    /* E74 80103674 07008010 */  beqz       $a0, .L80103694
    /* E78 80103678 8000BFAF */   sw        $ra, 0x80($sp)
    /* E7C 8010367C 01000424 */  addiu      $a0, $zero, 0x1
    /* E80 80103680 4BEA030C */  jal        func_800FA92C
    /* E84 80103684 21288000 */   addu      $a1, $a0, $zero
    /* E88 80103688 1080023C */  lui        $v0, %hi(D_80104ED0)
    /* E8C 8010368C F40D0408 */  j          .L801037D0
    /* E90 80103690 D04E40AC */   sw        $zero, %lo(D_80104ED0)($v0)
  .L80103694:
    /* E94 80103694 1080023C */  lui        $v0, %hi(D_80104ED0)
    /* E98 80103698 D04E438C */  lw         $v1, %lo(D_80104ED0)($v0)
    /* E9C 8010369C 00000000 */  nop
    /* EA0 801036A0 05006010 */  beqz       $v1, .L801036B8
    /* EA4 801036A4 01000224 */   addiu     $v0, $zero, 0x1
    /* EA8 801036A8 41006210 */  beq        $v1, $v0, .L801037B0
    /* EAC 801036AC 21100000 */   addu      $v0, $zero, $zero
    /* EB0 801036B0 F50D0408 */  j          .L801037D4
    /* EB4 801036B4 00000000 */   nop
  .L801036B8:
    /* EB8 801036B8 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* EBC 801036BC 6A4E4290 */  lbu        $v0, %lo(vs_battle_shortcutInvoked)($v0)
    /* EC0 801036C0 00000000 */  nop
    /* EC4 801036C4 05004014 */  bnez       $v0, .L801036DC
    /* EC8 801036C8 21380000 */   addu      $a3, $zero, $zero
    /* ECC 801036CC 74EA030C */  jal        vs_mainmenu_ready
    /* ED0 801036D0 00000000 */   nop
    /* ED4 801036D4 3E004010 */  beqz       $v0, .L801037D0
    /* ED8 801036D8 21380000 */   addu      $a3, $zero, $zero
  .L801036DC:
    /* EDC 801036DC 2130E000 */  addu       $a2, $a3, $zero
    /* EE0 801036E0 0F80023C */  lui        $v0, %hi(vs_battle_defenseAbilityOffsets)
    /* EE4 801036E4 CCBD5824 */  addiu      $t8, $v0, %lo(vs_battle_defenseAbilityOffsets)
    /* EE8 801036E8 0580023C */  lui        $v0, %hi(vs_main_skills)
    /* EEC 801036EC DCB94D24 */  addiu      $t5, $v0, %lo(vs_main_skills)
    /* EF0 801036F0 1C00AF25 */  addiu      $t7, $t5, 0x1C
    /* EF4 801036F4 1080023C */  lui        $v0, %hi(_battleAbilityStrings)
    /* EF8 801036F8 90464C24 */  addiu      $t4, $v0, %lo(_battleAbilityStrings)
    /* EFC 801036FC 1080023C */  lui        $v0, %hi(_unlockedDefenseAbilities)
    /* F00 80103700 E0504E24 */  addiu      $t6, $v0, %lo(_unlockedDefenseAbilities)
    /* F04 80103704 28000A24 */  addiu      $t2, $zero, 0x28
    /* F08 80103708 04000924 */  addiu      $t1, $zero, 0x4
    /* F0C 8010370C 1000AB27 */  addiu      $t3, $sp, 0x10
    /* F10 80103710 21406001 */  addu       $t0, $t3, $zero
  .L80103714:
    /* F14 80103714 2110D800 */  addu       $v0, $a2, $t8
    /* F18 80103718 00004590 */  lbu        $a1, 0x0($v0)
    /* F1C 8010371C 00000000 */  nop
    /* F20 80103720 40100500 */  sll        $v0, $a1, 1
    /* F24 80103724 21104500 */  addu       $v0, $v0, $a1
    /* F28 80103728 80100200 */  sll        $v0, $v0, 2
    /* F2C 8010372C 21104500 */  addu       $v0, $v0, $a1
    /* F30 80103730 80180200 */  sll        $v1, $v0, 2
    /* F34 80103734 21106D00 */  addu       $v0, $v1, $t5
    /* F38 80103738 0C00428C */  lw         $v0, 0xC($v0)
    /* F3C 8010373C 00000000 */  nop
    /* F40 80103740 C2130200 */  srl        $v0, $v0, 15
    /* F44 80103744 01004230 */  andi       $v0, $v0, 0x1
    /* F48 80103748 0D004010 */  beqz       $v0, .L80103780
    /* F4C 8010374C 21206901 */   addu      $a0, $t3, $t1
    /* F50 80103750 08002925 */  addiu      $t1, $t1, 0x8
    /* F54 80103754 21106F00 */  addu       $v0, $v1, $t7
    /* F58 80103758 000002AD */  sw         $v0, 0x0($t0)
    /* F5C 8010375C 08000825 */  addiu      $t0, $t0, 0x8
    /* F60 80103760 21104C01 */  addu       $v0, $t2, $t4
    /* F64 80103764 2118EE00 */  addu       $v1, $a3, $t6
    /* F68 80103768 00004294 */  lhu        $v0, 0x0($v0)
    /* F6C 8010376C 0100E724 */  addiu      $a3, $a3, 0x1
    /* F70 80103770 40100200 */  sll        $v0, $v0, 1
    /* F74 80103774 21104C00 */  addu       $v0, $v0, $t4
    /* F78 80103778 000082AC */  sw         $v0, 0x0($a0)
    /* F7C 8010377C 000065A0 */  sb         $a1, 0x0($v1)
  .L80103780:
    /* F80 80103780 0100C624 */  addiu      $a2, $a2, 0x1
    /* F84 80103784 0E00C228 */  slti       $v0, $a2, 0xE
    /* F88 80103788 E2FF4014 */  bnez       $v0, .L80103714
    /* F8C 8010378C 02004A25 */   addiu     $t2, $t2, 0x2
    /* F90 80103790 2120E000 */  addu       $a0, $a3, $zero
    /* F94 80103794 19000524 */  addiu      $a1, $zero, 0x19
    /* F98 80103798 4A0A040C */  jal        _initAbilityMenu
    /* F9C 8010379C 1000A627 */   addiu     $a2, $sp, 0x10
    /* FA0 801037A0 1080033C */  lui        $v1, %hi(D_80104ED0)
    /* FA4 801037A4 01000224 */  addiu      $v0, $zero, 0x1
    /* FA8 801037A8 F40D0408 */  j          .L801037D0
    /* FAC 801037AC D04E62AC */   sw        $v0, %lo(D_80104ED0)($v1)
  .L801037B0:
    /* FB0 801037B0 2B0B040C */  jal        _abilityMenu
    /* FB4 801037B4 00000000 */   nop
    /* FB8 801037B8 06004010 */  beqz       $v0, .L801037D4
    /* FBC 801037BC 21100000 */   addu      $v0, $zero, $zero
    /* FC0 801037C0 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* FC4 801037C4 02000424 */   addiu     $a0, $zero, 0x2
    /* FC8 801037C8 F50D0408 */  j          .L801037D4
    /* FCC 801037CC 01000224 */   addiu     $v0, $zero, 0x1
  .L801037D0:
    /* FD0 801037D0 21100000 */  addu       $v0, $zero, $zero
  .L801037D4:
    /* FD4 801037D4 8000BF8F */  lw         $ra, 0x80($sp)
    /* FD8 801037D8 00000000 */  nop
    /* FDC 801037DC 0800E003 */  jr         $ra
    /* FE0 801037E0 8800BD27 */   addiu     $sp, $sp, 0x88
endlabel _defenseAbilityMenu
