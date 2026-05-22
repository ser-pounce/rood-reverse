nonmatching func_80103CC8, 0x15C

glabel func_80103CC8
    /* 14C8 80103CC8 28FEBD27 */  addiu      $sp, $sp, -0x1D8
    /* 14CC 80103CCC D001BEAF */  sw         $fp, 0x1D0($sp)
    /* 14D0 80103CD0 21F08000 */  addu       $fp, $a0, $zero
    /* 14D4 80103CD4 B001B0AF */  sw         $s0, 0x1B0($sp)
    /* 14D8 80103CD8 A801B027 */  addiu      $s0, $sp, 0x1A8
    /* 14DC 80103CDC 21200002 */  addu       $a0, $s0, $zero
    /* 14E0 80103CE0 08000524 */  addiu      $a1, $zero, 0x8
    /* 14E4 80103CE4 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 14E8 80103CE8 CC01B7AF */  sw         $s7, 0x1CC($sp)
    /* 14EC 80103CEC 68015724 */  addiu      $s7, $v0, %lo(vs_battle_inventory)
    /* 14F0 80103CF0 0680023C */  lui        $v0, %hi(vs_main_inventoryIndices)
    /* 14F4 80103CF4 C401B5AF */  sw         $s5, 0x1C4($sp)
    /* 14F8 80103CF8 D8195524 */  addiu      $s5, $v0, %lo(vs_main_inventoryIndices)
    /* 14FC 80103CFC D401BFAF */  sw         $ra, 0x1D4($sp)
    /* 1500 80103D00 C801B6AF */  sw         $s6, 0x1C8($sp)
    /* 1504 80103D04 C001B4AF */  sw         $s4, 0x1C0($sp)
    /* 1508 80103D08 BC01B3AF */  sw         $s3, 0x1BC($sp)
    /* 150C 80103D0C B801B2AF */  sw         $s2, 0x1B8($sp)
    /* 1510 80103D10 0733030C */  jal        vs_battle_rMemzero
    /* 1514 80103D14 B401B1AF */   sw        $s1, 0x1B4($sp)
    /* 1518 80103D18 21A00000 */  addu       $s4, $zero, $zero
    /* 151C 80103D1C 21B00002 */  addu       $s6, $s0, $zero
    /* 1520 80103D20 0080133C */  lui        $s3, (0x80000000 >> 16)
  .L80103D24:
    /* 1524 80103D24 21880000 */  addu       $s1, $zero, $zero
    /* 1528 80103D28 2110B102 */  addu       $v0, $s5, $s1
  .L80103D2C:
    /* 152C 80103D2C 00005090 */  lbu        $s0, 0x0($v0)
    /* 1530 80103D30 00000000 */  nop
    /* 1534 80103D34 0D000012 */  beqz       $s0, .L80103D6C
    /* 1538 80103D38 1000A427 */   addiu     $a0, $sp, 0x10
    /* 153C 80103D3C 40291000 */  sll        $a1, $s0, 5
    /* 1540 80103D40 E0FFA524 */  addiu      $a1, $a1, -0x20
    /* 1544 80103D44 ABAB010C */  jal        vs_battle_applyWeapon
    /* 1548 80103D48 2128E502 */   addu      $a1, $s7, $a1
    /* 154C 80103D4C 2120C003 */  addu       $a0, $fp, $zero
    /* 1550 80103D50 F90E040C */  jal        _getWeaponStat
    /* 1554 80103D54 1000A527 */   addiu     $a1, $sp, 0x10
    /* 1558 80103D58 21184000 */  addu       $v1, $v0, $zero
    /* 155C 80103D5C 2A106302 */  slt        $v0, $s3, $v1
    /* 1560 80103D60 02004010 */  beqz       $v0, .L80103D6C
    /* 1564 80103D64 00000000 */   nop
    /* 1568 80103D68 21986000 */  addu       $s3, $v1, $zero
  .L80103D6C:
    /* 156C 80103D6C 01003126 */  addiu      $s1, $s1, 0x1
    /* 1570 80103D70 0800222A */  slti       $v0, $s1, 0x8
    /* 1574 80103D74 EDFF4014 */  bnez       $v0, .L80103D2C
    /* 1578 80103D78 2110B102 */   addu      $v0, $s5, $s1
    /* 157C 80103D7C 0080023C */  lui        $v0, (0x80000000 >> 16)
    /* 1580 80103D80 18006212 */  beq        $s3, $v0, .L80103DE4
    /* 1584 80103D84 21880000 */   addu      $s1, $zero, $zero
    /* 1588 80103D88 2190B102 */  addu       $s2, $s5, $s1
  .L80103D8C:
    /* 158C 80103D8C 00005092 */  lbu        $s0, 0x0($s2)
    /* 1590 80103D90 00000000 */  nop
    /* 1594 80103D94 0D000012 */  beqz       $s0, .L80103DCC
    /* 1598 80103D98 1000A427 */   addiu     $a0, $sp, 0x10
    /* 159C 80103D9C 40291000 */  sll        $a1, $s0, 5
    /* 15A0 80103DA0 E0FFA524 */  addiu      $a1, $a1, -0x20
    /* 15A4 80103DA4 ABAB010C */  jal        vs_battle_applyWeapon
    /* 15A8 80103DA8 2128E502 */   addu      $a1, $s7, $a1
    /* 15AC 80103DAC 2120C003 */  addu       $a0, $fp, $zero
    /* 15B0 80103DB0 F90E040C */  jal        _getWeaponStat
    /* 15B4 80103DB4 1000A527 */   addiu     $a1, $sp, 0x10
    /* 15B8 80103DB8 04005314 */  bne        $v0, $s3, .L80103DCC
    /* 15BC 80103DBC 2110D402 */   addu      $v0, $s6, $s4
    /* 15C0 80103DC0 01009426 */  addiu      $s4, $s4, 0x1
    /* 15C4 80103DC4 000050A0 */  sb         $s0, 0x0($v0)
    /* 15C8 80103DC8 000040A2 */  sb         $zero, 0x0($s2)
  .L80103DCC:
    /* 15CC 80103DCC 01003126 */  addiu      $s1, $s1, 0x1
    /* 15D0 80103DD0 0800222A */  slti       $v0, $s1, 0x8
    /* 15D4 80103DD4 EDFF4014 */  bnez       $v0, .L80103D8C
    /* 15D8 80103DD8 2190B102 */   addu      $s2, $s5, $s1
    /* 15DC 80103DDC 490F0408 */  j          .L80103D24
    /* 15E0 80103DE0 0080133C */   lui       $s3, (0x80000000 >> 16)
  .L80103DE4:
    /* 15E4 80103DE4 2120A002 */  addu       $a0, $s5, $zero
    /* 15E8 80103DE8 A801A527 */  addiu      $a1, $sp, 0x1A8
    /* 15EC 80103DEC 7800030C */  jal        vs_battle_memcpy
    /* 15F0 80103DF0 08000624 */   addiu     $a2, $zero, 0x8
    /* 15F4 80103DF4 D401BF8F */  lw         $ra, 0x1D4($sp)
    /* 15F8 80103DF8 D001BE8F */  lw         $fp, 0x1D0($sp)
    /* 15FC 80103DFC CC01B78F */  lw         $s7, 0x1CC($sp)
    /* 1600 80103E00 C801B68F */  lw         $s6, 0x1C8($sp)
    /* 1604 80103E04 C401B58F */  lw         $s5, 0x1C4($sp)
    /* 1608 80103E08 C001B48F */  lw         $s4, 0x1C0($sp)
    /* 160C 80103E0C BC01B38F */  lw         $s3, 0x1BC($sp)
    /* 1610 80103E10 B801B28F */  lw         $s2, 0x1B8($sp)
    /* 1614 80103E14 B401B18F */  lw         $s1, 0x1B4($sp)
    /* 1618 80103E18 B001B08F */  lw         $s0, 0x1B0($sp)
    /* 161C 80103E1C 0800E003 */  jr         $ra
    /* 1620 80103E20 D801BD27 */   addiu     $sp, $sp, 0x1D8
endlabel func_80103CC8
