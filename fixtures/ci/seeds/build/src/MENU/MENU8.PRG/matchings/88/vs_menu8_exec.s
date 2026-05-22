nonmatching vs_menu8_exec, 0x5D4

glabel vs_menu8_exec
    /* FB4 801037B4 70FFBD27 */  addiu      $sp, $sp, -0x90
    /* FB8 801037B8 8800B2AF */  sw         $s2, 0x88($sp)
    /* FBC 801037BC 21908000 */  addu       $s2, $a0, $zero
    /* FC0 801037C0 8C00BFAF */  sw         $ra, 0x8C($sp)
    /* FC4 801037C4 8400B1AF */  sw         $s1, 0x84($sp)
    /* FC8 801037C8 8000B0AF */  sw         $s0, 0x80($sp)
    /* FCC 801037CC 00004292 */  lbu        $v0, 0x0($s2)
    /* FD0 801037D0 00000000 */  nop
    /* FD4 801037D4 FDFF4324 */  addiu      $v1, $v0, -0x3
    /* FD8 801037D8 0E00622C */  sltiu      $v0, $v1, 0xE
    /* FDC 801037DC 63014010 */  beqz       $v0, .L80103D6C
    /* FE0 801037E0 1080023C */   lui       $v0, %hi(jtbl_80102800)
    /* FE4 801037E4 00284224 */  addiu      $v0, $v0, %lo(jtbl_80102800)
    /* FE8 801037E8 80180300 */  sll        $v1, $v1, 2
    /* FEC 801037EC 21186200 */  addu       $v1, $v1, $v0
    /* FF0 801037F0 0000628C */  lw         $v0, 0x0($v1)
    /* FF4 801037F4 00000000 */  nop
    /* FF8 801037F8 08004000 */  jr         $v0
    /* FFC 801037FC 00000000 */   nop
    /* 1000 80103800 74EA030C */  jal        vs_mainmenu_ready
    /* 1004 80103804 00000000 */   nop
    /* 1008 80103808 59014010 */  beqz       $v0, .L80103D70
    /* 100C 8010380C 21100000 */   addu      $v0, $zero, $zero
    /* 1010 80103810 F2FE030C */  jal        func_800FFBC8
    /* 1014 80103814 00000000 */   nop
    /* 1018 80103818 21800000 */  addu       $s0, $zero, $zero
    /* 101C 8010381C 5800AA27 */  addiu      $t2, $sp, 0x58
    /* 1020 80103820 02000924 */  addiu      $t1, $zero, 0x2
    /* 1024 80103824 04000824 */  addiu      $t0, $zero, 0x4
    /* 1028 80103828 1000AB27 */  addiu      $t3, $sp, 0x10
    /* 102C 8010382C 21306001 */  addu       $a2, $t3, $zero
    /* 1030 80103830 1080023C */  lui        $v0, %hi(_menuStrings)
    /* 1034 80103834 58554724 */  addiu      $a3, $v0, %lo(_menuStrings)
    /* 1038 80103838 2128E000 */  addu       $a1, $a3, $zero
  .L8010383C:
    /* 103C 8010383C 21182701 */  addu       $v1, $t1, $a3
    /* 1040 80103840 04002925 */  addiu      $t1, $t1, 0x4
    /* 1044 80103844 21206801 */  addu       $a0, $t3, $t0
    /* 1048 80103848 08000825 */  addiu      $t0, $t0, 0x8
    /* 104C 8010384C 0000A294 */  lhu        $v0, 0x0($a1)
    /* 1050 80103850 0400A524 */  addiu      $a1, $a1, 0x4
    /* 1054 80103854 01001026 */  addiu      $s0, $s0, 0x1
    /* 1058 80103858 40100200 */  sll        $v0, $v0, 1
    /* 105C 8010385C 21104700 */  addu       $v0, $v0, $a3
    /* 1060 80103860 0000C2AC */  sw         $v0, 0x0($a2)
    /* 1064 80103864 00006294 */  lhu        $v0, 0x0($v1)
    /* 1068 80103868 0800C624 */  addiu      $a2, $a2, 0x8
    /* 106C 8010386C 40100200 */  sll        $v0, $v0, 1
    /* 1070 80103870 21104700 */  addu       $v0, $v0, $a3
    /* 1074 80103874 000082AC */  sw         $v0, 0x0($a0)
    /* 1078 80103878 000040AD */  sw         $zero, 0x0($t2)
    /* 107C 8010387C 0900022A */  slti       $v0, $s0, 0x9
    /* 1080 80103880 EEFF4014 */  bnez       $v0, .L8010383C
    /* 1084 80103884 04004A25 */   addiu     $t2, $t2, 0x4
    /* 1088 80103888 0680023C */  lui        $v0, %hi(vs_main_stateFlags + 0x11D)
    /* 108C 8010388C B5164290 */  lbu        $v0, %lo(vs_main_stateFlags + 0x11D)($v0)
    /* 1090 80103890 00000000 */  nop
    /* 1094 80103894 05004010 */  beqz       $v0, .L801038AC
    /* 1098 80103898 1080023C */   lui       $v0, %hi(D_80105D26)
    /* 109C 8010389C 265D4224 */  addiu      $v0, $v0, %lo(D_80105D26)
    /* 10A0 801038A0 4400A2AF */  sw         $v0, 0x44($sp)
    /* 10A4 801038A4 01000224 */  addiu      $v0, $zero, 0x1
    /* 10A8 801038A8 7000A2AF */  sw         $v0, 0x70($sp)
  .L801038AC:
    /* 10AC 801038AC 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 10B0 801038B0 20005124 */  addiu      $s1, $v0, %lo(vs_main_settings)
    /* 10B4 801038B4 03000224 */  addiu      $v0, $zero, 0x3
    /* 10B8 801038B8 00004392 */  lbu        $v1, 0x0($s2)
    /* 10BC 801038BC 01003092 */  lbu        $s0, 0x1($s1)
    /* 10C0 801038C0 02006210 */  beq        $v1, $v0, .L801038CC
    /* 10C4 801038C4 01000224 */   addiu     $v0, $zero, 0x1
    /* 10C8 801038C8 010022A2 */  sb         $v0, 0x1($s1)
  .L801038CC:
    /* 10CC 801038CC 09000424 */  addiu      $a0, $zero, 0x9
    /* 10D0 801038D0 45010524 */  addiu      $a1, $zero, 0x145
    /* 10D4 801038D4 1000A627 */  addiu      $a2, $sp, 0x10
    /* 10D8 801038D8 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 10DC 801038DC 5800A727 */   addiu     $a3, $sp, 0x58
    /* 10E0 801038E0 05000224 */  addiu      $v0, $zero, 0x5
    /* 10E4 801038E4 010030A2 */  sb         $s0, 0x1($s1)
    /* 10E8 801038E8 5B0F0408 */  j          .L80103D6C
    /* 10EC 801038EC 000042A2 */   sb        $v0, 0x0($s2)
    /* 10F0 801038F0 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 10F4 801038F4 00000000 */   nop
    /* 10F8 801038F8 21884000 */  addu       $s1, $v0, $zero
    /* 10FC 801038FC 01003026 */  addiu      $s0, $s1, 0x1
    /* 1100 80103900 52000012 */  beqz       $s0, .L80103A4C
    /* 1104 80103904 0680023C */   lui       $v0, %hi(vs_main_stateFlags + 0x11D)
    /* 1108 80103908 4400001A */  blez       $s0, .L80103A1C
    /* 110C 8010390C 0F80023C */   lui       $v0, %hi(D_800F4EE8 + 0x8A)
    /* 1110 80103910 724F4490 */  lbu        $a0, %lo(D_800F4EE8 + 0x8A)($v0)
    /* 1114 80103914 4BEA030C */  jal        func_800FA92C
    /* 1118 80103918 01000524 */   addiu     $a1, $zero, 0x1
    /* 111C 8010391C 0900222E */  sltiu      $v0, $s1, 0x9
    /* 1120 80103920 12014010 */  beqz       $v0, .L80103D6C
    /* 1124 80103924 1080023C */   lui       $v0, %hi(jtbl_80102838)
    /* 1128 80103928 38284224 */  addiu      $v0, $v0, %lo(jtbl_80102838)
    /* 112C 8010392C 80181100 */  sll        $v1, $s1, 2
    /* 1130 80103930 21186200 */  addu       $v1, $v1, $v0
    /* 1134 80103934 0000628C */  lw         $v0, 0x0($v1)
    /* 1138 80103938 00000000 */  nop
    /* 113C 8010393C 08004000 */  jr         $v0
    /* 1140 80103940 00000000 */   nop
    /* 1144 80103944 06000224 */  addiu      $v0, $zero, 0x6
    /* 1148 80103948 000042A2 */  sb         $v0, 0x0($s2)
    /* 114C 8010394C 220A040C */  jal        _simpleMapOptionMenu
    /* 1150 80103950 01000424 */   addiu     $a0, $zero, 0x1
    /* 1154 80103954 5C0F0408 */  j          .L80103D70
    /* 1158 80103958 21100000 */   addu      $v0, $zero, $zero
    /* 115C 8010395C 07000224 */  addiu      $v0, $zero, 0x7
    /* 1160 80103960 000042A2 */  sb         $v0, 0x0($s2)
    /* 1164 80103964 970A040C */  jal        _abilityTimingOptionMenu
    /* 1168 80103968 01000424 */   addiu     $a0, $zero, 0x1
    /* 116C 8010396C 5C0F0408 */  j          .L80103D70
    /* 1170 80103970 21100000 */   addu      $v0, $zero, $zero
    /* 1174 80103974 08000224 */  addiu      $v0, $zero, 0x8
    /* 1178 80103978 000042A2 */  sb         $v0, 0x0($s2)
    /* 117C 8010397C 030B040C */  jal        _weaponStatusOptionMenu
    /* 1180 80103980 01000424 */   addiu     $a0, $zero, 0x1
    /* 1184 80103984 5C0F0408 */  j          .L80103D70
    /* 1188 80103988 21100000 */   addu      $v0, $zero, $zero
    /* 118C 8010398C 09000224 */  addiu      $v0, $zero, 0x9
    /* 1190 80103990 000042A2 */  sb         $v0, 0x0($s2)
    /* 1194 80103994 6F0B040C */  jal        _armorStatusOptionMenu
    /* 1198 80103998 01000424 */   addiu     $a0, $zero, 0x1
    /* 119C 8010399C 5C0F0408 */  j          .L80103D70
    /* 11A0 801039A0 21100000 */   addu      $v0, $zero, $zero
    /* 11A4 801039A4 0A000224 */  addiu      $v0, $zero, 0xA
    /* 11A8 801039A8 000042A2 */  sb         $v0, 0x0($s2)
    /* 11AC 801039AC DA0B040C */  jal        _cursorMemoryOptionMenu
    /* 11B0 801039B0 01000424 */   addiu     $a0, $zero, 0x1
    /* 11B4 801039B4 5C0F0408 */  j          .L80103D70
    /* 11B8 801039B8 21100000 */   addu      $v0, $zero, $zero
    /* 11BC 801039BC 0B000224 */  addiu      $v0, $zero, 0xB
    /* 11C0 801039C0 000042A2 */  sb         $v0, 0x0($s2)
    /* 11C4 801039C4 440C040C */  jal        _informationOptionMenu
    /* 11C8 801039C8 01000424 */   addiu     $a0, $zero, 0x1
    /* 11CC 801039CC 5C0F0408 */  j          .L80103D70
    /* 11D0 801039D0 21100000 */   addu      $v0, $zero, $zero
    /* 11D4 801039D4 0C000224 */  addiu      $v0, $zero, 0xC
    /* 11D8 801039D8 000042A2 */  sb         $v0, 0x0($s2)
    /* 11DC 801039DC AE0C040C */  jal        _puzzleModeOptionMenu
    /* 11E0 801039E0 01000424 */   addiu     $a0, $zero, 0x1
    /* 11E4 801039E4 5C0F0408 */  j          .L80103D70
    /* 11E8 801039E8 21100000 */   addu      $v0, $zero, $zero
    /* 11EC 801039EC 0D000224 */  addiu      $v0, $zero, 0xD
    /* 11F0 801039F0 000042A2 */  sb         $v0, 0x0($s2)
    /* 11F4 801039F4 170D040C */  jal        _soundOptionMenu
    /* 11F8 801039F8 01000424 */   addiu     $a0, $zero, 0x1
    /* 11FC 801039FC 5C0F0408 */  j          .L80103D70
    /* 1200 80103A00 21100000 */   addu      $v0, $zero, $zero
    /* 1204 80103A04 0E000224 */  addiu      $v0, $zero, 0xE
    /* 1208 80103A08 000042A2 */  sb         $v0, 0x0($s2)
    /* 120C 80103A0C 7F0D040C */  jal        _vibrationOptionMenu
    /* 1210 80103A10 01000424 */   addiu     $a0, $zero, 0x1
    /* 1214 80103A14 5C0F0408 */  j          .L80103D70
    /* 1218 80103A18 21100000 */   addu      $v0, $zero, $zero
  .L80103A1C:
    /* 121C 80103A1C FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 1220 80103A20 05000216 */  bne        $s0, $v0, .L80103A38
    /* 1224 80103A24 00000000 */   nop
    /* 1228 80103A28 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 122C 80103A2C 28000424 */   addiu     $a0, $zero, 0x28
    /* 1230 80103A30 3A0F0408 */  j          .L80103CE8
    /* 1234 80103A34 10000224 */   addiu     $v0, $zero, 0x10
  .L80103A38:
    /* 1238 80103A38 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 123C 80103A3C 28000424 */   addiu     $a0, $zero, 0x28
    /* 1240 80103A40 0F000224 */  addiu      $v0, $zero, 0xF
    /* 1244 80103A44 5B0F0408 */  j          .L80103D6C
    /* 1248 80103A48 000042A2 */   sb        $v0, 0x0($s2)
  .L80103A4C:
    /* 124C 80103A4C B5164290 */  lbu        $v0, %lo(vs_main_stateFlags + 0x11D)($v0)
    /* 1250 80103A50 00000000 */  nop
    /* 1254 80103A54 C6004010 */  beqz       $v0, .L80103D70
    /* 1258 80103A58 21100000 */   addu      $v0, $zero, $zero
    /* 125C 80103A5C 2C02040C */  jal        func_801008B0
    /* 1260 80103A60 00000000 */   nop
    /* 1264 80103A64 06000324 */  addiu      $v1, $zero, 0x6
    /* 1268 80103A68 03004314 */  bne        $v0, $v1, .L80103A78
    /* 126C 80103A6C 0680023C */   lui       $v0, %hi(D_80060028)
    /* 1270 80103A70 A20E0408 */  j          .L80103A88
    /* 1274 80103A74 01000424 */   addiu     $a0, $zero, 0x1
  .L80103A78:
    /* 1278 80103A78 28004290 */  lbu        $v0, %lo(D_80060028)($v0)
    /* 127C 80103A7C 00000000 */  nop
    /* 1280 80103A80 07004010 */  beqz       $v0, .L80103AA0
    /* 1284 80103A84 02000424 */   addiu     $a0, $zero, 0x2
  .L80103A88:
    /* 1288 80103A88 8123030C */  jal        func_800C8E04
    /* 128C 80103A8C 00000000 */   nop
    /* 1290 80103A90 0F80033C */  lui        $v1, %hi(D_800F514C)
    /* 1294 80103A94 0B000224 */  addiu      $v0, $zero, 0xB
    /* 1298 80103A98 5B0F0408 */  j          .L80103D6C
    /* 129C 80103A9C 4C5162A4 */   sh        $v0, %lo(D_800F514C)($v1)
  .L80103AA0:
    /* 12A0 80103AA0 0F80023C */  lui        $v0, %hi(D_800F514C)
    /* 12A4 80103AA4 5B0F0408 */  j          .L80103D6C
    /* 12A8 80103AA8 4C5140A4 */   sh        $zero, %lo(D_800F514C)($v0)
    /* 12AC 80103AAC 220A040C */  jal        _simpleMapOptionMenu
    /* 12B0 80103AB0 21200000 */   addu      $a0, $zero, $zero
    /* 12B4 80103AB4 21804000 */  addu       $s0, $v0, $zero
    /* 12B8 80103AB8 AC000012 */  beqz       $s0, .L80103D6C
    /* 12BC 80103ABC FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 12C0 80103AC0 89000212 */  beq        $s0, $v0, .L80103CE8
    /* 12C4 80103AC4 10000224 */   addiu     $v0, $zero, 0x10
    /* 12C8 80103AC8 8E00001A */  blez       $s0, .L80103D04
    /* 12CC 80103ACC 1080023C */   lui       $v0, %hi(_simpleMapValues)
    /* 12D0 80103AD0 645D4224 */  addiu      $v0, $v0, %lo(_simpleMapValues)
    /* 12D4 80103AD4 21100202 */  addu       $v0, $s0, $v0
    /* 12D8 80103AD8 FFFF4390 */  lbu        $v1, -0x1($v0)
    /* 12DC 80103ADC 0680023C */  lui        $v0, %hi(D_80060029)
    /* 12E0 80103AE0 410F0408 */  j          .L80103D04
    /* 12E4 80103AE4 290043A0 */   sb        $v1, %lo(D_80060029)($v0)
    /* 12E8 80103AE8 970A040C */  jal        _abilityTimingOptionMenu
    /* 12EC 80103AEC 21200000 */   addu      $a0, $zero, $zero
    /* 12F0 80103AF0 21804000 */  addu       $s0, $v0, $zero
    /* 12F4 80103AF4 9D000012 */  beqz       $s0, .L80103D6C
    /* 12F8 80103AF8 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 12FC 80103AFC 79000212 */  beq        $s0, $v0, .L80103CE4
    /* 1300 80103B00 00000000 */   nop
    /* 1304 80103B04 7F00001A */  blez       $s0, .L80103D04
    /* 1308 80103B08 0680043C */   lui       $a0, %hi(vs_main_settings)
    /* 130C 80103B0C 2000838C */  lw         $v1, %lo(vs_main_settings)($a0)
    /* 1310 80103B10 DFFF0224 */  addiu      $v0, $zero, -0x21
    /* 1314 80103B14 24186200 */  and        $v1, $v1, $v0
    /* 1318 80103B18 02000224 */  addiu      $v0, $zero, 0x2
    /* 131C 80103B1C 23105000 */  subu       $v0, $v0, $s0
    /* 1320 80103B20 01004230 */  andi       $v0, $v0, 0x1
    /* 1324 80103B24 EC0E0408 */  j          .L80103BB0
    /* 1328 80103B28 40110200 */   sll       $v0, $v0, 5
    /* 132C 80103B2C 030B040C */  jal        _weaponStatusOptionMenu
    /* 1330 80103B30 21200000 */   addu      $a0, $zero, $zero
    /* 1334 80103B34 21804000 */  addu       $s0, $v0, $zero
    /* 1338 80103B38 8C000012 */  beqz       $s0, .L80103D6C
    /* 133C 80103B3C FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 1340 80103B40 68000212 */  beq        $s0, $v0, .L80103CE4
    /* 1344 80103B44 00000000 */   nop
    /* 1348 80103B48 6E00001A */  blez       $s0, .L80103D04
    /* 134C 80103B4C 0680043C */   lui       $a0, %hi(vs_main_settings)
    /* 1350 80103B50 2000838C */  lw         $v1, %lo(vs_main_settings)($a0)
    /* 1354 80103B54 BFFF0224 */  addiu      $v0, $zero, -0x41
    /* 1358 80103B58 24186200 */  and        $v1, $v1, $v0
    /* 135C 80103B5C 02000224 */  addiu      $v0, $zero, 0x2
    /* 1360 80103B60 23105000 */  subu       $v0, $v0, $s0
    /* 1364 80103B64 01004230 */  andi       $v0, $v0, 0x1
    /* 1368 80103B68 EC0E0408 */  j          .L80103BB0
    /* 136C 80103B6C 80110200 */   sll       $v0, $v0, 6
    /* 1370 80103B70 6F0B040C */  jal        _armorStatusOptionMenu
    /* 1374 80103B74 21200000 */   addu      $a0, $zero, $zero
    /* 1378 80103B78 21804000 */  addu       $s0, $v0, $zero
    /* 137C 80103B7C 7B000012 */  beqz       $s0, .L80103D6C
    /* 1380 80103B80 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 1384 80103B84 58000212 */  beq        $s0, $v0, .L80103CE8
    /* 1388 80103B88 10000224 */   addiu     $v0, $zero, 0x10
    /* 138C 80103B8C 5D00001A */  blez       $s0, .L80103D04
    /* 1390 80103B90 0680043C */   lui       $a0, %hi(vs_main_settings)
    /* 1394 80103B94 2000838C */  lw         $v1, %lo(vs_main_settings)($a0)
    /* 1398 80103B98 7FFF0224 */  addiu      $v0, $zero, -0x81
    /* 139C 80103B9C 24186200 */  and        $v1, $v1, $v0
    /* 13A0 80103BA0 02000224 */  addiu      $v0, $zero, 0x2
    /* 13A4 80103BA4 23105000 */  subu       $v0, $v0, $s0
    /* 13A8 80103BA8 01004230 */  andi       $v0, $v0, 0x1
    /* 13AC 80103BAC C0110200 */  sll        $v0, $v0, 7
  .L80103BB0:
    /* 13B0 80103BB0 25186200 */  or         $v1, $v1, $v0
    /* 13B4 80103BB4 410F0408 */  j          .L80103D04
    /* 13B8 80103BB8 200083AC */   sw        $v1, %lo(vs_main_settings)($a0)
    /* 13BC 80103BBC DA0B040C */  jal        _cursorMemoryOptionMenu
    /* 13C0 80103BC0 21200000 */   addu      $a0, $zero, $zero
    /* 13C4 80103BC4 21804000 */  addu       $s0, $v0, $zero
    /* 13C8 80103BC8 68000012 */  beqz       $s0, .L80103D6C
    /* 13CC 80103BCC FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 13D0 80103BD0 45000212 */  beq        $s0, $v0, .L80103CE8
    /* 13D4 80103BD4 10000224 */   addiu     $v0, $zero, 0x10
    /* 13D8 80103BD8 4A00001A */  blez       $s0, .L80103D04
    /* 13DC 80103BDC 0680033C */   lui       $v1, %hi(D_80060021)
    /* 13E0 80103BE0 02000224 */  addiu      $v0, $zero, 0x2
    /* 13E4 80103BE4 23105000 */  subu       $v0, $v0, $s0
    /* 13E8 80103BE8 410F0408 */  j          .L80103D04
    /* 13EC 80103BEC 210062A0 */   sb        $v0, %lo(D_80060021)($v1)
    /* 13F0 80103BF0 440C040C */  jal        _informationOptionMenu
    /* 13F4 80103BF4 21200000 */   addu      $a0, $zero, $zero
    /* 13F8 80103BF8 21804000 */  addu       $s0, $v0, $zero
    /* 13FC 80103BFC 5B000012 */  beqz       $s0, .L80103D6C
    /* 1400 80103C00 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 1404 80103C04 38000212 */  beq        $s0, $v0, .L80103CE8
    /* 1408 80103C08 10000224 */   addiu     $v0, $zero, 0x10
    /* 140C 80103C0C 3D00001A */  blez       $s0, .L80103D04
    /* 1410 80103C10 0680033C */   lui       $v1, %hi(D_80060028)
    /* 1414 80103C14 02000224 */  addiu      $v0, $zero, 0x2
    /* 1418 80103C18 23105000 */  subu       $v0, $v0, $s0
    /* 141C 80103C1C F2FE030C */  jal        func_800FFBC8
    /* 1420 80103C20 280062A0 */   sb        $v0, %lo(D_80060028)($v1)
    /* 1424 80103C24 420F0408 */  j          .L80103D08
    /* 1428 80103C28 04000224 */   addiu     $v0, $zero, 0x4
    /* 142C 80103C2C AE0C040C */  jal        _puzzleModeOptionMenu
    /* 1430 80103C30 21200000 */   addu      $a0, $zero, $zero
    /* 1434 80103C34 21804000 */  addu       $s0, $v0, $zero
    /* 1438 80103C38 4C000012 */  beqz       $s0, .L80103D6C
    /* 143C 80103C3C FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 1440 80103C40 29000212 */  beq        $s0, $v0, .L80103CE8
    /* 1444 80103C44 10000224 */   addiu     $v0, $zero, 0x10
    /* 1448 80103C48 2E00001A */  blez       $s0, .L80103D04
    /* 144C 80103C4C 0680043C */   lui       $a0, %hi(vs_main_settings)
    /* 1450 80103C50 2000838C */  lw         $v1, %lo(vs_main_settings)($a0)
    /* 1454 80103C54 F7FF0224 */  addiu      $v0, $zero, -0x9
    /* 1458 80103C58 24186200 */  and        $v1, $v1, $v0
    /* 145C 80103C5C FFFF0226 */  addiu      $v0, $s0, -0x1
    /* 1460 80103C60 01004230 */  andi       $v0, $v0, 0x1
    /* 1464 80103C64 C0100200 */  sll        $v0, $v0, 3
    /* 1468 80103C68 25186200 */  or         $v1, $v1, $v0
    /* 146C 80103C6C 0680023C */  lui        $v0, %hi(vs_main_stateFlags + 0x11C)
    /* 1470 80103C70 200083AC */  sw         $v1, %lo(vs_main_settings)($a0)
    /* 1474 80103C74 C2180300 */  srl        $v1, $v1, 3
    /* 1478 80103C78 27180300 */  nor        $v1, $zero, $v1
    /* 147C 80103C7C 01006330 */  andi       $v1, $v1, 0x1
    /* 1480 80103C80 410F0408 */  j          .L80103D04
    /* 1484 80103C84 B41643A0 */   sb        $v1, %lo(vs_main_stateFlags + 0x11C)($v0)
    /* 1488 80103C88 170D040C */  jal        _soundOptionMenu
    /* 148C 80103C8C 21200000 */   addu      $a0, $zero, $zero
    /* 1490 80103C90 21804000 */  addu       $s0, $v0, $zero
    /* 1494 80103C94 35000012 */  beqz       $s0, .L80103D6C
    /* 1498 80103C98 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 149C 80103C9C 12000212 */  beq        $s0, $v0, .L80103CE8
    /* 14A0 80103CA0 10000224 */   addiu     $v0, $zero, 0x10
    /* 14A4 80103CA4 1700001A */  blez       $s0, .L80103D04
    /* 14A8 80103CA8 0680023C */   lui       $v0, %hi(vs_main_settings)
    /* 14AC 80103CAC 20004224 */  addiu      $v0, $v0, %lo(vs_main_settings)
    /* 14B0 80103CB0 FFFF0326 */  addiu      $v1, $s0, -0x1
    /* 14B4 80103CB4 0A0043A0 */  sb         $v1, 0xA($v0)
    /* 14B8 80103CB8 2F1A010C */  jal        vs_main_setMonoSound
    /* 14BC 80103CBC FF006430 */   andi      $a0, $v1, 0xFF
    /* 14C0 80103CC0 420F0408 */  j          .L80103D08
    /* 14C4 80103CC4 04000224 */   addiu     $v0, $zero, 0x4
    /* 14C8 80103CC8 7F0D040C */  jal        _vibrationOptionMenu
    /* 14CC 80103CCC 21200000 */   addu      $a0, $zero, $zero
    /* 14D0 80103CD0 21804000 */  addu       $s0, $v0, $zero
    /* 14D4 80103CD4 25000012 */  beqz       $s0, .L80103D6C
    /* 14D8 80103CD8 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 14DC 80103CDC 04000216 */  bne        $s0, $v0, .L80103CF0
    /* 14E0 80103CE0 00000000 */   nop
  .L80103CE4:
    /* 14E4 80103CE4 10000224 */  addiu      $v0, $zero, 0x10
  .L80103CE8:
    /* 14E8 80103CE8 5B0F0408 */  j          .L80103D6C
    /* 14EC 80103CEC 000042A2 */   sb        $v0, 0x0($s2)
  .L80103CF0:
    /* 14F0 80103CF0 0400001A */  blez       $s0, .L80103D04
    /* 14F4 80103CF4 0680033C */   lui       $v1, %hi(D_8006002B)
    /* 14F8 80103CF8 02000224 */  addiu      $v0, $zero, 0x2
    /* 14FC 80103CFC 23105000 */  subu       $v0, $v0, $s0
    /* 1500 80103D00 2B0062A0 */  sb         $v0, %lo(D_8006002B)($v1)
  .L80103D04:
    /* 1504 80103D04 04000224 */  addiu      $v0, $zero, 0x4
  .L80103D08:
    /* 1508 80103D08 5B0F0408 */  j          .L80103D6C
    /* 150C 80103D0C 000042A2 */   sb        $v0, 0x0($s2)
    /* 1510 80103D10 EAFE030C */  jal        func_800FFBA8
    /* 1514 80103D14 00000000 */   nop
    /* 1518 80103D18 A2FE030C */  jal        func_800FFA88
    /* 151C 80103D1C 21200000 */   addu      $a0, $zero, $zero
    /* 1520 80103D20 74EA030C */  jal        vs_mainmenu_ready
    /* 1524 80103D24 00000000 */   nop
    /* 1528 80103D28 10004010 */  beqz       $v0, .L80103D6C
    /* 152C 80103D2C 01000224 */   addiu     $v0, $zero, 0x1
    /* 1530 80103D30 5C0F0408 */  j          .L80103D70
    /* 1534 80103D34 000040A2 */   sb        $zero, 0x0($s2)
    /* 1538 80103D38 EAFE030C */  jal        func_800FFBA8
    /* 153C 80103D3C 00000000 */   nop
    /* 1540 80103D40 A2FE030C */  jal        func_800FFA88
    /* 1544 80103D44 21200000 */   addu      $a0, $zero, $zero
    /* 1548 80103D48 74EA030C */  jal        vs_mainmenu_ready
    /* 154C 80103D4C 00000000 */   nop
    /* 1550 80103D50 06004010 */  beqz       $v0, .L80103D6C
    /* 1554 80103D54 01000224 */   addiu     $v0, $zero, 0x1
    /* 1558 80103D58 0F80043C */  lui        $a0, %hi(vs_battle_menuState)
    /* 155C 80103D5C 08000324 */  addiu      $v1, $zero, 0x8
    /* 1560 80103D60 C05183A0 */  sb         $v1, %lo(vs_battle_menuState)($a0)
    /* 1564 80103D64 5C0F0408 */  j          .L80103D70
    /* 1568 80103D68 000040A2 */   sb        $zero, 0x0($s2)
  .L80103D6C:
    /* 156C 80103D6C 21100000 */  addu       $v0, $zero, $zero
  .L80103D70:
    /* 1570 80103D70 8C00BF8F */  lw         $ra, 0x8C($sp)
    /* 1574 80103D74 8800B28F */  lw         $s2, 0x88($sp)
    /* 1578 80103D78 8400B18F */  lw         $s1, 0x84($sp)
    /* 157C 80103D7C 8000B08F */  lw         $s0, 0x80($sp)
    /* 1580 80103D80 0800E003 */  jr         $ra
    /* 1584 80103D84 9000BD27 */   addiu     $sp, $sp, 0x90
endlabel vs_menu8_exec
