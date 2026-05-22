nonmatching _copyContainerToInventory, 0x17C

glabel _copyContainerToInventory
    /* 1320 80103B20 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 1324 80103B24 0100043C */  lui        $a0, (0x105B0 >> 16)
    /* 1328 80103B28 B0058434 */  ori        $a0, $a0, (0x105B0 & 0xFFFF)
    /* 132C 80103B2C 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 1330 80103B30 2800B6AF */  sw         $s6, 0x28($sp)
    /* 1334 80103B34 68015624 */  addiu      $s6, $v0, %lo(vs_battle_inventory)
    /* 1338 80103B38 1400B1AF */  sw         $s1, 0x14($sp)
    /* 133C 80103B3C 21880000 */  addu       $s1, $zero, $zero
    /* 1340 80103B40 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryItemCapacities)
    /* 1344 80103B44 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 1348 80103B48 A0225724 */  addiu      $s7, $v0, %lo(vs_mainMenu_inventoryItemCapacities)
    /* 134C 80103B4C 1080023C */  lui        $v0, %hi(vs_menu_inventoryStorage)
    /* 1350 80103B50 5C24438C */  lw         $v1, %lo(vs_menu_inventoryStorage)($v0)
    /* 1354 80103B54 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryIndices)
    /* 1358 80103B58 2000B4AF */  sw         $s4, 0x20($sp)
    /* 135C 80103B5C A8225424 */  addiu      $s4, $v0, %lo(vs_mainMenu_inventoryIndices)
    /* 1360 80103B60 3000BFAF */  sw         $ra, 0x30($sp)
    /* 1364 80103B64 2400B5AF */  sw         $s5, 0x24($sp)
    /* 1368 80103B68 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 136C 80103B6C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1370 80103B70 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1374 80103B74 21906400 */  addu       $s2, $v1, $a0
  .L80103B78:
    /* 1378 80103B78 21202002 */  addu       $a0, $s1, $zero
    /* 137C 80103B7C 0000958E */  lw         $s5, 0x0($s4)
    /* 1380 80103B80 250B040C */  jal        _getContainerIndicesOffset
    /* 1384 80103B84 21284002 */   addu      $a1, $s2, $zero
    /* 1388 80103B88 21984000 */  addu       $s3, $v0, $zero
    /* 138C 80103B8C 21800000 */  addu       $s0, $zero, $zero
    /* 1390 80103B90 21200002 */  addu       $a0, $s0, $zero
  .L80103B94:
    /* 1394 80103B94 F60D040C */  jal        _defragmentContainerItems
    /* 1398 80103B98 21284002 */   addu      $a1, $s2, $zero
    /* 139C 80103B9C 01001026 */  addiu      $s0, $s0, 0x1
    /* 13A0 80103BA0 0700022A */  slti       $v0, $s0, 0x7
    /* 13A4 80103BA4 FBFF4014 */  bnez       $v0, .L80103B94
    /* 13A8 80103BA8 21200002 */   addu      $a0, $s0, $zero
    /* 13AC 80103BAC 21103702 */  addu       $v0, $s1, $s7
    /* 13B0 80103BB0 00004290 */  lbu        $v0, 0x0($v0)
    /* 13B4 80103BB4 00000000 */  nop
    /* 13B8 80103BB8 0D004010 */  beqz       $v0, .L80103BF0
    /* 13BC 80103BBC 21200000 */   addu      $a0, $zero, $zero
    /* 13C0 80103BC0 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryItemCapacities)
    /* 13C4 80103BC4 A0224224 */  addiu      $v0, $v0, %lo(vs_mainMenu_inventoryItemCapacities)
    /* 13C8 80103BC8 21302202 */  addu       $a2, $s1, $v0
    /* 13CC 80103BCC 21286002 */  addu       $a1, $s3, $zero
  .L80103BD0:
    /* 13D0 80103BD0 0000A290 */  lbu        $v0, 0x0($a1)
    /* 13D4 80103BD4 2118A402 */  addu       $v1, $s5, $a0
    /* 13D8 80103BD8 000062A0 */  sb         $v0, 0x0($v1)
    /* 13DC 80103BDC 0000C290 */  lbu        $v0, 0x0($a2)
    /* 13E0 80103BE0 01008424 */  addiu      $a0, $a0, 0x1
    /* 13E4 80103BE4 2A108200 */  slt        $v0, $a0, $v0
    /* 13E8 80103BE8 F9FF4014 */  bnez       $v0, .L80103BD0
    /* 13EC 80103BEC 0200A524 */   addiu     $a1, $a1, 0x2
  .L80103BF0:
    /* 13F0 80103BF0 01003126 */  addiu      $s1, $s1, 0x1
    /* 13F4 80103BF4 0700222A */  slti       $v0, $s1, 0x7
    /* 13F8 80103BF8 DFFF4014 */  bnez       $v0, .L80103B78
    /* 13FC 80103BFC 04009426 */   addiu     $s4, $s4, 0x4
    /* 1400 80103C00 2120C002 */  addu       $a0, $s6, $zero
    /* 1404 80103C04 21284002 */  addu       $a1, $s2, $zero
    /* 1408 80103C08 7800030C */  jal        vs_battle_memcpy
    /* 140C 80103C0C 00010624 */   addiu     $a2, $zero, 0x100
    /* 1410 80103C10 8002C426 */  addiu      $a0, $s6, 0x280
    /* 1414 80103C14 000A4526 */  addiu      $a1, $s2, 0xA00
    /* 1418 80103C18 7800030C */  jal        vs_battle_memcpy
    /* 141C 80103C1C C0020624 */   addiu     $a2, $zero, 0x2C0
    /* 1420 80103C20 4005C426 */  addiu      $a0, $s6, 0x540
    /* 1424 80103C24 00154526 */  addiu      $a1, $s2, 0x1500
    /* 1428 80103C28 7800030C */  jal        vs_battle_memcpy
    /* 142C 80103C2C 00010624 */   addiu     $a2, $zero, 0x100
    /* 1430 80103C30 0001C426 */  addiu      $a0, $s6, 0x100
    /* 1434 80103C34 00044526 */  addiu      $a1, $s2, 0x400
    /* 1438 80103C38 7800030C */  jal        vs_battle_memcpy
    /* 143C 80103C3C 80010624 */   addiu     $a2, $zero, 0x180
    /* 1440 80103C40 4006C426 */  addiu      $a0, $s6, 0x640
    /* 1444 80103C44 00194526 */  addiu      $a1, $s2, 0x1900
    /* 1448 80103C48 7800030C */  jal        vs_battle_memcpy
    /* 144C 80103C4C 80020624 */   addiu     $a2, $zero, 0x280
    /* 1450 80103C50 C008C426 */  addiu      $a0, $s6, 0x8C0
    /* 1454 80103C54 00234526 */  addiu      $a1, $s2, 0x2300
    /* 1458 80103C58 7800030C */  jal        vs_battle_memcpy
    /* 145C 80103C5C 40050624 */   addiu     $a2, $zero, 0x540
    /* 1460 80103C60 000EC426 */  addiu      $a0, $s6, 0xE00
    /* 1464 80103C64 00384526 */  addiu      $a1, $s2, 0x3800
    /* 1468 80103C68 7800030C */  jal        vs_battle_memcpy
    /* 146C 80103C6C 00010624 */   addiu     $a2, $zero, 0x100
    /* 1470 80103C70 3000BF8F */  lw         $ra, 0x30($sp)
    /* 1474 80103C74 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 1478 80103C78 2800B68F */  lw         $s6, 0x28($sp)
    /* 147C 80103C7C 2400B58F */  lw         $s5, 0x24($sp)
    /* 1480 80103C80 2000B48F */  lw         $s4, 0x20($sp)
    /* 1484 80103C84 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1488 80103C88 1800B28F */  lw         $s2, 0x18($sp)
    /* 148C 80103C8C 1400B18F */  lw         $s1, 0x14($sp)
    /* 1490 80103C90 1000B08F */  lw         $s0, 0x10($sp)
    /* 1494 80103C94 0800E003 */  jr         $ra
    /* 1498 80103C98 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel _copyContainerToInventory
