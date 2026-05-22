nonmatching _drawContent, 0x17C

glabel _drawContent
    /* 14F0 80103CF0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 14F4 80103CF4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 14F8 80103CF8 801F103C */  lui        $s0, (0x1F800000 >> 16)
    /* 14FC 80103CFC 0680023C */  lui        $v0, %hi(vs_main_frameBuf)
    /* 1500 80103D00 2400BFAF */  sw         $ra, 0x24($sp)
    /* 1504 80103D04 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1508 80103D08 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 150C 80103D0C 0000118E */  lw         $s1, (0x1F800000 & 0xFFFF)($s0)
    /* 1510 80103D10 10E2428C */  lw         $v0, %lo(vs_main_frameBuf)($v0)
    /* 1514 80103D14 21202002 */  addu       $a0, $s1, $zero
    /* 1518 80103D18 01004224 */  addiu      $v0, $v0, 0x1
    /* 151C 80103D1C 01004230 */  andi       $v0, $v0, 0x1
    /* 1520 80103D20 40280200 */  sll        $a1, $v0, 1
    /* 1524 80103D24 2128A200 */  addu       $a1, $a1, $v0
    /* 1528 80103D28 C0280500 */  sll        $a1, $a1, 3
    /* 152C 80103D2C 2328A200 */  subu       $a1, $a1, $v0
    /* 1530 80103D30 80280500 */  sll        $a1, $a1, 2
    /* 1534 80103D34 0680023C */  lui        $v0, %hi(vs_main_drawEnv)
    /* 1538 80103D38 D0E04224 */  addiu      $v0, $v0, %lo(vs_main_drawEnv)
    /* 153C 80103D3C F7A4000C */  jal        SetDrawArea
    /* 1540 80103D40 2128A200 */   addu      $a1, $a1, $v0
    /* 1544 80103D44 21282002 */  addu       $a1, $s1, $zero
    /* 1548 80103D48 0400048E */  lw         $a0, (0x1F800004 & 0xFFFF)($s0)
    /* 154C 80103D4C 35AD000C */  jal        AddPrim
    /* 1550 80103D50 0C003126 */   addiu     $s1, $s1, 0xC
    /* 1554 80103D54 9112040C */  jal        _drawContentLines
    /* 1558 80103D58 000011AE */   sw        $s1, (0x1F800000 & 0xFFFF)($s0)
    /* 155C 80103D5C 1080023C */  lui        $v0, %hi(_helpText)
    /* 1560 80103D60 5452448C */  lw         $a0, %lo(_helpText)($v0)
    /* 1564 80103D64 00000000 */  nop
    /* 1568 80103D68 0000828C */  lw         $v0, 0x0($a0)
    /* 156C 80103D6C 00000000 */  nop
    /* 1570 80103D70 02004104 */  bgez       $v0, .L80103D7C
    /* 1574 80103D74 00000000 */   nop
    /* 1578 80103D78 03004224 */  addiu      $v0, $v0, 0x3
  .L80103D7C:
    /* 157C 80103D7C 83100200 */  sra        $v0, $v0, 2
    /* 1580 80103D80 80100200 */  sll        $v0, $v0, 2
    /* 1584 80103D84 10004224 */  addiu      $v0, $v0, 0x10
    /* 1588 80103D88 21908200 */  addu       $s2, $a0, $v0
    /* 158C 80103D8C 00004296 */  lhu        $v0, 0x0($s2)
    /* 1590 80103D90 00000000 */  nop
    /* 1594 80103D94 0C004010 */  beqz       $v0, .L80103DC8
    /* 1598 80103D98 21800000 */   addu      $s0, $zero, $zero
    /* 159C 80103D9C 21884002 */  addu       $s1, $s2, $zero
  .L80103DA0:
    /* 15A0 80103DA0 02002496 */  lhu        $a0, 0x2($s1)
    /* 15A4 80103DA4 02003126 */  addiu      $s1, $s1, 0x2
    /* 15A8 80103DA8 40200400 */  sll        $a0, $a0, 1
    /* 15AC 80103DAC 9B0F040C */  jal        _drawSprite
    /* 15B0 80103DB0 21204402 */   addu      $a0, $s2, $a0
    /* 15B4 80103DB4 00004296 */  lhu        $v0, 0x0($s2)
    /* 15B8 80103DB8 01001026 */  addiu      $s0, $s0, 0x1
    /* 15BC 80103DBC 2A100202 */  slt        $v0, $s0, $v0
    /* 15C0 80103DC0 F7FF4014 */  bnez       $v0, .L80103DA0
    /* 15C4 80103DC4 00000000 */   nop
  .L80103DC8:
    /* 15C8 80103DC8 0680043C */  lui        $a0, %hi(vs_main_drawEnv)
    /* 15CC 80103DCC 0680023C */  lui        $v0, %hi(vs_main_frameBuf)
    /* 15D0 80103DD0 10E2438C */  lw         $v1, %lo(vs_main_frameBuf)($v0)
    /* 15D4 80103DD4 D0E08424 */  addiu      $a0, $a0, %lo(vs_main_drawEnv)
    /* 15D8 80103DD8 01006324 */  addiu      $v1, $v1, 0x1
    /* 15DC 80103DDC 01006330 */  andi       $v1, $v1, 0x1
    /* 15E0 80103DE0 40100300 */  sll        $v0, $v1, 1
    /* 15E4 80103DE4 21104300 */  addu       $v0, $v0, $v1
    /* 15E8 80103DE8 C0100200 */  sll        $v0, $v0, 3
    /* 15EC 80103DEC 23104300 */  subu       $v0, $v0, $v1
    /* 15F0 80103DF0 80100200 */  sll        $v0, $v0, 2
    /* 15F4 80103DF4 21104400 */  addu       $v0, $v0, $a0
    /* 15F8 80103DF8 00004284 */  lh         $v0, 0x0($v0)
    /* 15FC 80103DFC 00000000 */  nop
    /* 1600 80103E00 40014228 */  slti       $v0, $v0, 0x140
    /* 1604 80103E04 02004014 */  bnez       $v0, .L80103E10
    /* 1608 80103E08 0D000224 */   addiu     $v0, $zero, 0xD
    /* 160C 80103E0C 4D010224 */  addiu      $v0, $zero, 0x14D
  .L80103E10:
    /* 1610 80103E10 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 1614 80103E14 1000A527 */  addiu      $a1, $sp, 0x10
    /* 1618 80103E18 801F103C */  lui        $s0, (0x1F800000 >> 16)
    /* 161C 80103E1C 0000118E */  lw         $s1, (0x1F800000 & 0xFFFF)($s0)
    /* 1620 80103E20 2C010224 */  addiu      $v0, $zero, 0x12C
    /* 1624 80103E24 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 1628 80103E28 37000224 */  addiu      $v0, $zero, 0x37
    /* 162C 80103E2C 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 1630 80103E30 82000224 */  addiu      $v0, $zero, 0x82
    /* 1634 80103E34 1600A2A7 */  sh         $v0, 0x16($sp)
    /* 1638 80103E38 F7A4000C */  jal        SetDrawArea
    /* 163C 80103E3C 21202002 */   addu      $a0, $s1, $zero
    /* 1640 80103E40 21282002 */  addu       $a1, $s1, $zero
    /* 1644 80103E44 0400048E */  lw         $a0, (0x1F800004 & 0xFFFF)($s0)
    /* 1648 80103E48 35AD000C */  jal        AddPrim
    /* 164C 80103E4C 0C003126 */   addiu     $s1, $s1, 0xC
    /* 1650 80103E50 000011AE */  sw         $s1, (0x1F800000 & 0xFFFF)($s0)
    /* 1654 80103E54 2400BF8F */  lw         $ra, 0x24($sp)
    /* 1658 80103E58 2000B28F */  lw         $s2, 0x20($sp)
    /* 165C 80103E5C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1660 80103E60 1800B08F */  lw         $s0, 0x18($sp)
    /* 1664 80103E64 0800E003 */  jr         $ra
    /* 1668 80103E68 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _drawContent
