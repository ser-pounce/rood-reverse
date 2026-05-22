nonmatching _enchanterMagicMenu, 0x344

glabel _enchanterMagicMenu
    /* 12EC 80103AEC 68FFBD27 */  addiu      $sp, $sp, -0x98
    /* 12F0 80103AF0 21188000 */  addu       $v1, $a0, $zero
    /* 12F4 80103AF4 9400BFAF */  sw         $ra, 0x94($sp)
    /* 12F8 80103AF8 9000BEAF */  sw         $fp, 0x90($sp)
    /* 12FC 80103AFC 8C00B7AF */  sw         $s7, 0x8C($sp)
    /* 1300 80103B00 8800B6AF */  sw         $s6, 0x88($sp)
    /* 1304 80103B04 8400B5AF */  sw         $s5, 0x84($sp)
    /* 1308 80103B08 8000B4AF */  sw         $s4, 0x80($sp)
    /* 130C 80103B0C 7C00B3AF */  sw         $s3, 0x7C($sp)
    /* 1310 80103B10 7800B2AF */  sw         $s2, 0x78($sp)
    /* 1314 80103B14 7400B1AF */  sw         $s1, 0x74($sp)
    /* 1318 80103B18 0C006010 */  beqz       $v1, .L80103B4C
    /* 131C 80103B1C 7000B0AF */   sw        $s0, 0x70($sp)
    /* 1320 80103B20 03000424 */  addiu      $a0, $zero, 0x3
    /* 1324 80103B24 01000524 */  addiu      $a1, $zero, 0x1
    /* 1328 80103B28 1080023C */  lui        $v0, %hi(D_80106914)
    /* 132C 80103B2C 02006338 */  xori       $v1, $v1, 0x2
    /* 1330 80103B30 2B186500 */  sltu       $v1, $v1, $a1
    /* 1334 80103B34 4BEA030C */  jal        func_800FA92C
    /* 1338 80103B38 146943AC */   sw        $v1, %lo(D_80106914)($v0)
    /* 133C 80103B3C 21100000 */  addu       $v0, $zero, $zero
    /* 1340 80103B40 1080033C */  lui        $v1, %hi(D_8010690C)
    /* 1344 80103B44 800F0408 */  j          .L80103E00
    /* 1348 80103B48 0C6960AC */   sw        $zero, %lo(D_8010690C)($v1)
  .L80103B4C:
    /* 134C 80103B4C 1080023C */  lui        $v0, %hi(D_8010690C)
    /* 1350 80103B50 0C69438C */  lw         $v1, %lo(D_8010690C)($v0)
    /* 1354 80103B54 01000224 */  addiu      $v0, $zero, 0x1
    /* 1358 80103B58 6E006210 */  beq        $v1, $v0, .L80103D14
    /* 135C 80103B5C 02006228 */   slti      $v0, $v1, 0x2
    /* 1360 80103B60 05004010 */  beqz       $v0, .L80103B78
    /* 1364 80103B64 02000224 */   addiu     $v0, $zero, 0x2
    /* 1368 80103B68 07006010 */  beqz       $v1, .L80103B88
    /* 136C 80103B6C 21100000 */   addu      $v0, $zero, $zero
    /* 1370 80103B70 800F0408 */  j          .L80103E00
    /* 1374 80103B74 00000000 */   nop
  .L80103B78:
    /* 1378 80103B78 99006210 */  beq        $v1, $v0, .L80103DE0
    /* 137C 80103B7C 21100000 */   addu      $v0, $zero, $zero
    /* 1380 80103B80 800F0408 */  j          .L80103E00
    /* 1384 80103B84 00000000 */   nop
  .L80103B88:
    /* 1388 80103B88 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* 138C 80103B8C 6A4E4290 */  lbu        $v0, %lo(vs_battle_shortcutInvoked)($v0)
    /* 1390 80103B90 00000000 */  nop
    /* 1394 80103B94 05004014 */  bnez       $v0, .L80103BAC
    /* 1398 80103B98 21980000 */   addu      $s3, $zero, $zero
    /* 139C 80103B9C 74EA030C */  jal        vs_mainmenu_ready
    /* 13A0 80103BA0 00000000 */   nop
    /* 13A4 80103BA4 96004010 */  beqz       $v0, .L80103E00
    /* 13A8 80103BA8 21100000 */   addu      $v0, $zero, $zero
  .L80103BAC:
    /* 13AC 80103BAC 21906002 */  addu       $s2, $s3, $zero
    /* 13B0 80103BB0 1080023C */  lui        $v0, %hi(_baseStrings)
    /* 13B4 80103BB4 584A5E24 */  addiu      $fp, $v0, %lo(_baseStrings)
    /* 13B8 80103BB8 6C001624 */  addiu      $s6, $zero, 0x6C
    /* 13BC 80103BBC 04001524 */  addiu      $s5, $zero, 0x4
    /* 13C0 80103BC0 1000B727 */  addiu      $s7, $sp, 0x10
    /* 13C4 80103BC4 21A0E002 */  addu       $s4, $s7, $zero
  .L80103BC8:
    /* 13C8 80103BC8 0F80083C */  lui        $t0, %hi(vs_battle_enchanterSpellIds)
    /* 13CC 80103BCC A0BD0825 */  addiu      $t0, $t0, %lo(vs_battle_enchanterSpellIds)
    /* 13D0 80103BD0 21104802 */  addu       $v0, $s2, $t0
    /* 13D4 80103BD4 0580083C */  lui        $t0, %hi(vs_main_skills)
    /* 13D8 80103BD8 00005190 */  lbu        $s1, 0x0($v0)
    /* 13DC 80103BDC DCB90825 */  addiu      $t0, $t0, %lo(vs_main_skills)
    /* 13E0 80103BE0 40101100 */  sll        $v0, $s1, 1
    /* 13E4 80103BE4 21105100 */  addu       $v0, $v0, $s1
    /* 13E8 80103BE8 80100200 */  sll        $v0, $v0, 2
    /* 13EC 80103BEC 21105100 */  addu       $v0, $v0, $s1
    /* 13F0 80103BF0 80180200 */  sll        $v1, $v0, 2
    /* 13F4 80103BF4 21106800 */  addu       $v0, $v1, $t0
    /* 13F8 80103BF8 0C00428C */  lw         $v0, 0xC($v0)
    /* 13FC 80103BFC 00000000 */  nop
    /* 1400 80103C00 C2130200 */  srl        $v0, $v0, 15
    /* 1404 80103C04 01004230 */  andi       $v0, $v0, 0x1
    /* 1408 80103C08 1E004010 */  beqz       $v0, .L80103C84
    /* 140C 80103C0C 21200000 */   addu      $a0, $zero, $zero
    /* 1410 80103C10 21282002 */  addu       $a1, $s1, $zero
    /* 1414 80103C14 0580083C */  lui        $t0, %hi(D_8004B9F8)
    /* 1418 80103C18 F8B90825 */  addiu      $t0, $t0, %lo(D_8004B9F8)
    /* 141C 80103C1C 21106800 */  addu       $v0, $v1, $t0
    /* 1420 80103C20 000082AE */  sw         $v0, 0x0($s4)
    /* 1424 80103C24 2110DE02 */  addu       $v0, $s6, $fp
    /* 1428 80103C28 00004294 */  lhu        $v0, 0x0($v0)
    /* 142C 80103C2C 2118F502 */  addu       $v1, $s7, $s5
    /* 1430 80103C30 40100200 */  sll        $v0, $v0, 1
    /* 1434 80103C34 21105E00 */  addu       $v0, $v0, $fp
    /* 1438 80103C38 000062AC */  sw         $v0, 0x0($v1)
    /* 143C 80103C3C 80181300 */  sll        $v1, $s3, 2
    /* 1440 80103C40 5000A227 */  addiu      $v0, $sp, 0x50
    /* 1444 80103C44 21804300 */  addu       $s0, $v0, $v1
    /* 1448 80103C48 7429020C */  jal        vs_battle_getSkillFlags
    /* 144C 80103C4C 000000AE */   sw        $zero, 0x0($s0)
    /* 1450 80103C50 06004010 */  beqz       $v0, .L80103C6C
    /* 1454 80103C54 1080023C */   lui       $v0, %hi(_availableEnchanterSpells)
    /* 1458 80103C58 0000028E */  lw         $v0, 0x0($s0)
    /* 145C 80103C5C 00000000 */  nop
    /* 1460 80103C60 01004234 */  ori        $v0, $v0, 0x1
    /* 1464 80103C64 000002AE */  sw         $v0, 0x0($s0)
    /* 1468 80103C68 1080023C */  lui        $v0, %hi(_availableEnchanterSpells)
  .L80103C6C:
    /* 146C 80103C6C 70694224 */  addiu      $v0, $v0, %lo(_availableEnchanterSpells)
    /* 1470 80103C70 21106202 */  addu       $v0, $s3, $v0
    /* 1474 80103C74 000051A0 */  sb         $s1, 0x0($v0)
    /* 1478 80103C78 0800B526 */  addiu      $s5, $s5, 0x8
    /* 147C 80103C7C 08009426 */  addiu      $s4, $s4, 0x8
    /* 1480 80103C80 01007326 */  addiu      $s3, $s3, 0x1
  .L80103C84:
    /* 1484 80103C84 01005226 */  addiu      $s2, $s2, 0x1
    /* 1488 80103C88 0800422A */  slti       $v0, $s2, 0x8
    /* 148C 80103C8C CEFF4014 */  bnez       $v0, .L80103BC8
    /* 1490 80103C90 0200D626 */   addiu     $s6, $s6, 0x2
    /* 1494 80103C94 0F80023C */  lui        $v0, %hi(D_800F4EA0)
    /* 1498 80103C98 A04E428C */  lw         $v0, %lo(D_800F4EA0)($v0)
    /* 149C 80103C9C 00000000 */  nop
    /* 14A0 80103CA0 B7004230 */  andi       $v0, $v0, 0xB7
    /* 14A4 80103CA4 09004010 */  beqz       $v0, .L80103CCC
    /* 14A8 80103CA8 21900000 */   addu      $s2, $zero, $zero
    /* 14AC 80103CAC 5000A327 */  addiu      $v1, $sp, 0x50
  .L80103CB0:
    /* 14B0 80103CB0 0000628C */  lw         $v0, 0x0($v1)
    /* 14B4 80103CB4 01005226 */  addiu      $s2, $s2, 0x1
    /* 14B8 80103CB8 01004234 */  ori        $v0, $v0, 0x1
    /* 14BC 80103CBC 000062AC */  sw         $v0, 0x0($v1)
    /* 14C0 80103CC0 0800422A */  slti       $v0, $s2, 0x8
    /* 14C4 80103CC4 FAFF4014 */  bnez       $v0, .L80103CB0
    /* 14C8 80103CC8 04006324 */   addiu     $v1, $v1, 0x4
  .L80103CCC:
    /* 14CC 80103CCC 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 14D0 80103CD0 20005024 */  addiu      $s0, $v0, %lo(vs_main_settings)
    /* 14D4 80103CD4 1080023C */  lui        $v0, %hi(D_80106914)
    /* 14D8 80103CD8 1469428C */  lw         $v0, %lo(D_80106914)($v0)
    /* 14DC 80103CDC 01001292 */  lbu        $s2, 0x1($s0)
    /* 14E0 80103CE0 02004010 */  beqz       $v0, .L80103CEC
    /* 14E4 80103CE4 01000224 */   addiu     $v0, $zero, 0x1
    /* 14E8 80103CE8 010002A2 */  sb         $v0, 0x1($s0)
  .L80103CEC:
    /* 14EC 80103CEC 21206002 */  addu       $a0, $s3, $zero
    /* 14F0 80103CF0 0A020524 */  addiu      $a1, $zero, 0x20A
    /* 14F4 80103CF4 1000A627 */  addiu      $a2, $sp, 0x10
    /* 14F8 80103CF8 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 14FC 80103CFC 5000A727 */   addiu     $a3, $sp, 0x50
    /* 1500 80103D00 1080033C */  lui        $v1, %hi(D_8010690C)
    /* 1504 80103D04 01000224 */  addiu      $v0, $zero, 0x1
    /* 1508 80103D08 010012A2 */  sb         $s2, 0x1($s0)
    /* 150C 80103D0C 7F0F0408 */  j          .L80103DFC
    /* 1510 80103D10 0C6962AC */   sw        $v0, %lo(D_8010690C)($v1)
  .L80103D14:
    /* 1514 80103D14 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 1518 80103D18 1080103C */   lui       $s0, %hi(D_80106910)
    /* 151C 80103D1C 01004424 */  addiu      $a0, $v0, 0x1
    /* 1520 80103D20 26008010 */  beqz       $a0, .L80103DBC
    /* 1524 80103D24 106904AE */   sw        $a0, %lo(D_80106910)($s0)
    /* 1528 80103D28 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* 152C 80103D2C 6A4E4390 */  lbu        $v1, %lo(vs_battle_shortcutInvoked)($v0)
    /* 1530 80103D30 1080023C */  lui        $v0, %hi(vs_mainMenu_isLevelledSpell)
    /* 1534 80103D34 06006010 */  beqz       $v1, .L80103D50
    /* 1538 80103D38 D42240A0 */   sb        $zero, %lo(vs_mainMenu_isLevelledSpell)($v0)
    /* 153C 80103D3C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 1540 80103D40 0B008214 */  bne        $a0, $v0, .L80103D70
    /* 1544 80103D44 1080043C */   lui       $a0, %hi(D_80106910)
    /* 1548 80103D48 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 154C 80103D4C 106902AE */  sw         $v0, %lo(D_80106910)($s0)
  .L80103D50:
    /* 1550 80103D50 1069038E */  lw         $v1, %lo(D_80106910)($s0)
    /* 1554 80103D54 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 1558 80103D58 05006214 */  bne        $v1, $v0, .L80103D70
    /* 155C 80103D5C 1080043C */   lui       $a0, %hi(D_80106910)
    /* 1560 80103D60 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 1564 80103D64 21200000 */   addu      $a0, $zero, $zero
    /* 1568 80103D68 6C0F0408 */  j          .L80103DB0
    /* 156C 80103D6C 1080033C */   lui       $v1, %hi(D_8010690C)
  .L80103D70:
    /* 1570 80103D70 1069838C */  lw         $v1, %lo(D_80106910)($a0)
    /* 1574 80103D74 00000000 */  nop
    /* 1578 80103D78 06006018 */  blez       $v1, .L80103D94
    /* 157C 80103D7C 1080023C */   lui       $v0, %hi(_availableEnchanterSpells)
    /* 1580 80103D80 70694224 */  addiu      $v0, $v0, %lo(_availableEnchanterSpells)
    /* 1584 80103D84 21106200 */  addu       $v0, $v1, $v0
    /* 1588 80103D88 FFFF4290 */  lbu        $v0, -0x1($v0)
    /* 158C 80103D8C 00000000 */  nop
    /* 1590 80103D90 106982AC */  sw         $v0, %lo(D_80106910)($a0)
  .L80103D94:
    /* 1594 80103D94 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 1598 80103D98 28000424 */   addiu     $a0, $zero, 0x28
    /* 159C 80103D9C EAFE030C */  jal        func_800FFBA8
    /* 15A0 80103DA0 00000000 */   nop
    /* 15A4 80103DA4 A2FE030C */  jal        func_800FFA88
    /* 15A8 80103DA8 21200000 */   addu      $a0, $zero, $zero
    /* 15AC 80103DAC 1080033C */  lui        $v1, %hi(D_8010690C)
  .L80103DB0:
    /* 15B0 80103DB0 02000224 */  addiu      $v0, $zero, 0x2
    /* 15B4 80103DB4 7F0F0408 */  j          .L80103DFC
    /* 15B8 80103DB8 0C6962AC */   sw        $v0, %lo(D_8010690C)($v1)
  .L80103DBC:
    /* 15BC 80103DBC 1080103C */  lui        $s0, %hi(_availableEnchanterSpells)
    /* 15C0 80103DC0 2C02040C */  jal        func_801008B0
    /* 15C4 80103DC4 70691026 */   addiu     $s0, $s0, %lo(_availableEnchanterSpells)
    /* 15C8 80103DC8 21105000 */  addu       $v0, $v0, $s0
    /* 15CC 80103DCC 00004490 */  lbu        $a0, 0x0($v0)
    /* 15D0 80103DD0 210A040C */  jal        _setMPCost
    /* 15D4 80103DD4 00000000 */   nop
    /* 15D8 80103DD8 800F0408 */  j          .L80103E00
    /* 15DC 80103DDC 21100000 */   addu      $v0, $zero, $zero
  .L80103DE0:
    /* 15E0 80103DE0 74EA030C */  jal        vs_mainmenu_ready
    /* 15E4 80103DE4 00000000 */   nop
    /* 15E8 80103DE8 04004010 */  beqz       $v0, .L80103DFC
    /* 15EC 80103DEC 1080023C */   lui       $v0, %hi(D_80106910)
    /* 15F0 80103DF0 1069428C */  lw         $v0, %lo(D_80106910)($v0)
    /* 15F4 80103DF4 800F0408 */  j          .L80103E00
    /* 15F8 80103DF8 00000000 */   nop
  .L80103DFC:
    /* 15FC 80103DFC 21100000 */  addu       $v0, $zero, $zero
  .L80103E00:
    /* 1600 80103E00 9400BF8F */  lw         $ra, 0x94($sp)
    /* 1604 80103E04 9000BE8F */  lw         $fp, 0x90($sp)
    /* 1608 80103E08 8C00B78F */  lw         $s7, 0x8C($sp)
    /* 160C 80103E0C 8800B68F */  lw         $s6, 0x88($sp)
    /* 1610 80103E10 8400B58F */  lw         $s5, 0x84($sp)
    /* 1614 80103E14 8000B48F */  lw         $s4, 0x80($sp)
    /* 1618 80103E18 7C00B38F */  lw         $s3, 0x7C($sp)
    /* 161C 80103E1C 7800B28F */  lw         $s2, 0x78($sp)
    /* 1620 80103E20 7400B18F */  lw         $s1, 0x74($sp)
    /* 1624 80103E24 7000B08F */  lw         $s0, 0x70($sp)
    /* 1628 80103E28 0800E003 */  jr         $ra
    /* 162C 80103E2C 9800BD27 */   addiu     $sp, $sp, 0x98
endlabel _enchanterMagicMenu
