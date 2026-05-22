nonmatching func_80106610, 0x654

glabel func_80106610
    /* 3E10 80106610 68FFBD27 */  addiu      $sp, $sp, -0x98
    /* 3E14 80106614 7000B0AF */  sw         $s0, 0x70($sp)
    /* 3E18 80106618 21808000 */  addu       $s0, $a0, $zero
    /* 3E1C 8010661C 9400BFAF */  sw         $ra, 0x94($sp)
    /* 3E20 80106620 9000BEAF */  sw         $fp, 0x90($sp)
    /* 3E24 80106624 8C00B7AF */  sw         $s7, 0x8C($sp)
    /* 3E28 80106628 8800B6AF */  sw         $s6, 0x88($sp)
    /* 3E2C 8010662C 8400B5AF */  sw         $s5, 0x84($sp)
    /* 3E30 80106630 8000B4AF */  sw         $s4, 0x80($sp)
    /* 3E34 80106634 7C00B3AF */  sw         $s3, 0x7C($sp)
    /* 3E38 80106638 7800B2AF */  sw         $s2, 0x78($sp)
    /* 3E3C 8010663C 0A000012 */  beqz       $s0, .L80106668
    /* 3E40 80106640 7400B1AF */   sw        $s1, 0x74($sp)
    /* 3E44 80106644 8123030C */  jal        func_800C8E04
    /* 3E48 80106648 01000424 */   addiu     $a0, $zero, 0x1
    /* 3E4C 8010664C 21100000 */  addu       $v0, $zero, $zero
    /* 3E50 80106650 1180033C */  lui        $v1, %hi(D_8010BC3E)
    /* 3E54 80106654 FFFF0426 */  addiu      $a0, $s0, -0x1
    /* 3E58 80106658 3EBC64A0 */  sb         $a0, %lo(D_8010BC3E)($v1)
    /* 3E5C 8010665C 1180033C */  lui        $v1, %hi(D_8010BC3C)
    /* 3E60 80106660 0D1B0408 */  j          .L80106C34
    /* 3E64 80106664 3CBC60A0 */   sb        $zero, %lo(D_8010BC3C)($v1)
  .L80106668:
    /* 3E68 80106668 1180023C */  lui        $v0, %hi(D_8010BC3C)
    /* 3E6C 8010666C 3CBC4390 */  lbu        $v1, %lo(D_8010BC3C)($v0)
    /* 3E70 80106670 00000000 */  nop
    /* 3E74 80106674 0800622C */  sltiu      $v0, $v1, 0x8
    /* 3E78 80106678 6D014010 */  beqz       $v0, .L80106C30
    /* 3E7C 8010667C 1080023C */   lui       $v0, %hi(jtbl_80102858)
    /* 3E80 80106680 58284224 */  addiu      $v0, $v0, %lo(jtbl_80102858)
    /* 3E84 80106684 80180300 */  sll        $v1, $v1, 2
    /* 3E88 80106688 21186200 */  addu       $v1, $v1, $v0
    /* 3E8C 8010668C 0000628C */  lw         $v0, 0x0($v1)
    /* 3E90 80106690 00000000 */  nop
    /* 3E94 80106694 08004000 */  jr         $v0
    /* 3E98 80106698 00000000 */   nop
    /* 3E9C 8010669C 74EA030C */  jal        vs_mainmenu_ready
    /* 3EA0 801066A0 00000000 */   nop
    /* 3EA4 801066A4 62014010 */  beqz       $v0, .L80106C30
    /* 3EA8 801066A8 1180023C */   lui       $v0, %hi(D_8010BC3E)
    /* 3EAC 801066AC 1080033C */  lui        $v1, %hi(vs_mainMenu_menu12Text)
    /* 3EB0 801066B0 3EBC4290 */  lbu        $v0, %lo(D_8010BC3E)($v0)
    /* 3EB4 801066B4 A424638C */  lw         $v1, %lo(vs_mainMenu_menu12Text)($v1)
    /* 3EB8 801066B8 40100200 */  sll        $v0, $v0, 1
    /* 3EBC 801066BC 21104300 */  addu       $v0, $v0, $v1
    /* 3EC0 801066C0 52004594 */  lhu        $a1, 0x52($v0)
    /* 3EC4 801066C4 740A040C */  jal        func_801029D0
    /* 3EC8 801066C8 21200000 */   addu      $a0, $zero, $zero
    /* 3ECC 801066CC 1180033C */  lui        $v1, %hi(D_8010BC3C)
    /* 3ED0 801066D0 01000224 */  addiu      $v0, $zero, 0x1
    /* 3ED4 801066D4 0C1B0408 */  j          .L80106C30
    /* 3ED8 801066D8 3CBC62A0 */   sb        $v0, %lo(D_8010BC3C)($v1)
    /* 3EDC 801066DC 74EA030C */  jal        vs_mainmenu_ready
    /* 3EE0 801066E0 00000000 */   nop
    /* 3EE4 801066E4 52014010 */  beqz       $v0, .L80106C30
    /* 3EE8 801066E8 21B80000 */   addu      $s7, $zero, $zero
    /* 3EEC 801066EC 0680163C */  lui        $s6, %hi(vs_main_inventoryIndices)
    /* 3EF0 801066F0 D819D626 */  addiu      $s6, $s6, %lo(vs_main_inventoryIndices)
    /* 3EF4 801066F4 1180023C */  lui        $v0, %hi(D_8010BCA4)
    /* 3EF8 801066F8 A4BC5524 */  addiu      $s5, $v0, %lo(D_8010BCA4)
    /* 3EFC 801066FC 04001324 */  addiu      $s3, $zero, 0x4
    /* 3F00 80106700 5000B227 */  addiu      $s2, $sp, 0x50
    /* 3F04 80106704 1000BE27 */  addiu      $fp, $sp, 0x10
    /* 3F08 80106708 21A0C003 */  addu       $s4, $fp, $zero
    /* 3F0C 8010670C 1180023C */  lui        $v0, %hi(D_8010BC3E)
  .L80106710:
    /* 3F10 80106710 3EBC4290 */  lbu        $v0, %lo(D_8010BC3E)($v0)
    /* 3F14 80106714 00000000 */  nop
    /* 3F18 80106718 34004010 */  beqz       $v0, .L801067EC
    /* 3F1C 8010671C 00000000 */   nop
    /* 3F20 80106720 2800D192 */  lbu        $s1, 0x28($s6)
    /* 3F24 80106724 00000000 */  nop
    /* 3F28 80106728 47002012 */  beqz       $s1, .L80106848
    /* 3F2C 8010672C 40181100 */   sll       $v1, $s1, 1
    /* 3F30 80106730 21187100 */  addu       $v1, $v1, $s1
    /* 3F34 80106734 00190300 */  sll        $v1, $v1, 4
    /* 3F38 80106738 0680023C */  lui        $v0, %hi(D_80060238)
    /* 3F3C 8010673C 38024224 */  addiu      $v0, $v0, %lo(D_80060238)
    /* 3F40 80106740 21806200 */  addu       $s0, $v1, $v0
    /* 3F44 80106744 21200002 */  addu       $a0, $s0, $zero
    /* 3F48 80106748 21288002 */  addu       $a1, $s4, $zero
    /* 3F4C 8010674C 0F80083C */  lui        $t0, %hi(vs_battle_stringBuf)
    /* 3F50 80106750 8C4E078D */  lw         $a3, %lo(vs_battle_stringBuf)($t0)
    /* 3F54 80106754 90F3030C */  jal        vs_mainMenu_initUiShield
    /* 3F58 80106758 21304002 */   addu      $a2, $s2, $zero
    /* 3F5C 8010675C 1080083C */  lui        $t0, %hi(vs_mainMenu_menu12Text)
    /* 3F60 80106760 A424028D */  lw         $v0, %lo(vs_mainMenu_menu12Text)($t0)
    /* 3F64 80106764 2118D303 */  addu       $v1, $fp, $s3
    /* 3F68 80106768 02044224 */  addiu      $v0, $v0, 0x402
    /* 3F6C 8010676C 000062AC */  sw         $v0, 0x0($v1)
    /* 3F70 80106770 10000492 */  lbu        $a0, 0x10($s0)
    /* 3F74 80106774 00000000 */  nop
    /* 3F78 80106778 0A008010 */  beqz       $a0, .L801067A4
    /* 3F7C 8010677C 21180000 */   addu      $v1, $zero, $zero
    /* 3F80 80106780 21100302 */  addu       $v0, $s0, $v1
  .L80106784:
    /* 3F84 80106784 2C004290 */  lbu        $v0, 0x2C($v0)
    /* 3F88 80106788 00000000 */  nop
    /* 3F8C 8010678C 05004014 */  bnez       $v0, .L801067A4
    /* 3F90 80106790 00000000 */   nop
    /* 3F94 80106794 01006324 */  addiu      $v1, $v1, 0x1
    /* 3F98 80106798 2A106400 */  slt        $v0, $v1, $a0
    /* 3F9C 8010679C F9FF4014 */  bnez       $v0, .L80106784
    /* 3FA0 801067A0 21100302 */   addu      $v0, $s0, $v1
  .L801067A4:
    /* 3FA4 801067A4 10000292 */  lbu        $v0, 0x10($s0)
    /* 3FA8 801067A8 00000000 */  nop
    /* 3FAC 801067AC 09006214 */  bne        $v1, $v0, .L801067D4
    /* 3FB0 801067B0 1080083C */   lui       $t0, %hi(vs_mainMenu_menu12Text)
    /* 3FB4 801067B4 A424028D */  lw         $v0, %lo(vs_mainMenu_menu12Text)($t0)
    /* 3FB8 801067B8 2118D303 */  addu       $v1, $fp, $s3
    /* 3FBC 801067BC C0034224 */  addiu      $v0, $v0, 0x3C0
    /* 3FC0 801067C0 000062AC */  sw         $v0, 0x0($v1)
    /* 3FC4 801067C4 0000428E */  lw         $v0, 0x0($s2)
    /* 3FC8 801067C8 00000000 */  nop
    /* 3FCC 801067CC 01004234 */  ori        $v0, $v0, 0x1
    /* 3FD0 801067D0 000042AE */  sw         $v0, 0x0($s2)
  .L801067D4:
    /* 3FD4 801067D4 0100B526 */  addiu      $s5, $s5, 0x1
    /* 3FD8 801067D8 08007326 */  addiu      $s3, $s3, 0x8
    /* 3FDC 801067DC 04005226 */  addiu      $s2, $s2, 0x4
    /* 3FE0 801067E0 08009426 */  addiu      $s4, $s4, 0x8
    /* 3FE4 801067E4 111A0408 */  j          .L80106844
    /* 3FE8 801067E8 0100F726 */   addiu     $s7, $s7, 0x1
  .L801067EC:
    /* 3FEC 801067EC 0000D192 */  lbu        $s1, 0x0($s6)
    /* 3FF0 801067F0 00000000 */  nop
    /* 3FF4 801067F4 14002012 */  beqz       $s1, .L80106848
    /* 3FF8 801067F8 40111100 */   sll       $v0, $s1, 5
    /* 3FFC 801067FC 0680043C */  lui        $a0, %hi(D_80060148)
    /* 4000 80106800 48018424 */  addiu      $a0, $a0, %lo(D_80060148)
    /* 4004 80106804 21204400 */  addu       $a0, $v0, $a0
    /* 4008 80106808 21288002 */  addu       $a1, $s4, $zero
    /* 400C 8010680C 21304002 */  addu       $a2, $s2, $zero
    /* 4010 80106810 0100B526 */  addiu      $s5, $s5, 0x1
    /* 4014 80106814 04005226 */  addiu      $s2, $s2, 0x4
    /* 4018 80106818 08009426 */  addiu      $s4, $s4, 0x8
    /* 401C 8010681C 0F80083C */  lui        $t0, %hi(vs_battle_stringBuf)
    /* 4020 80106820 8C4E078D */  lw         $a3, %lo(vs_battle_stringBuf)($t0)
    /* 4024 80106824 82F2030C */  jal        vs_mainMenu_initUiWeapon
    /* 4028 80106828 0100F726 */   addiu     $s7, $s7, 0x1
    /* 402C 8010682C 2118D303 */  addu       $v1, $fp, $s3
    /* 4030 80106830 1080083C */  lui        $t0, %hi(vs_mainMenu_menu12Text)
    /* 4034 80106834 A424028D */  lw         $v0, %lo(vs_mainMenu_menu12Text)($t0)
    /* 4038 80106838 08007326 */  addiu      $s3, $s3, 0x8
    /* 403C 8010683C E2034224 */  addiu      $v0, $v0, 0x3E2
    /* 4040 80106840 000062AC */  sw         $v0, 0x0($v1)
  .L80106844:
    /* 4044 80106844 0000B1A2 */  sb         $s1, 0x0($s5)
  .L80106848:
    /* 4048 80106848 0100D626 */  addiu      $s6, $s6, 0x1
    /* 404C 8010684C 0680083C */  lui        $t0, %hi(vs_main_inventoryIndices)
    /* 4050 80106850 D8190825 */  addiu      $t0, $t0, %lo(vs_main_inventoryIndices)
    /* 4054 80106854 08000225 */  addiu      $v0, $t0, 0x8
    /* 4058 80106858 2A10C202 */  slt        $v0, $s6, $v0
    /* 405C 8010685C ACFF4014 */  bnez       $v0, .L80106710
    /* 4060 80106860 1180023C */   lui       $v0, %hi(D_8010BC3E)
    /* 4064 80106864 0100033C */  lui        $v1, (0x19100 >> 16)
    /* 4068 80106868 00916334 */  ori        $v1, $v1, (0x19100 & 0xFFFF)
    /* 406C 8010686C 2120E002 */  addu       $a0, $s7, $zero
    /* 4070 80106870 1000A627 */  addiu      $a2, $sp, 0x10
    /* 4074 80106874 3EBC4590 */  lbu        $a1, %lo(D_8010BC3E)($v0)
    /* 4078 80106878 5000A727 */  addiu      $a3, $sp, 0x50
    /* 407C 8010687C 3A00A524 */  addiu      $a1, $a1, 0x3A
    /* 4080 80106880 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 4084 80106884 2528A300 */   or        $a1, $a1, $v1
    /* 4088 80106888 1180033C */  lui        $v1, %hi(D_8010BC3C)
    /* 408C 8010688C 02000224 */  addiu      $v0, $zero, 0x2
    /* 4090 80106890 0C1B0408 */  j          .L80106C30
    /* 4094 80106894 3CBC62A0 */   sb        $v0, %lo(D_8010BC3C)($v1)
    /* 4098 80106898 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 409C 8010689C 1180103C */   lui       $s0, %hi(D_8010BC38)
    /* 40A0 801068A0 01004224 */  addiu      $v0, $v0, 0x1
    /* 40A4 801068A4 E2004010 */  beqz       $v0, .L80106C30
    /* 40A8 801068A8 38BC02AE */   sw        $v0, %lo(D_8010BC38)($s0)
    /* 40AC 801068AC 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 40B0 801068B0 28000424 */   addiu     $a0, $zero, 0x28
    /* 40B4 801068B4 38BC028E */  lw         $v0, %lo(D_8010BC38)($s0)
    /* 40B8 801068B8 00000000 */  nop
    /* 40BC 801068BC DD004004 */  bltz       $v0, .L80106C34
    /* 40C0 801068C0 00000000 */   nop
    /* 40C4 801068C4 9223030C */  jal        vs_battle_getMenuItem
    /* 40C8 801068C8 21200000 */   addu      $a0, $zero, $zero
    /* 40CC 801068CC 21184000 */  addu       $v1, $v0, $zero
    /* 40D0 801068D0 02000224 */  addiu      $v0, $zero, 0x2
    /* 40D4 801068D4 000062A0 */  sb         $v0, 0x0($v1)
    /* 40D8 801068D8 A4000224 */  addiu      $v0, $zero, 0xA4
    /* 40DC 801068DC 010062A0 */  sb         $v0, 0x1($v1)
    /* 40E0 801068E0 38BC048E */  lw         $a0, %lo(D_8010BC38)($s0)
    /* 40E4 801068E4 10000224 */  addiu      $v0, $zero, 0x10
    /* 40E8 801068E8 180062A4 */  sh         $v0, 0x18($v1)
    /* 40EC 801068EC 9223030C */  jal        vs_battle_getMenuItem
    /* 40F0 801068F0 09008424 */   addiu     $a0, $a0, 0x9
    /* 40F4 801068F4 21184000 */  addu       $v1, $v0, $zero
    /* 40F8 801068F8 04000224 */  addiu      $v0, $zero, 0x4
    /* 40FC 801068FC 000062A0 */  sb         $v0, 0x0($v1)
    /* 4100 80106900 9B000224 */  addiu      $v0, $zero, 0x9B
    /* 4104 80106904 180062A4 */  sh         $v0, 0x18($v1)
    /* 4108 80106908 12000224 */  addiu      $v0, $zero, 0x12
    /* 410C 8010690C 1A0062A4 */  sh         $v0, 0x1A($v1)
    /* 4110 80106910 1180033C */  lui        $v1, %hi(D_8010BC3C)
    /* 4114 80106914 03000224 */  addiu      $v0, $zero, 0x3
    /* 4118 80106918 0C1B0408 */  j          .L80106C30
    /* 411C 8010691C 3CBC62A0 */   sb        $v0, %lo(D_8010BC3C)($v1)
    /* 4120 80106920 74EA030C */  jal        vs_mainmenu_ready
    /* 4124 80106924 00000000 */   nop
    /* 4128 80106928 C2004010 */  beqz       $v0, .L80106C34
    /* 412C 8010692C 21100000 */   addu      $v0, $zero, $zero
    /* 4130 80106930 9223030C */  jal        vs_battle_getMenuItem
    /* 4134 80106934 21200000 */   addu      $a0, $zero, $zero
    /* 4138 80106938 1180123C */  lui        $s2, %hi(D_8010BC3E)
    /* 413C 8010693C 3EBC4392 */  lbu        $v1, %lo(D_8010BC3E)($s2)
    /* 4140 80106940 00000000 */  nop
    /* 4144 80106944 02006010 */  beqz       $v1, .L80106950
    /* 4148 80106948 18000624 */   addiu     $a2, $zero, 0x18
    /* 414C 8010694C 1B000624 */  addiu      $a2, $zero, 0x1B
  .L80106950:
    /* 4150 80106950 21200000 */  addu       $a0, $zero, $zero
    /* 4154 80106954 20000524 */  addiu      $a1, $zero, 0x20
    /* 4158 80106958 030B040C */  jal        func_80102C0C
    /* 415C 8010695C 090046A0 */   sb        $a2, 0x9($v0)
    /* 4160 80106960 1180103C */  lui        $s0, %hi(D_8010BC38)
    /* 4164 80106964 38BC048E */  lw         $a0, %lo(D_8010BC38)($s0)
    /* 4168 80106968 0A000524 */  addiu      $a1, $zero, 0xA
    /* 416C 8010696C 030B040C */  jal        func_80102C0C
    /* 4170 80106970 09008424 */   addiu     $a0, $a0, 0x9
    /* 4174 80106974 1180023C */  lui        $v0, %hi(D_8010BCA4)
    /* 4178 80106978 A4BC4224 */  addiu      $v0, $v0, %lo(D_8010BCA4)
    /* 417C 8010697C 38BC038E */  lw         $v1, %lo(D_8010BC38)($s0)
    /* 4180 80106980 3EBC4492 */  lbu        $a0, %lo(D_8010BC3E)($s2)
    /* 4184 80106984 21186200 */  addu       $v1, $v1, $v0
    /* 4188 80106988 00007190 */  lbu        $s1, 0x0($v1)
    /* 418C 8010698C 1180033C */  lui        $v1, %hi(_combiningItem)
    /* 4190 80106990 FFFF2226 */  addiu      $v0, $s1, -0x1
    /* 4194 80106994 05008010 */  beqz       $a0, .L801069AC
    /* 4198 80106998 81BC62A0 */   sb        $v0, %lo(_combiningItem)($v1)
    /* 419C 8010699C 68F5030C */  jal        vs_mainMenu_setShieldStats
    /* 41A0 801069A0 21202002 */   addu      $a0, $s1, $zero
    /* 41A4 801069A4 6D1A0408 */  j          .L801069B4
    /* 41A8 801069A8 00000000 */   nop
  .L801069AC:
    /* 41AC 801069AC 9CF4030C */  jal        vs_mainMenu_setUiWeaponStats
    /* 41B0 801069B0 21202002 */   addu      $a0, $s1, $zero
  .L801069B4:
    /* 41B4 801069B4 F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 41B8 801069B8 07000424 */   addiu     $a0, $zero, 0x7
    /* 41BC 801069BC 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 41C0 801069C0 03000424 */   addiu     $a0, $zero, 0x3
    /* 41C4 801069C4 1180023C */  lui        $v0, %hi(D_8010BC3D)
    /* 41C8 801069C8 1180033C */  lui        $v1, %hi(D_8010BC3C)
    /* 41CC 801069CC 3DBC40A0 */  sb         $zero, %lo(D_8010BC3D)($v0)
    /* 41D0 801069D0 04000224 */  addiu      $v0, $zero, 0x4
    /* 41D4 801069D4 0C1B0408 */  j          .L80106C30
    /* 41D8 801069D8 3CBC62A0 */   sb        $v0, %lo(D_8010BC3C)($v1)
    /* 41DC 801069DC 1180073C */  lui        $a3, %hi(D_8010BC3D)
    /* 41E0 801069E0 3DBCE490 */  lbu        $a0, %lo(D_8010BC3D)($a3)
    /* 41E4 801069E4 00000000 */  nop
    /* 41E8 801069E8 0500822C */  sltiu      $v0, $a0, 0x5
    /* 41EC 801069EC 15004010 */  beqz       $v0, .L80106A44
    /* 41F0 801069F0 1180023C */   lui       $v0, %hi(D_8010BC3E)
    /* 41F4 801069F4 3EBC4390 */  lbu        $v1, %lo(D_8010BC3E)($v0)
    /* 41F8 801069F8 01008224 */  addiu      $v0, $a0, 0x1
    /* 41FC 801069FC 09006010 */  beqz       $v1, .L80106A24
    /* 4200 80106A00 3DBCE2A0 */   sb        $v0, %lo(D_8010BC3D)($a3)
    /* 4204 80106A04 01000624 */  addiu      $a2, $zero, 0x1
    /* 4208 80106A08 1180023C */  lui        $v0, %hi(_combiningItem)
    /* 420C 80106A0C 81BC4590 */  lbu        $a1, %lo(_combiningItem)($v0)
    /* 4210 80106A10 3DBCE490 */  lbu        $a0, %lo(D_8010BC3D)($a3)
    /* 4214 80106A14 C1F1030C */  jal        vs_mainMenu_initSetShieldGemMenu
    /* 4218 80106A18 2128A600 */   addu      $a1, $a1, $a2
    /* 421C 80106A1C 0D1B0408 */  j          .L80106C34
    /* 4220 80106A20 21100000 */   addu      $v0, $zero, $zero
  .L80106A24:
    /* 4224 80106A24 01000624 */  addiu      $a2, $zero, 0x1
    /* 4228 80106A28 1180023C */  lui        $v0, %hi(_combiningItem)
    /* 422C 80106A2C 81BC4590 */  lbu        $a1, %lo(_combiningItem)($v0)
    /* 4230 80106A30 3DBCE490 */  lbu        $a0, %lo(D_8010BC3D)($a3)
    /* 4234 80106A34 44F1030C */  jal        vs_mainMenu_initSetWeaponGemMenu
    /* 4238 80106A38 2128A600 */   addu      $a1, $a1, $a2
    /* 423C 80106A3C 0D1B0408 */  j          .L80106C34
    /* 4240 80106A40 21100000 */   addu      $v0, $zero, $zero
  .L80106A44:
    /* 4244 80106A44 3EBC4290 */  lbu        $v0, %lo(D_8010BC3E)($v0)
    /* 4248 80106A48 00000000 */  nop
    /* 424C 80106A4C 0B004010 */  beqz       $v0, .L80106A7C
    /* 4250 80106A50 0680033C */   lui       $v1, %hi(vs_battle_inventory)
    /* 4254 80106A54 1180023C */  lui        $v0, %hi(_combiningItem)
    /* 4258 80106A58 81BC4490 */  lbu        $a0, %lo(_combiningItem)($v0)
    /* 425C 80106A5C 68016324 */  addiu      $v1, $v1, %lo(vs_battle_inventory)
    /* 4260 80106A60 40100400 */  sll        $v0, $a0, 1
    /* 4264 80106A64 21104400 */  addu       $v0, $v0, $a0
    /* 4268 80106A68 00110200 */  sll        $v0, $v0, 4
    /* 426C 80106A6C 21104300 */  addu       $v0, $v0, $v1
    /* 4270 80106A70 01015090 */  lbu        $s0, 0x101($v0)
    /* 4274 80106A74 A51A0408 */  j          .L80106A94
    /* 4278 80106A78 00000000 */   nop
  .L80106A7C:
    /* 427C 80106A7C 1180023C */  lui        $v0, %hi(_combiningItem)
    /* 4280 80106A80 81BC4290 */  lbu        $v0, %lo(_combiningItem)($v0)
    /* 4284 80106A84 68016324 */  addiu      $v1, $v1, %lo(vs_battle_inventory)
    /* 4288 80106A88 40110200 */  sll        $v0, $v0, 5
    /* 428C 80106A8C 21104300 */  addu       $v0, $v0, $v1
    /* 4290 80106A90 03005090 */  lbu        $s0, 0x3($v0)
  .L80106A94:
    /* 4294 80106A94 160B040C */  jal        func_80102C58
    /* 4298 80106A98 01000424 */   addiu     $a0, $zero, 0x1
    /* 429C 80106A9C 1080033C */  lui        $v1, %hi(vs_mainMenu_menu12Text)
    /* 42A0 80106AA0 1180023C */  lui        $v0, %hi(D_8010BC3E)
    /* 42A4 80106AA4 3EBC4290 */  lbu        $v0, %lo(D_8010BC3E)($v0)
    /* 42A8 80106AA8 A4246524 */  addiu      $a1, $v1, %lo(vs_mainMenu_menu12Text)
    /* 42AC 80106AAC 80100200 */  sll        $v0, $v0, 2
    /* 42B0 80106AB0 05000012 */  beqz       $s0, .L80106AC8
    /* 42B4 80106AB4 27004424 */   addiu     $a0, $v0, 0x27
    /* 42B8 80106AB8 28004224 */  addiu      $v0, $v0, 0x28
    /* 42BC 80106ABC A424638C */  lw         $v1, %lo(vs_mainMenu_menu12Text)($v1)
    /* 42C0 80106AC0 B41A0408 */  j          .L80106AD0
    /* 42C4 80106AC4 40100200 */   sll       $v0, $v0, 1
  .L80106AC8:
    /* 42C8 80106AC8 A424638C */  lw         $v1, %lo(vs_mainMenu_menu12Text)($v1)
    /* 42CC 80106ACC 40100400 */  sll        $v0, $a0, 1
  .L80106AD0:
    /* 42D0 80106AD0 21186200 */  addu       $v1, $v1, $v0
    /* 42D4 80106AD4 00006494 */  lhu        $a0, 0x0($v1)
    /* 42D8 80106AD8 0000A28C */  lw         $v0, 0x0($a1)
    /* 42DC 80106ADC 40200400 */  sll        $a0, $a0, 1
    /* 42E0 80106AE0 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 42E4 80106AE4 21204400 */   addu      $a0, $v0, $a0
    /* 42E8 80106AE8 1180033C */  lui        $v1, %hi(D_8010BC3C)
    /* 42EC 80106AEC 05000226 */  addiu      $v0, $s0, 0x5
    /* 42F0 80106AF0 0C1B0408 */  j          .L80106C30
    /* 42F4 80106AF4 3CBC62A0 */   sb        $v0, %lo(D_8010BC3C)($v1)
    /* 42F8 80106AF8 160B040C */  jal        func_80102C58
    /* 42FC 80106AFC 21200000 */   addu      $a0, $zero, $zero
    /* 4300 80106B00 21804000 */  addu       $s0, $v0, $zero
    /* 4304 80106B04 4B000012 */  beqz       $s0, .L80106C34
    /* 4308 80106B08 21100000 */   addu      $v0, $zero, $zero
    /* 430C 80106B0C F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 4310 80106B10 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 4314 80106B14 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 4318 80106B18 04000424 */   addiu     $a0, $zero, 0x4
    /* 431C 80106B1C 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 4320 80106B20 28000424 */   addiu     $a0, $zero, 0x28
    /* 4324 80106B24 04EA030C */  jal        vs_mainMenu_menuItemFlyoutLeft
    /* 4328 80106B28 21200000 */   addu      $a0, $zero, $zero
    /* 432C 80106B2C 02000224 */  addiu      $v0, $zero, 0x2
    /* 4330 80106B30 31000212 */  beq        $s0, $v0, .L80106BF8
    /* 4334 80106B34 0300022A */   slti      $v0, $s0, 0x3
    /* 4338 80106B38 05004010 */  beqz       $v0, .L80106B50
    /* 433C 80106B3C 01000224 */   addiu     $v0, $zero, 0x1
    /* 4340 80106B40 08000212 */  beq        $s0, $v0, .L80106B64
    /* 4344 80106B44 21100000 */   addu      $v0, $zero, $zero
    /* 4348 80106B48 0D1B0408 */  j          .L80106C34
    /* 434C 80106B4C 00000000 */   nop
  .L80106B50:
    /* 4350 80106B50 03000224 */  addiu      $v0, $zero, 0x3
    /* 4354 80106B54 2B000212 */  beq        $s0, $v0, .L80106C04
    /* 4358 80106B58 21100000 */   addu      $v0, $zero, $zero
    /* 435C 80106B5C 0D1B0408 */  j          .L80106C34
    /* 4360 80106B60 00000000 */   nop
  .L80106B64:
    /* 4364 80106B64 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 4368 80106B68 6216010C */  jal        vs_main_playSfxDefault
    /* 436C 80106B6C 19000524 */   addiu     $a1, $zero, 0x19
    /* 4370 80106B70 1180023C */  lui        $v0, %hi(D_8010BC3E)
    /* 4374 80106B74 3EBC4290 */  lbu        $v0, %lo(D_8010BC3E)($v0)
    /* 4378 80106B78 00000000 */  nop
    /* 437C 80106B7C 06004010 */  beqz       $v0, .L80106B98
    /* 4380 80106B80 1180023C */   lui       $v0, %hi(_combiningItem)
    /* 4384 80106B84 81BC4490 */  lbu        $a0, %lo(_combiningItem)($v0)
    /* 4388 80106B88 B30C040C */  jal        _disassembleShield
    /* 438C 80106B8C 00000000 */   nop
    /* 4390 80106B90 EA1A0408 */  j          .L80106BA8
    /* 4394 80106B94 1180023C */   lui       $v0, %hi(D_8010BC3C)
  .L80106B98:
    /* 4398 80106B98 81BC4490 */  lbu        $a0, %lo(_combiningItem)($v0)
    /* 439C 80106B9C 1B0C040C */  jal        _disassembleWeapon
    /* 43A0 80106BA0 00000000 */   nop
    /* 43A4 80106BA4 1180023C */  lui        $v0, %hi(D_8010BC3C)
  .L80106BA8:
    /* 43A8 80106BA8 3CBC4390 */  lbu        $v1, %lo(D_8010BC3C)($v0)
    /* 43AC 80106BAC 05000224 */  addiu      $v0, $zero, 0x5
    /* 43B0 80106BB0 03006214 */  bne        $v1, $v0, .L80106BC0
    /* 43B4 80106BB4 1180023C */   lui       $v0, %hi(D_8010BC3E)
    /* 43B8 80106BB8 0D1B0408 */  j          .L80106C34
    /* 43BC 80106BBC FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80106BC0:
    /* 43C0 80106BC0 3EBC4290 */  lbu        $v0, %lo(D_8010BC3E)($v0)
    /* 43C4 80106BC4 00000000 */  nop
    /* 43C8 80106BC8 05004010 */  beqz       $v0, .L80106BE0
    /* 43CC 80106BCC 00000000 */   nop
    /* 43D0 80106BD0 E8F8030C */  jal        vs_mainMenu_unequipShield
    /* 43D4 80106BD4 00000000 */   nop
    /* 43D8 80106BD8 FB1A0408 */  j          .L80106BEC
    /* 43DC 80106BDC 1180033C */   lui       $v1, %hi(D_8010BC3C)
  .L80106BE0:
    /* 43E0 80106BE0 D8F8030C */  jal        vs_mainMenu_unequipAllWeapons
    /* 43E4 80106BE4 00000000 */   nop
    /* 43E8 80106BE8 1180033C */  lui        $v1, %hi(D_8010BC3C)
  .L80106BEC:
    /* 43EC 80106BEC 07000224 */  addiu      $v0, $zero, 0x7
    /* 43F0 80106BF0 0C1B0408 */  j          .L80106C30
    /* 43F4 80106BF4 3CBC62A0 */   sb        $v0, %lo(D_8010BC3C)($v1)
  .L80106BF8:
    /* 43F8 80106BF8 1180023C */  lui        $v0, %hi(D_8010BC3C)
    /* 43FC 80106BFC 0C1B0408 */  j          .L80106C30
    /* 4400 80106C00 3CBC40A0 */   sb        $zero, %lo(D_8010BC3C)($v0)
  .L80106C04:
    /* 4404 80106C04 E00C040C */  jal        func_80103380
    /* 4408 80106C08 21200000 */   addu      $a0, $zero, $zero
    /* 440C 80106C0C 0D1B0408 */  j          .L80106C34
    /* 4410 80106C10 00000000 */   nop
    /* 4414 80106C14 1180023C */  lui        $v0, %hi(D_8010BC3E)
    /* 4418 80106C18 3EBC4490 */  lbu        $a0, %lo(D_8010BC3E)($v0)
    /* 441C 80106C1C 962E040C */  jal        func_8010BA58
    /* 4420 80106C20 00000000 */   nop
    /* 4424 80106C24 21184000 */  addu       $v1, $v0, $zero
    /* 4428 80106C28 02006010 */  beqz       $v1, .L80106C34
    /* 442C 80106C2C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80106C30:
    /* 4430 80106C30 21100000 */  addu       $v0, $zero, $zero
  .L80106C34:
    /* 4434 80106C34 9400BF8F */  lw         $ra, 0x94($sp)
    /* 4438 80106C38 9000BE8F */  lw         $fp, 0x90($sp)
    /* 443C 80106C3C 8C00B78F */  lw         $s7, 0x8C($sp)
    /* 4440 80106C40 8800B68F */  lw         $s6, 0x88($sp)
    /* 4444 80106C44 8400B58F */  lw         $s5, 0x84($sp)
    /* 4448 80106C48 8000B48F */  lw         $s4, 0x80($sp)
    /* 444C 80106C4C 7C00B38F */  lw         $s3, 0x7C($sp)
    /* 4450 80106C50 7800B28F */  lw         $s2, 0x78($sp)
    /* 4454 80106C54 7400B18F */  lw         $s1, 0x74($sp)
    /* 4458 80106C58 7000B08F */  lw         $s0, 0x70($sp)
    /* 445C 80106C5C 0800E003 */  jr         $ra
    /* 4460 80106C60 9800BD27 */   addiu     $sp, $sp, 0x98
endlabel func_80106610
