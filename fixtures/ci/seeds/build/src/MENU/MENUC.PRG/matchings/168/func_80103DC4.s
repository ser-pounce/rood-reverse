nonmatching func_80103DC4, 0x3C8

glabel func_80103DC4
    /* 15C4 80103DC4 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 15C8 80103DC8 21288000 */  addu       $a1, $a0, $zero
    /* 15CC 80103DCC 2000B2AF */  sw         $s2, 0x20($sp)
    /* 15D0 80103DD0 21900000 */  addu       $s2, $zero, $zero
    /* 15D4 80103DD4 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 15D8 80103DD8 3800BEAF */  sw         $fp, 0x38($sp)
    /* 15DC 80103DDC 3400B7AF */  sw         $s7, 0x34($sp)
    /* 15E0 80103DE0 3000B6AF */  sw         $s6, 0x30($sp)
    /* 15E4 80103DE4 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 15E8 80103DE8 2800B4AF */  sw         $s4, 0x28($sp)
    /* 15EC 80103DEC 2400B3AF */  sw         $s3, 0x24($sp)
    /* 15F0 80103DF0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 15F4 80103DF4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 15F8 80103DF8 0D00A010 */  beqz       $a1, .L80103E30
    /* 15FC 80103DFC 1000A0AF */   sw        $zero, 0x10($sp)
    /* 1600 80103E00 0B000424 */  addiu      $a0, $zero, 0xB
    /* 1604 80103E04 1180033C */  lui        $v1, %hi(D_8010BC01)
    /* 1608 80103E08 7F00A230 */  andi       $v0, $a1, 0x7F
    /* 160C 80103E0C 01BC62A0 */  sb         $v0, %lo(D_8010BC01)($v1)
    /* 1610 80103E10 1180033C */  lui        $v1, %hi(D_8010BC02)
    /* 1614 80103E14 03120500 */  sra        $v0, $a1, 8
    /* 1618 80103E18 630F040C */  jal        func_80103D8C
    /* 161C 80103E1C 02BC62A0 */   sb        $v0, %lo(D_8010BC02)($v1)
    /* 1620 80103E20 21104002 */  addu       $v0, $s2, $zero
    /* 1624 80103E24 1180033C */  lui        $v1, %hi(D_8010BC00)
    /* 1628 80103E28 57100408 */  j          .L8010415C
    /* 162C 80103E2C 00BC60A0 */   sb        $zero, %lo(D_8010BC00)($v1)
  .L80103E30:
    /* 1630 80103E30 1180033C */  lui        $v1, %hi(D_8010BC01)
    /* 1634 80103E34 01BC6290 */  lbu        $v0, %lo(D_8010BC01)($v1)
    /* 1638 80103E38 00000000 */  nop
    /* 163C 80103E3C 08004010 */  beqz       $v0, .L80103E60
    /* 1640 80103E40 40180200 */   sll       $v1, $v0, 1
    /* 1644 80103E44 21186200 */  addu       $v1, $v1, $v0
    /* 1648 80103E48 80180300 */  sll        $v1, $v1, 2
    /* 164C 80103E4C 23186200 */  subu       $v1, $v1, $v0
    /* 1650 80103E50 80180300 */  sll        $v1, $v1, 2
    /* 1654 80103E54 0680023C */  lui        $v0, %hi(D_800603BC)
    /* 1658 80103E58 BC034224 */  addiu      $v0, $v0, %lo(D_800603BC)
    /* 165C 80103E5C 21906200 */  addu       $s2, $v1, $v0
  .L80103E60:
    /* 1660 80103E60 1180033C */  lui        $v1, %hi(D_8010BC02)
    /* 1664 80103E64 02BC6290 */  lbu        $v0, %lo(D_8010BC02)($v1)
    /* 1668 80103E68 00000000 */  nop
    /* 166C 80103E6C 06004010 */  beqz       $v0, .L80103E88
    /* 1670 80103E70 21184000 */   addu      $v1, $v0, $zero
    /* 1674 80103E74 00190300 */  sll        $v1, $v1, 4
    /* 1678 80103E78 0680023C */  lui        $v0, %hi(D_80060698)
    /* 167C 80103E7C 98064224 */  addiu      $v0, $v0, %lo(D_80060698)
    /* 1680 80103E80 21186200 */  addu       $v1, $v1, $v0
    /* 1684 80103E84 1000A3AF */  sw         $v1, 0x10($sp)
  .L80103E88:
    /* 1688 80103E88 1180023C */  lui        $v0, %hi(D_8010BC00)
    /* 168C 80103E8C 00BC4390 */  lbu        $v1, %lo(D_8010BC00)($v0)
    /* 1690 80103E90 01001024 */  addiu      $s0, $zero, 0x1
    /* 1694 80103E94 70007010 */  beq        $v1, $s0, .L80104058
    /* 1698 80103E98 02006228 */   slti      $v0, $v1, 0x2
    /* 169C 80103E9C 05004010 */  beqz       $v0, .L80103EB4
    /* 16A0 80103EA0 02000224 */   addiu     $v0, $zero, 0x2
    /* 16A4 80103EA4 07006010 */  beqz       $v1, .L80103EC4
    /* 16A8 80103EA8 21100000 */   addu      $v0, $zero, $zero
    /* 16AC 80103EAC 57100408 */  j          .L8010415C
    /* 16B0 80103EB0 00000000 */   nop
  .L80103EB4:
    /* 16B4 80103EB4 A1006210 */  beq        $v1, $v0, .L8010413C
    /* 16B8 80103EB8 21100000 */   addu      $v0, $zero, $zero
    /* 16BC 80103EBC 57100408 */  j          .L8010415C
    /* 16C0 80103EC0 00000000 */   nop
  .L80103EC4:
    /* 16C4 80103EC4 74EA030C */  jal        vs_mainmenu_ready
    /* 16C8 80103EC8 00000000 */   nop
    /* 16CC 80103ECC A3004010 */  beqz       $v0, .L8010415C
    /* 16D0 80103ED0 21100000 */   addu      $v0, $zero, $zero
    /* 16D4 80103ED4 8F0F010C */  jal        vs_main_allocHeapR
    /* 16D8 80103ED8 2C070424 */   addiu     $a0, $zero, 0x72C
    /* 16DC 80103EDC 21B84000 */  addu       $s7, $v0, $zero
    /* 16E0 80103EE0 0C004016 */  bnez       $s2, .L80103F14
    /* 16E4 80103EE4 A406FE26 */   addiu     $fp, $s7, 0x6A4
    /* 16E8 80103EE8 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 16EC 80103EEC A424438C */  lw         $v1, %lo(vs_mainMenu_menu12Text)($v0)
    /* 16F0 80103EF0 00000000 */  nop
    /* 16F4 80103EF4 14086224 */  addiu      $v0, $v1, 0x814
    /* 16F8 80103EF8 A406E2AE */  sw         $v0, 0x6A4($s7)
    /* 16FC 80103EFC 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 1700 80103F00 844E428C */  lw         $v0, %lo(vs_battle_rowTypeBuf)($v0)
    /* 1704 80103F04 1C086324 */  addiu      $v1, $v1, 0x81C
    /* 1708 80103F08 0400C3AF */  sw         $v1, 0x4($fp)
    /* 170C 80103F0C CB0F0408 */  j          .L80103F2C
    /* 1710 80103F10 000050AC */   sw        $s0, 0x0($v0)
  .L80103F14:
    /* 1714 80103F14 21204002 */  addu       $a0, $s2, $zero
    /* 1718 80103F18 2128C003 */  addu       $a1, $fp, $zero
    /* 171C 80103F1C 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 1720 80103F20 844E468C */  lw         $a2, %lo(vs_battle_rowTypeBuf)($v0)
    /* 1724 80103F24 A9F2030C */  jal        vs_mainMenu_setUiBlade
    /* 1728 80103F28 2138E002 */   addu      $a3, $s7, $zero
  .L80103F2C:
    /* 172C 80103F2C 01001424 */  addiu      $s4, $zero, 0x1
    /* 1730 80103F30 21A80000 */  addu       $s5, $zero, $zero
    /* 1734 80103F34 1180033C */  lui        $v1, %hi(D_8010BCA4)
    /* 1738 80103F38 6000F626 */  addiu      $s6, $s7, 0x60
    /* 173C 80103F3C 1180023C */  lui        $v0, %hi(D_8010BC01)
    /* 1740 80103F40 01BC4290 */  lbu        $v0, %lo(D_8010BC01)($v0)
    /* 1744 80103F44 0800D327 */  addiu      $s3, $fp, 0x8
    /* 1748 80103F48 A4BC62A0 */  sb         $v0, %lo(D_8010BCA4)($v1)
    /* 174C 80103F4C 0680083C */  lui        $t0, %hi(vs_main_inventoryIndices)
  .L80103F50:
    /* 1750 80103F50 D8190825 */  addiu      $t0, $t0, %lo(vs_main_inventoryIndices)
    /* 1754 80103F54 2110A802 */  addu       $v0, $s5, $t0
    /* 1758 80103F58 08005090 */  lbu        $s0, 0x8($v0)
    /* 175C 80103F5C 00000000 */  nop
    /* 1760 80103F60 2E000012 */  beqz       $s0, .L8010401C
    /* 1764 80103F64 1180023C */   lui       $v0, %hi(D_8010BC01)
    /* 1768 80103F68 01BC4290 */  lbu        $v0, %lo(D_8010BC01)($v0)
    /* 176C 80103F6C 00000000 */  nop
    /* 1770 80103F70 2A000212 */  beq        $s0, $v0, .L8010401C
    /* 1774 80103F74 40101000 */   sll       $v0, $s0, 1
    /* 1778 80103F78 21105000 */  addu       $v0, $v0, $s0
    /* 177C 80103F7C 80100200 */  sll        $v0, $v0, 2
    /* 1780 80103F80 23105000 */  subu       $v0, $v0, $s0
    /* 1784 80103F84 80100200 */  sll        $v0, $v0, 2
    /* 1788 80103F88 0680083C */  lui        $t0, %hi(D_800603BC)
    /* 178C 80103F8C BC030825 */  addiu      $t0, $t0, %lo(D_800603BC)
    /* 1790 80103F90 21904800 */  addu       $s2, $v0, $t0
    /* 1794 80103F94 2A004292 */  lbu        $v0, 0x2A($s2)
    /* 1798 80103F98 00000000 */  nop
    /* 179C 80103F9C 1F004014 */  bnez       $v0, .L8010401C
    /* 17A0 80103FA0 21286002 */   addu      $a1, $s3, $zero
    /* 17A4 80103FA4 21204002 */  addu       $a0, $s2, $zero
    /* 17A8 80103FA8 2138C002 */  addu       $a3, $s6, $zero
    /* 17AC 80103FAC 0F80083C */  lui        $t0, %hi(vs_battle_rowTypeBuf)
    /* 17B0 80103FB0 844E068D */  lw         $a2, %lo(vs_battle_rowTypeBuf)($t0)
    /* 17B4 80103FB4 80881400 */  sll        $s1, $s4, 2
    /* 17B8 80103FB8 A9F2030C */  jal        vs_mainMenu_setUiBlade
    /* 17BC 80103FBC 2130D100 */   addu      $a2, $a2, $s1
    /* 17C0 80103FC0 1000A58F */  lw         $a1, 0x10($sp)
    /* 17C4 80103FC4 CF0C040C */  jal        _isValidGrip
    /* 17C8 80103FC8 21204002 */   addu      $a0, $s2, $zero
    /* 17CC 80103FCC 0D004014 */  bnez       $v0, .L80104004
    /* 17D0 80103FD0 1180083C */   lui       $t0, %hi(D_8010BCA4)
    /* 17D4 80103FD4 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 17D8 80103FD8 0F80083C */  lui        $t0, %hi(vs_battle_rowTypeBuf)
    /* 17DC 80103FDC A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 17E0 80103FE0 844E038D */  lw         $v1, %lo(vs_battle_rowTypeBuf)($t0)
    /* 17E4 80103FE4 A2024224 */  addiu      $v0, $v0, 0x2A2
    /* 17E8 80103FE8 21182302 */  addu       $v1, $s1, $v1
    /* 17EC 80103FEC 040062AE */  sw         $v0, 0x4($s3)
    /* 17F0 80103FF0 0000628C */  lw         $v0, 0x0($v1)
    /* 17F4 80103FF4 00000000 */  nop
    /* 17F8 80103FF8 01004234 */  ori        $v0, $v0, 0x1
    /* 17FC 80103FFC 000062AC */  sw         $v0, 0x0($v1)
    /* 1800 80104000 1180083C */  lui        $t0, %hi(D_8010BCA4)
  .L80104004:
    /* 1804 80104004 A4BC0825 */  addiu      $t0, $t0, %lo(D_8010BCA4)
    /* 1808 80104008 21108802 */  addu       $v0, $s4, $t0
    /* 180C 8010400C 000050A0 */  sb         $s0, 0x0($v0)
    /* 1810 80104010 6000D626 */  addiu      $s6, $s6, 0x60
    /* 1814 80104014 08007326 */  addiu      $s3, $s3, 0x8
    /* 1818 80104018 01009426 */  addiu      $s4, $s4, 0x1
  .L8010401C:
    /* 181C 8010401C 0100B526 */  addiu      $s5, $s5, 0x1
    /* 1820 80104020 1000A22A */  slti       $v0, $s5, 0x10
    /* 1824 80104024 CAFF4014 */  bnez       $v0, .L80103F50
    /* 1828 80104028 0680083C */   lui       $t0, %hi(vs_main_inventoryIndices)
    /* 182C 8010402C 21208002 */  addu       $a0, $s4, $zero
    /* 1830 80104030 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 1834 80104034 844E468C */  lw         $a2, %lo(vs_battle_rowTypeBuf)($v0)
    /* 1838 80104038 FF0C040C */  jal        _populateItemsList
    /* 183C 8010403C 2128C003 */   addu      $a1, $fp, $zero
    /* 1840 80104040 180F010C */  jal        vs_main_freeHeapR
    /* 1844 80104044 2120E002 */   addu      $a0, $s7, $zero
    /* 1848 80104048 1180033C */  lui        $v1, %hi(D_8010BC00)
    /* 184C 8010404C 01000224 */  addiu      $v0, $zero, 0x1
    /* 1850 80104050 56100408 */  j          .L80104158
    /* 1854 80104054 00BC62A0 */   sb        $v0, %lo(D_8010BC00)($v1)
  .L80104058:
    /* 1858 80104058 1180033C */  lui        $v1, %hi(D_8010BCA4)
    /* 185C 8010405C 1180023C */  lui        $v0, %hi(D_8010BCA2)
    /* 1860 80104060 1180043C */  lui        $a0, %hi(D_8010BC9C)
    /* 1864 80104064 A2BC4290 */  lbu        $v0, %lo(D_8010BCA2)($v0)
    /* 1868 80104068 9CBC848C */  lw         $a0, %lo(D_8010BC9C)($a0)
    /* 186C 8010406C A4BC6324 */  addiu      $v1, $v1, %lo(D_8010BCA4)
    /* 1870 80104070 21104400 */  addu       $v0, $v0, $a0
    /* 1874 80104074 21104300 */  addu       $v0, $v0, $v1
    /* 1878 80104078 00005090 */  lbu        $s0, 0x0($v0)
    /* 187C 8010407C 00000000 */  nop
    /* 1880 80104080 05000012 */  beqz       $s0, .L80104098
    /* 1884 80104084 00000000 */   nop
    /* 1888 80104088 01F5030C */  jal        vs_mainMenu_setUiBladeStats
    /* 188C 8010408C 21200002 */   addu      $a0, $s0, $zero
    /* 1890 80104090 30100408 */  j          .L801040C0
    /* 1894 80104094 1180043C */   lui       $a0, %hi(D_8010BC9C)
  .L80104098:
    /* 1898 80104098 E3EE030C */  jal        func_800FBB8C
    /* 189C 8010409C 03000424 */   addiu     $a0, $zero, 0x3
    /* 18A0 801040A0 88F4030C */  jal        vs_mainMenu_resetStats
    /* 18A4 801040A4 00000000 */   nop
    /* 18A8 801040A8 21200000 */  addu       $a0, $zero, $zero
    /* 18AC 801040AC 21288000 */  addu       $a1, $a0, $zero
    /* 18B0 801040B0 21308000 */  addu       $a2, $a0, $zero
    /* 18B4 801040B4 43EF030C */  jal        vs_mainMenu_setRangeRisk
    /* 18B8 801040B8 01000724 */   addiu     $a3, $zero, 0x1
    /* 18BC 801040BC 1180043C */  lui        $a0, %hi(D_8010BC9C)
  .L801040C0:
    /* 18C0 801040C0 1180023C */  lui        $v0, %hi(D_8010BCA2)
    /* 18C4 801040C4 1180033C */  lui        $v1, %hi(D_8010BCA0)
    /* 18C8 801040C8 A2BC4290 */  lbu        $v0, %lo(D_8010BCA2)($v0)
    /* 18CC 801040CC 9CBC848C */  lw         $a0, %lo(D_8010BC9C)($a0)
    /* 18D0 801040D0 A0BC6590 */  lbu        $a1, %lo(D_8010BCA0)($v1)
    /* 18D4 801040D4 79FE030C */  jal        vs_mainMenu_printInformation
    /* 18D8 801040D8 21208200 */   addu      $a0, $a0, $v0
    /* 18DC 801040DC 820D040C */  jal        func_80103608
    /* 18E0 801040E0 02000424 */   addiu     $a0, $zero, 0x2
    /* 18E4 801040E4 780D040C */  jal        func_801035E0
    /* 18E8 801040E8 1180103C */   lui       $s0, %hi(D_8010BBFC)
    /* 18EC 801040EC 01004224 */  addiu      $v0, $v0, 0x1
    /* 18F0 801040F0 19004010 */  beqz       $v0, .L80104158
    /* 18F4 801040F4 FCBB02AE */   sw        $v0, %lo(D_8010BBFC)($s0)
    /* 18F8 801040F8 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 18FC 801040FC 28000424 */   addiu     $a0, $zero, 0x28
    /* 1900 80104100 FCBB038E */  lw         $v1, %lo(D_8010BBFC)($s0)
    /* 1904 80104104 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 1908 80104108 14006210 */  beq        $v1, $v0, .L8010415C
    /* 190C 8010410C 00000000 */   nop
    /* 1910 80104110 06006018 */  blez       $v1, .L8010412C
    /* 1914 80104114 1180023C */   lui       $v0, %hi(D_8010BCA4)
    /* 1918 80104118 A4BC4224 */  addiu      $v0, $v0, %lo(D_8010BCA4)
    /* 191C 8010411C 21106200 */  addu       $v0, $v1, $v0
    /* 1920 80104120 FFFF4290 */  lbu        $v0, -0x1($v0)
    /* 1924 80104124 00000000 */  nop
    /* 1928 80104128 FCBB02AE */  sw         $v0, %lo(D_8010BBFC)($s0)
  .L8010412C:
    /* 192C 8010412C 1180033C */  lui        $v1, %hi(D_8010BC00)
    /* 1930 80104130 02000224 */  addiu      $v0, $zero, 0x2
    /* 1934 80104134 56100408 */  j          .L80104158
    /* 1938 80104138 00BC62A0 */   sb        $v0, %lo(D_8010BC00)($v1)
  .L8010413C:
    /* 193C 8010413C 74EA030C */  jal        vs_mainmenu_ready
    /* 1940 80104140 00000000 */   nop
    /* 1944 80104144 04004010 */  beqz       $v0, .L80104158
    /* 1948 80104148 1180023C */   lui       $v0, %hi(D_8010BBFC)
    /* 194C 8010414C FCBB428C */  lw         $v0, %lo(D_8010BBFC)($v0)
    /* 1950 80104150 57100408 */  j          .L8010415C
    /* 1954 80104154 00000000 */   nop
  .L80104158:
    /* 1958 80104158 21100000 */  addu       $v0, $zero, $zero
  .L8010415C:
    /* 195C 8010415C 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 1960 80104160 3800BE8F */  lw         $fp, 0x38($sp)
    /* 1964 80104164 3400B78F */  lw         $s7, 0x34($sp)
    /* 1968 80104168 3000B68F */  lw         $s6, 0x30($sp)
    /* 196C 8010416C 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 1970 80104170 2800B48F */  lw         $s4, 0x28($sp)
    /* 1974 80104174 2400B38F */  lw         $s3, 0x24($sp)
    /* 1978 80104178 2000B28F */  lw         $s2, 0x20($sp)
    /* 197C 8010417C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1980 80104180 1800B08F */  lw         $s0, 0x18($sp)
    /* 1984 80104184 0800E003 */  jr         $ra
    /* 1988 80104188 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_80103DC4
