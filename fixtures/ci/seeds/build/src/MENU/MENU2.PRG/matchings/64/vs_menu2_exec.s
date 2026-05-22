nonmatching vs_menu2_exec, 0x368

glabel vs_menu2_exec
    /* 10D4 801038D4 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 10D8 801038D8 3800B2AF */  sw         $s2, 0x38($sp)
    /* 10DC 801038DC 21908000 */  addu       $s2, $a0, $zero
    /* 10E0 801038E0 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 10E4 801038E4 3400B1AF */  sw         $s1, 0x34($sp)
    /* 10E8 801038E8 3000B0AF */  sw         $s0, 0x30($sp)
    /* 10EC 801038EC 00004292 */  lbu        $v0, 0x0($s2)
    /* 10F0 801038F0 00000000 */  nop
    /* 10F4 801038F4 FDFF4324 */  addiu      $v1, $v0, -0x3
    /* 10F8 801038F8 0700622C */  sltiu      $v0, $v1, 0x7
    /* 10FC 801038FC AC004010 */  beqz       $v0, .L80103BB0
    /* 1100 80103900 1080023C */   lui       $v0, %hi(jtbl_80102810)
    /* 1104 80103904 10284224 */  addiu      $v0, $v0, %lo(jtbl_80102810)
    /* 1108 80103908 80180300 */  sll        $v1, $v1, 2
    /* 110C 8010390C 21186200 */  addu       $v1, $v1, $v0
    /* 1110 80103910 0000628C */  lw         $v0, 0x0($v1)
    /* 1114 80103914 00000000 */  nop
    /* 1118 80103918 08004000 */  jr         $v0
    /* 111C 8010391C 00000000 */   nop
    /* 1120 80103920 1080023C */  lui        $v0, %hi(menuAnimating)
    /* 1124 80103924 1080033C */  lui        $v1, %hi(pointsAnimStep)
    /* 1128 80103928 C05040A0 */  sb         $zero, %lo(menuAnimating)($v0)
    /* 112C 8010392C 0A000224 */  addiu      $v0, $zero, 0xA
    /* 1130 80103930 74EA030C */  jal        vs_mainmenu_ready
    /* 1134 80103934 C15062A0 */   sb        $v0, %lo(pointsAnimStep)($v1)
    /* 1138 80103938 9E004010 */  beqz       $v0, .L80103BB4
    /* 113C 8010393C 1080023C */   lui       $v0, %hi(menuAnimating)
    /* 1140 80103940 F2FE030C */  jal        func_800FFBC8
    /* 1144 80103944 00000000 */   nop
    /* 1148 80103948 0F80033C */  lui        $v1, %hi(vs_battle_shortcutInvoked)
    /* 114C 8010394C 6A4E6290 */  lbu        $v0, %lo(vs_battle_shortcutInvoked)($v1)
    /* 1150 80103950 00000000 */  nop
    /* 1154 80103954 18004010 */  beqz       $v0, .L801039B8
    /* 1158 80103958 40010524 */   addiu     $a1, $zero, 0x140
    /* 115C 8010395C 22000624 */  addiu      $a2, $zero, 0x22
    /* 1160 80103960 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 1164 80103964 21204000 */  addu       $a0, $v0, $zero
    /* 1168 80103968 08000224 */  addiu      $v0, $zero, 0x8
    /* 116C 8010396C F9FF9024 */  addiu      $s0, $a0, -0x7
    /* 1170 80103970 1080033C */  lui        $v1, %hi(_battleAbilityStrings)
    /* 1174 80103974 90466324 */  addiu      $v1, $v1, %lo(_battleAbilityStrings)
    /* 1178 80103978 1000A2AF */  sw         $v0, 0x10($sp)
    /* 117C 8010397C 40101000 */  sll        $v0, $s0, 1
    /* 1180 80103980 21105000 */  addu       $v0, $v0, $s0
    /* 1184 80103984 40100200 */  sll        $v0, $v0, 1
    /* 1188 80103988 21104300 */  addu       $v0, $v0, $v1
    /* 118C 8010398C 00004294 */  lhu        $v0, 0x0($v0)
    /* 1190 80103990 03008424 */  addiu      $a0, $a0, 0x3
    /* 1194 80103994 40100200 */  sll        $v0, $v0, 1
    /* 1198 80103998 21104300 */  addu       $v0, $v0, $v1
    /* 119C 8010399C 9723030C */  jal        vs_battle_setMenuItem
    /* 11A0 801039A0 1400A2AF */   sw        $v0, 0x14($sp)
    /* 11A4 801039A4 01000324 */  addiu      $v1, $zero, 0x1
    /* 11A8 801039A8 3C000012 */  beqz       $s0, .L80103A9C
    /* 11AC 801039AC 060043A0 */   sb        $v1, 0x6($v0)
    /* 11B0 801039B0 B00E0408 */  j          .L80103AC0
    /* 11B4 801039B4 07000224 */   addiu     $v0, $zero, 0x7
  .L801039B8:
    /* 11B8 801039B8 74EA030C */  jal        vs_mainmenu_ready
    /* 11BC 801039BC 00000000 */   nop
    /* 11C0 801039C0 7B004010 */  beqz       $v0, .L80103BB0
    /* 11C4 801039C4 21200000 */   addu      $a0, $zero, $zero
    /* 11C8 801039C8 1080023C */  lui        $v0, %hi(D_801046D4)
    /* 11CC 801039CC D4465024 */  addiu      $s0, $v0, %lo(D_801046D4)
    /* 11D0 801039D0 10000226 */  addiu      $v0, $s0, 0x10
    /* 11D4 801039D4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 11D8 801039D8 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 11DC 801039DC 2800A0AF */  sw         $zero, 0x28($sp)
    /* 11E0 801039E0 ED2B030C */  jal        vs_battle_chainAbilitiesUnlocked
    /* 11E4 801039E4 2C00A0AF */   sw        $zero, 0x2C($sp)
    /* 11E8 801039E8 06004014 */  bnez       $v0, .L80103A04
    /* 11EC 801039EC 01000424 */   addiu     $a0, $zero, 0x1
    /* 11F0 801039F0 1800A28F */  lw         $v0, 0x18($sp)
    /* 11F4 801039F4 6A000326 */  addiu      $v1, $s0, 0x6A
    /* 11F8 801039F8 1C00A3AF */  sw         $v1, 0x1C($sp)
    /* 11FC 801039FC 01004234 */  ori        $v0, $v0, 0x1
    /* 1200 80103A00 1800A2AF */  sw         $v0, 0x18($sp)
  .L80103A04:
    /* 1204 80103A04 9A000226 */  addiu      $v0, $s0, 0x9A
    /* 1208 80103A08 2000A2AF */  sw         $v0, 0x20($sp)
    /* 120C 80103A0C AC000226 */  addiu      $v0, $s0, 0xAC
    /* 1210 80103A10 ED2B030C */  jal        vs_battle_chainAbilitiesUnlocked
    /* 1214 80103A14 2400A2AF */   sw        $v0, 0x24($sp)
    /* 1218 80103A18 07004014 */  bnez       $v0, .L80103A38
    /* 121C 80103A1C 0680023C */   lui       $v0, %hi(vs_main_settings)
    /* 1220 80103A20 2C00A28F */  lw         $v0, 0x2C($sp)
    /* 1224 80103A24 08010326 */  addiu      $v1, $s0, 0x108
    /* 1228 80103A28 2400A3AF */  sw         $v1, 0x24($sp)
    /* 122C 80103A2C 01004234 */  ori        $v0, $v0, 0x1
    /* 1230 80103A30 2C00A2AF */  sw         $v0, 0x2C($sp)
    /* 1234 80103A34 0680023C */  lui        $v0, %hi(vs_main_settings)
  .L80103A38:
    /* 1238 80103A38 20005124 */  addiu      $s1, $v0, %lo(vs_main_settings)
    /* 123C 80103A3C 03000224 */  addiu      $v0, $zero, 0x3
    /* 1240 80103A40 00004392 */  lbu        $v1, 0x0($s2)
    /* 1244 80103A44 01003092 */  lbu        $s0, 0x1($s1)
    /* 1248 80103A48 02006210 */  beq        $v1, $v0, .L80103A54
    /* 124C 80103A4C 01000224 */   addiu     $v0, $zero, 0x1
    /* 1250 80103A50 010022A2 */  sb         $v0, 0x1($s1)
  .L80103A54:
    /* 1254 80103A54 02000424 */  addiu      $a0, $zero, 0x2
    /* 1258 80103A58 17010524 */  addiu      $a1, $zero, 0x117
    /* 125C 80103A5C 1800A627 */  addiu      $a2, $sp, 0x18
    /* 1260 80103A60 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 1264 80103A64 2800A727 */   addiu     $a3, $sp, 0x28
    /* 1268 80103A68 05000224 */  addiu      $v0, $zero, 0x5
    /* 126C 80103A6C 010030A2 */  sb         $s0, 0x1($s1)
    /* 1270 80103A70 EC0E0408 */  j          .L80103BB0
    /* 1274 80103A74 000042A2 */   sb        $v0, 0x0($s2)
    /* 1278 80103A78 1080113C */  lui        $s1, %hi(menuAnimating)
    /* 127C 80103A7C 01000224 */  addiu      $v0, $zero, 0x1
    /* 1280 80103A80 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 1284 80103A84 C05022A2 */   sb        $v0, %lo(menuAnimating)($s1)
    /* 1288 80103A88 01005024 */  addiu      $s0, $v0, 0x1
    /* 128C 80103A8C 48000012 */  beqz       $s0, .L80103BB0
    /* 1290 80103A90 01000224 */   addiu     $v0, $zero, 0x1
    /* 1294 80103A94 07000216 */  bne        $s0, $v0, .L80103AB4
    /* 1298 80103A98 C05020A2 */   sb        $zero, %lo(menuAnimating)($s1)
  .L80103A9C:
    /* 129C 80103A9C 06000224 */  addiu      $v0, $zero, 0x6
    /* 12A0 80103AA0 000042A2 */  sb         $v0, 0x0($s2)
    /* 12A4 80103AA4 3F0D040C */  jal        _chainAbilityMenu
    /* 12A8 80103AA8 01000424 */   addiu     $a0, $zero, 0x1
    /* 12AC 80103AAC ED0E0408 */  j          .L80103BB4
    /* 12B0 80103AB0 1080023C */   lui       $v0, %hi(menuAnimating)
  .L80103AB4:
    /* 12B4 80103AB4 02000224 */  addiu      $v0, $zero, 0x2
    /* 12B8 80103AB8 06000216 */  bne        $s0, $v0, .L80103AD4
    /* 12BC 80103ABC 07000224 */   addiu     $v0, $zero, 0x7
  .L80103AC0:
    /* 12C0 80103AC0 000042A2 */  sb         $v0, 0x0($s2)
    /* 12C4 80103AC4 9C0D040C */  jal        _defenseAbilityMenu
    /* 12C8 80103AC8 01000424 */   addiu     $a0, $zero, 0x1
    /* 12CC 80103ACC ED0E0408 */  j          .L80103BB4
    /* 12D0 80103AD0 1080023C */   lui       $v0, %hi(menuAnimating)
  .L80103AD4:
    /* 12D4 80103AD4 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 12D8 80103AD8 28000424 */   addiu     $a0, $zero, 0x28
    /* 12DC 80103ADC FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 12E0 80103AE0 17000212 */  beq        $s0, $v0, .L80103B40
    /* 12E4 80103AE4 08000224 */   addiu     $v0, $zero, 0x8
    /* 12E8 80103AE8 EC0E0408 */  j          .L80103BB0
    /* 12EC 80103AEC 000042A2 */   sb        $v0, 0x0($s2)
    /* 12F0 80103AF0 3F0D040C */  jal        _chainAbilityMenu
    /* 12F4 80103AF4 21200000 */   addu      $a0, $zero, $zero
    /* 12F8 80103AF8 2D004010 */  beqz       $v0, .L80103BB0
    /* 12FC 80103AFC 0F80023C */   lui       $v0, %hi(vs_battle_shortcutInvoked)
    /* 1300 80103B00 6A4E4290 */  lbu        $v0, %lo(vs_battle_shortcutInvoked)($v0)
    /* 1304 80103B04 00000000 */  nop
    /* 1308 80103B08 0B004014 */  bnez       $v0, .L80103B38
    /* 130C 80103B0C 04000224 */   addiu     $v0, $zero, 0x4
    /* 1310 80103B10 EC0E0408 */  j          .L80103BB0
    /* 1314 80103B14 000042A2 */   sb        $v0, 0x0($s2)
    /* 1318 80103B18 9C0D040C */  jal        _defenseAbilityMenu
    /* 131C 80103B1C 21200000 */   addu      $a0, $zero, $zero
    /* 1320 80103B20 23004010 */  beqz       $v0, .L80103BB0
    /* 1324 80103B24 0F80023C */   lui       $v0, %hi(vs_battle_shortcutInvoked)
    /* 1328 80103B28 6A4E4290 */  lbu        $v0, %lo(vs_battle_shortcutInvoked)($v0)
    /* 132C 80103B2C 00000000 */  nop
    /* 1330 80103B30 06004010 */  beqz       $v0, .L80103B4C
    /* 1334 80103B34 04000224 */   addiu     $v0, $zero, 0x4
  .L80103B38:
    /* 1338 80103B38 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 133C 80103B3C 28000424 */   addiu     $a0, $zero, 0x28
  .L80103B40:
    /* 1340 80103B40 09000224 */  addiu      $v0, $zero, 0x9
    /* 1344 80103B44 EC0E0408 */  j          .L80103BB0
    /* 1348 80103B48 000042A2 */   sb        $v0, 0x0($s2)
  .L80103B4C:
    /* 134C 80103B4C EC0E0408 */  j          .L80103BB0
    /* 1350 80103B50 000042A2 */   sb        $v0, 0x0($s2)
    /* 1354 80103B54 EAFE030C */  jal        func_800FFBA8
    /* 1358 80103B58 00000000 */   nop
    /* 135C 80103B5C A2FE030C */  jal        func_800FFA88
    /* 1360 80103B60 21200000 */   addu      $a0, $zero, $zero
    /* 1364 80103B64 74EA030C */  jal        vs_mainmenu_ready
    /* 1368 80103B68 00000000 */   nop
    /* 136C 80103B6C 10004010 */  beqz       $v0, .L80103BB0
    /* 1370 80103B70 01000224 */   addiu     $v0, $zero, 0x1
    /* 1374 80103B74 090F0408 */  j          .L80103C24
    /* 1378 80103B78 000040A2 */   sb        $zero, 0x0($s2)
    /* 137C 80103B7C EAFE030C */  jal        func_800FFBA8
    /* 1380 80103B80 00000000 */   nop
    /* 1384 80103B84 A2FE030C */  jal        func_800FFA88
    /* 1388 80103B88 21200000 */   addu      $a0, $zero, $zero
    /* 138C 80103B8C 74EA030C */  jal        vs_mainmenu_ready
    /* 1390 80103B90 00000000 */   nop
    /* 1394 80103B94 06004010 */  beqz       $v0, .L80103BB0
    /* 1398 80103B98 01000224 */   addiu     $v0, $zero, 0x1
    /* 139C 80103B9C 0F80043C */  lui        $a0, %hi(vs_battle_menuState)
    /* 13A0 80103BA0 03000324 */  addiu      $v1, $zero, 0x3
    /* 13A4 80103BA4 C05183A0 */  sb         $v1, %lo(vs_battle_menuState)($a0)
    /* 13A8 80103BA8 090F0408 */  j          .L80103C24
    /* 13AC 80103BAC 000040A2 */   sb        $zero, 0x0($s2)
  .L80103BB0:
    /* 13B0 80103BB0 1080023C */  lui        $v0, %hi(menuAnimating)
  .L80103BB4:
    /* 13B4 80103BB4 C0504290 */  lbu        $v0, %lo(menuAnimating)($v0)
    /* 13B8 80103BB8 00000000 */  nop
    /* 13BC 80103BBC 0E004010 */  beqz       $v0, .L80103BF8
    /* 13C0 80103BC0 0F80033C */   lui       $v1, %hi(vs_battle_rowAnimationSteps)
    /* 13C4 80103BC4 1080103C */  lui        $s0, %hi(pointsAnimStep)
    /* 13C8 80103BC8 C1500292 */  lbu        $v0, %lo(pointsAnimStep)($s0)
    /* 13CC 80103BCC C8BB6324 */  addiu      $v1, $v1, %lo(vs_battle_rowAnimationSteps)
    /* 13D0 80103BD0 21104300 */  addu       $v0, $v0, $v1
    /* 13D4 80103BD4 00004490 */  lbu        $a0, 0x0($v0)
    /* 13D8 80103BD8 F90D040C */  jal        _drawPointsRemaining
    /* 13DC 80103BDC 00000000 */   nop
    /* 13E0 80103BE0 C1500292 */  lbu        $v0, %lo(pointsAnimStep)($s0)
    /* 13E4 80103BE4 00000000 */  nop
    /* 13E8 80103BE8 0D004010 */  beqz       $v0, .L80103C20
    /* 13EC 80103BEC FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 13F0 80103BF0 080F0408 */  j          .L80103C20
    /* 13F4 80103BF4 C15002A2 */   sb        $v0, %lo(pointsAnimStep)($s0)
  .L80103BF8:
    /* 13F8 80103BF8 1080043C */  lui        $a0, %hi(pointsAnimStep)
    /* 13FC 80103BFC C1508390 */  lbu        $v1, %lo(pointsAnimStep)($a0)
    /* 1400 80103C00 00000000 */  nop
    /* 1404 80103C04 0A00622C */  sltiu      $v0, $v1, 0xA
    /* 1408 80103C08 05004010 */  beqz       $v0, .L80103C20
    /* 140C 80103C0C 01006224 */   addiu     $v0, $v1, 0x1
    /* 1410 80103C10 C15082A0 */  sb         $v0, %lo(pointsAnimStep)($a0)
    /* 1414 80103C14 FF004430 */  andi       $a0, $v0, 0xFF
    /* 1418 80103C18 F90D040C */  jal        _drawPointsRemaining
    /* 141C 80103C1C 40210400 */   sll       $a0, $a0, 5
  .L80103C20:
    /* 1420 80103C20 21100000 */  addu       $v0, $zero, $zero
  .L80103C24:
    /* 1424 80103C24 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 1428 80103C28 3800B28F */  lw         $s2, 0x38($sp)
    /* 142C 80103C2C 3400B18F */  lw         $s1, 0x34($sp)
    /* 1430 80103C30 3000B08F */  lw         $s0, 0x30($sp)
    /* 1434 80103C34 0800E003 */  jr         $ra
    /* 1438 80103C38 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel vs_menu2_exec
