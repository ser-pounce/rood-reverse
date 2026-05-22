nonmatching _insertDeleteHandler, 0x194

glabel _insertDeleteHandler
    /* 1588 80103D88 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 158C 80103D8C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1590 80103D90 21808000 */  addu       $s0, $a0, $zero
    /* 1594 80103D94 1080033C */  lui        $v1, %hi(D_80105DB0)
    /* 1598 80103D98 01000224 */  addiu      $v0, $zero, 0x1
    /* 159C 80103D9C B05D62A0 */  sb         $v0, %lo(D_80105DB0)($v1)
    /* 15A0 80103DA0 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 15A4 80103DA4 DCDF448C */  lw         $a0, %lo(vs_main_buttonRepeat)($v0)
    /* 15A8 80103DA8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 15AC 80103DAC 21880002 */  addu       $s1, $s0, $zero
    /* 15B0 80103DB0 10008230 */  andi       $v0, $a0, 0x10
    /* 15B4 80103DB4 17004010 */  beqz       $v0, .L80103E14
    /* 15B8 80103DB8 1800BFAF */   sw        $ra, 0x18($sp)
    /* 15BC 80103DBC BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 15C0 80103DC0 00000000 */   nop
    /* 15C4 80103DC4 13000324 */  addiu      $v1, $zero, 0x13
    /* 15C8 80103DC8 2A100302 */  slt        $v0, $s0, $v1
    /* 15CC 80103DCC 0B004010 */  beqz       $v0, .L80103DFC
    /* 15D0 80103DD0 1080023C */   lui       $v0, %hi(_stringBuf)
    /* 15D4 80103DD4 405F4524 */  addiu      $a1, $v0, %lo(_stringBuf)
    /* 15D8 80103DD8 21206500 */  addu       $a0, $v1, $a1
  .L80103DDC:
    /* 15DC 80103DDC FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 15E0 80103DE0 21106500 */  addu       $v0, $v1, $a1
    /* 15E4 80103DE4 00004290 */  lbu        $v0, 0x0($v0)
    /* 15E8 80103DE8 00000000 */  nop
    /* 15EC 80103DEC 000082A0 */  sb         $v0, 0x0($a0)
    /* 15F0 80103DF0 2A100302 */  slt        $v0, $s0, $v1
    /* 15F4 80103DF4 F9FF4014 */  bnez       $v0, .L80103DDC
    /* 15F8 80103DF8 21206500 */   addu      $a0, $v1, $a1
  .L80103DFC:
    /* 15FC 80103DFC 1080023C */  lui        $v0, %hi(_stringBuf)
    /* 1600 80103E00 405F4224 */  addiu      $v0, $v0, %lo(_stringBuf)
    /* 1604 80103E04 21100202 */  addu       $v0, $s0, $v0
    /* 1608 80103E08 8F000324 */  addiu      $v1, $zero, 0x8F
    /* 160C 80103E0C BD0F0408 */  j          .L80103EF4
    /* 1610 80103E10 000043A0 */   sb        $v1, 0x0($v0)
  .L80103E14:
    /* 1614 80103E14 80008230 */  andi       $v0, $a0, 0x80
    /* 1618 80103E18 15004010 */  beqz       $v0, .L80103E70
    /* 161C 80103E1C 0680023C */   lui       $v0, %hi(vs_main_buttonsState)
    /* 1620 80103E20 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 1624 80103E24 00000000 */   nop
    /* 1628 80103E28 1300022A */  slti       $v0, $s0, 0x13
    /* 162C 80103E2C 0C004010 */  beqz       $v0, .L80103E60
    /* 1630 80103E30 21180002 */   addu      $v1, $s0, $zero
    /* 1634 80103E34 1080023C */  lui        $v0, %hi(_stringBuf)
    /* 1638 80103E38 405F4524 */  addiu      $a1, $v0, %lo(_stringBuf)
    /* 163C 80103E3C 21206500 */  addu       $a0, $v1, $a1
  .L80103E40:
    /* 1640 80103E40 01006324 */  addiu      $v1, $v1, 0x1
    /* 1644 80103E44 21106500 */  addu       $v0, $v1, $a1
    /* 1648 80103E48 00004290 */  lbu        $v0, 0x0($v0)
    /* 164C 80103E4C 00000000 */  nop
    /* 1650 80103E50 000082A0 */  sb         $v0, 0x0($a0)
    /* 1654 80103E54 13006228 */  slti       $v0, $v1, 0x13
    /* 1658 80103E58 F9FF4014 */  bnez       $v0, .L80103E40
    /* 165C 80103E5C 21206500 */   addu      $a0, $v1, $a1
  .L80103E60:
    /* 1660 80103E60 1080033C */  lui        $v1, %hi(D_80105F53)
    /* 1664 80103E64 8F000224 */  addiu      $v0, $zero, 0x8F
    /* 1668 80103E68 BD0F0408 */  j          .L80103EF4
    /* 166C 80103E6C 535F62A0 */   sb        $v0, %lo(D_80105F53)($v1)
  .L80103E70:
    /* 1670 80103E70 38E2428C */  lw         $v0, %lo(vs_main_buttonsState)($v0)
    /* 1674 80103E74 0C000324 */  addiu      $v1, $zero, 0xC
    /* 1678 80103E78 0C004230 */  andi       $v0, $v0, 0xC
    /* 167C 80103E7C 1D004310 */  beq        $v0, $v1, .L80103EF4
    /* 1680 80103E80 04008230 */   andi      $v0, $a0, 0x4
    /* 1684 80103E84 0C004010 */  beqz       $v0, .L80103EB8
    /* 1688 80103E88 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 168C 80103E8C 08000016 */  bnez       $s0, .L80103EB0
    /* 1690 80103E90 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 1694 80103E94 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 1698 80103E98 00000000 */  nop
    /* 169C 80103E9C 04004230 */  andi       $v0, $v0, 0x4
    /* 16A0 80103EA0 05004010 */  beqz       $v0, .L80103EB8
    /* 16A4 80103EA4 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 16A8 80103EA8 AE0F0408 */  j          .L80103EB8
    /* 16AC 80103EAC 13001024 */   addiu     $s0, $zero, 0x13
  .L80103EB0:
    /* 16B0 80103EB0 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 16B4 80103EB4 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
  .L80103EB8:
    /* 16B8 80103EB8 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 16BC 80103EBC 00000000 */  nop
    /* 16C0 80103EC0 08004230 */  andi       $v0, $v0, 0x8
    /* 16C4 80103EC4 0B004010 */  beqz       $v0, .L80103EF4
    /* 16C8 80103EC8 13000224 */   addiu     $v0, $zero, 0x13
    /* 16CC 80103ECC 08000216 */  bne        $s0, $v0, .L80103EF0
    /* 16D0 80103ED0 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 16D4 80103ED4 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 16D8 80103ED8 00000000 */  nop
    /* 16DC 80103EDC 08004230 */  andi       $v0, $v0, 0x8
    /* 16E0 80103EE0 04004010 */  beqz       $v0, .L80103EF4
    /* 16E4 80103EE4 00000000 */   nop
    /* 16E8 80103EE8 BD0F0408 */  j          .L80103EF4
    /* 16EC 80103EEC 21800000 */   addu      $s0, $zero, $zero
  .L80103EF0:
    /* 16F0 80103EF0 01001026 */  addiu      $s0, $s0, 0x1
  .L80103EF4:
    /* 16F4 80103EF4 04001112 */  beq        $s0, $s1, .L80103F08
    /* 16F8 80103EF8 21100002 */   addu      $v0, $s0, $zero
    /* 16FC 80103EFC BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 1700 80103F00 00000000 */   nop
    /* 1704 80103F04 21100002 */  addu       $v0, $s0, $zero
  .L80103F08:
    /* 1708 80103F08 1800BF8F */  lw         $ra, 0x18($sp)
    /* 170C 80103F0C 1400B18F */  lw         $s1, 0x14($sp)
    /* 1710 80103F10 1000B08F */  lw         $s0, 0x10($sp)
    /* 1714 80103F14 0800E003 */  jr         $ra
    /* 1718 80103F18 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _insertDeleteHandler
