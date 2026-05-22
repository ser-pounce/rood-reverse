nonmatching func_800FAEBC, 0x50C

glabel func_800FAEBC
    /* 16BC 800FAEBC C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 16C0 800FAEC0 1800B0AF */  sw         $s0, 0x18($sp)
    /* 16C4 800FAEC4 21808000 */  addu       $s0, $a0, $zero
    /* 16C8 800FAEC8 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 16CC 800FAECC 3800BEAF */  sw         $fp, 0x38($sp)
    /* 16D0 800FAED0 3400B7AF */  sw         $s7, 0x34($sp)
    /* 16D4 800FAED4 3000B6AF */  sw         $s6, 0x30($sp)
    /* 16D8 800FAED8 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 16DC 800FAEDC 2800B4AF */  sw         $s4, 0x28($sp)
    /* 16E0 800FAEE0 2400B3AF */  sw         $s3, 0x24($sp)
    /* 16E4 800FAEE4 2000B2AF */  sw         $s2, 0x20($sp)
    /* 16E8 800FAEE8 0B000012 */  beqz       $s0, .L800FAF18
    /* 16EC 800FAEEC 1C00B1AF */   sw        $s1, 0x1C($sp)
    /* 16F0 800FAEF0 F2FE030C */  jal        func_800FFBC8
    /* 16F4 800FAEF4 00000000 */   nop
    /* 16F8 800FAEF8 01000232 */  andi       $v0, $s0, 0x1
    /* 16FC 800FAEFC 03004010 */  beqz       $v0, .L800FAF0C
    /* 1700 800FAF00 1080033C */   lui       $v1, %hi(D_80102456)
    /* 1704 800FAF04 01000224 */  addiu      $v0, $zero, 0x1
    /* 1708 800FAF08 562462A0 */  sb         $v0, %lo(D_80102456)($v1)
  .L800FAF0C:
    /* 170C 800FAF0C 1080023C */  lui        $v0, %hi(D_80102454)
    /* 1710 800FAF10 E6EC0308 */  j          .L800FB398
    /* 1714 800FAF14 542440A0 */   sb        $zero, %lo(D_80102454)($v0)
  .L800FAF18:
    /* 1718 800FAF18 1080023C */  lui        $v0, %hi(D_80102454)
    /* 171C 800FAF1C 54244390 */  lbu        $v1, %lo(D_80102454)($v0)
    /* 1720 800FAF20 00000000 */  nop
    /* 1724 800FAF24 0500622C */  sltiu      $v0, $v1, 0x5
    /* 1728 800FAF28 19014010 */  beqz       $v0, .L800FB390
    /* 172C 800FAF2C 1080023C */   lui       $v0, %hi(jtbl_800F9800)
    /* 1730 800FAF30 00984224 */  addiu      $v0, $v0, %lo(jtbl_800F9800)
    /* 1734 800FAF34 80180300 */  sll        $v1, $v1, 2
    /* 1738 800FAF38 21186200 */  addu       $v1, $v1, $v0
    /* 173C 800FAF3C 0000628C */  lw         $v0, 0x0($v1)
    /* 1740 800FAF40 00000000 */  nop
    /* 1744 800FAF44 08004000 */  jr         $v0
    /* 1748 800FAF48 00000000 */   nop
    /* 174C 800FAF4C 21200000 */  addu       $a0, $zero, $zero
    /* 1750 800FAF50 40010524 */  addiu      $a1, $zero, 0x140
    /* 1754 800FAF54 12000624 */  addiu      $a2, $zero, 0x12
    /* 1758 800FAF58 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 175C 800FAF5C 0F80083C */  lui        $t0, %hi(vs_battle_menuStrings)
    /* 1760 800FAF60 DCB90825 */  addiu      $t0, $t0, %lo(vs_battle_menuStrings)
    /* 1764 800FAF64 06000295 */  lhu        $v0, 0x6($t0)
    /* 1768 800FAF68 08000324 */  addiu      $v1, $zero, 0x8
    /* 176C 800FAF6C 1000A3AF */  sw         $v1, 0x10($sp)
    /* 1770 800FAF70 40100200 */  sll        $v0, $v0, 1
    /* 1774 800FAF74 21104800 */  addu       $v0, $v0, $t0
    /* 1778 800FAF78 9723030C */  jal        vs_battle_setMenuItem
    /* 177C 800FAF7C 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1780 800FAF80 21304000 */  addu       $a2, $v0, $zero
    /* 1784 800FAF84 01000424 */  addiu      $a0, $zero, 0x1
    /* 1788 800FAF88 02000224 */  addiu      $v0, $zero, 0x2
    /* 178C 800FAF8C 21288000 */  addu       $a1, $a0, $zero
    /* 1790 800FAF90 0000C2A0 */  sb         $v0, 0x0($a2)
    /* 1794 800FAF94 0F80023C */  lui        $v0, %hi(D_800F4EA0)
    /* 1798 800FAF98 0600C5A0 */  sb         $a1, 0x6($a2)
    /* 179C 800FAF9C A04E428C */  lw         $v0, %lo(D_800F4EA0)($v0)
    /* 17A0 800FAFA0 B4000324 */  addiu      $v1, $zero, 0xB4
    /* 17A4 800FAFA4 1800C3A4 */  sh         $v1, 0x18($a2)
    /* 17A8 800FAFA8 07004230 */  andi       $v0, $v0, 0x7
    /* 17AC 800FAFAC 2B100200 */  sltu       $v0, $zero, $v0
    /* 17B0 800FAFB0 0700C2A0 */  sb         $v0, 0x7($a2)
    /* 17B4 800FAFB4 1080023C */  lui        $v0, %hi(D_80102454)
    /* 17B8 800FAFB8 73F9030C */  jal        vs_mainMenu_loadItemNames
    /* 17BC 800FAFBC 542445A0 */   sb        $a1, %lo(D_80102454)($v0)
    /* 17C0 800FAFC0 E4EC0308 */  j          .L800FB390
    /* 17C4 800FAFC4 00000000 */   nop
    /* 17C8 800FAFC8 74EA030C */  jal        vs_mainmenu_ready
    /* 17CC 800FAFCC 00000000 */   nop
    /* 17D0 800FAFD0 EF004010 */  beqz       $v0, .L800FB390
    /* 17D4 800FAFD4 00000000 */   nop
    /* 17D8 800FAFD8 73F9030C */  jal        vs_mainMenu_loadItemNames
    /* 17DC 800FAFDC 21200000 */   addu      $a0, $zero, $zero
    /* 17E0 800FAFE0 EB004010 */  beqz       $v0, .L800FB390
    /* 17E4 800FAFE4 0A000424 */   addiu     $a0, $zero, 0xA
    /* 17E8 800FAFE8 40010524 */  addiu      $a1, $zero, 0x140
    /* 17EC 800FAFEC 22000624 */  addiu      $a2, $zero, 0x22
    /* 17F0 800FAFF0 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 17F4 800FAFF4 08000224 */  addiu      $v0, $zero, 0x8
    /* 17F8 800FAFF8 1000A2AF */  sw         $v0, 0x10($sp)
    /* 17FC 800FAFFC 1080023C */  lui        $v0, %hi(D_80102060)
    /* 1800 800FB000 60204224 */  addiu      $v0, $v0, %lo(D_80102060)
    /* 1804 800FB004 9723030C */  jal        vs_battle_setMenuItem
    /* 1808 800FB008 1400A2AF */   sw        $v0, 0x14($sp)
    /* 180C 800FB00C 21304000 */  addu       $a2, $v0, $zero
    /* 1810 800FB010 02000324 */  addiu      $v1, $zero, 0x2
    /* 1814 800FB014 B4000224 */  addiu      $v0, $zero, 0xB4
    /* 1818 800FB018 1800C2A4 */  sh         $v0, 0x18($a2)
    /* 181C 800FB01C 01000224 */  addiu      $v0, $zero, 0x1
    /* 1820 800FB020 0600C2A0 */  sb         $v0, 0x6($a2)
    /* 1824 800FB024 1080023C */  lui        $v0, %hi(D_80102454)
    /* 1828 800FB028 0000C3A0 */  sb         $v1, 0x0($a2)
    /* 182C 800FB02C E4EC0308 */  j          .L800FB390
    /* 1830 800FB030 542443A0 */   sb        $v1, %lo(D_80102454)($v0)
    /* 1834 800FB034 8F0F010C */  jal        vs_main_allocHeapR
    /* 1838 800FB038 001B0424 */   addiu     $a0, $zero, 0x1B00
    /* 183C 800FB03C 21A80000 */  addu       $s5, $zero, $zero
    /* 1840 800FB040 06000424 */  addiu      $a0, $zero, 0x6
    /* 1844 800FB044 2CFA030C */  jal        vs_mainMenu_rebuildInventory
    /* 1848 800FB048 21B04000 */   addu      $s6, $v0, $zero
    /* 184C 800FB04C 2188A002 */  addu       $s1, $s5, $zero
    /* 1850 800FB050 0018DE26 */  addiu      $fp, $s6, 0x1800
    /* 1854 800FB054 2190C003 */  addu       $s2, $fp, $zero
    /* 1858 800FB058 21A0C002 */  addu       $s4, $s6, $zero
    /* 185C 800FB05C 0019D726 */  addiu      $s7, $s6, 0x1900
    /* 1860 800FB060 2198E002 */  addu       $s3, $s7, $zero
  .L800FB064:
    /* 1864 800FB064 0680023C */  lui        $v0, %hi(vs_main_inventoryIndices)
    /* 1868 800FB068 D8194224 */  addiu      $v0, $v0, %lo(vs_main_inventoryIndices)
    /* 186C 800FB06C 21102202 */  addu       $v0, $s1, $v0
    /* 1870 800FB070 70004290 */  lbu        $v0, 0x70($v0)
    /* 1874 800FB074 00000000 */  nop
    /* 1878 800FB078 4D004010 */  beqz       $v0, .L800FB1B0
    /* 187C 800FB07C 80100200 */   sll       $v0, $v0, 2
    /* 1880 800FB080 0680033C */  lui        $v1, %hi(D_80060F64)
    /* 1884 800FB084 640F6324 */  addiu      $v1, $v1, %lo(D_80060F64)
    /* 1888 800FB088 21804300 */  addu       $s0, $v0, $v1
    /* 188C 800FB08C 21200002 */  addu       $a0, $s0, $zero
    /* 1890 800FB090 21286002 */  addu       $a1, $s3, $zero
    /* 1894 800FB094 21304002 */  addu       $a2, $s2, $zero
    /* 1898 800FB098 5FF4030C */  jal        vs_mainMenu_setUiItem
    /* 189C 800FB09C 21388002 */   addu      $a3, $s4, $zero
    /* 18A0 800FB0A0 00000296 */  lhu        $v0, 0x0($s0)
    /* 18A4 800FB0A4 00000000 */  nop
    /* 18A8 800FB0A8 CA01422C */  sltiu      $v0, $v0, 0x1CA
    /* 18AC 800FB0AC 23004010 */  beqz       $v0, .L800FB13C
    /* 18B0 800FB0B0 0F80023C */   lui       $v0, %hi(D_800F4EA0)
    /* 18B4 800FB0B4 1080093C */  lui        $t1, %hi(D_80102214)
    /* 18B8 800FB0B8 00000296 */  lhu        $v0, 0x0($s0)
    /* 18BC 800FB0BC 14222925 */  addiu      $t1, $t1, %lo(D_80102214)
    /* 18C0 800FB0C0 21104900 */  addu       $v0, $v0, $t1
    /* 18C4 800FB0C4 BDFE4490 */  lbu        $a0, -0x143($v0)
    /* 18C8 800FB0C8 00000000 */  nop
    /* 18CC 800FB0CC 96FF8224 */  addiu      $v0, $a0, -0x6A
    /* 18D0 800FB0D0 1C00422C */  sltiu      $v0, $v0, 0x1C
    /* 18D4 800FB0D4 14004010 */  beqz       $v0, .L800FB128
    /* 18D8 800FB0D8 40100400 */   sll       $v0, $a0, 1
    /* 18DC 800FB0DC 02000524 */  addiu      $a1, $zero, 0x2
    /* 18E0 800FB0E0 0580033C */  lui        $v1, %hi(vs_main_skills)
    /* 18E4 800FB0E4 DCB96324 */  addiu      $v1, $v1, %lo(vs_main_skills)
    /* 18E8 800FB0E8 21104400 */  addu       $v0, $v0, $a0
    /* 18EC 800FB0EC 0410A200 */  sllv       $v0, $v0, $a1
    /* 18F0 800FB0F0 21104400 */  addu       $v0, $v0, $a0
    /* 18F4 800FB0F4 0410A200 */  sllv       $v0, $v0, $a1
    /* 18F8 800FB0F8 21184300 */  addu       $v1, $v0, $v1
  .L800FB0FC:
    /* 18FC 800FB0FC 0C00628C */  lw         $v0, 0xC($v1)
    /* 1900 800FB100 00000000 */  nop
    /* 1904 800FB104 C2130200 */  srl        $v0, $v0, 15
    /* 1908 800FB108 01004230 */  andi       $v0, $v0, 0x1
    /* 190C 800FB10C 03004010 */  beqz       $v0, .L800FB11C
    /* 1910 800FB110 00000000 */   nop
    /* 1914 800FB114 34006324 */  addiu      $v1, $v1, 0x34
    /* 1918 800FB118 01008424 */  addiu      $a0, $a0, 0x1
  .L800FB11C:
    /* 191C 800FB11C FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 1920 800FB120 F6FFA104 */  bgez       $a1, .L800FB0FC
    /* 1924 800FB124 00000000 */   nop
  .L800FB128:
    /* 1928 800FB128 1080023C */  lui        $v0, %hi(D_80102410)
    /* 192C 800FB12C 10244224 */  addiu      $v0, $v0, %lo(D_80102410)
    /* 1930 800FB130 21102202 */  addu       $v0, $s1, $v0
    /* 1934 800FB134 000044A0 */  sb         $a0, 0x0($v0)
    /* 1938 800FB138 0F80023C */  lui        $v0, %hi(D_800F4EA0)
  .L800FB13C:
    /* 193C 800FB13C A04E428C */  lw         $v0, %lo(D_800F4EA0)($v0)
    /* 1940 800FB140 00000000 */  nop
    /* 1944 800FB144 07004230 */  andi       $v0, $v0, 0x7
    /* 1948 800FB148 0E004014 */  bnez       $v0, .L800FB184
    /* 194C 800FB14C 00000000 */   nop
    /* 1950 800FB150 00000296 */  lhu        $v0, 0x0($s0)
    /* 1954 800FB154 00000000 */  nop
    /* 1958 800FB158 CA01422C */  sltiu      $v0, $v0, 0x1CA
    /* 195C 800FB15C 09004010 */  beqz       $v0, .L800FB184
    /* 1960 800FB160 1080023C */   lui       $v0, %hi(D_80102410)
    /* 1964 800FB164 10244224 */  addiu      $v0, $v0, %lo(D_80102410)
    /* 1968 800FB168 21102202 */  addu       $v0, $s1, $v0
    /* 196C 800FB16C 00004590 */  lbu        $a1, 0x0($v0)
    /* 1970 800FB170 7429020C */  jal        vs_battle_getSkillFlags
    /* 1974 800FB174 21200000 */   addu      $a0, $zero, $zero
    /* 1978 800FB178 02004230 */  andi       $v0, $v0, 0x2
    /* 197C 800FB17C 05004010 */  beqz       $v0, .L800FB194
    /* 1980 800FB180 00000000 */   nop
  .L800FB184:
    /* 1984 800FB184 0000428E */  lw         $v0, 0x0($s2)
    /* 1988 800FB188 00000000 */  nop
    /* 198C 800FB18C 01004234 */  ori        $v0, $v0, 0x1
    /* 1990 800FB190 000042AE */  sw         $v0, 0x0($s2)
  .L800FB194:
    /* 1994 800FB194 04005226 */  addiu      $s2, $s2, 0x4
    /* 1998 800FB198 60009426 */  addiu      $s4, $s4, 0x60
    /* 199C 800FB19C 08007326 */  addiu      $s3, $s3, 0x8
    /* 19A0 800FB1A0 01003126 */  addiu      $s1, $s1, 0x1
    /* 19A4 800FB1A4 4000222A */  slti       $v0, $s1, 0x40
    /* 19A8 800FB1A8 AEFF4014 */  bnez       $v0, .L800FB064
    /* 19AC 800FB1AC 0100B526 */   addiu     $s5, $s5, 0x1
  .L800FB1B0:
    /* 19B0 800FB1B0 1080033C */  lui        $v1, %hi(D_80102455)
    /* 19B4 800FB1B4 0100A22E */  sltiu      $v0, $s5, 0x1
    /* 19B8 800FB1B8 07004010 */  beqz       $v0, .L800FB1D8
    /* 19BC 800FB1BC 552462A0 */   sb        $v0, %lo(D_80102455)($v1)
    /* 19C0 800FB1C0 1080023C */  lui        $v0, %hi(vs_mainMenu_itemHelp)
    /* 19C4 800FB1C4 4025448C */  lw         $a0, %lo(vs_mainMenu_itemHelp)($v0)
    /* 19C8 800FB1C8 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 19CC 800FB1CC C6678424 */   addiu     $a0, $a0, 0x67C6
    /* 19D0 800FB1D0 88EC0308 */  j          .L800FB220
    /* 19D4 800FB1D4 00000000 */   nop
  .L800FB1D8:
    /* 19D8 800FB1D8 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 19DC 800FB1DC 20004424 */  addiu      $a0, $v0, %lo(vs_main_settings)
    /* 19E0 800FB1E0 1080033C */  lui        $v1, %hi(D_80102456)
    /* 19E4 800FB1E4 56246290 */  lbu        $v0, %lo(D_80102456)($v1)
    /* 19E8 800FB1E8 01009190 */  lbu        $s1, 0x1($a0)
    /* 19EC 800FB1EC 03004010 */  beqz       $v0, .L800FB1FC
    /* 19F0 800FB1F0 01000224 */   addiu     $v0, $zero, 0x1
    /* 19F4 800FB1F4 80EC0308 */  j          .L800FB200
    /* 19F8 800FB1F8 562460A0 */   sb        $zero, %lo(D_80102456)($v1)
  .L800FB1FC:
    /* 19FC 800FB1FC 010082A0 */  sb         $v0, 0x1($a0)
  .L800FB200:
    /* 1A00 800FB200 2120A002 */  addu       $a0, $s5, $zero
    /* 1A04 800FB204 0100053C */  lui        $a1, (0x19224 >> 16)
    /* 1A08 800FB208 2492A534 */  ori        $a1, $a1, (0x19224 & 0xFFFF)
    /* 1A0C 800FB20C 2130E002 */  addu       $a2, $s7, $zero
    /* 1A10 800FB210 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 1A14 800FB214 2138C003 */   addu      $a3, $fp, $zero
    /* 1A18 800FB218 0680023C */  lui        $v0, %hi(D_80060021)
    /* 1A1C 800FB21C 210051A0 */  sb         $s1, %lo(D_80060021)($v0)
  .L800FB220:
    /* 1A20 800FB220 180F010C */  jal        vs_main_freeHeapR
    /* 1A24 800FB224 2120C002 */   addu      $a0, $s6, $zero
    /* 1A28 800FB228 1080033C */  lui        $v1, %hi(D_80102454)
    /* 1A2C 800FB22C 03000224 */  addiu      $v0, $zero, 0x3
    /* 1A30 800FB230 E4EC0308 */  j          .L800FB390
    /* 1A34 800FB234 542462A0 */   sb        $v0, %lo(D_80102454)($v1)
    /* 1A38 800FB238 1080023C */  lui        $v0, %hi(D_80102455)
    /* 1A3C 800FB23C 55244290 */  lbu        $v0, %lo(D_80102455)($v0)
    /* 1A40 800FB240 00000000 */  nop
    /* 1A44 800FB244 16004010 */  beqz       $v0, .L800FB2A0
    /* 1A48 800FB248 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 1A4C 800FB24C D0E1438C */  lw         $v1, %lo(vs_main_buttonsPressed)($v0)
    /* 1A50 800FB250 00000000 */  nop
    /* 1A54 800FB254 70006230 */  andi       $v0, $v1, 0x70
    /* 1A58 800FB258 4D004010 */  beqz       $v0, .L800FB390
    /* 1A5C 800FB25C 20006230 */   andi      $v0, $v1, 0x20
    /* 1A60 800FB260 05004010 */  beqz       $v0, .L800FB278
    /* 1A64 800FB264 00000000 */   nop
    /* 1A68 800FB268 B800030C */  jal        vs_battle_playInvalidSfx
    /* 1A6C 800FB26C 00000000 */   nop
    /* 1A70 800FB270 E4EC0308 */  j          .L800FB390
    /* 1A74 800FB274 00000000 */   nop
  .L800FB278:
    /* 1A78 800FB278 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 1A7C 800FB27C 00000000 */   nop
    /* 1A80 800FB280 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 1A84 800FB284 28000424 */   addiu     $a0, $zero, 0x28
    /* 1A88 800FB288 EAFE030C */  jal        func_800FFBA8
    /* 1A8C 800FB28C 00000000 */   nop
    /* 1A90 800FB290 1080033C */  lui        $v1, %hi(D_80102450)
    /* 1A94 800FB294 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 1A98 800FB298 CBEC0308 */  j          .L800FB32C
    /* 1A9C 800FB29C 502462AC */   sw        $v0, %lo(D_80102450)($v1)
  .L800FB2A0:
    /* 1AA0 800FB2A0 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 1AA4 800FB2A4 1080103C */   lui       $s0, %hi(D_80102450)
    /* 1AA8 800FB2A8 01004224 */  addiu      $v0, $v0, 0x1
    /* 1AAC 800FB2AC 38004010 */  beqz       $v0, .L800FB390
    /* 1AB0 800FB2B0 502402AE */   sw        $v0, %lo(D_80102450)($s0)
    /* 1AB4 800FB2B4 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 1AB8 800FB2B8 28000424 */   addiu     $a0, $zero, 0x28
    /* 1ABC 800FB2BC EAFE030C */  jal        func_800FFBA8
    /* 1AC0 800FB2C0 00000000 */   nop
    /* 1AC4 800FB2C4 5024038E */  lw         $v1, %lo(D_80102450)($s0)
    /* 1AC8 800FB2C8 00000000 */  nop
    /* 1ACC 800FB2CC 17006018 */  blez       $v1, .L800FB32C
    /* 1AD0 800FB2D0 0680023C */   lui       $v0, %hi(vs_main_inventoryIndices)
    /* 1AD4 800FB2D4 D8194224 */  addiu      $v0, $v0, %lo(vs_main_inventoryIndices)
    /* 1AD8 800FB2D8 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 1ADC 800FB2DC 21106200 */  addu       $v0, $v1, $v0
    /* 1AE0 800FB2E0 0F80053C */  lui        $a1, %hi(D_800F5210)
    /* 1AE4 800FB2E4 0F80043C */  lui        $a0, %hi(D_800F4E98)
    /* 1AE8 800FB2E8 70004290 */  lbu        $v0, 0x70($v0)
    /* 1AEC 800FB2EC 984E8424 */  addiu      $a0, $a0, %lo(D_800F4E98)
    /* 1AF0 800FB2F0 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1AF4 800FB2F4 1052A2A0 */  sb         $v0, %lo(D_800F5210)($a1)
    /* 1AF8 800FB2F8 1080023C */  lui        $v0, %hi(D_80102410)
    /* 1AFC 800FB2FC 10244224 */  addiu      $v0, $v0, %lo(D_80102410)
    /* 1B00 800FB300 21186200 */  addu       $v1, $v1, $v0
    /* 1B04 800FB304 00006290 */  lbu        $v0, 0x0($v1)
    /* 1B08 800FB308 0680033C */  lui        $v1, %hi(vs_battle_inventory)
    /* 1B0C 800FB30C 040082A4 */  sh         $v0, 0x4($a0)
    /* 1B10 800FB310 1052A290 */  lbu        $v0, %lo(D_800F5210)($a1)
    /* 1B14 800FB314 68016324 */  addiu      $v1, $v1, %lo(vs_battle_inventory)
    /* 1B18 800FB318 80100200 */  sll        $v0, $v0, 2
    /* 1B1C 800FB31C 21104300 */  addu       $v0, $v0, $v1
    /* 1B20 800FB320 000E4294 */  lhu        $v0, 0xE00($v0)
    /* 1B24 800FB324 00000000 */  nop
    /* 1B28 800FB328 060082A4 */  sh         $v0, 0x6($a0)
  .L800FB32C:
    /* 1B2C 800FB32C 1080033C */  lui        $v1, %hi(D_80102454)
    /* 1B30 800FB330 04000224 */  addiu      $v0, $zero, 0x4
    /* 1B34 800FB334 E4EC0308 */  j          .L800FB390
    /* 1B38 800FB338 542462A0 */   sb        $v0, %lo(D_80102454)($v1)
    /* 1B3C 800FB33C 74EA030C */  jal        vs_mainmenu_ready
    /* 1B40 800FB340 00000000 */   nop
    /* 1B44 800FB344 12004010 */  beqz       $v0, .L800FB390
    /* 1B48 800FB348 00000000 */   nop
    /* 1B4C 800FB34C A5F9030C */  jal        vs_mainMenu_ensureItemNamesLoaded
    /* 1B50 800FB350 00000000 */   nop
    /* 1B54 800FB354 0E004010 */  beqz       $v0, .L800FB390
    /* 1B58 800FB358 1080023C */   lui       $v0, %hi(D_80102450)
    /* 1B5C 800FB35C 5024428C */  lw         $v0, %lo(D_80102450)($v0)
    /* 1B60 800FB360 00000000 */  nop
    /* 1B64 800FB364 03004018 */  blez       $v0, .L800FB374
    /* 1B68 800FB368 0F80033C */   lui       $v1, %hi(D_800F4E98 + 0x2)
    /* 1B6C 800FB36C 08000224 */  addiu      $v0, $zero, 0x8
    /* 1B70 800FB370 9A4E62A4 */  sh         $v0, %lo(D_800F4E98 + 0x2)($v1)
  .L800FB374:
    /* 1B74 800FB374 0F80033C */  lui        $v1, %hi(vs_battle_menuState)
    /* 1B78 800FB378 3F000224 */  addiu      $v0, $zero, 0x3F
    /* 1B7C 800FB37C C05162A0 */  sb         $v0, %lo(vs_battle_menuState)($v1)
    /* 1B80 800FB380 0F80033C */  lui        $v1, %hi(D_800F4E98)
    /* 1B84 800FB384 02000224 */  addiu      $v0, $zero, 0x2
    /* 1B88 800FB388 E6EC0308 */  j          .L800FB398
    /* 1B8C 800FB38C 984E62A4 */   sh        $v0, %lo(D_800F4E98)($v1)
  .L800FB390:
    /* 1B90 800FB390 CE07040C */  jal        func_80101F38
    /* 1B94 800FB394 00000000 */   nop
  .L800FB398:
    /* 1B98 800FB398 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 1B9C 800FB39C 3800BE8F */  lw         $fp, 0x38($sp)
    /* 1BA0 800FB3A0 3400B78F */  lw         $s7, 0x34($sp)
    /* 1BA4 800FB3A4 3000B68F */  lw         $s6, 0x30($sp)
    /* 1BA8 800FB3A8 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 1BAC 800FB3AC 2800B48F */  lw         $s4, 0x28($sp)
    /* 1BB0 800FB3B0 2400B38F */  lw         $s3, 0x24($sp)
    /* 1BB4 800FB3B4 2000B28F */  lw         $s2, 0x20($sp)
    /* 1BB8 800FB3B8 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1BBC 800FB3BC 1800B08F */  lw         $s0, 0x18($sp)
    /* 1BC0 800FB3C0 0800E003 */  jr         $ra
    /* 1BC4 800FB3C4 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_800FAEBC
