nonmatching _battleAbilityUnlocked, 0x758

glabel _battleAbilityUnlocked
    /* 1620 80103E20 A0FEBD27 */  addiu      $sp, $sp, -0x160
    /* 1624 80103E24 5801BFAF */  sw         $ra, 0x158($sp)
    /* 1628 80103E28 5401B5AF */  sw         $s5, 0x154($sp)
    /* 162C 80103E2C 5001B4AF */  sw         $s4, 0x150($sp)
    /* 1630 80103E30 4C01B3AF */  sw         $s3, 0x14C($sp)
    /* 1634 80103E34 4801B2AF */  sw         $s2, 0x148($sp)
    /* 1638 80103E38 4401B1AF */  sw         $s1, 0x144($sp)
    /* 163C 80103E3C 69008010 */  beqz       $a0, .L80103FE4
    /* 1640 80103E40 4001B0AF */   sw        $s0, 0x140($sp)
    /* 1644 80103E44 0680023C */  lui        $v0, %hi(vs_main_artsStatus)
    /* 1648 80103E48 40004724 */  addiu      $a3, $v0, %lo(vs_main_artsStatus)
    /* 164C 80103E4C 2000F194 */  lhu        $s1, 0x20($a3)
    /* 1650 80103E50 16000224 */  addiu      $v0, $zero, 0x16
    /* 1654 80103E54 B5012212 */  beq        $s1, $v0, .L8010452C
    /* 1658 80103E58 0580023C */   lui       $v0, %hi(vs_main_battleAbilitiesPointsRequirements)
    /* 165C 80103E5C 5CFE4224 */  addiu      $v0, $v0, %lo(vs_main_battleAbilitiesPointsRequirements)
    /* 1660 80103E60 40181100 */  sll        $v1, $s1, 1
    /* 1664 80103E64 21186200 */  addu       $v1, $v1, $v0
    /* 1668 80103E68 2200E294 */  lhu        $v0, 0x22($a3)
    /* 166C 80103E6C 00006394 */  lhu        $v1, 0x0($v1)
    /* 1670 80103E70 00000000 */  nop
    /* 1674 80103E74 2B104300 */  sltu       $v0, $v0, $v1
    /* 1678 80103E78 B6014014 */  bnez       $v0, .L80104554
    /* 167C 80103E7C 01000224 */   addiu     $v0, $zero, 0x1
    /* 1680 80103E80 0F80043C */  lui        $a0, %hi(D_800F4EE8 + 0x34)
    /* 1684 80103E84 1C4F8424 */  addiu      $a0, $a0, %lo(D_800F4EE8 + 0x34)
    /* 1688 80103E88 21280000 */  addu       $a1, $zero, $zero
    /* 168C 80103E8C 06000624 */  addiu      $a2, $zero, 0x6
    /* 1690 80103E90 01002226 */  addiu      $v0, $s1, 0x1
    /* 1694 80103E94 AD9B000C */  jal        memset
    /* 1698 80103E98 2000E2A4 */   sh        $v0, 0x20($a3)
    /* 169C 80103E9C 21880000 */  addu       $s1, $zero, $zero
    /* 16A0 80103EA0 1080023C */  lui        $v0, %hi(_unlockableChainAbilities)
    /* 16A4 80103EA4 60504824 */  addiu      $t0, $v0, %lo(_unlockableChainAbilities)
    /* 16A8 80103EA8 0580023C */  lui        $v0, %hi(vs_main_skills)
    /* 16AC 80103EAC DCB94724 */  addiu      $a3, $v0, %lo(vs_main_skills)
    /* 16B0 80103EB0 1080023C */  lui        $v0, %hi(remainingChainAbilities)
    /* 16B4 80103EB4 00514624 */  addiu      $a2, $v0, %lo(remainingChainAbilities)
    /* 16B8 80103EB8 1080023C */  lui        $v0, %hi(remainingChainAbilityCount)
    /* 16BC 80103EBC 21284000 */  addu       $a1, $v0, $zero
    /* 16C0 80103EC0 1B51A0A0 */  sb         $zero, %lo(remainingChainAbilityCount)($a1)
    /* 16C4 80103EC4 21102802 */  addu       $v0, $s1, $t0
  .L80103EC8:
    /* 16C8 80103EC8 00004490 */  lbu        $a0, 0x0($v0)
    /* 16CC 80103ECC 00000000 */  nop
    /* 16D0 80103ED0 40100400 */  sll        $v0, $a0, 1
    /* 16D4 80103ED4 21104400 */  addu       $v0, $v0, $a0
    /* 16D8 80103ED8 80100200 */  sll        $v0, $v0, 2
    /* 16DC 80103EDC 21104400 */  addu       $v0, $v0, $a0
    /* 16E0 80103EE0 80100200 */  sll        $v0, $v0, 2
    /* 16E4 80103EE4 21104700 */  addu       $v0, $v0, $a3
    /* 16E8 80103EE8 0C00428C */  lw         $v0, 0xC($v0)
    /* 16EC 80103EEC 00000000 */  nop
    /* 16F0 80103EF0 C2130200 */  srl        $v0, $v0, 15
    /* 16F4 80103EF4 01004230 */  andi       $v0, $v0, 0x1
    /* 16F8 80103EF8 08004014 */  bnez       $v0, .L80103F1C
    /* 16FC 80103EFC 00000000 */   nop
    /* 1700 80103F00 1B51A290 */  lbu        $v0, %lo(remainingChainAbilityCount)($a1)
    /* 1704 80103F04 00000000 */  nop
    /* 1708 80103F08 01004324 */  addiu      $v1, $v0, 0x1
    /* 170C 80103F0C FF004230 */  andi       $v0, $v0, 0xFF
    /* 1710 80103F10 21104600 */  addu       $v0, $v0, $a2
    /* 1714 80103F14 1B51A3A0 */  sb         $v1, %lo(remainingChainAbilityCount)($a1)
    /* 1718 80103F18 000044A0 */  sb         $a0, 0x0($v0)
  .L80103F1C:
    /* 171C 80103F1C 01003126 */  addiu      $s1, $s1, 0x1
    /* 1720 80103F20 0B00222A */  slti       $v0, $s1, 0xB
    /* 1724 80103F24 E8FF4014 */  bnez       $v0, .L80103EC8
    /* 1728 80103F28 21102802 */   addu      $v0, $s1, $t0
    /* 172C 80103F2C 1080033C */  lui        $v1, %hi(remainingDefenseAbilityCount)
    /* 1730 80103F30 1C5160A0 */  sb         $zero, %lo(remainingDefenseAbilityCount)($v1)
    /* 1734 80103F34 21880000 */  addu       $s1, $zero, $zero
    /* 1738 80103F38 1080023C */  lui        $v0, %hi(_unlockableDefenseAbilities)
    /* 173C 80103F3C 6C504824 */  addiu      $t0, $v0, %lo(_unlockableDefenseAbilities)
    /* 1740 80103F40 0580023C */  lui        $v0, %hi(vs_main_skills)
    /* 1744 80103F44 DCB94724 */  addiu      $a3, $v0, %lo(vs_main_skills)
    /* 1748 80103F48 1080023C */  lui        $v0, %hi(remainingDefenseAbilities)
    /* 174C 80103F4C 10514624 */  addiu      $a2, $v0, %lo(remainingDefenseAbilities)
    /* 1750 80103F50 21286000 */  addu       $a1, $v1, $zero
    /* 1754 80103F54 21102802 */  addu       $v0, $s1, $t0
  .L80103F58:
    /* 1758 80103F58 00004490 */  lbu        $a0, 0x0($v0)
    /* 175C 80103F5C 00000000 */  nop
    /* 1760 80103F60 40100400 */  sll        $v0, $a0, 1
    /* 1764 80103F64 21104400 */  addu       $v0, $v0, $a0
    /* 1768 80103F68 80100200 */  sll        $v0, $v0, 2
    /* 176C 80103F6C 21104400 */  addu       $v0, $v0, $a0
    /* 1770 80103F70 80100200 */  sll        $v0, $v0, 2
    /* 1774 80103F74 21104700 */  addu       $v0, $v0, $a3
    /* 1778 80103F78 0C00428C */  lw         $v0, 0xC($v0)
    /* 177C 80103F7C 00000000 */  nop
    /* 1780 80103F80 C2130200 */  srl        $v0, $v0, 15
    /* 1784 80103F84 01004230 */  andi       $v0, $v0, 0x1
    /* 1788 80103F88 08004014 */  bnez       $v0, .L80103FAC
    /* 178C 80103F8C 00000000 */   nop
    /* 1790 80103F90 1C51A290 */  lbu        $v0, %lo(remainingDefenseAbilityCount)($a1)
    /* 1794 80103F94 00000000 */  nop
    /* 1798 80103F98 01004324 */  addiu      $v1, $v0, 0x1
    /* 179C 80103F9C FF004230 */  andi       $v0, $v0, 0xFF
    /* 17A0 80103FA0 21104600 */  addu       $v0, $v0, $a2
    /* 17A4 80103FA4 1C51A3A0 */  sb         $v1, %lo(remainingDefenseAbilityCount)($a1)
    /* 17A8 80103FA8 000044A0 */  sb         $a0, 0x0($v0)
  .L80103FAC:
    /* 17AC 80103FAC 01003126 */  addiu      $s1, $s1, 0x1
    /* 17B0 80103FB0 0B00222A */  slti       $v0, $s1, 0xB
    /* 17B4 80103FB4 E8FF4014 */  bnez       $v0, .L80103F58
    /* 17B8 80103FB8 21102802 */   addu      $v0, $s1, $t0
    /* 17BC 80103FBC 21100000 */  addu       $v0, $zero, $zero
    /* 17C0 80103FC0 1080043C */  lui        $a0, %hi(menuNotEntered)
    /* 17C4 80103FC4 03000324 */  addiu      $v1, $zero, 0x3
    /* 17C8 80103FC8 1F5183A0 */  sb         $v1, %lo(menuNotEntered)($a0)
    /* 17CC 80103FCC 1080043C */  lui        $a0, %hi(remainingDefenseAbilityCount + 0x2)
    /* 17D0 80103FD0 78000324 */  addiu      $v1, $zero, 0x78
    /* 17D4 80103FD4 1E5183A0 */  sb         $v1, %lo(remainingDefenseAbilityCount + 0x2)($a0)
    /* 17D8 80103FD8 1080033C */  lui        $v1, %hi(remainingDefenseAbilityCount + 0x1)
    /* 17DC 80103FDC 55110408 */  j          .L80104554
    /* 17E0 80103FE0 1D5160A0 */   sb        $zero, %lo(remainingDefenseAbilityCount + 0x1)($v1)
  .L80103FE4:
    /* 17E4 80103FE4 1080023C */  lui        $v0, %hi(remainingDefenseAbilityCount + 0x1)
    /* 17E8 80103FE8 1D514390 */  lbu        $v1, %lo(remainingDefenseAbilityCount + 0x1)($v0)
    /* 17EC 80103FEC 00000000 */  nop
    /* 17F0 80103FF0 0800622C */  sltiu      $v0, $v1, 0x8
    /* 17F4 80103FF4 56014010 */  beqz       $v0, .L80104550
    /* 17F8 80103FF8 1080023C */   lui       $v0, %hi(jtbl_8010282C)
    /* 17FC 80103FFC 2C284224 */  addiu      $v0, $v0, %lo(jtbl_8010282C)
    /* 1800 80104000 80180300 */  sll        $v1, $v1, 2
    /* 1804 80104004 21186200 */  addu       $v1, $v1, $v0
    /* 1808 80104008 0000628C */  lw         $v0, 0x0($v1)
    /* 180C 8010400C 00000000 */  nop
    /* 1810 80104010 08004000 */  jr         $v0
    /* 1814 80104014 00000000 */   nop
    /* 1818 80104018 1080023C */  lui        $v0, %hi(remainingChainAbilityCount)
    /* 181C 8010401C 1080033C */  lui        $v1, %hi(remainingDefenseAbilityCount)
    /* 1820 80104020 1B514290 */  lbu        $v0, %lo(remainingChainAbilityCount)($v0)
    /* 1824 80104024 1C516390 */  lbu        $v1, %lo(remainingDefenseAbilityCount)($v1)
    /* 1828 80104028 00000000 */  nop
    /* 182C 8010402C 02006010 */  beqz       $v1, .L80104038
    /* 1830 80104030 2B800200 */   sltu      $s0, $zero, $v0
    /* 1834 80104034 02001026 */  addiu      $s0, $s0, 0x2
  .L80104038:
    /* 1838 80104038 01001224 */  addiu      $s2, $zero, 0x1
    /* 183C 8010403C 14001212 */  beq        $s0, $s2, .L80104090
    /* 1840 80104040 0200022A */   slti      $v0, $s0, 0x2
    /* 1844 80104044 05004010 */  beqz       $v0, .L8010405C
    /* 1848 80104048 02000224 */   addiu     $v0, $zero, 0x2
    /* 184C 8010404C 09000012 */  beqz       $s0, .L80104074
    /* 1850 80104050 21100000 */   addu      $v0, $zero, $zero
    /* 1854 80104054 55110408 */  j          .L80104554
    /* 1858 80104058 00000000 */   nop
  .L8010405C:
    /* 185C 8010405C 1F000212 */  beq        $s0, $v0, .L801040DC
    /* 1860 80104060 03000224 */   addiu     $v0, $zero, 0x3
    /* 1864 80104064 30000212 */  beq        $s0, $v0, .L80104128
    /* 1868 80104068 21100000 */   addu      $v0, $zero, $zero
    /* 186C 8010406C 55110408 */  j          .L80104554
    /* 1870 80104070 00000000 */   nop
  .L80104074:
    /* 1874 80104074 1080043C */  lui        $a0, %hi(D_80105026)
    /* 1878 80104078 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 187C 8010407C 26508424 */   addiu     $a0, $a0, %lo(D_80105026)
    /* 1880 80104080 1080033C */  lui        $v1, %hi(remainingDefenseAbilityCount + 0x1)
    /* 1884 80104084 06000224 */  addiu      $v0, $zero, 0x6
    /* 1888 80104088 54110408 */  j          .L80104550
    /* 188C 8010408C 1D5162A0 */   sb        $v0, %lo(remainingDefenseAbilityCount + 0x1)($v1)
  .L80104090:
    /* 1890 80104090 21200000 */  addu       $a0, $zero, $zero
    /* 1894 80104094 40010524 */  addiu      $a1, $zero, 0x140
    /* 1898 80104098 12000624 */  addiu      $a2, $zero, 0x12
    /* 189C 8010409C 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 18A0 801040A0 08000224 */  addiu      $v0, $zero, 0x8
    /* 18A4 801040A4 1000A2AF */  sw         $v0, 0x10($sp)
    /* 18A8 801040A8 1080023C */  lui        $v0, %hi(D_80105004)
    /* 18AC 801040AC 04504224 */  addiu      $v0, $v0, %lo(D_80105004)
    /* 18B0 801040B0 9723030C */  jal        vs_battle_setMenuItem
    /* 18B4 801040B4 1400A2AF */   sw        $v0, 0x14($sp)
    /* 18B8 801040B8 21204000 */  addu       $a0, $v0, $zero
    /* 18BC 801040BC 02000324 */  addiu      $v1, $zero, 0x2
    /* 18C0 801040C0 B4000224 */  addiu      $v0, $zero, 0xB4
    /* 18C4 801040C4 180082A4 */  sh         $v0, 0x18($a0)
    /* 18C8 801040C8 1080023C */  lui        $v0, %hi(remainingDefenseAbilityCount + 0x1)
    /* 18CC 801040CC 000083A0 */  sb         $v1, 0x0($a0)
    /* 18D0 801040D0 060092A0 */  sb         $s2, 0x6($a0)
    /* 18D4 801040D4 54110408 */  j          .L80104550
    /* 18D8 801040D8 1D5143A0 */   sb        $v1, %lo(remainingDefenseAbilityCount + 0x1)($v0)
  .L801040DC:
    /* 18DC 801040DC 01000424 */  addiu      $a0, $zero, 0x1
    /* 18E0 801040E0 40010524 */  addiu      $a1, $zero, 0x140
    /* 18E4 801040E4 12000624 */  addiu      $a2, $zero, 0x12
    /* 18E8 801040E8 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 18EC 801040EC 08000224 */  addiu      $v0, $zero, 0x8
    /* 18F0 801040F0 1000A2AF */  sw         $v0, 0x10($sp)
    /* 18F4 801040F4 1080023C */  lui        $v0, %hi(D_80105014)
    /* 18F8 801040F8 14504224 */  addiu      $v0, $v0, %lo(D_80105014)
    /* 18FC 801040FC 9723030C */  jal        vs_battle_setMenuItem
    /* 1900 80104100 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1904 80104104 21204000 */  addu       $a0, $v0, $zero
    /* 1908 80104108 B4000224 */  addiu      $v0, $zero, 0xB4
    /* 190C 8010410C 1080033C */  lui        $v1, %hi(remainingDefenseAbilityCount + 0x1)
    /* 1910 80104110 180082A4 */  sh         $v0, 0x18($a0)
    /* 1914 80104114 03000224 */  addiu      $v0, $zero, 0x3
    /* 1918 80104118 000090A0 */  sb         $s0, 0x0($a0)
    /* 191C 8010411C 060092A0 */  sb         $s2, 0x6($a0)
    /* 1920 80104120 54110408 */  j          .L80104550
    /* 1924 80104124 1D5162A0 */   sb        $v0, %lo(remainingDefenseAbilityCount + 0x1)($v1)
  .L80104128:
    /* 1928 80104128 02000424 */  addiu      $a0, $zero, 0x2
    /* 192C 8010412C 1A000524 */  addiu      $a1, $zero, 0x1A
    /* 1930 80104130 1800A627 */  addiu      $a2, $sp, 0x18
    /* 1934 80104134 2800A727 */  addiu      $a3, $sp, 0x28
    /* 1938 80104138 0680103C */  lui        $s0, %hi(vs_main_settings)
    /* 193C 8010413C 20001026 */  addiu      $s0, $s0, %lo(vs_main_settings)
    /* 1940 80104140 1080023C */  lui        $v0, %hi(D_80105004)
    /* 1944 80104144 04504224 */  addiu      $v0, $v0, %lo(D_80105004)
    /* 1948 80104148 01001192 */  lbu        $s1, 0x1($s0)
    /* 194C 8010414C A2FF4324 */  addiu      $v1, $v0, -0x5E
    /* 1950 80104150 1800A2AF */  sw         $v0, 0x18($sp)
    /* 1954 80104154 10004224 */  addiu      $v0, $v0, 0x10
    /* 1958 80104158 1C00A3AF */  sw         $v1, 0x1C($sp)
    /* 195C 8010415C 2000A2AF */  sw         $v0, 0x20($sp)
    /* 1960 80104160 2400A3AF */  sw         $v1, 0x24($sp)
    /* 1964 80104164 2800A0AF */  sw         $zero, 0x28($sp)
    /* 1968 80104168 2C00A0AF */  sw         $zero, 0x2C($sp)
    /* 196C 8010416C 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 1970 80104170 010012A2 */   sb        $s2, 0x1($s0)
    /* 1974 80104174 1080023C */  lui        $v0, %hi(remainingDefenseAbilityCount + 0x1)
    /* 1978 80104178 1D5152A0 */  sb         $s2, %lo(remainingDefenseAbilityCount + 0x1)($v0)
    /* 197C 8010417C 54110408 */  j          .L80104550
    /* 1980 80104180 010011A2 */   sb        $s1, 0x1($s0)
    /* 1984 80104184 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 1988 80104188 00000000 */   nop
    /* 198C 8010418C 01005124 */  addiu      $s1, $v0, 0x1
    /* 1990 80104190 EF002012 */  beqz       $s1, .L80104550
    /* 1994 80104194 00000000 */   nop
    /* 1998 80104198 05002106 */  bgez       $s1, .L801041B0
    /* 199C 8010419C 21204000 */   addu      $a0, $v0, $zero
    /* 19A0 801041A0 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 19A4 801041A4 28000424 */   addiu     $a0, $zero, 0x28
    /* 19A8 801041A8 1D110408 */  j          .L80104474
    /* 19AC 801041AC 1080033C */   lui       $v1, %hi(remainingDefenseAbilityCount + 0x1)
  .L801041B0:
    /* 19B0 801041B0 4BEA030C */  jal        func_800FA92C
    /* 19B4 801041B4 21280000 */   addu      $a1, $zero, $zero
    /* 19B8 801041B8 1080033C */  lui        $v1, %hi(remainingDefenseAbilityCount + 0x1)
    /* 19BC 801041BC 1D516290 */  lbu        $v0, %lo(remainingDefenseAbilityCount + 0x1)($v1)
    /* 19C0 801041C0 00000000 */  nop
    /* 19C4 801041C4 21105100 */  addu       $v0, $v0, $s1
    /* 19C8 801041C8 54110408 */  j          .L80104550
    /* 19CC 801041CC 1D5162A0 */   sb        $v0, %lo(remainingDefenseAbilityCount + 0x1)($v1)
    /* 19D0 801041D0 74EA030C */  jal        vs_mainmenu_ready
    /* 19D4 801041D4 00000000 */   nop
    /* 19D8 801041D8 DD004010 */  beqz       $v0, .L80104550
    /* 19DC 801041DC 1080023C */   lui       $v0, %hi(remainingChainAbilityCount)
    /* 19E0 801041E0 1B514290 */  lbu        $v0, %lo(remainingChainAbilityCount)($v0)
    /* 19E4 801041E4 00000000 */  nop
    /* 19E8 801041E8 20004010 */  beqz       $v0, .L8010426C
    /* 19EC 801041EC 21880000 */   addu      $s1, $zero, $zero
    /* 19F0 801041F0 1080023C */  lui        $v0, %hi(remainingChainAbilities)
    /* 19F4 801041F4 00515524 */  addiu      $s5, $v0, %lo(remainingChainAbilities)
    /* 19F8 801041F8 0580023C */  lui        $v0, %hi(D_8004B9F8)
    /* 19FC 801041FC F8B95424 */  addiu      $s4, $v0, %lo(D_8004B9F8)
    /* 1A00 80104200 04001224 */  addiu      $s2, $zero, 0x4
    /* 1A04 80104204 3000B327 */  addiu      $s3, $sp, 0x30
    /* 1A08 80104208 21806002 */  addu       $s0, $s3, $zero
  .L8010420C:
    /* 1A0C 8010420C 21203502 */  addu       $a0, $s1, $s5
    /* 1A10 80104210 00008390 */  lbu        $v1, 0x0($a0)
    /* 1A14 80104214 00000000 */  nop
    /* 1A18 80104218 40100300 */  sll        $v0, $v1, 1
    /* 1A1C 8010421C 21104300 */  addu       $v0, $v0, $v1
    /* 1A20 80104220 80100200 */  sll        $v0, $v0, 2
    /* 1A24 80104224 21104300 */  addu       $v0, $v0, $v1
    /* 1A28 80104228 80100200 */  sll        $v0, $v0, 2
    /* 1A2C 8010422C 21105400 */  addu       $v0, $v0, $s4
    /* 1A30 80104230 000002AE */  sw         $v0, 0x0($s0)
    /* 1A34 80104234 00008490 */  lbu        $a0, 0x0($a0)
    /* 1A38 80104238 760F040C */  jal        _getAbilityDescription
    /* 1A3C 8010423C 08001026 */   addiu     $s0, $s0, 0x8
    /* 1A40 80104240 21187202 */  addu       $v1, $s3, $s2
    /* 1A44 80104244 08005226 */  addiu      $s2, $s2, 0x8
    /* 1A48 80104248 80201100 */  sll        $a0, $s1, 2
    /* 1A4C 8010424C 01003126 */  addiu      $s1, $s1, 0x1
    /* 1A50 80104250 000062AC */  sw         $v0, 0x0($v1)
    /* 1A54 80104254 1080023C */  lui        $v0, %hi(remainingChainAbilityCount)
    /* 1A58 80104258 1B514390 */  lbu        $v1, %lo(remainingChainAbilityCount)($v0)
    /* 1A5C 8010425C 2110A403 */  addu       $v0, $sp, $a0
    /* 1A60 80104260 2A182302 */  slt        $v1, $s1, $v1
    /* 1A64 80104264 E9FF6014 */  bnez       $v1, .L8010420C
    /* 1A68 80104268 880040AC */   sw        $zero, 0x88($v0)
  .L8010426C:
    /* 1A6C 8010426C 1080053C */  lui        $a1, %hi(remainingChainAbilityCount)
    /* 1A70 80104270 1B51A390 */  lbu        $v1, %lo(remainingChainAbilityCount)($a1)
    /* 1A74 80104274 01000224 */  addiu      $v0, $zero, 0x1
    /* 1A78 80104278 03006214 */  bne        $v1, $v0, .L80104288
    /* 1A7C 8010427C 04000424 */   addiu     $a0, $zero, 0x4
    /* 1A80 80104280 A8100408 */  j          .L801042A0
    /* 1A84 80104284 21204000 */   addu      $a0, $v0, $zero
  .L80104288:
    /* 1A88 80104288 0500622C */  sltiu      $v0, $v1, 0x5
    /* 1A8C 8010428C 05004010 */  beqz       $v0, .L801042A4
    /* 1A90 80104290 0680023C */   lui       $v0, %hi(vs_main_settings)
    /* 1A94 80104294 1B51A290 */  lbu        $v0, %lo(remainingChainAbilityCount)($a1)
    /* 1A98 80104298 00000000 */  nop
    /* 1A9C 8010429C FFFF4424 */  addiu      $a0, $v0, -0x1
  .L801042A0:
    /* 1AA0 801042A0 0680023C */  lui        $v0, %hi(vs_main_settings)
  .L801042A4:
    /* 1AA4 801042A4 20005024 */  addiu      $s0, $v0, %lo(vs_main_settings)
    /* 1AA8 801042A8 1080053C */  lui        $a1, %hi(menuNotEntered)
    /* 1AAC 801042AC 1F51A390 */  lbu        $v1, %lo(menuNotEntered)($a1)
    /* 1AB0 801042B0 01001192 */  lbu        $s1, 0x1($s0)
    /* 1AB4 801042B4 01006230 */  andi       $v0, $v1, 0x1
    /* 1AB8 801042B8 04004010 */  beqz       $v0, .L801042CC
    /* 1ABC 801042BC FFFF6224 */   addiu     $v0, $v1, -0x1
    /* 1AC0 801042C0 1F51A2A0 */  sb         $v0, %lo(menuNotEntered)($a1)
    /* 1AC4 801042C4 01000224 */  addiu      $v0, $zero, 0x1
    /* 1AC8 801042C8 010002A2 */  sb         $v0, 0x1($s0)
  .L801042CC:
    /* 1ACC 801042CC 1B010524 */  addiu      $a1, $zero, 0x11B
    /* 1AD0 801042D0 3000A627 */  addiu      $a2, $sp, 0x30
    /* 1AD4 801042D4 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 1AD8 801042D8 8800A727 */   addiu     $a3, $sp, 0x88
    /* 1ADC 801042DC 1080033C */  lui        $v1, %hi(remainingDefenseAbilityCount + 0x1)
    /* 1AE0 801042E0 FF100408 */  j          .L801043FC
    /* 1AE4 801042E4 04000224 */   addiu     $v0, $zero, 0x4
    /* 1AE8 801042E8 74EA030C */  jal        vs_mainmenu_ready
    /* 1AEC 801042EC 00000000 */   nop
    /* 1AF0 801042F0 97004010 */  beqz       $v0, .L80104550
    /* 1AF4 801042F4 1080023C */   lui       $v0, %hi(remainingDefenseAbilityCount)
    /* 1AF8 801042F8 1C514290 */  lbu        $v0, %lo(remainingDefenseAbilityCount)($v0)
    /* 1AFC 801042FC 00000000 */  nop
    /* 1B00 80104300 20004010 */  beqz       $v0, .L80104384
    /* 1B04 80104304 21880000 */   addu      $s1, $zero, $zero
    /* 1B08 80104308 1080023C */  lui        $v0, %hi(remainingDefenseAbilities)
    /* 1B0C 8010430C 10515524 */  addiu      $s5, $v0, %lo(remainingDefenseAbilities)
    /* 1B10 80104310 0580023C */  lui        $v0, %hi(D_8004B9F8)
    /* 1B14 80104314 F8B95424 */  addiu      $s4, $v0, %lo(D_8004B9F8)
    /* 1B18 80104318 04001224 */  addiu      $s2, $zero, 0x4
    /* 1B1C 8010431C B800B327 */  addiu      $s3, $sp, 0xB8
    /* 1B20 80104320 21806002 */  addu       $s0, $s3, $zero
  .L80104324:
    /* 1B24 80104324 21203502 */  addu       $a0, $s1, $s5
    /* 1B28 80104328 00008390 */  lbu        $v1, 0x0($a0)
    /* 1B2C 8010432C 00000000 */  nop
    /* 1B30 80104330 40100300 */  sll        $v0, $v1, 1
    /* 1B34 80104334 21104300 */  addu       $v0, $v0, $v1
    /* 1B38 80104338 80100200 */  sll        $v0, $v0, 2
    /* 1B3C 8010433C 21104300 */  addu       $v0, $v0, $v1
    /* 1B40 80104340 80100200 */  sll        $v0, $v0, 2
    /* 1B44 80104344 21105400 */  addu       $v0, $v0, $s4
    /* 1B48 80104348 000002AE */  sw         $v0, 0x0($s0)
    /* 1B4C 8010434C 00008490 */  lbu        $a0, 0x0($a0)
    /* 1B50 80104350 760F040C */  jal        _getAbilityDescription
    /* 1B54 80104354 08001026 */   addiu     $s0, $s0, 0x8
    /* 1B58 80104358 21187202 */  addu       $v1, $s3, $s2
    /* 1B5C 8010435C 08005226 */  addiu      $s2, $s2, 0x8
    /* 1B60 80104360 80201100 */  sll        $a0, $s1, 2
    /* 1B64 80104364 01003126 */  addiu      $s1, $s1, 0x1
    /* 1B68 80104368 000062AC */  sw         $v0, 0x0($v1)
    /* 1B6C 8010436C 1080023C */  lui        $v0, %hi(remainingDefenseAbilityCount)
    /* 1B70 80104370 1C514390 */  lbu        $v1, %lo(remainingDefenseAbilityCount)($v0)
    /* 1B74 80104374 2110A403 */  addu       $v0, $sp, $a0
    /* 1B78 80104378 2A182302 */  slt        $v1, $s1, $v1
    /* 1B7C 8010437C E9FF6014 */  bnez       $v1, .L80104324
    /* 1B80 80104380 100140AC */   sw        $zero, 0x110($v0)
  .L80104384:
    /* 1B84 80104384 1080053C */  lui        $a1, %hi(remainingDefenseAbilityCount)
    /* 1B88 80104388 1C51A390 */  lbu        $v1, %lo(remainingDefenseAbilityCount)($a1)
    /* 1B8C 8010438C 01000224 */  addiu      $v0, $zero, 0x1
    /* 1B90 80104390 03006214 */  bne        $v1, $v0, .L801043A0
    /* 1B94 80104394 04000424 */   addiu     $a0, $zero, 0x4
    /* 1B98 80104398 EE100408 */  j          .L801043B8
    /* 1B9C 8010439C 21204000 */   addu      $a0, $v0, $zero
  .L801043A0:
    /* 1BA0 801043A0 0500622C */  sltiu      $v0, $v1, 0x5
    /* 1BA4 801043A4 05004010 */  beqz       $v0, .L801043BC
    /* 1BA8 801043A8 0680023C */   lui       $v0, %hi(vs_main_settings)
    /* 1BAC 801043AC 1C51A290 */  lbu        $v0, %lo(remainingDefenseAbilityCount)($a1)
    /* 1BB0 801043B0 00000000 */  nop
    /* 1BB4 801043B4 FFFF4424 */  addiu      $a0, $v0, -0x1
  .L801043B8:
    /* 1BB8 801043B8 0680023C */  lui        $v0, %hi(vs_main_settings)
  .L801043BC:
    /* 1BBC 801043BC 20005024 */  addiu      $s0, $v0, %lo(vs_main_settings)
    /* 1BC0 801043C0 1080053C */  lui        $a1, %hi(menuNotEntered)
    /* 1BC4 801043C4 1F51A390 */  lbu        $v1, %lo(menuNotEntered)($a1)
    /* 1BC8 801043C8 01001192 */  lbu        $s1, 0x1($s0)
    /* 1BCC 801043CC 02006230 */  andi       $v0, $v1, 0x2
    /* 1BD0 801043D0 04004010 */  beqz       $v0, .L801043E4
    /* 1BD4 801043D4 FEFF6224 */   addiu     $v0, $v1, -0x2
    /* 1BD8 801043D8 1F51A2A0 */  sb         $v0, %lo(menuNotEntered)($a1)
    /* 1BDC 801043DC 01000224 */  addiu      $v0, $zero, 0x1
    /* 1BE0 801043E0 010002A2 */  sb         $v0, 0x1($s0)
  .L801043E4:
    /* 1BE4 801043E4 1C010524 */  addiu      $a1, $zero, 0x11C
    /* 1BE8 801043E8 B800A627 */  addiu      $a2, $sp, 0xB8
    /* 1BEC 801043EC 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 1BF0 801043F0 1001A727 */   addiu     $a3, $sp, 0x110
    /* 1BF4 801043F4 1080033C */  lui        $v1, %hi(remainingDefenseAbilityCount + 0x1)
    /* 1BF8 801043F8 05000224 */  addiu      $v0, $zero, 0x5
  .L801043FC:
    /* 1BFC 801043FC 010011A2 */  sb         $s1, 0x1($s0)
    /* 1C00 80104400 54110408 */  j          .L80104550
    /* 1C04 80104404 1D5162A0 */   sb        $v0, %lo(remainingDefenseAbilityCount + 0x1)($v1)
    /* 1C08 80104408 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 1C0C 8010440C 00000000 */   nop
    /* 1C10 80104410 21804000 */  addu       $s0, $v0, $zero
    /* 1C14 80104414 01001126 */  addiu      $s1, $s0, 0x1
    /* 1C18 80104418 4E002012 */  beqz       $s1, .L80104554
    /* 1C1C 8010441C 21100000 */   addu      $v0, $zero, $zero
    /* 1C20 80104420 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 1C24 80104424 28000424 */   addiu     $a0, $zero, 0x28
    /* 1C28 80104428 12002006 */  bltz       $s1, .L80104474
    /* 1C2C 8010442C 1080033C */   lui       $v1, %hi(remainingDefenseAbilityCount + 0x1)
    /* 1C30 80104430 8123030C */  jal        func_800C8E04
    /* 1C34 80104434 03000424 */   addiu     $a0, $zero, 0x3
    /* 1C38 80104438 1080043C */  lui        $a0, %hi(D_80104FC0)
    /* 1C3C 8010443C C04F8424 */  addiu      $a0, $a0, %lo(D_80104FC0)
    /* 1C40 80104440 1080023C */  lui        $v0, %hi(remainingChainAbilities)
    /* 1C44 80104444 26110408 */  j          .L80104498
    /* 1C48 80104448 00514224 */   addiu     $v0, $v0, %lo(remainingChainAbilities)
    /* 1C4C 8010444C 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 1C50 80104450 00000000 */   nop
    /* 1C54 80104454 21804000 */  addu       $s0, $v0, $zero
    /* 1C58 80104458 01001126 */  addiu      $s1, $s0, 0x1
    /* 1C5C 8010445C 3D002012 */  beqz       $s1, .L80104554
    /* 1C60 80104460 21100000 */   addu      $v0, $zero, $zero
    /* 1C64 80104464 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 1C68 80104468 28000424 */   addiu     $a0, $zero, 0x28
    /* 1C6C 8010446C 04002106 */  bgez       $s1, .L80104480
    /* 1C70 80104470 1080033C */   lui       $v1, %hi(remainingDefenseAbilityCount + 0x1)
  .L80104474:
    /* 1C74 80104474 07000224 */  addiu      $v0, $zero, 0x7
    /* 1C78 80104478 54110408 */  j          .L80104550
    /* 1C7C 8010447C 1D5162A0 */   sb        $v0, %lo(remainingDefenseAbilityCount + 0x1)($v1)
  .L80104480:
    /* 1C80 80104480 8123030C */  jal        func_800C8E04
    /* 1C84 80104484 03000424 */   addiu     $a0, $zero, 0x3
    /* 1C88 80104488 1080043C */  lui        $a0, %hi(D_80104FC0)
    /* 1C8C 8010448C C04F8424 */  addiu      $a0, $a0, %lo(D_80104FC0)
    /* 1C90 80104490 1080023C */  lui        $v0, %hi(remainingDefenseAbilities)
    /* 1C94 80104494 10514224 */  addiu      $v0, $v0, %lo(remainingDefenseAbilities)
  .L80104498:
    /* 1C98 80104498 21100202 */  addu       $v0, $s0, $v0
    /* 1C9C 8010449C 00005190 */  lbu        $s1, 0x0($v0)
    /* 1CA0 801044A0 0F80033C */  lui        $v1, %hi(vs_battle_stringContext + 0x2C)
    /* 1CA4 801044A4 40801100 */  sll        $s0, $s1, 1
    /* 1CA8 801044A8 21801102 */  addu       $s0, $s0, $s1
    /* 1CAC 801044AC 80801000 */  sll        $s0, $s0, 2
    /* 1CB0 801044B0 21801102 */  addu       $s0, $s0, $s1
    /* 1CB4 801044B4 80801000 */  sll        $s0, $s0, 2
    /* 1CB8 801044B8 0580113C */  lui        $s1, %hi(D_8004B9F8)
    /* 1CBC 801044BC F8B93126 */  addiu      $s1, $s1, %lo(D_8004B9F8)
    /* 1CC0 801044C0 21101102 */  addu       $v0, $s0, $s1
    /* 1CC4 801044C4 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 1CC8 801044C8 945162AC */   sw        $v0, %lo(vs_battle_stringContext + 0x2C)($v1)
    /* 1CCC 801044CC E4FF3126 */  addiu      $s1, $s1, -0x1C
    /* 1CD0 801044D0 21801102 */  addu       $s0, $s0, $s1
    /* 1CD4 801044D4 1080043C */  lui        $a0, %hi(remainingDefenseAbilityCount + 0x1)
    /* 1CD8 801044D8 0C00028E */  lw         $v0, 0xC($s0)
    /* 1CDC 801044DC 06000324 */  addiu      $v1, $zero, 0x6
    /* 1CE0 801044E0 1D5183A0 */  sb         $v1, %lo(remainingDefenseAbilityCount + 0x1)($a0)
    /* 1CE4 801044E4 00804234 */  ori        $v0, $v0, 0x8000
    /* 1CE8 801044E8 54110408 */  j          .L80104550
    /* 1CEC 801044EC 0C0002AE */   sw        $v0, 0xC($s0)
    /* 1CF0 801044F0 0F80023C */  lui        $v0, %hi(D_800F5130)
    /* 1CF4 801044F4 3051428C */  lw         $v0, %lo(D_800F5130)($v0)
    /* 1CF8 801044F8 00000000 */  nop
    /* 1CFC 801044FC 82170200 */  srl        $v0, $v0, 30
    /* 1D00 80104500 01004230 */  andi       $v0, $v0, 0x1
    /* 1D04 80104504 12004010 */  beqz       $v0, .L80104550
    /* 1D08 80104508 1080043C */   lui       $a0, %hi(remainingDefenseAbilityCount + 0x2)
    /* 1D0C 8010450C 1E518390 */  lbu        $v1, %lo(remainingDefenseAbilityCount + 0x2)($a0)
    /* 1D10 80104510 00000000 */  nop
    /* 1D14 80104514 05006010 */  beqz       $v1, .L8010452C
    /* 1D18 80104518 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 1D1C 8010451C D0E14290 */  lbu        $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 1D20 80104520 00000000 */  nop
    /* 1D24 80104524 03004010 */  beqz       $v0, .L80104534
    /* 1D28 80104528 FFFF6224 */   addiu     $v0, $v1, -0x1
  .L8010452C:
    /* 1D2C 8010452C 55110408 */  j          .L80104554
    /* 1D30 80104530 01000224 */   addiu     $v0, $zero, 0x1
  .L80104534:
    /* 1D34 80104534 54110408 */  j          .L80104550
    /* 1D38 80104538 1E5182A0 */   sb        $v0, %lo(remainingDefenseAbilityCount + 0x2)($a0)
    /* 1D3C 8010453C 74EA030C */  jal        vs_mainmenu_ready
    /* 1D40 80104540 00000000 */   nop
    /* 1D44 80104544 02004010 */  beqz       $v0, .L80104550
    /* 1D48 80104548 1080023C */   lui       $v0, %hi(remainingDefenseAbilityCount + 0x1)
    /* 1D4C 8010454C 1D5140A0 */  sb         $zero, %lo(remainingDefenseAbilityCount + 0x1)($v0)
  .L80104550:
    /* 1D50 80104550 21100000 */  addu       $v0, $zero, $zero
  .L80104554:
    /* 1D54 80104554 5801BF8F */  lw         $ra, 0x158($sp)
    /* 1D58 80104558 5401B58F */  lw         $s5, 0x154($sp)
    /* 1D5C 8010455C 5001B48F */  lw         $s4, 0x150($sp)
    /* 1D60 80104560 4C01B38F */  lw         $s3, 0x14C($sp)
    /* 1D64 80104564 4801B28F */  lw         $s2, 0x148($sp)
    /* 1D68 80104568 4401B18F */  lw         $s1, 0x144($sp)
    /* 1D6C 8010456C 4001B08F */  lw         $s0, 0x140($sp)
    /* 1D70 80104570 0800E003 */  jr         $ra
    /* 1D74 80104574 6001BD27 */   addiu     $sp, $sp, 0x160
endlabel _battleAbilityUnlocked
