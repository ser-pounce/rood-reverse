nonmatching _gemDetailsPage, 0x1EC

glabel _gemDetailsPage
    /* 11BC 801039BC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 11C0 801039C0 21288000 */  addu       $a1, $a0, $zero
    /* 11C4 801039C4 2800BFAF */  sw         $ra, 0x28($sp)
    /* 11C8 801039C8 2400B1AF */  sw         $s1, 0x24($sp)
    /* 11CC 801039CC 1000A010 */  beqz       $a1, .L80103A10
    /* 11D0 801039D0 2000B0AF */   sw        $s0, 0x20($sp)
    /* 11D4 801039D4 1180033C */  lui        $v1, %hi(D_8010A605)
    /* 11D8 801039D8 03120500 */  sra        $v0, $a1, 8
    /* 11DC 801039DC 05A662A0 */  sb         $v0, %lo(D_8010A605)($v1)
    /* 11E0 801039E0 FF004430 */  andi       $a0, $v0, 0xFF
    /* 11E4 801039E4 1180033C */  lui        $v1, %hi(D_8010A606)
    /* 11E8 801039E8 FFFFA224 */  addiu      $v0, $a1, -0x1
    /* 11EC 801039EC 140B040C */  jal        func_80102C50
    /* 11F0 801039F0 06A662A0 */   sb        $v0, %lo(D_8010A606)($v1)
    /* 11F4 801039F4 21100000 */  addu       $v0, $zero, $zero
    /* 11F8 801039F8 1180043C */  lui        $a0, %hi(D_8010A604)
    /* 11FC 801039FC 0A000324 */  addiu      $v1, $zero, 0xA
    /* 1200 80103A00 04A683A0 */  sb         $v1, %lo(D_8010A604)($a0)
    /* 1204 80103A04 1180033C */  lui        $v1, %hi(D_8010A603)
    /* 1208 80103A08 E50E0408 */  j          .L80103B94
    /* 120C 80103A0C 03A660A0 */   sb        $zero, %lo(D_8010A603)($v1)
  .L80103A10:
    /* 1210 80103A10 1180113C */  lui        $s1, %hi(D_8010A603)
    /* 1214 80103A14 03A62392 */  lbu        $v1, %lo(D_8010A603)($s1)
    /* 1218 80103A18 01001024 */  addiu      $s0, $zero, 0x1
    /* 121C 80103A1C 1E007010 */  beq        $v1, $s0, .L80103A98
    /* 1220 80103A20 02006228 */   slti      $v0, $v1, 0x2
    /* 1224 80103A24 05004010 */  beqz       $v0, .L80103A3C
    /* 1228 80103A28 02000224 */   addiu     $v0, $zero, 0x2
    /* 122C 80103A2C 09006010 */  beqz       $v1, .L80103A54
    /* 1230 80103A30 21100000 */   addu      $v0, $zero, $zero
    /* 1234 80103A34 E50E0408 */  j          .L80103B94
    /* 1238 80103A38 00000000 */   nop
  .L80103A3C:
    /* 123C 80103A3C 20006210 */  beq        $v1, $v0, .L80103AC0
    /* 1240 80103A40 03000224 */   addiu     $v0, $zero, 0x3
    /* 1244 80103A44 4E006210 */  beq        $v1, $v0, .L80103B80
    /* 1248 80103A48 21100000 */   addu      $v0, $zero, $zero
    /* 124C 80103A4C E50E0408 */  j          .L80103B94
    /* 1250 80103A50 00000000 */   nop
  .L80103A54:
    /* 1254 80103A54 74EA030C */  jal        vs_mainmenu_ready
    /* 1258 80103A58 00000000 */   nop
    /* 125C 80103A5C 4C004010 */  beqz       $v0, .L80103B90
    /* 1260 80103A60 1180023C */   lui       $v0, %hi(D_8010A605)
    /* 1264 80103A64 05A64490 */  lbu        $a0, %lo(D_8010A605)($v0)
    /* 1268 80103A68 470B040C */  jal        _initMenuLayout
    /* 126C 80103A6C 03000524 */   addiu     $a1, $zero, 0x3
    /* 1270 80103A70 0680033C */  lui        $v1, %hi(vs_main_inventoryIndices)
    /* 1274 80103A74 1180023C */  lui        $v0, %hi(D_8010A606)
    /* 1278 80103A78 06A64290 */  lbu        $v0, %lo(D_8010A606)($v0)
    /* 127C 80103A7C D8196324 */  addiu      $v1, $v1, %lo(vs_main_inventoryIndices)
    /* 1280 80103A80 21104300 */  addu       $v0, $v0, $v1
    /* 1284 80103A84 40004490 */  lbu        $a0, 0x40($v0)
    /* 1288 80103A88 1EF6030C */  jal        vs_mainMenu_setGemStats
    /* 128C 80103A8C 00000000 */   nop
    /* 1290 80103A90 E40E0408 */  j          .L80103B90
    /* 1294 80103A94 03A630A2 */   sb        $s0, %lo(D_8010A603)($s1)
  .L80103A98:
    /* 1298 80103A98 1180033C */  lui        $v1, %hi(D_8010A604)
    /* 129C 80103A9C 04A66290 */  lbu        $v0, %lo(D_8010A604)($v1)
    /* 12A0 80103AA0 00000000 */  nop
    /* 12A4 80103AA4 03004010 */  beqz       $v0, .L80103AB4
    /* 12A8 80103AA8 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 12AC 80103AAC E40E0408 */  j          .L80103B90
    /* 12B0 80103AB0 04A662A0 */   sb        $v0, %lo(D_8010A604)($v1)
  .L80103AB4:
    /* 12B4 80103AB4 02000224 */  addiu      $v0, $zero, 0x2
    /* 12B8 80103AB8 E40E0408 */  j          .L80103B90
    /* 12BC 80103ABC 03A622A2 */   sb        $v0, %lo(D_8010A603)($s1)
  .L80103AC0:
    /* 12C0 80103AC0 0680103C */  lui        $s0, %hi(vs_main_buttonsPressed)
    /* 12C4 80103AC4 D0E1028E */  lw         $v0, %lo(vs_main_buttonsPressed)($s0)
    /* 12C8 80103AC8 00000000 */  nop
    /* 12CC 80103ACC 50004230 */  andi       $v0, $v0, 0x50
    /* 12D0 80103AD0 0A004010 */  beqz       $v0, .L80103AFC
    /* 12D4 80103AD4 00000000 */   nop
    /* 12D8 80103AD8 950B040C */  jal        _initMenuLeave
    /* 12DC 80103ADC 21200000 */   addu      $a0, $zero, $zero
    /* 12E0 80103AE0 03000224 */  addiu      $v0, $zero, 0x3
    /* 12E4 80103AE4 03A622A2 */  sb         $v0, %lo(D_8010A603)($s1)
    /* 12E8 80103AE8 D0E1028E */  lw         $v0, %lo(vs_main_buttonsPressed)($s0)
    /* 12EC 80103AEC 1180033C */  lui        $v1, %hi(_exitToBattle)
    /* 12F0 80103AF0 10004230 */  andi       $v0, $v0, 0x10
    /* 12F4 80103AF4 E40E0408 */  j          .L80103B90
    /* 12F8 80103AF8 C0A662AC */   sw        $v0, %lo(_exitToBattle)($v1)
  .L80103AFC:
    /* 12FC 80103AFC 1180103C */  lui        $s0, %hi(D_8010A606)
    /* 1300 80103B00 06A60592 */  lbu        $a1, %lo(D_8010A606)($s0)
    /* 1304 80103B04 980A040C */  jal        _handleItemPaging
    /* 1308 80103B08 05000424 */   addiu     $a0, $zero, 0x5
    /* 130C 80103B0C 06A60392 */  lbu        $v1, %lo(D_8010A606)($s0)
    /* 1310 80103B10 21884000 */  addu       $s1, $v0, $zero
    /* 1314 80103B14 1E002312 */  beq        $s1, $v1, .L80103B90
    /* 1318 80103B18 05000424 */   addiu     $a0, $zero, 0x5
    /* 131C 80103B1C 21282002 */  addu       $a1, $s1, $zero
    /* 1320 80103B20 820B040C */  jal        _getItemIndex
    /* 1324 80103B24 06A611A2 */   sb        $s1, %lo(D_8010A606)($s0)
    /* 1328 80103B28 21804000 */  addu       $s0, $v0, $zero
    /* 132C 80103B2C C0101000 */  sll        $v0, $s0, 3
    /* 1330 80103B30 23105000 */  subu       $v0, $v0, $s0
    /* 1334 80103B34 80100200 */  sll        $v0, $v0, 2
    /* 1338 80103B38 0680043C */  lui        $a0, %hi(D_80060A0C)
    /* 133C 80103B3C 0C0A8424 */  addiu      $a0, $a0, %lo(D_80060A0C)
    /* 1340 80103B40 21204400 */  addu       $a0, $v0, $a0
    /* 1344 80103B44 1000A527 */  addiu      $a1, $sp, 0x10
    /* 1348 80103B48 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 134C 80103B4C 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 1350 80103B50 38F4030C */  jal        vs_mainMenu_setUiGem
    /* 1354 80103B54 1800A627 */   addiu     $a2, $sp, 0x18
    /* 1358 80103B58 1EF6030C */  jal        vs_mainMenu_setGemStats
    /* 135C 80103B5C 21200002 */   addu      $a0, $s0, $zero
    /* 1360 80103B60 1000A527 */  addiu      $a1, $sp, 0x10
    /* 1364 80103B64 1180023C */  lui        $v0, %hi(D_8010A605)
    /* 1368 80103B68 05A64490 */  lbu        $a0, %lo(D_8010A605)($v0)
    /* 136C 80103B6C 1800A68F */  lw         $a2, 0x18($sp)
    /* 1370 80103B70 5B0B040C */  jal        _setSubMenu
    /* 1374 80103B74 21382002 */   addu      $a3, $s1, $zero
    /* 1378 80103B78 E50E0408 */  j          .L80103B94
    /* 137C 80103B7C 21100000 */   addu      $v0, $zero, $zero
  .L80103B80:
    /* 1380 80103B80 74EA030C */  jal        vs_mainmenu_ready
    /* 1384 80103B84 00000000 */   nop
    /* 1388 80103B88 E50E0408 */  j          .L80103B94
    /* 138C 80103B8C 00000000 */   nop
  .L80103B90:
    /* 1390 80103B90 21100000 */  addu       $v0, $zero, $zero
  .L80103B94:
    /* 1394 80103B94 2800BF8F */  lw         $ra, 0x28($sp)
    /* 1398 80103B98 2400B18F */  lw         $s1, 0x24($sp)
    /* 139C 80103B9C 2000B08F */  lw         $s0, 0x20($sp)
    /* 13A0 80103BA0 0800E003 */  jr         $ra
    /* 13A4 80103BA4 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _gemDetailsPage
