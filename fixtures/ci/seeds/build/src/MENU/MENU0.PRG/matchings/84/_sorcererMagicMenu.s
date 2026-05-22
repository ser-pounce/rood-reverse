nonmatching _sorcererMagicMenu, 0x344

glabel _sorcererMagicMenu
    /* FA8 801037A8 F0FEBD27 */  addiu      $sp, $sp, -0x110
    /* FAC 801037AC 21188000 */  addu       $v1, $a0, $zero
    /* FB0 801037B0 0C01BFAF */  sw         $ra, 0x10C($sp)
    /* FB4 801037B4 0801BEAF */  sw         $fp, 0x108($sp)
    /* FB8 801037B8 0401B7AF */  sw         $s7, 0x104($sp)
    /* FBC 801037BC 0001B6AF */  sw         $s6, 0x100($sp)
    /* FC0 801037C0 FC00B5AF */  sw         $s5, 0xFC($sp)
    /* FC4 801037C4 F800B4AF */  sw         $s4, 0xF8($sp)
    /* FC8 801037C8 F400B3AF */  sw         $s3, 0xF4($sp)
    /* FCC 801037CC F000B2AF */  sw         $s2, 0xF0($sp)
    /* FD0 801037D0 EC00B1AF */  sw         $s1, 0xEC($sp)
    /* FD4 801037D4 0C006010 */  beqz       $v1, .L80103808
    /* FD8 801037D8 E800B0AF */   sw        $s0, 0xE8($sp)
    /* FDC 801037DC 02000424 */  addiu      $a0, $zero, 0x2
    /* FE0 801037E0 01000524 */  addiu      $a1, $zero, 0x1
    /* FE4 801037E4 1080023C */  lui        $v0, %hi(D_80106908)
    /* FE8 801037E8 26186400 */  xor        $v1, $v1, $a0
    /* FEC 801037EC 2B186500 */  sltu       $v1, $v1, $a1
    /* FF0 801037F0 4BEA030C */  jal        func_800FA92C
    /* FF4 801037F4 086943AC */   sw        $v1, %lo(D_80106908)($v0)
    /* FF8 801037F8 21100000 */  addu       $v0, $zero, $zero
    /* FFC 801037FC 1080033C */  lui        $v1, %hi(D_80106900)
    /* 1000 80103800 AF0E0408 */  j          .L80103ABC
    /* 1004 80103804 006960AC */   sw        $zero, %lo(D_80106900)($v1)
  .L80103808:
    /* 1008 80103808 1080023C */  lui        $v0, %hi(D_80106900)
    /* 100C 8010380C 0069438C */  lw         $v1, %lo(D_80106900)($v0)
    /* 1010 80103810 01000224 */  addiu      $v0, $zero, 0x1
    /* 1014 80103814 6E006210 */  beq        $v1, $v0, .L801039D0
    /* 1018 80103818 02006228 */   slti      $v0, $v1, 0x2
    /* 101C 8010381C 05004010 */  beqz       $v0, .L80103834
    /* 1020 80103820 02000224 */   addiu     $v0, $zero, 0x2
    /* 1024 80103824 07006010 */  beqz       $v1, .L80103844
    /* 1028 80103828 21100000 */   addu      $v0, $zero, $zero
    /* 102C 8010382C AF0E0408 */  j          .L80103ABC
    /* 1030 80103830 00000000 */   nop
  .L80103834:
    /* 1034 80103834 99006210 */  beq        $v1, $v0, .L80103A9C
    /* 1038 80103838 21100000 */   addu      $v0, $zero, $zero
    /* 103C 8010383C AF0E0408 */  j          .L80103ABC
    /* 1040 80103840 00000000 */   nop
  .L80103844:
    /* 1044 80103844 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* 1048 80103848 6A4E4290 */  lbu        $v0, %lo(vs_battle_shortcutInvoked)($v0)
    /* 104C 8010384C 00000000 */  nop
    /* 1050 80103850 05004014 */  bnez       $v0, .L80103868
    /* 1054 80103854 21980000 */   addu      $s3, $zero, $zero
    /* 1058 80103858 74EA030C */  jal        vs_mainmenu_ready
    /* 105C 8010385C 00000000 */   nop
    /* 1060 80103860 96004010 */  beqz       $v0, .L80103ABC
    /* 1064 80103864 21100000 */   addu      $v0, $zero, $zero
  .L80103868:
    /* 1068 80103868 21906002 */  addu       $s2, $s3, $zero
    /* 106C 8010386C 1080023C */  lui        $v0, %hi(_baseStrings)
    /* 1070 80103870 584A5E24 */  addiu      $fp, $v0, %lo(_baseStrings)
    /* 1074 80103874 48001624 */  addiu      $s6, $zero, 0x48
    /* 1078 80103878 04001524 */  addiu      $s5, $zero, 0x4
    /* 107C 8010387C 1000B727 */  addiu      $s7, $sp, 0x10
    /* 1080 80103880 21A0E002 */  addu       $s4, $s7, $zero
  .L80103884:
    /* 1084 80103884 0F80083C */  lui        $t0, %hi(vs_battle_sorcererSpellIds)
    /* 1088 80103888 8CBD0825 */  addiu      $t0, $t0, %lo(vs_battle_sorcererSpellIds)
    /* 108C 8010388C 21104802 */  addu       $v0, $s2, $t0
    /* 1090 80103890 0580083C */  lui        $t0, %hi(vs_main_skills)
    /* 1094 80103894 00005190 */  lbu        $s1, 0x0($v0)
    /* 1098 80103898 DCB90825 */  addiu      $t0, $t0, %lo(vs_main_skills)
    /* 109C 8010389C 40101100 */  sll        $v0, $s1, 1
    /* 10A0 801038A0 21105100 */  addu       $v0, $v0, $s1
    /* 10A4 801038A4 80100200 */  sll        $v0, $v0, 2
    /* 10A8 801038A8 21105100 */  addu       $v0, $v0, $s1
    /* 10AC 801038AC 80180200 */  sll        $v1, $v0, 2
    /* 10B0 801038B0 21106800 */  addu       $v0, $v1, $t0
    /* 10B4 801038B4 0C00428C */  lw         $v0, 0xC($v0)
    /* 10B8 801038B8 00000000 */  nop
    /* 10BC 801038BC C2130200 */  srl        $v0, $v0, 15
    /* 10C0 801038C0 01004230 */  andi       $v0, $v0, 0x1
    /* 10C4 801038C4 1E004010 */  beqz       $v0, .L80103940
    /* 10C8 801038C8 21200000 */   addu      $a0, $zero, $zero
    /* 10CC 801038CC 21282002 */  addu       $a1, $s1, $zero
    /* 10D0 801038D0 0580083C */  lui        $t0, %hi(D_8004B9F8)
    /* 10D4 801038D4 F8B90825 */  addiu      $t0, $t0, %lo(D_8004B9F8)
    /* 10D8 801038D8 21106800 */  addu       $v0, $v1, $t0
    /* 10DC 801038DC 000082AE */  sw         $v0, 0x0($s4)
    /* 10E0 801038E0 2110DE02 */  addu       $v0, $s6, $fp
    /* 10E4 801038E4 00004294 */  lhu        $v0, 0x0($v0)
    /* 10E8 801038E8 2118F502 */  addu       $v1, $s7, $s5
    /* 10EC 801038EC 40100200 */  sll        $v0, $v0, 1
    /* 10F0 801038F0 21105E00 */  addu       $v0, $v0, $fp
    /* 10F4 801038F4 000062AC */  sw         $v0, 0x0($v1)
    /* 10F8 801038F8 80181300 */  sll        $v1, $s3, 2
    /* 10FC 801038FC A000A227 */  addiu      $v0, $sp, 0xA0
    /* 1100 80103900 21804300 */  addu       $s0, $v0, $v1
    /* 1104 80103904 7429020C */  jal        vs_battle_getSkillFlags
    /* 1108 80103908 000000AE */   sw        $zero, 0x0($s0)
    /* 110C 8010390C 06004010 */  beqz       $v0, .L80103928
    /* 1110 80103910 1080023C */   lui       $v0, %hi(_availableSorcereSpells)
    /* 1114 80103914 0000028E */  lw         $v0, 0x0($s0)
    /* 1118 80103918 00000000 */  nop
    /* 111C 8010391C 01004234 */  ori        $v0, $v0, 0x1
    /* 1120 80103920 000002AE */  sw         $v0, 0x0($s0)
    /* 1124 80103924 1080023C */  lui        $v0, %hi(_availableSorcereSpells)
  .L80103928:
    /* 1128 80103928 58694224 */  addiu      $v0, $v0, %lo(_availableSorcereSpells)
    /* 112C 8010392C 21106202 */  addu       $v0, $s3, $v0
    /* 1130 80103930 000051A0 */  sb         $s1, 0x0($v0)
    /* 1134 80103934 0800B526 */  addiu      $s5, $s5, 0x8
    /* 1138 80103938 08009426 */  addiu      $s4, $s4, 0x8
    /* 113C 8010393C 01007326 */  addiu      $s3, $s3, 0x1
  .L80103940:
    /* 1140 80103940 01005226 */  addiu      $s2, $s2, 0x1
    /* 1144 80103944 1200422A */  slti       $v0, $s2, 0x12
    /* 1148 80103948 CEFF4014 */  bnez       $v0, .L80103884
    /* 114C 8010394C 0200D626 */   addiu     $s6, $s6, 0x2
    /* 1150 80103950 0F80023C */  lui        $v0, %hi(D_800F4EA0)
    /* 1154 80103954 A04E428C */  lw         $v0, %lo(D_800F4EA0)($v0)
    /* 1158 80103958 00000000 */  nop
    /* 115C 8010395C B7004230 */  andi       $v0, $v0, 0xB7
    /* 1160 80103960 09004010 */  beqz       $v0, .L80103988
    /* 1164 80103964 21900000 */   addu      $s2, $zero, $zero
    /* 1168 80103968 A000A327 */  addiu      $v1, $sp, 0xA0
  .L8010396C:
    /* 116C 8010396C 0000628C */  lw         $v0, 0x0($v1)
    /* 1170 80103970 01005226 */  addiu      $s2, $s2, 0x1
    /* 1174 80103974 01004234 */  ori        $v0, $v0, 0x1
    /* 1178 80103978 000062AC */  sw         $v0, 0x0($v1)
    /* 117C 8010397C 1200422A */  slti       $v0, $s2, 0x12
    /* 1180 80103980 FAFF4014 */  bnez       $v0, .L8010396C
    /* 1184 80103984 04006324 */   addiu     $v1, $v1, 0x4
  .L80103988:
    /* 1188 80103988 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 118C 8010398C 20005024 */  addiu      $s0, $v0, %lo(vs_main_settings)
    /* 1190 80103990 1080023C */  lui        $v0, %hi(D_80106908)
    /* 1194 80103994 0869428C */  lw         $v0, %lo(D_80106908)($v0)
    /* 1198 80103998 01001292 */  lbu        $s2, 0x1($s0)
    /* 119C 8010399C 02004010 */  beqz       $v0, .L801039A8
    /* 11A0 801039A0 01000224 */   addiu     $v0, $zero, 0x1
    /* 11A4 801039A4 010002A2 */  sb         $v0, 0x1($s0)
  .L801039A8:
    /* 11A8 801039A8 21206002 */  addu       $a0, $s3, $zero
    /* 11AC 801039AC 09020524 */  addiu      $a1, $zero, 0x209
    /* 11B0 801039B0 1000A627 */  addiu      $a2, $sp, 0x10
    /* 11B4 801039B4 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 11B8 801039B8 A000A727 */   addiu     $a3, $sp, 0xA0
    /* 11BC 801039BC 1080033C */  lui        $v1, %hi(D_80106900)
    /* 11C0 801039C0 01000224 */  addiu      $v0, $zero, 0x1
    /* 11C4 801039C4 010012A2 */  sb         $s2, 0x1($s0)
    /* 11C8 801039C8 AE0E0408 */  j          .L80103AB8
    /* 11CC 801039CC 006962AC */   sw        $v0, %lo(D_80106900)($v1)
  .L801039D0:
    /* 11D0 801039D0 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 11D4 801039D4 1080103C */   lui       $s0, %hi(D_80106904)
    /* 11D8 801039D8 01004424 */  addiu      $a0, $v0, 0x1
    /* 11DC 801039DC 26008010 */  beqz       $a0, .L80103A78
    /* 11E0 801039E0 046904AE */   sw        $a0, %lo(D_80106904)($s0)
    /* 11E4 801039E4 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* 11E8 801039E8 6A4E4390 */  lbu        $v1, %lo(vs_battle_shortcutInvoked)($v0)
    /* 11EC 801039EC 1080023C */  lui        $v0, %hi(vs_mainMenu_isLevelledSpell)
    /* 11F0 801039F0 06006010 */  beqz       $v1, .L80103A0C
    /* 11F4 801039F4 D42240A0 */   sb        $zero, %lo(vs_mainMenu_isLevelledSpell)($v0)
    /* 11F8 801039F8 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 11FC 801039FC 0B008214 */  bne        $a0, $v0, .L80103A2C
    /* 1200 80103A00 1080043C */   lui       $a0, %hi(D_80106904)
    /* 1204 80103A04 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 1208 80103A08 046902AE */  sw         $v0, %lo(D_80106904)($s0)
  .L80103A0C:
    /* 120C 80103A0C 0469038E */  lw         $v1, %lo(D_80106904)($s0)
    /* 1210 80103A10 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 1214 80103A14 05006214 */  bne        $v1, $v0, .L80103A2C
    /* 1218 80103A18 1080043C */   lui       $a0, %hi(D_80106904)
    /* 121C 80103A1C 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 1220 80103A20 21200000 */   addu      $a0, $zero, $zero
    /* 1224 80103A24 9B0E0408 */  j          .L80103A6C
    /* 1228 80103A28 1080033C */   lui       $v1, %hi(D_80106900)
  .L80103A2C:
    /* 122C 80103A2C 0469838C */  lw         $v1, %lo(D_80106904)($a0)
    /* 1230 80103A30 00000000 */  nop
    /* 1234 80103A34 06006018 */  blez       $v1, .L80103A50
    /* 1238 80103A38 1080023C */   lui       $v0, %hi(_availableSorcereSpells)
    /* 123C 80103A3C 58694224 */  addiu      $v0, $v0, %lo(_availableSorcereSpells)
    /* 1240 80103A40 21106200 */  addu       $v0, $v1, $v0
    /* 1244 80103A44 FFFF4290 */  lbu        $v0, -0x1($v0)
    /* 1248 80103A48 00000000 */  nop
    /* 124C 80103A4C 046982AC */  sw         $v0, %lo(D_80106904)($a0)
  .L80103A50:
    /* 1250 80103A50 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 1254 80103A54 28000424 */   addiu     $a0, $zero, 0x28
    /* 1258 80103A58 EAFE030C */  jal        func_800FFBA8
    /* 125C 80103A5C 00000000 */   nop
    /* 1260 80103A60 A2FE030C */  jal        func_800FFA88
    /* 1264 80103A64 21200000 */   addu      $a0, $zero, $zero
    /* 1268 80103A68 1080033C */  lui        $v1, %hi(D_80106900)
  .L80103A6C:
    /* 126C 80103A6C 02000224 */  addiu      $v0, $zero, 0x2
    /* 1270 80103A70 AE0E0408 */  j          .L80103AB8
    /* 1274 80103A74 006962AC */   sw        $v0, %lo(D_80106900)($v1)
  .L80103A78:
    /* 1278 80103A78 1080103C */  lui        $s0, %hi(_availableSorcereSpells)
    /* 127C 80103A7C 2C02040C */  jal        func_801008B0
    /* 1280 80103A80 58691026 */   addiu     $s0, $s0, %lo(_availableSorcereSpells)
    /* 1284 80103A84 21105000 */  addu       $v0, $v0, $s0
    /* 1288 80103A88 00004490 */  lbu        $a0, 0x0($v0)
    /* 128C 80103A8C 210A040C */  jal        _setMPCost
    /* 1290 80103A90 00000000 */   nop
    /* 1294 80103A94 AF0E0408 */  j          .L80103ABC
    /* 1298 80103A98 21100000 */   addu      $v0, $zero, $zero
  .L80103A9C:
    /* 129C 80103A9C 74EA030C */  jal        vs_mainmenu_ready
    /* 12A0 80103AA0 00000000 */   nop
    /* 12A4 80103AA4 04004010 */  beqz       $v0, .L80103AB8
    /* 12A8 80103AA8 1080023C */   lui       $v0, %hi(D_80106904)
    /* 12AC 80103AAC 0469428C */  lw         $v0, %lo(D_80106904)($v0)
    /* 12B0 80103AB0 AF0E0408 */  j          .L80103ABC
    /* 12B4 80103AB4 00000000 */   nop
  .L80103AB8:
    /* 12B8 80103AB8 21100000 */  addu       $v0, $zero, $zero
  .L80103ABC:
    /* 12BC 80103ABC 0C01BF8F */  lw         $ra, 0x10C($sp)
    /* 12C0 80103AC0 0801BE8F */  lw         $fp, 0x108($sp)
    /* 12C4 80103AC4 0401B78F */  lw         $s7, 0x104($sp)
    /* 12C8 80103AC8 0001B68F */  lw         $s6, 0x100($sp)
    /* 12CC 80103ACC FC00B58F */  lw         $s5, 0xFC($sp)
    /* 12D0 80103AD0 F800B48F */  lw         $s4, 0xF8($sp)
    /* 12D4 80103AD4 F400B38F */  lw         $s3, 0xF4($sp)
    /* 12D8 80103AD8 F000B28F */  lw         $s2, 0xF0($sp)
    /* 12DC 80103ADC EC00B18F */  lw         $s1, 0xEC($sp)
    /* 12E0 80103AE0 E800B08F */  lw         $s0, 0xE8($sp)
    /* 12E4 80103AE4 0800E003 */  jr         $ra
    /* 12E8 80103AE8 1001BD27 */   addiu     $sp, $sp, 0x110
endlabel _sorcererMagicMenu
