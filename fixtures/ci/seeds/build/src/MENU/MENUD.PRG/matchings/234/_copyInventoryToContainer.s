nonmatching _copyInventoryToContainer, 0x174

glabel _copyInventoryToContainer
    /* 11AC 801039AC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 11B0 801039B0 0100033C */  lui        $v1, (0x105B0 >> 16)
    /* 11B4 801039B4 B0056334 */  ori        $v1, $v1, (0x105B0 & 0xFFFF)
    /* 11B8 801039B8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 11BC 801039BC 1080103C */  lui        $s0, %hi(vs_menu_inventoryStorage)
    /* 11C0 801039C0 5C24028E */  lw         $v0, %lo(vs_menu_inventoryStorage)($s0)
    /* 11C4 801039C4 003C0524 */  addiu      $a1, $zero, 0x3C00
    /* 11C8 801039C8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 11CC 801039CC 21880000 */  addu       $s1, $zero, $zero
    /* 11D0 801039D0 2800BFAF */  sw         $ra, 0x28($sp)
    /* 11D4 801039D4 2400B5AF */  sw         $s5, 0x24($sp)
    /* 11D8 801039D8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 11DC 801039DC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 11E0 801039E0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 11E4 801039E4 21984300 */  addu       $s3, $v0, $v1
    /* 11E8 801039E8 21206002 */  addu       $a0, $s3, $zero
    /* 11EC 801039EC 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 11F0 801039F0 0733030C */  jal        vs_battle_rMemzero
    /* 11F4 801039F4 68015424 */   addiu     $s4, $v0, %lo(vs_battle_inventory)
    /* 11F8 801039F8 0100023C */  lui        $v0, (0x141B0 >> 16)
    /* 11FC 801039FC B0414234 */  ori        $v0, $v0, (0x141B0 & 0xFFFF)
    /* 1200 80103A00 5C24048E */  lw         $a0, %lo(vs_menu_inventoryStorage)($s0)
    /* 1204 80103A04 80050524 */  addiu      $a1, $zero, 0x580
    /* 1208 80103A08 0733030C */  jal        vs_battle_rMemzero
    /* 120C 80103A0C 21208200 */   addu      $a0, $a0, $v0
    /* 1210 80103A10 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryItemCapacities)
    /* 1214 80103A14 A0225524 */  addiu      $s5, $v0, %lo(vs_mainMenu_inventoryItemCapacities)
    /* 1218 80103A18 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryIndices)
    /* 121C 80103A1C A8225224 */  addiu      $s2, $v0, %lo(vs_mainMenu_inventoryIndices)
  .L80103A20:
    /* 1220 80103A20 21202002 */  addu       $a0, $s1, $zero
    /* 1224 80103A24 0000508E */  lw         $s0, 0x0($s2)
    /* 1228 80103A28 250B040C */  jal        _getContainerIndicesOffset
    /* 122C 80103A2C 21286002 */   addu      $a1, $s3, $zero
    /* 1230 80103A30 21200000 */  addu       $a0, $zero, $zero
    /* 1234 80103A34 21183502 */  addu       $v1, $s1, $s5
    /* 1238 80103A38 00006390 */  lbu        $v1, 0x0($v1)
    /* 123C 80103A3C 00000000 */  nop
    /* 1240 80103A40 0E006010 */  beqz       $v1, .L80103A7C
    /* 1244 80103A44 21284000 */   addu      $a1, $v0, $zero
    /* 1248 80103A48 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryItemCapacities)
    /* 124C 80103A4C A0224224 */  addiu      $v0, $v0, %lo(vs_mainMenu_inventoryItemCapacities)
    /* 1250 80103A50 21302202 */  addu       $a2, $s1, $v0
    /* 1254 80103A54 2118A000 */  addu       $v1, $a1, $zero
  .L80103A58:
    /* 1258 80103A58 21100402 */  addu       $v0, $s0, $a0
    /* 125C 80103A5C 00004290 */  lbu        $v0, 0x0($v0)
    /* 1260 80103A60 01008424 */  addiu      $a0, $a0, 0x1
    /* 1264 80103A64 000062A4 */  sh         $v0, 0x0($v1)
    /* 1268 80103A68 0000C290 */  lbu        $v0, 0x0($a2)
    /* 126C 80103A6C 00000000 */  nop
    /* 1270 80103A70 2A108200 */  slt        $v0, $a0, $v0
    /* 1274 80103A74 F8FF4014 */  bnez       $v0, .L80103A58
    /* 1278 80103A78 02006324 */   addiu     $v1, $v1, 0x2
  .L80103A7C:
    /* 127C 80103A7C 01003126 */  addiu      $s1, $s1, 0x1
    /* 1280 80103A80 0700222A */  slti       $v0, $s1, 0x7
    /* 1284 80103A84 E6FF4014 */  bnez       $v0, .L80103A20
    /* 1288 80103A88 04005226 */   addiu     $s2, $s2, 0x4
    /* 128C 80103A8C 21206002 */  addu       $a0, $s3, $zero
    /* 1290 80103A90 21288002 */  addu       $a1, $s4, $zero
    /* 1294 80103A94 7800030C */  jal        vs_battle_memcpy
    /* 1298 80103A98 00010624 */   addiu     $a2, $zero, 0x100
    /* 129C 80103A9C 000A6426 */  addiu      $a0, $s3, 0xA00
    /* 12A0 80103AA0 80028526 */  addiu      $a1, $s4, 0x280
    /* 12A4 80103AA4 7800030C */  jal        vs_battle_memcpy
    /* 12A8 80103AA8 C0020624 */   addiu     $a2, $zero, 0x2C0
    /* 12AC 80103AAC 00156426 */  addiu      $a0, $s3, 0x1500
    /* 12B0 80103AB0 40058526 */  addiu      $a1, $s4, 0x540
    /* 12B4 80103AB4 7800030C */  jal        vs_battle_memcpy
    /* 12B8 80103AB8 00010624 */   addiu     $a2, $zero, 0x100
    /* 12BC 80103ABC 00046426 */  addiu      $a0, $s3, 0x400
    /* 12C0 80103AC0 00018526 */  addiu      $a1, $s4, 0x100
    /* 12C4 80103AC4 7800030C */  jal        vs_battle_memcpy
    /* 12C8 80103AC8 80010624 */   addiu     $a2, $zero, 0x180
    /* 12CC 80103ACC 00196426 */  addiu      $a0, $s3, 0x1900
    /* 12D0 80103AD0 40068526 */  addiu      $a1, $s4, 0x640
    /* 12D4 80103AD4 7800030C */  jal        vs_battle_memcpy
    /* 12D8 80103AD8 80020624 */   addiu     $a2, $zero, 0x280
    /* 12DC 80103ADC 00236426 */  addiu      $a0, $s3, 0x2300
    /* 12E0 80103AE0 C0088526 */  addiu      $a1, $s4, 0x8C0
    /* 12E4 80103AE4 7800030C */  jal        vs_battle_memcpy
    /* 12E8 80103AE8 40050624 */   addiu     $a2, $zero, 0x540
    /* 12EC 80103AEC 00386426 */  addiu      $a0, $s3, 0x3800
    /* 12F0 80103AF0 000E8526 */  addiu      $a1, $s4, 0xE00
    /* 12F4 80103AF4 7800030C */  jal        vs_battle_memcpy
    /* 12F8 80103AF8 00010624 */   addiu     $a2, $zero, 0x100
    /* 12FC 80103AFC 2800BF8F */  lw         $ra, 0x28($sp)
    /* 1300 80103B00 2400B58F */  lw         $s5, 0x24($sp)
    /* 1304 80103B04 2000B48F */  lw         $s4, 0x20($sp)
    /* 1308 80103B08 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 130C 80103B0C 1800B28F */  lw         $s2, 0x18($sp)
    /* 1310 80103B10 1400B18F */  lw         $s1, 0x14($sp)
    /* 1314 80103B14 1000B08F */  lw         $s0, 0x10($sp)
    /* 1318 80103B18 0800E003 */  jr         $ra
    /* 131C 80103B1C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _copyInventoryToContainer
