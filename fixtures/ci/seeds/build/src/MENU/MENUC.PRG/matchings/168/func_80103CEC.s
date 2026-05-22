nonmatching func_80103CEC, 0xA0

glabel func_80103CEC
    /* 14EC 80103CEC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 14F0 80103CF0 1800B0AF */  sw         $s0, 0x18($sp)
    /* 14F4 80103CF4 21808000 */  addu       $s0, $a0, $zero
    /* 14F8 80103CF8 03311000 */  sra        $a2, $s0, 4
    /* 14FC 80103CFC 833A1000 */  sra        $a3, $s0, 10
    /* 1500 80103D00 0F001032 */  andi       $s0, $s0, 0xF
    /* 1504 80103D04 20000424 */  addiu      $a0, $zero, 0x20
    /* 1508 80103D08 08000224 */  addiu      $v0, $zero, 0x8
    /* 150C 80103D0C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1510 80103D10 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 1514 80103D14 A424438C */  lw         $v1, %lo(vs_mainMenu_menu12Text)($v0)
    /* 1518 80103D18 40101000 */  sll        $v0, $s0, 1
    /* 151C 80103D1C 10000524 */  addiu      $a1, $zero, 0x10
    /* 1520 80103D20 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1524 80103D24 3F00D130 */  andi       $s1, $a2, 0x3F
    /* 1528 80103D28 2000B2AF */  sw         $s2, 0x20($sp)
    /* 152C 80103D2C 3F00F230 */  andi       $s2, $a3, 0x3F
    /* 1530 80103D30 12000624 */  addiu      $a2, $zero, 0x12
    /* 1534 80103D34 2400BFAF */  sw         $ra, 0x24($sp)
    /* 1538 80103D38 21104300 */  addu       $v0, $v0, $v1
    /* 153C 80103D3C 1A004294 */  lhu        $v0, 0x1A($v0)
    /* 1540 80103D40 A4000724 */  addiu      $a3, $zero, 0xA4
    /* 1544 80103D44 40100200 */  sll        $v0, $v0, 1
    /* 1548 80103D48 21186200 */  addu       $v1, $v1, $v0
    /* 154C 80103D4C 9723030C */  jal        vs_battle_setMenuItem
    /* 1550 80103D50 1400A3AF */   sw        $v1, 0x14($sp)
    /* 1554 80103D54 18000324 */  addiu      $v1, $zero, 0x18
    /* 1558 80103D58 090043A0 */  sb         $v1, 0x9($v0)
    /* 155C 80103D5C 01000324 */  addiu      $v1, $zero, 0x1
    /* 1560 80103D60 04000016 */  bnez       $s0, .L80103D74
    /* 1564 80103D64 060043A0 */   sb        $v1, 0x6($v0)
    /* 1568 80103D68 21202002 */  addu       $a0, $s1, $zero
    /* 156C 80103D6C 080F040C */  jal        func_80103C20
    /* 1570 80103D70 21284002 */   addu      $a1, $s2, $zero
  .L80103D74:
    /* 1574 80103D74 2400BF8F */  lw         $ra, 0x24($sp)
    /* 1578 80103D78 2000B28F */  lw         $s2, 0x20($sp)
    /* 157C 80103D7C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1580 80103D80 1800B08F */  lw         $s0, 0x18($sp)
    /* 1584 80103D84 0800E003 */  jr         $ra
    /* 1588 80103D88 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80103CEC
