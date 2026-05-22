nonmatching vs_mainMenu_exec, 0x3F4

glabel vs_mainMenu_exec
    /* 12C8 800FAAC8 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 12CC 800FAACC 1800B0AF */  sw         $s0, 0x18($sp)
    /* 12D0 800FAAD0 21808000 */  addu       $s0, $a0, $zero
    /* 12D4 800FAAD4 FFFF0426 */  addiu      $a0, $s0, -0x1
    /* 12D8 800FAAD8 0F008430 */  andi       $a0, $a0, 0xF
    /* 12DC 800FAADC 0F80023C */  lui        $v0, %hi(vs_battle_menuState)
    /* 12E0 800FAAE0 3400B7AF */  sw         $s7, 0x34($sp)
    /* 12E4 800FAAE4 C0515724 */  addiu      $s7, $v0, %lo(vs_battle_menuState)
    /* 12E8 800FAAE8 3800BFAF */  sw         $ra, 0x38($sp)
    /* 12EC 800FAAEC 3000B6AF */  sw         $s6, 0x30($sp)
    /* 12F0 800FAAF0 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 12F4 800FAAF4 2800B4AF */  sw         $s4, 0x28($sp)
    /* 12F8 800FAAF8 2400B3AF */  sw         $s3, 0x24($sp)
    /* 12FC 800FAAFC 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1300 800FAB00 9223030C */  jal        vs_battle_getMenuItem
    /* 1304 800FAB04 1C00B1AF */   sw        $s1, 0x1C($sp)
    /* 1308 800FAB08 21904000 */  addu       $s2, $v0, $zero
    /* 130C 800FAB0C 21A00000 */  addu       $s4, $zero, $zero
    /* 1310 800FAB10 21200002 */  addu       $a0, $s0, $zero
    /* 1314 800FAB14 0680033C */  lui        $v1, %hi(vs_battle_inventory)
    /* 1318 800FAB18 68016324 */  addiu      $v1, $v1, %lo(vs_battle_inventory)
    /* 131C 800FAB1C 1080023C */  lui        $v0, %hi(vs_mainMenu_weapons)
    /* 1320 800FAB20 1080053C */  lui        $a1, %hi(vs_mainMenu_blades)
    /* 1324 800FAB24 702443AC */  sw         $v1, %lo(vs_mainMenu_weapons)($v0)
    /* 1328 800FAB28 80026224 */  addiu      $v0, $v1, 0x280
    /* 132C 800FAB2C 6424A2AC */  sw         $v0, %lo(vs_mainMenu_blades)($a1)
    /* 1330 800FAB30 1080053C */  lui        $a1, %hi(vs_mainMenu_grips)
    /* 1334 800FAB34 40056224 */  addiu      $v0, $v1, 0x540
    /* 1338 800FAB38 6024A2AC */  sw         $v0, %lo(vs_mainMenu_grips)($a1)
    /* 133C 800FAB3C 1080053C */  lui        $a1, %hi(vs_mainMenu_shields)
    /* 1340 800FAB40 00016224 */  addiu      $v0, $v1, 0x100
    /* 1344 800FAB44 6C24A2AC */  sw         $v0, %lo(vs_mainMenu_shields)($a1)
    /* 1348 800FAB48 1080053C */  lui        $a1, %hi(vs_mainMenu_armor)
    /* 134C 800FAB4C 40066224 */  addiu      $v0, $v1, 0x640
    /* 1350 800FAB50 6824A2AC */  sw         $v0, %lo(vs_mainMenu_armor)($a1)
    /* 1354 800FAB54 1080023C */  lui        $v0, %hi(vs_mainMenu_gems)
    /* 1358 800FAB58 C0086324 */  addiu      $v1, $v1, 0x8C0
    /* 135C 800FAB5C 582443AC */  sw         $v1, %lo(vs_mainMenu_gems)($v0)
    /* 1360 800FAB60 0F000332 */  andi       $v1, $s0, 0xF
    /* 1364 800FAB64 0F80023C */  lui        $v0, %hi(vs_battle_submenuStates)
    /* 1368 800FAB68 704E4224 */  addiu      $v0, $v0, %lo(vs_battle_submenuStates)
    /* 136C 800FAB6C 1423030C */  jal        vs_battle_loadMenuPrg
    /* 1370 800FAB70 21986200 */   addu      $s3, $v1, $v0
    /* 1374 800FAB74 3F001132 */  andi       $s1, $s0, 0x3F
    /* 1378 800FAB78 AF002012 */  beqz       $s1, .L800FAE38
    /* 137C 800FAB7C 21A84000 */   addu      $s5, $v0, $zero
    /* 1380 800FAB80 1F000224 */  addiu      $v0, $zero, 0x1F
    /* 1384 800FAB84 05002216 */  bne        $s1, $v0, .L800FAB9C
    /* 1388 800FAB88 0F80023C */   lui       $v0, %hi(D_800F4EA0)
    /* 138C 800FAB8C 88EA030C */  jal        func_800FAA20
    /* 1390 800FAB90 00000000 */   nop
    /* 1394 800FAB94 9BEB0308 */  j          .L800FAE6C
    /* 1398 800FAB98 21A04000 */   addu      $s4, $v0, $zero
  .L800FAB9C:
    /* 139C 800FAB9C A04E448C */  lw         $a0, %lo(D_800F4EA0)($v0)
    /* 13A0 800FABA0 00000000 */  nop
    /* 13A4 800FABA4 00028230 */  andi       $v0, $a0, 0x200
    /* 13A8 800FABA8 3A004010 */  beqz       $v0, .L800FAC94
    /* 13AC 800FABAC 00000000 */   nop
    /* 13B0 800FABB0 AE00A012 */  beqz       $s5, .L800FAE6C
    /* 13B4 800FABB4 0F000224 */   addiu     $v0, $zero, 0xF
    /* 13B8 800FABB8 05002216 */  bne        $s1, $v0, .L800FABD0
    /* 13BC 800FABBC 03000224 */   addiu     $v0, $zero, 0x3
    /* 13C0 800FABC0 EE0A040C */  jal        vs_menuF_exec
    /* 13C4 800FABC4 21206002 */   addu      $a0, $s3, $zero
    /* 13C8 800FABC8 9BEB0308 */  j          .L800FAE6C
    /* 13CC 800FABCC 21A04000 */   addu      $s4, $v0, $zero
  .L800FABD0:
    /* 13D0 800FABD0 05002216 */  bne        $s1, $v0, .L800FABE8
    /* 13D4 800FABD4 0E000224 */   addiu     $v0, $zero, 0xE
    /* 13D8 800FABD8 5E11040C */  jal        vs_menu2_skillUnlock
    /* 13DC 800FABDC 21206002 */   addu      $a0, $s3, $zero
    /* 13E0 800FABE0 9BEB0308 */  j          .L800FAE6C
    /* 13E4 800FABE4 21A04000 */   addu      $s4, $v0, $zero
  .L800FABE8:
    /* 13E8 800FABE8 05002216 */  bne        $s1, $v0, .L800FAC00
    /* 13EC 800FABEC 08000224 */   addiu     $v0, $zero, 0x8
    /* 13F0 800FABF0 1B23040C */  jal        func_80108C6C
    /* 13F4 800FABF4 21206002 */   addu      $a0, $s3, $zero
    /* 13F8 800FABF8 9BEB0308 */  j          .L800FAE6C
    /* 13FC 800FABFC 21A04000 */   addu      $s4, $v0, $zero
  .L800FAC00:
    /* 1400 800FAC00 05002216 */  bne        $s1, $v0, .L800FAC18
    /* 1404 800FAC04 0D000224 */   addiu     $v0, $zero, 0xD
    /* 1408 800FAC08 C514040C */  jal        vs_menu8_execRename
    /* 140C 800FAC0C 21206002 */   addu      $a0, $s3, $zero
    /* 1410 800FAC10 9BEB0308 */  j          .L800FAE6C
    /* 1414 800FAC14 21A04000 */   addu      $s4, $v0, $zero
  .L800FAC18:
    /* 1418 800FAC18 05002216 */  bne        $s1, $v0, .L800FAC30
    /* 141C 800FAC1C 0C000224 */   addiu     $v0, $zero, 0xC
    /* 1420 800FAC20 5E2A040C */  jal        vs_menuC_exec
    /* 1424 800FAC24 21206002 */   addu      $a0, $s3, $zero
    /* 1428 800FAC28 9BEB0308 */  j          .L800FAE6C
    /* 142C 800FAC2C 21A04000 */   addu      $s4, $v0, $zero
  .L800FAC30:
    /* 1430 800FAC30 05002216 */  bne        $s1, $v0, .L800FAC48
    /* 1434 800FAC34 07000224 */   addiu     $v0, $zero, 0x7
    /* 1438 800FAC38 A427040C */  jal        vs_menuB_exec
    /* 143C 800FAC3C 21206002 */   addu      $a0, $s3, $zero
    /* 1440 800FAC40 9BEB0308 */  j          .L800FAE6C
    /* 1444 800FAC44 21A04000 */   addu      $s4, $v0, $zero
  .L800FAC48:
    /* 1448 800FAC48 10002216 */  bne        $s1, $v0, .L800FAC8C
    /* 144C 800FAC4C 0F80023C */   lui       $v0, %hi(D_800F4EA0)
    /* 1450 800FAC50 00048230 */  andi       $v0, $a0, 0x400
    /* 1454 800FAC54 05004010 */  beqz       $v0, .L800FAC6C
    /* 1458 800FAC58 0680023C */   lui       $v0, %hi(vs_main_stateFlags + 0xA4)
    /* 145C 800FAC5C DE25040C */  jal        vs_menu7_saveContainerMenu
    /* 1460 800FAC60 21206002 */   addu      $a0, $s3, $zero
    /* 1464 800FAC64 9BEB0308 */  j          .L800FAE6C
    /* 1468 800FAC68 21A04000 */   addu      $s4, $v0, $zero
  .L800FAC6C:
    /* 146C 800FAC6C 3C164390 */  lbu        $v1, %lo(vs_main_stateFlags + 0xA4)($v0)
    /* 1470 800FAC70 01000224 */  addiu      $v0, $zero, 0x1
    /* 1474 800FAC74 05006214 */  bne        $v1, $v0, .L800FAC8C
    /* 1478 800FAC78 0F80023C */   lui       $v0, %hi(D_800F4EA0)
    /* 147C 800FAC7C 3A23040C */  jal        vs_menu7_gameOver
    /* 1480 800FAC80 21206002 */   addu      $a0, $s3, $zero
    /* 1484 800FAC84 9BEB0308 */  j          .L800FAE6C
    /* 1488 800FAC88 21A04000 */   addu      $s4, $v0, $zero
  .L800FAC8C:
    /* 148C 800FAC8C 9BEB0308 */  j          .L800FAE6C
    /* 1490 800FAC90 A04E40AC */   sw        $zero, %lo(D_800F4EA0)($v0)
  .L800FAC94:
    /* 1494 800FAC94 00006392 */  lbu        $v1, 0x0($s3)
    /* 1498 800FAC98 00000000 */  nop
    /* 149C 800FAC9C 05006010 */  beqz       $v1, .L800FACB4
    /* 14A0 800FACA0 01000224 */   addiu     $v0, $zero, 0x1
    /* 14A4 800FACA4 3D006210 */  beq        $v1, $v0, .L800FAD9C
    /* 14A8 800FACA8 00000000 */   nop
    /* 14AC 800FACAC 82EB0308 */  j          .L800FAE08
    /* 14B0 800FACB0 00000000 */   nop
  .L800FACB4:
    /* 14B4 800FACB4 40000232 */  andi       $v0, $s0, 0x40
    /* 14B8 800FACB8 1C004014 */  bnez       $v0, .L800FAD2C
    /* 14BC 800FACBC FCFF2226 */   addiu     $v0, $s1, -0x4
    /* 14C0 800FACC0 01000224 */  addiu      $v0, $zero, 0x1
    /* 14C4 800FACC4 03002216 */  bne        $s1, $v0, .L800FACD4
    /* 14C8 800FACC8 21800000 */   addu      $s0, $zero, $zero
    /* 14CC 800FACCC B7009030 */  andi       $s0, $a0, 0xB7
    /* 14D0 800FACD0 2B801000 */  sltu       $s0, $zero, $s0
  .L800FACD4:
    /* 14D4 800FACD4 02000224 */  addiu      $v0, $zero, 0x2
    /* 14D8 800FACD8 03002216 */  bne        $s1, $v0, .L800FACE8
    /* 14DC 800FACDC 00000000 */   nop
    /* 14E0 800FACE0 5F019030 */  andi       $s0, $a0, 0x15F
    /* 14E4 800FACE4 2B801000 */  sltu       $s0, $zero, $s0
  .L800FACE8:
    /* 14E8 800FACE8 FFFF2426 */  addiu      $a0, $s1, -0x1
    /* 14EC 800FACEC 40010524 */  addiu      $a1, $zero, 0x140
    /* 14F0 800FACF0 12000624 */  addiu      $a2, $zero, 0x12
    /* 14F4 800FACF4 08000224 */  addiu      $v0, $zero, 0x8
    /* 14F8 800FACF8 0F80033C */  lui        $v1, %hi(vs_battle_menuStrings)
    /* 14FC 800FACFC DCB96324 */  addiu      $v1, $v1, %lo(vs_battle_menuStrings)
    /* 1500 800FAD00 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1504 800FAD04 40100400 */  sll        $v0, $a0, 1
    /* 1508 800FAD08 21104300 */  addu       $v0, $v0, $v1
    /* 150C 800FAD0C 00004294 */  lhu        $v0, 0x0($v0)
    /* 1510 800FAD10 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 1514 800FAD14 40100200 */  sll        $v0, $v0, 1
    /* 1518 800FAD18 21104300 */  addu       $v0, $v0, $v1
    /* 151C 800FAD1C 9723030C */  jal        vs_battle_setMenuItem
    /* 1520 800FAD20 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1524 800FAD24 070050A0 */  sb         $s0, 0x7($v0)
    /* 1528 800FAD28 FCFF2226 */  addiu      $v0, $s1, -0x4
  .L800FAD2C:
    /* 152C 800FAD2C 0200422C */  sltiu      $v0, $v0, 0x2
    /* 1530 800FAD30 05004014 */  bnez       $v0, .L800FAD48
    /* 1534 800FAD34 07000224 */   addiu     $v0, $zero, 0x7
    /* 1538 800FAD38 03002212 */  beq        $s1, $v0, .L800FAD48
    /* 153C 800FAD3C 09000224 */   addiu     $v0, $zero, 0x9
    /* 1540 800FAD40 03002216 */  bne        $s1, $v0, .L800FAD50
    /* 1544 800FAD44 00000000 */   nop
  .L800FAD48:
    /* 1548 800FAD48 DAFE030C */  jal        func_800FFB68
    /* 154C 800FAD4C 01000424 */   addiu     $a0, $zero, 0x1
  .L800FAD50:
    /* 1550 800FAD50 A2FE030C */  jal        func_800FFA88
    /* 1554 800FAD54 02000424 */   addiu     $a0, $zero, 0x2
    /* 1558 800FAD58 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 155C 800FAD5C FFFF2426 */   addiu     $a0, $s1, -0x1
    /* 1560 800FAD60 02000224 */  addiu      $v0, $zero, 0x2
    /* 1564 800FAD64 000042A2 */  sb         $v0, 0x0($s2)
    /* 1568 800FAD68 B4000224 */  addiu      $v0, $zero, 0xB4
    /* 156C 800FAD6C 01001024 */  addiu      $s0, $zero, 0x1
    /* 1570 800FAD70 180042A6 */  sh         $v0, 0x18($s2)
    /* 1574 800FAD74 05000224 */  addiu      $v0, $zero, 0x5
    /* 1578 800FAD78 06002216 */  bne        $s1, $v0, .L800FAD94
    /* 157C 800FAD7C 060050A2 */   sb        $s0, 0x6($s2)
    /* 1580 800FAD80 FEFF0424 */  addiu      $a0, $zero, -0x2
    /* 1584 800FAD84 0501040C */  jal        func_80100414
    /* 1588 800FAD88 80000524 */   addiu     $a1, $zero, 0x80
    /* 158C 800FAD8C 40010224 */  addiu      $v0, $zero, 0x140
    /* 1590 800FAD90 180042A6 */  sh         $v0, 0x18($s2)
  .L800FAD94:
    /* 1594 800FAD94 9BEB0308 */  j          .L800FAE6C
    /* 1598 800FAD98 000070A2 */   sb        $s0, 0x0($s3)
  .L800FAD9C:
    /* 159C 800FAD9C 00005092 */  lbu        $s0, 0x0($s2)
    /* 15A0 800FADA0 00000000 */  nop
    /* 15A4 800FADA4 31000316 */  bne        $s0, $v1, .L800FAE6C
    /* 15A8 800FADA8 03001624 */   addiu     $s6, $zero, 0x3
    /* 15AC 800FADAC 12000224 */  addiu      $v0, $zero, 0x12
    /* 15B0 800FADB0 180042A6 */  sh         $v0, 0x18($s2)
    /* 15B4 800FADB4 05000224 */  addiu      $v0, $zero, 0x5
    /* 15B8 800FADB8 12002216 */  bne        $s1, $v0, .L800FAE04
    /* 15BC 800FADBC 000056A2 */   sb        $s6, 0x0($s2)
    /* 15C0 800FADC0 04000424 */  addiu      $a0, $zero, 0x4
    /* 15C4 800FADC4 40010524 */  addiu      $a1, $zero, 0x140
    /* 15C8 800FADC8 12000624 */  addiu      $a2, $zero, 0x12
    /* 15CC 800FADCC 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 15D0 800FADD0 FC19438C */  lw         $v1, %lo(vs_battle_characterState)($v0)
    /* 15D4 800FADD4 08000224 */  addiu      $v0, $zero, 0x8
    /* 15D8 800FADD8 1000A2AF */  sw         $v0, 0x10($sp)
    /* 15DC 800FADDC 3C00628C */  lw         $v0, 0x3C($v1)
    /* 15E0 800FADE0 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 15E4 800FADE4 9723030C */  jal        vs_battle_setMenuItem
    /* 15E8 800FADE8 1400A2AF */   sw        $v0, 0x14($sp)
    /* 15EC 800FADEC 21904000 */  addu       $s2, $v0, $zero
    /* 15F0 800FADF0 02000224 */  addiu      $v0, $zero, 0x2
    /* 15F4 800FADF4 000042A2 */  sb         $v0, 0x0($s2)
    /* 15F8 800FADF8 B4000224 */  addiu      $v0, $zero, 0xB4
    /* 15FC 800FADFC 180042A6 */  sh         $v0, 0x18($s2)
    /* 1600 800FAE00 060050A2 */  sb         $s0, 0x6($s2)
  .L800FAE04:
    /* 1604 800FAE04 000076A2 */  sb         $s6, 0x0($s3)
  .L800FAE08:
    /* 1608 800FAE08 1800A012 */  beqz       $s5, .L800FAE6C
    /* 160C 800FAE0C 1080023C */   lui       $v0, %hi(_submenuEntrypoints)
    /* 1610 800FAE10 38204224 */  addiu      $v0, $v0, %lo(_submenuEntrypoints)
    /* 1614 800FAE14 FFFF2326 */  addiu      $v1, $s1, -0x1
    /* 1618 800FAE18 80180300 */  sll        $v1, $v1, 2
    /* 161C 800FAE1C 21186200 */  addu       $v1, $v1, $v0
    /* 1620 800FAE20 0000628C */  lw         $v0, 0x0($v1)
    /* 1624 800FAE24 00000000 */  nop
    /* 1628 800FAE28 09F84000 */  jalr       $v0
    /* 162C 800FAE2C 21206002 */   addu      $a0, $s3, $zero
    /* 1630 800FAE30 9BEB0308 */  j          .L800FAE6C
    /* 1634 800FAE34 21A04000 */   addu      $s4, $v0, $zero
  .L800FAE38:
    /* 1638 800FAE38 A2FE030C */  jal        func_800FFA88
    /* 163C 800FAE3C 01000424 */   addiu     $a0, $zero, 0x1
    /* 1640 800FAE40 C324030C */  jal        func_800C930C
    /* 1644 800FAE44 21200000 */   addu      $a0, $zero, $zero
    /* 1648 800FAE48 21804000 */  addu       $s0, $v0, $zero
    /* 164C 800FAE4C 07000012 */  beqz       $s0, .L800FAE6C
    /* 1650 800FAE50 00000000 */   nop
    /* 1654 800FAE54 0400001E */  bgtz       $s0, .L800FAE68
    /* 1658 800FAE58 40001036 */   ori       $s0, $s0, 0x40
    /* 165C 800FAE5C 1F001024 */  addiu      $s0, $zero, 0x1F
    /* 1660 800FAE60 A2FE030C */  jal        func_800FFA88
    /* 1664 800FAE64 21200000 */   addu      $a0, $zero, $zero
  .L800FAE68:
    /* 1668 800FAE68 0000F0A2 */  sb         $s0, 0x0($s7)
  .L800FAE6C:
    /* 166C 800FAE6C 06008012 */  beqz       $s4, .L800FAE88
    /* 1670 800FAE70 00000000 */   nop
    /* 1674 800FAE74 0000E492 */  lbu        $a0, 0x0($s7)
    /* 1678 800FAE78 97EA030C */  jal        func_800FAA5C
    /* 167C 800FAE7C 00000000 */   nop
    /* 1680 800FAE80 03004014 */  bnez       $v0, .L800FAE90
    /* 1684 800FAE84 00000000 */   nop
  .L800FAE88:
    /* 1688 800FAE88 CE07040C */  jal        func_80101F38
    /* 168C 800FAE8C 00000000 */   nop
  .L800FAE90:
    /* 1690 800FAE90 3800BF8F */  lw         $ra, 0x38($sp)
    /* 1694 800FAE94 3400B78F */  lw         $s7, 0x34($sp)
    /* 1698 800FAE98 3000B68F */  lw         $s6, 0x30($sp)
    /* 169C 800FAE9C 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 16A0 800FAEA0 2800B48F */  lw         $s4, 0x28($sp)
    /* 16A4 800FAEA4 2400B38F */  lw         $s3, 0x24($sp)
    /* 16A8 800FAEA8 2000B28F */  lw         $s2, 0x20($sp)
    /* 16AC 800FAEAC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 16B0 800FAEB0 1800B08F */  lw         $s0, 0x18($sp)
    /* 16B4 800FAEB4 0800E003 */  jr         $ra
    /* 16B8 800FAEB8 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel vs_mainMenu_exec
