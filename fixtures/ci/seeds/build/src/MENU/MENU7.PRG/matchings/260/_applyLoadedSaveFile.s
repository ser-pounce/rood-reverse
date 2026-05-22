nonmatching _applyLoadedSaveFile, 0x1B8

glabel _applyLoadedSaveFile
    /* E30 80103630 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* E34 80103634 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* E38 80103638 21988000 */  addu       $s3, $a0, $zero
    /* E3C 8010363C 1180023C */  lui        $v0, %hi(_spmcimg)
    /* E40 80103640 1400B1AF */  sw         $s1, 0x14($sp)
    /* E44 80103644 F0AD518C */  lw         $s1, %lo(_spmcimg)($v0)
    /* E48 80103648 7C5A0624 */  addiu      $a2, $zero, 0x5A7C
    /* E4C 8010364C 2400BFAF */  sw         $ra, 0x24($sp)
    /* E50 80103650 2000B4AF */  sw         $s4, 0x20($sp)
    /* E54 80103654 1800B2AF */  sw         $s2, 0x18($sp)
    /* E58 80103658 1000B0AF */  sw         $s0, 0x10($sp)
    /* E5C 8010365C 805D248E */  lw         $a0, 0x5D80($s1)
    /* E60 80103660 AF0B040C */  jal        _decode
    /* E64 80103664 845D2526 */   addiu     $a1, $s1, 0x5D84
    /* E68 80103668 5C000524 */  addiu      $a1, $zero, 0x5C
    /* E6C 8010366C 005C3026 */  addiu      $s0, $s1, 0x5C00
    /* E70 80103670 21A00002 */  addu       $s4, $s0, $zero
    /* E74 80103674 02006012 */  beqz       $s3, .L80103680
    /* E78 80103678 805D3226 */   addiu     $s2, $s1, 0x5D80
    /* E7C 8010367C 20000524 */  addiu      $a1, $zero, 0x20
  .L80103680:
    /* E80 80103680 8A0B040C */  jal        _verifySaveChecksums
    /* E84 80103684 21200002 */   addu      $a0, $s0, $zero
    /* E88 80103688 4F004014 */  bnez       $v0, .L801037C8
    /* E8C 8010368C 01000224 */   addiu     $v0, $zero, 0x1
    /* E90 80103690 0020033C */  lui        $v1, (0x20000107 >> 16)
    /* E94 80103694 0C00428E */  lw         $v0, 0xC($s2)
    /* E98 80103698 07016334 */  ori        $v1, $v1, (0x20000107 & 0xFFFF)
    /* E9C 8010369C 4A004314 */  bne        $v0, $v1, .L801037C8
    /* EA0 801036A0 01000224 */   addiu     $v0, $zero, 0x1
    /* EA4 801036A4 47006012 */  beqz       $s3, .L801037C4
    /* EA8 801036A8 0680043C */   lui       $a0, %hi(vs_main_stateFlags)
    /* EAC 801036AC 98158424 */  addiu      $a0, $a0, %lo(vs_main_stateFlags)
    /* EB0 801036B0 005E2526 */  addiu      $a1, $s1, 0x5E00
    /* EB4 801036B4 E70A040C */  jal        _rMemcpy
    /* EB8 801036B8 40040624 */   addiu     $a2, $zero, 0x440
    /* EBC 801036BC 0680043C */  lui        $a0, %hi(vs_main_skillsLearned)
    /* EC0 801036C0 B8FF8424 */  addiu      $a0, $a0, %lo(vs_main_skillsLearned)
    /* EC4 801036C4 40622526 */  addiu      $a1, $s1, 0x6240
    /* EC8 801036C8 E70A040C */  jal        _rMemcpy
    /* ECC 801036CC 20000624 */   addiu     $a2, $zero, 0x20
    /* ED0 801036D0 0680043C */  lui        $a0, %hi(vs_main_mapStatus)
    /* ED4 801036D4 D8FF8424 */  addiu      $a0, $a0, %lo(vs_main_mapStatus)
    /* ED8 801036D8 60622526 */  addiu      $a1, $s1, 0x6260
    /* EDC 801036DC E70A040C */  jal        _rMemcpy
    /* EE0 801036E0 48000624 */   addiu     $a2, $zero, 0x48
    /* EE4 801036E4 0680103C */  lui        $s0, %hi(vs_main_settings)
    /* EE8 801036E8 20001026 */  addiu      $s0, $s0, %lo(vs_main_settings)
    /* EEC 801036EC 21200002 */  addu       $a0, $s0, $zero
    /* EF0 801036F0 A8622526 */  addiu      $a1, $s1, 0x62A8
    /* EF4 801036F4 E70A040C */  jal        _rMemcpy
    /* EF8 801036F8 20000624 */   addiu     $a2, $zero, 0x20
    /* EFC 801036FC 0680043C */  lui        $a0, %hi(D_80060068)
    /* F00 80103700 68008424 */  addiu      $a0, $a0, %lo(D_80060068)
    /* F04 80103704 C8622526 */  addiu      $a1, $s1, 0x62C8
    /* F08 80103708 E70A040C */  jal        _rMemcpy
    /* F0C 8010370C 00010624 */   addiu     $a2, $zero, 0x100
    /* F10 80103710 0680043C */  lui        $a0, %hi(vs_battle_inventory)
    /* F14 80103714 68018424 */  addiu      $a0, $a0, %lo(vs_battle_inventory)
    /* F18 80103718 C8632526 */  addiu      $a1, $s1, 0x63C8
    /* F1C 8010371C E70A040C */  jal        _rMemcpy
    /* F20 80103720 000F0624 */   addiu     $a2, $zero, 0xF00
    /* F24 80103724 0680043C */  lui        $a0, %hi(vs_main_inventoryIndices)
    /* F28 80103728 D8198424 */  addiu      $a0, $a0, %lo(vs_main_inventoryIndices)
    /* F2C 8010372C C8722526 */  addiu      $a1, $s1, 0x72C8
    /* F30 80103730 E70A040C */  jal        _rMemcpy
    /* F34 80103734 B0000624 */   addiu     $a2, $zero, 0xB0
    /* F38 80103738 0680043C */  lui        $a0, %hi(D_80061068)
    /* F3C 8010373C 68108424 */  addiu      $a0, $a0, %lo(D_80061068)
    /* F40 80103740 78732526 */  addiu      $a1, $s1, 0x7378
    /* F44 80103744 E70A040C */  jal        _rMemcpy
    /* F48 80103748 0C000624 */   addiu     $a2, $zero, 0xC
    /* F4C 8010374C 0680043C */  lui        $a0, %hi(vs_main_scoredata)
    /* F50 80103750 A0FE8424 */  addiu      $a0, $a0, %lo(vs_main_scoredata)
    /* F54 80103754 84732526 */  addiu      $a1, $s1, 0x7384
    /* F58 80103758 E70A040C */  jal        _rMemcpy
    /* F5C 8010375C 14010624 */   addiu     $a2, $zero, 0x114
    /* F60 80103760 0680043C */  lui        $a0, %hi(D_80061078)
    /* F64 80103764 78108424 */  addiu      $a0, $a0, %lo(D_80061078)
    /* F68 80103768 9C742526 */  addiu      $a1, $s1, 0x749C
    /* F6C 8010376C 20050624 */  addiu      $a2, $zero, 0x520
    /* F70 80103770 9818838E */  lw         $v1, 0x1898($s4)
    /* F74 80103774 0680023C */  lui        $v0, %hi(D_80060064)
    /* F78 80103778 E70A040C */  jal        _rMemcpy
    /* F7C 8010377C 640043AC */   sw        $v1, %lo(D_80060064)($v0)
    /* F80 80103780 0680043C */  lui        $a0, %hi(vs_main_artsStatus)
    /* F84 80103784 40008424 */  addiu      $a0, $a0, %lo(vs_main_artsStatus)
    /* F88 80103788 BC792526 */  addiu      $a1, $s1, 0x79BC
    /* F8C 8010378C E70A040C */  jal        _rMemcpy
    /* F90 80103790 24000624 */   addiu     $a2, $zero, 0x24
    /* F94 80103794 0680023C */  lui        $v0, %hi(vs_main_gametime)
    /* F98 80103798 74104A24 */  addiu      $t2, $v0, %lo(vs_main_gametime)
    /* F9C 8010379C 935D278A */  lwl        $a3, 0x5D93($s1)
    /* FA0 801037A0 905D279A */  lwr        $a3, 0x5D90($s1)
    /* FA4 801037A4 00000000 */  nop
    /* FA8 801037A8 030047A9 */  swl        $a3, 0x3($t2)
    /* FAC 801037AC 000047B9 */  swr        $a3, 0x0($t2)
    /* FB0 801037B0 280B010C */  jal        func_80042CA0
    /* FB4 801037B4 00000000 */   nop
    /* FB8 801037B8 0A000492 */  lbu        $a0, 0xA($s0)
    /* FBC 801037BC 2F1A010C */  jal        vs_main_setMonoSound
    /* FC0 801037C0 00000000 */   nop
  .L801037C4:
    /* FC4 801037C4 21100000 */  addu       $v0, $zero, $zero
  .L801037C8:
    /* FC8 801037C8 2400BF8F */  lw         $ra, 0x24($sp)
    /* FCC 801037CC 2000B48F */  lw         $s4, 0x20($sp)
    /* FD0 801037D0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* FD4 801037D4 1800B28F */  lw         $s2, 0x18($sp)
    /* FD8 801037D8 1400B18F */  lw         $s1, 0x14($sp)
    /* FDC 801037DC 1000B08F */  lw         $s0, 0x10($sp)
    /* FE0 801037E0 0800E003 */  jr         $ra
    /* FE4 801037E4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _applyLoadedSaveFile
