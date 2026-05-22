nonmatching func_80106ECC, 0x430

glabel func_80106ECC
    /* 46CC 80106ECC 68FFBD27 */  addiu      $sp, $sp, -0x98
    /* 46D0 80106ED0 9400BFAF */  sw         $ra, 0x94($sp)
    /* 46D4 80106ED4 9000BEAF */  sw         $fp, 0x90($sp)
    /* 46D8 80106ED8 8C00B7AF */  sw         $s7, 0x8C($sp)
    /* 46DC 80106EDC 8800B6AF */  sw         $s6, 0x88($sp)
    /* 46E0 80106EE0 8400B5AF */  sw         $s5, 0x84($sp)
    /* 46E4 80106EE4 8000B4AF */  sw         $s4, 0x80($sp)
    /* 46E8 80106EE8 7C00B3AF */  sw         $s3, 0x7C($sp)
    /* 46EC 80106EEC 7800B2AF */  sw         $s2, 0x78($sp)
    /* 46F0 80106EF0 7400B1AF */  sw         $s1, 0x74($sp)
    /* 46F4 80106EF4 0D008010 */  beqz       $a0, .L80106F2C
    /* 46F8 80106EF8 7000B0AF */   sw        $s0, 0x70($sp)
    /* 46FC 80106EFC 8123030C */  jal        func_800C8E04
    /* 4700 80106F00 01000424 */   addiu     $a0, $zero, 0x1
    /* 4704 80106F04 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 4708 80106F08 A424448C */  lw         $a0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 470C 80106F0C 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 4710 80106F10 90038424 */   addiu     $a0, $a0, 0x390
    /* 4714 80106F14 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 4718 80106F18 28000424 */   addiu     $a0, $zero, 0x28
    /* 471C 80106F1C 21100000 */  addu       $v0, $zero, $zero
    /* 4720 80106F20 1180033C */  lui        $v1, %hi(D_8010BC48)
    /* 4724 80106F24 B31C0408 */  j          .L801072CC
    /* 4728 80106F28 48BC60A0 */   sb        $zero, %lo(D_8010BC48)($v1)
  .L80106F2C:
    /* 472C 80106F2C 1180023C */  lui        $v0, %hi(D_8010BC48)
    /* 4730 80106F30 48BC4390 */  lbu        $v1, %lo(D_8010BC48)($v0)
    /* 4734 80106F34 00000000 */  nop
    /* 4738 80106F38 0700622C */  sltiu      $v0, $v1, 0x7
    /* 473C 80106F3C E2004010 */  beqz       $v0, .L801072C8
    /* 4740 80106F40 1080023C */   lui       $v0, %hi(jtbl_80102878)
    /* 4744 80106F44 78284224 */  addiu      $v0, $v0, %lo(jtbl_80102878)
    /* 4748 80106F48 80180300 */  sll        $v1, $v1, 2
    /* 474C 80106F4C 21186200 */  addu       $v1, $v1, $v0
    /* 4750 80106F50 0000628C */  lw         $v0, 0x0($v1)
    /* 4754 80106F54 00000000 */  nop
    /* 4758 80106F58 08004000 */  jr         $v0
    /* 475C 80106F5C 00000000 */   nop
    /* 4760 80106F60 74EA030C */  jal        vs_mainmenu_ready
    /* 4764 80106F64 00000000 */   nop
    /* 4768 80106F68 D7004010 */  beqz       $v0, .L801072C8
    /* 476C 80106F6C 21200000 */   addu      $a0, $zero, $zero
    /* 4770 80106F70 740A040C */  jal        func_801029D0
    /* 4774 80106F74 B8000524 */   addiu     $a1, $zero, 0xB8
    /* 4778 80106F78 1180033C */  lui        $v1, %hi(D_8010BC48)
    /* 477C 80106F7C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4780 80106F80 B21C0408 */  j          .L801072C8
    /* 4784 80106F84 48BC62A0 */   sb        $v0, %lo(D_8010BC48)($v1)
    /* 4788 80106F88 74EA030C */  jal        vs_mainmenu_ready
    /* 478C 80106F8C 00000000 */   nop
    /* 4790 80106F90 CD004010 */  beqz       $v0, .L801072C8
    /* 4794 80106F94 21900000 */   addu      $s2, $zero, $zero
    /* 4798 80106F98 21884002 */  addu       $s1, $s2, $zero
    /* 479C 80106F9C 0680023C */  lui        $v0, %hi(D_80060148)
    /* 47A0 80106FA0 48015E24 */  addiu      $fp, $v0, %lo(D_80060148)
    /* 47A4 80106FA4 0F80173C */  lui        $s7, %hi(vs_battle_stringBuf)
    /* 47A8 80106FA8 1180023C */  lui        $v0, %hi(D_8010BCA4)
    /* 47AC 80106FAC A4BC5624 */  addiu      $s6, $v0, %lo(D_8010BCA4)
    /* 47B0 80106FB0 04001424 */  addiu      $s4, $zero, 0x4
    /* 47B4 80106FB4 1000B527 */  addiu      $s5, $sp, 0x10
    /* 47B8 80106FB8 2198A002 */  addu       $s3, $s5, $zero
    /* 47BC 80106FBC 0680083C */  lui        $t0, %hi(vs_main_inventoryIndices)
  .L80106FC0:
    /* 47C0 80106FC0 D8190825 */  addiu      $t0, $t0, %lo(vs_main_inventoryIndices)
    /* 47C4 80106FC4 21102802 */  addu       $v0, $s1, $t0
    /* 47C8 80106FC8 00005090 */  lbu        $s0, 0x0($v0)
    /* 47CC 80106FCC 00000000 */  nop
    /* 47D0 80106FD0 12000012 */  beqz       $s0, .L8010701C
    /* 47D4 80106FD4 40211000 */   sll       $a0, $s0, 5
    /* 47D8 80106FD8 21209E00 */  addu       $a0, $a0, $fp
    /* 47DC 80106FDC 21286002 */  addu       $a1, $s3, $zero
    /* 47E0 80106FE0 5000A227 */  addiu      $v0, $sp, 0x50
    /* 47E4 80106FE4 80301200 */  sll        $a2, $s2, 2
    /* 47E8 80106FE8 21304600 */  addu       $a2, $v0, $a2
    /* 47EC 80106FEC 08007326 */  addiu      $s3, $s3, 0x8
    /* 47F0 80106FF0 8C4EE78E */  lw         $a3, %lo(vs_battle_stringBuf)($s7)
    /* 47F4 80106FF4 82F2030C */  jal        vs_mainMenu_initUiWeapon
    /* 47F8 80106FF8 01005226 */   addiu     $s2, $s2, 0x1
    /* 47FC 80106FFC 2118B402 */  addu       $v1, $s5, $s4
    /* 4800 80107000 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 4804 80107004 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 4808 80107008 08009426 */  addiu      $s4, $s4, 0x8
    /* 480C 8010700C 90034224 */  addiu      $v0, $v0, 0x390
    /* 4810 80107010 000062AC */  sw         $v0, 0x0($v1)
    /* 4814 80107014 21105602 */  addu       $v0, $s2, $s6
    /* 4818 80107018 000050A0 */  sb         $s0, 0x0($v0)
  .L8010701C:
    /* 481C 8010701C 01003126 */  addiu      $s1, $s1, 0x1
    /* 4820 80107020 0800222A */  slti       $v0, $s1, 0x8
    /* 4824 80107024 E6FF4014 */  bnez       $v0, .L80106FC0
    /* 4828 80107028 0680083C */   lui       $t0, %hi(vs_main_inventoryIndices)
    /* 482C 8010702C 21204002 */  addu       $a0, $s2, $zero
    /* 4830 80107030 0100053C */  lui        $a1, (0x1913C >> 16)
    /* 4834 80107034 3C91A534 */  ori        $a1, $a1, (0x1913C & 0xFFFF)
    /* 4838 80107038 1000A627 */  addiu      $a2, $sp, 0x10
    /* 483C 8010703C 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 4840 80107040 5000A727 */   addiu     $a3, $sp, 0x50
    /* 4844 80107044 1180033C */  lui        $v1, %hi(D_8010BC48)
    /* 4848 80107048 02000224 */  addiu      $v0, $zero, 0x2
    /* 484C 8010704C B21C0408 */  j          .L801072C8
    /* 4850 80107050 48BC62A0 */   sb        $v0, %lo(D_8010BC48)($v1)
    /* 4854 80107054 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 4858 80107058 1180103C */   lui       $s0, %hi(D_8010BC44)
    /* 485C 8010705C 01004224 */  addiu      $v0, $v0, 0x1
    /* 4860 80107060 99004010 */  beqz       $v0, .L801072C8
    /* 4864 80107064 44BC02AE */   sw        $v0, %lo(D_8010BC44)($s0)
    /* 4868 80107068 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 486C 8010706C 28000424 */   addiu     $a0, $zero, 0x28
    /* 4870 80107070 44BC028E */  lw         $v0, %lo(D_8010BC44)($s0)
    /* 4874 80107074 00000000 */  nop
    /* 4878 80107078 94004004 */  bltz       $v0, .L801072CC
    /* 487C 8010707C 00000000 */   nop
    /* 4880 80107080 9223030C */  jal        vs_battle_getMenuItem
    /* 4884 80107084 21200000 */   addu      $a0, $zero, $zero
    /* 4888 80107088 21184000 */  addu       $v1, $v0, $zero
    /* 488C 8010708C 02000224 */  addiu      $v0, $zero, 0x2
    /* 4890 80107090 000062A0 */  sb         $v0, 0x0($v1)
    /* 4894 80107094 A4000224 */  addiu      $v0, $zero, 0xA4
    /* 4898 80107098 010062A0 */  sb         $v0, 0x1($v1)
    /* 489C 8010709C 44BC048E */  lw         $a0, %lo(D_8010BC44)($s0)
    /* 48A0 801070A0 10000224 */  addiu      $v0, $zero, 0x10
    /* 48A4 801070A4 180062A4 */  sh         $v0, 0x18($v1)
    /* 48A8 801070A8 9223030C */  jal        vs_battle_getMenuItem
    /* 48AC 801070AC 09008424 */   addiu     $a0, $a0, 0x9
    /* 48B0 801070B0 21184000 */  addu       $v1, $v0, $zero
    /* 48B4 801070B4 04000224 */  addiu      $v0, $zero, 0x4
    /* 48B8 801070B8 000062A0 */  sb         $v0, 0x0($v1)
    /* 48BC 801070BC 9B000224 */  addiu      $v0, $zero, 0x9B
    /* 48C0 801070C0 180062A4 */  sh         $v0, 0x18($v1)
    /* 48C4 801070C4 12000224 */  addiu      $v0, $zero, 0x12
    /* 48C8 801070C8 1A0062A4 */  sh         $v0, 0x1A($v1)
    /* 48CC 801070CC 1180033C */  lui        $v1, %hi(D_8010BC48)
    /* 48D0 801070D0 03000224 */  addiu      $v0, $zero, 0x3
    /* 48D4 801070D4 B21C0408 */  j          .L801072C8
    /* 48D8 801070D8 48BC62A0 */   sb        $v0, %lo(D_8010BC48)($v1)
    /* 48DC 801070DC 74EA030C */  jal        vs_mainmenu_ready
    /* 48E0 801070E0 00000000 */   nop
    /* 48E4 801070E4 79004010 */  beqz       $v0, .L801072CC
    /* 48E8 801070E8 21100000 */   addu      $v0, $zero, $zero
    /* 48EC 801070EC 9223030C */  jal        vs_battle_getMenuItem
    /* 48F0 801070F0 21200000 */   addu      $a0, $zero, $zero
    /* 48F4 801070F4 21200000 */  addu       $a0, $zero, $zero
    /* 48F8 801070F8 20000524 */  addiu      $a1, $zero, 0x20
    /* 48FC 801070FC 18000324 */  addiu      $v1, $zero, 0x18
    /* 4900 80107100 030B040C */  jal        func_80102C0C
    /* 4904 80107104 090043A0 */   sb        $v1, 0x9($v0)
    /* 4908 80107108 1180103C */  lui        $s0, %hi(D_8010BC44)
    /* 490C 8010710C 44BC048E */  lw         $a0, %lo(D_8010BC44)($s0)
    /* 4910 80107110 0A000524 */  addiu      $a1, $zero, 0xA
    /* 4914 80107114 030B040C */  jal        func_80102C0C
    /* 4918 80107118 09008424 */   addiu     $a0, $a0, 0x9
    /* 491C 8010711C 1180023C */  lui        $v0, %hi(D_8010BCA4)
    /* 4920 80107120 44BC038E */  lw         $v1, %lo(D_8010BC44)($s0)
    /* 4924 80107124 A4BC4224 */  addiu      $v0, $v0, %lo(D_8010BCA4)
    /* 4928 80107128 21186200 */  addu       $v1, $v1, $v0
    /* 492C 8010712C 00007090 */  lbu        $s0, 0x0($v1)
    /* 4930 80107130 1180033C */  lui        $v1, %hi(_combiningItem)
    /* 4934 80107134 21200002 */  addu       $a0, $s0, $zero
    /* 4938 80107138 FFFF8224 */  addiu      $v0, $a0, -0x1
    /* 493C 8010713C 9CF4030C */  jal        vs_mainMenu_setUiWeaponStats
    /* 4940 80107140 81BC62A0 */   sb        $v0, %lo(_combiningItem)($v1)
    /* 4944 80107144 F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 4948 80107148 07000424 */   addiu     $a0, $zero, 0x7
    /* 494C 8010714C 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 4950 80107150 03000424 */   addiu     $a0, $zero, 0x3
    /* 4954 80107154 1180023C */  lui        $v0, %hi(D_8010BC49)
    /* 4958 80107158 1180033C */  lui        $v1, %hi(D_8010BC48)
    /* 495C 8010715C 49BC40A0 */  sb         $zero, %lo(D_8010BC49)($v0)
    /* 4960 80107160 04000224 */  addiu      $v0, $zero, 0x4
    /* 4964 80107164 B21C0408 */  j          .L801072C8
    /* 4968 80107168 48BC62A0 */   sb        $v0, %lo(D_8010BC48)($v1)
    /* 496C 8010716C 1180043C */  lui        $a0, %hi(D_8010BC49)
    /* 4970 80107170 49BC8390 */  lbu        $v1, %lo(D_8010BC49)($a0)
    /* 4974 80107174 00000000 */  nop
    /* 4978 80107178 0500622C */  sltiu      $v0, $v1, 0x5
    /* 497C 8010717C 0A004010 */  beqz       $v0, .L801071A8
    /* 4980 80107180 01000624 */   addiu     $a2, $zero, 0x1
    /* 4984 80107184 21106600 */  addu       $v0, $v1, $a2
    /* 4988 80107188 49BC82A0 */  sb         $v0, %lo(D_8010BC49)($a0)
    /* 498C 8010718C 1180023C */  lui        $v0, %hi(_combiningItem)
    /* 4990 80107190 81BC4590 */  lbu        $a1, %lo(_combiningItem)($v0)
    /* 4994 80107194 49BC8490 */  lbu        $a0, %lo(D_8010BC49)($a0)
    /* 4998 80107198 44F1030C */  jal        vs_mainMenu_initSetWeaponGemMenu
    /* 499C 8010719C 2128A600 */   addu      $a1, $a1, $a2
    /* 49A0 801071A0 B31C0408 */  j          .L801072CC
    /* 49A4 801071A4 21100000 */   addu      $v0, $zero, $zero
  .L801071A8:
    /* 49A8 801071A8 160B040C */  jal        func_80102C58
    /* 49AC 801071AC 01000424 */   addiu     $a0, $zero, 0x1
    /* 49B0 801071B0 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 49B4 801071B4 A424448C */  lw         $a0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 49B8 801071B8 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 49BC 801071BC AC038424 */   addiu     $a0, $a0, 0x3AC
    /* 49C0 801071C0 1180033C */  lui        $v1, %hi(D_8010BC48)
    /* 49C4 801071C4 05000224 */  addiu      $v0, $zero, 0x5
    /* 49C8 801071C8 B21C0408 */  j          .L801072C8
    /* 49CC 801071CC 48BC62A0 */   sb        $v0, %lo(D_8010BC48)($v1)
    /* 49D0 801071D0 160B040C */  jal        func_80102C58
    /* 49D4 801071D4 21200000 */   addu      $a0, $zero, $zero
    /* 49D8 801071D8 21884000 */  addu       $s1, $v0, $zero
    /* 49DC 801071DC 3B002012 */  beqz       $s1, .L801072CC
    /* 49E0 801071E0 21100000 */   addu      $v0, $zero, $zero
    /* 49E4 801071E4 F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 49E8 801071E8 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 49EC 801071EC 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 49F0 801071F0 04000424 */   addiu     $a0, $zero, 0x4
    /* 49F4 801071F4 02000224 */  addiu      $v0, $zero, 0x2
    /* 49F8 801071F8 17002212 */  beq        $s1, $v0, .L80107258
    /* 49FC 801071FC 0300222A */   slti      $v0, $s1, 0x3
    /* 4A00 80107200 05004010 */  beqz       $v0, .L80107218
    /* 4A04 80107204 01000224 */   addiu     $v0, $zero, 0x1
    /* 4A08 80107208 08002212 */  beq        $s1, $v0, .L8010722C
    /* 4A0C 8010720C 21100000 */   addu      $v0, $zero, $zero
    /* 4A10 80107210 B31C0408 */  j          .L801072CC
    /* 4A14 80107214 00000000 */   nop
  .L80107218:
    /* 4A18 80107218 03000224 */  addiu      $v0, $zero, 0x3
    /* 4A1C 8010721C 15002212 */  beq        $s1, $v0, .L80107274
    /* 4A20 80107220 21100000 */   addu      $v0, $zero, $zero
    /* 4A24 80107224 B31C0408 */  j          .L801072CC
    /* 4A28 80107228 00000000 */   nop
  .L8010722C:
    /* 4A2C 8010722C BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 4A30 80107230 00000000 */   nop
    /* 4A34 80107234 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 4A38 80107238 0A000424 */   addiu     $a0, $zero, 0xA
    /* 4A3C 8010723C 9223030C */  jal        vs_battle_getMenuItem
    /* 4A40 80107240 0A000424 */   addiu     $a0, $zero, 0xA
    /* 4A44 80107244 1180033C */  lui        $v1, %hi(D_8010BC48)
    /* 4A48 80107248 020051A0 */  sb         $s1, 0x2($v0)
    /* 4A4C 8010724C 06000224 */  addiu      $v0, $zero, 0x6
    /* 4A50 80107250 B21C0408 */  j          .L801072C8
    /* 4A54 80107254 48BC62A0 */   sb        $v0, %lo(D_8010BC48)($v1)
  .L80107258:
    /* 4A58 80107258 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 4A5C 8010725C 28000424 */   addiu     $a0, $zero, 0x28
    /* 4A60 80107260 04EA030C */  jal        vs_mainMenu_menuItemFlyoutLeft
    /* 4A64 80107264 21200000 */   addu      $a0, $zero, $zero
    /* 4A68 80107268 1180023C */  lui        $v0, %hi(D_8010BC48)
    /* 4A6C 8010726C B21C0408 */  j          .L801072C8
    /* 4A70 80107270 48BC40A0 */   sb        $zero, %lo(D_8010BC48)($v0)
  .L80107274:
    /* 4A74 80107274 E00C040C */  jal        func_80103380
    /* 4A78 80107278 21200000 */   addu      $a0, $zero, $zero
    /* 4A7C 8010727C B31C0408 */  j          .L801072CC
    /* 4A80 80107280 00000000 */   nop
    /* 4A84 80107284 74EA030C */  jal        vs_mainmenu_ready
    /* 4A88 80107288 00000000 */   nop
    /* 4A8C 8010728C 0E004010 */  beqz       $v0, .L801072C8
    /* 4A90 80107290 0F80043C */   lui       $a0, %hi(vs_battle_stringBuf)
    /* 4A94 80107294 8C4E838C */  lw         $v1, %lo(vs_battle_stringBuf)($a0)
    /* 4A98 80107298 1080023C */  lui        $v0, %hi(D_801022D5)
    /* 4A9C 8010729C D52240A0 */  sb         $zero, %lo(D_801022D5)($v0)
    /* 4AA0 801072A0 01000224 */  addiu      $v0, $zero, 0x1
    /* 4AA4 801072A4 000062A0 */  sb         $v0, 0x0($v1)
    /* 4AA8 801072A8 1180023C */  lui        $v0, %hi(_combiningItem)
    /* 4AAC 801072AC 8C4E838C */  lw         $v1, %lo(vs_battle_stringBuf)($a0)
    /* 4AB0 801072B0 81BC4290 */  lbu        $v0, %lo(_combiningItem)($v0)
    /* 4AB4 801072B4 02000424 */  addiu      $a0, $zero, 0x2
    /* 4AB8 801072B8 A2FE030C */  jal        func_800FFA88
    /* 4ABC 801072BC 010062A0 */   sb        $v0, 0x1($v1)
    /* 4AC0 801072C0 B31C0408 */  j          .L801072CC
    /* 4AC4 801072C4 01000224 */   addiu     $v0, $zero, 0x1
  .L801072C8:
    /* 4AC8 801072C8 21100000 */  addu       $v0, $zero, $zero
  .L801072CC:
    /* 4ACC 801072CC 9400BF8F */  lw         $ra, 0x94($sp)
    /* 4AD0 801072D0 9000BE8F */  lw         $fp, 0x90($sp)
    /* 4AD4 801072D4 8C00B78F */  lw         $s7, 0x8C($sp)
    /* 4AD8 801072D8 8800B68F */  lw         $s6, 0x88($sp)
    /* 4ADC 801072DC 8400B58F */  lw         $s5, 0x84($sp)
    /* 4AE0 801072E0 8000B48F */  lw         $s4, 0x80($sp)
    /* 4AE4 801072E4 7C00B38F */  lw         $s3, 0x7C($sp)
    /* 4AE8 801072E8 7800B28F */  lw         $s2, 0x78($sp)
    /* 4AEC 801072EC 7400B18F */  lw         $s1, 0x74($sp)
    /* 4AF0 801072F0 7000B08F */  lw         $s0, 0x70($sp)
    /* 4AF4 801072F4 0800E003 */  jr         $ra
    /* 4AF8 801072F8 9800BD27 */   addiu     $sp, $sp, 0x98
endlabel func_80106ECC
