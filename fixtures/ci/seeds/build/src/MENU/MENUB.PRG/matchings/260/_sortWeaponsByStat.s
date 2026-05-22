nonmatching _sortWeaponsByStat, 0x15C

glabel _sortWeaponsByStat
    /* 15A0 80103DA0 28FEBD27 */  addiu      $sp, $sp, -0x1D8
    /* 15A4 80103DA4 D001BEAF */  sw         $fp, 0x1D0($sp)
    /* 15A8 80103DA8 21F08000 */  addu       $fp, $a0, $zero
    /* 15AC 80103DAC B001B0AF */  sw         $s0, 0x1B0($sp)
    /* 15B0 80103DB0 A801B027 */  addiu      $s0, $sp, 0x1A8
    /* 15B4 80103DB4 21200002 */  addu       $a0, $s0, $zero
    /* 15B8 80103DB8 08000524 */  addiu      $a1, $zero, 0x8
    /* 15BC 80103DBC 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 15C0 80103DC0 CC01B7AF */  sw         $s7, 0x1CC($sp)
    /* 15C4 80103DC4 68015724 */  addiu      $s7, $v0, %lo(vs_battle_inventory)
    /* 15C8 80103DC8 0680023C */  lui        $v0, %hi(vs_main_inventoryIndices)
    /* 15CC 80103DCC C401B5AF */  sw         $s5, 0x1C4($sp)
    /* 15D0 80103DD0 D8195524 */  addiu      $s5, $v0, %lo(vs_main_inventoryIndices)
    /* 15D4 80103DD4 D401BFAF */  sw         $ra, 0x1D4($sp)
    /* 15D8 80103DD8 C801B6AF */  sw         $s6, 0x1C8($sp)
    /* 15DC 80103DDC C001B4AF */  sw         $s4, 0x1C0($sp)
    /* 15E0 80103DE0 BC01B3AF */  sw         $s3, 0x1BC($sp)
    /* 15E4 80103DE4 B801B2AF */  sw         $s2, 0x1B8($sp)
    /* 15E8 80103DE8 0733030C */  jal        vs_battle_rMemzero
    /* 15EC 80103DEC B401B1AF */   sw        $s1, 0x1B4($sp)
    /* 15F0 80103DF0 21A00000 */  addu       $s4, $zero, $zero
    /* 15F4 80103DF4 21B00002 */  addu       $s6, $s0, $zero
    /* 15F8 80103DF8 0080133C */  lui        $s3, (0x80000000 >> 16)
  .L80103DFC:
    /* 15FC 80103DFC 21880000 */  addu       $s1, $zero, $zero
    /* 1600 80103E00 2110B102 */  addu       $v0, $s5, $s1
  .L80103E04:
    /* 1604 80103E04 00005090 */  lbu        $s0, 0x0($v0)
    /* 1608 80103E08 00000000 */  nop
    /* 160C 80103E0C 0D000012 */  beqz       $s0, .L80103E44
    /* 1610 80103E10 1000A427 */   addiu     $a0, $sp, 0x10
    /* 1614 80103E14 40291000 */  sll        $a1, $s0, 5
    /* 1618 80103E18 E0FFA524 */  addiu      $a1, $a1, -0x20
    /* 161C 80103E1C ABAB010C */  jal        vs_battle_applyWeapon
    /* 1620 80103E20 2128E502 */   addu      $a1, $s7, $a1
    /* 1624 80103E24 2120C003 */  addu       $a0, $fp, $zero
    /* 1628 80103E28 2F0F040C */  jal        _getWeaponStat
    /* 162C 80103E2C 1000A527 */   addiu     $a1, $sp, 0x10
    /* 1630 80103E30 21184000 */  addu       $v1, $v0, $zero
    /* 1634 80103E34 2A106302 */  slt        $v0, $s3, $v1
    /* 1638 80103E38 02004010 */  beqz       $v0, .L80103E44
    /* 163C 80103E3C 00000000 */   nop
    /* 1640 80103E40 21986000 */  addu       $s3, $v1, $zero
  .L80103E44:
    /* 1644 80103E44 01003126 */  addiu      $s1, $s1, 0x1
    /* 1648 80103E48 0800222A */  slti       $v0, $s1, 0x8
    /* 164C 80103E4C EDFF4014 */  bnez       $v0, .L80103E04
    /* 1650 80103E50 2110B102 */   addu      $v0, $s5, $s1
    /* 1654 80103E54 0080023C */  lui        $v0, (0x80000000 >> 16)
    /* 1658 80103E58 18006212 */  beq        $s3, $v0, .L80103EBC
    /* 165C 80103E5C 21880000 */   addu      $s1, $zero, $zero
    /* 1660 80103E60 2190B102 */  addu       $s2, $s5, $s1
  .L80103E64:
    /* 1664 80103E64 00005092 */  lbu        $s0, 0x0($s2)
    /* 1668 80103E68 00000000 */  nop
    /* 166C 80103E6C 0D000012 */  beqz       $s0, .L80103EA4
    /* 1670 80103E70 1000A427 */   addiu     $a0, $sp, 0x10
    /* 1674 80103E74 40291000 */  sll        $a1, $s0, 5
    /* 1678 80103E78 E0FFA524 */  addiu      $a1, $a1, -0x20
    /* 167C 80103E7C ABAB010C */  jal        vs_battle_applyWeapon
    /* 1680 80103E80 2128E502 */   addu      $a1, $s7, $a1
    /* 1684 80103E84 2120C003 */  addu       $a0, $fp, $zero
    /* 1688 80103E88 2F0F040C */  jal        _getWeaponStat
    /* 168C 80103E8C 1000A527 */   addiu     $a1, $sp, 0x10
    /* 1690 80103E90 04005314 */  bne        $v0, $s3, .L80103EA4
    /* 1694 80103E94 2110D402 */   addu      $v0, $s6, $s4
    /* 1698 80103E98 01009426 */  addiu      $s4, $s4, 0x1
    /* 169C 80103E9C 000050A0 */  sb         $s0, 0x0($v0)
    /* 16A0 80103EA0 000040A2 */  sb         $zero, 0x0($s2)
  .L80103EA4:
    /* 16A4 80103EA4 01003126 */  addiu      $s1, $s1, 0x1
    /* 16A8 80103EA8 0800222A */  slti       $v0, $s1, 0x8
    /* 16AC 80103EAC EDFF4014 */  bnez       $v0, .L80103E64
    /* 16B0 80103EB0 2190B102 */   addu      $s2, $s5, $s1
    /* 16B4 80103EB4 7F0F0408 */  j          .L80103DFC
    /* 16B8 80103EB8 0080133C */   lui       $s3, (0x80000000 >> 16)
  .L80103EBC:
    /* 16BC 80103EBC 2120A002 */  addu       $a0, $s5, $zero
    /* 16C0 80103EC0 A801A527 */  addiu      $a1, $sp, 0x1A8
    /* 16C4 80103EC4 7800030C */  jal        vs_battle_memcpy
    /* 16C8 80103EC8 08000624 */   addiu     $a2, $zero, 0x8
    /* 16CC 80103ECC D401BF8F */  lw         $ra, 0x1D4($sp)
    /* 16D0 80103ED0 D001BE8F */  lw         $fp, 0x1D0($sp)
    /* 16D4 80103ED4 CC01B78F */  lw         $s7, 0x1CC($sp)
    /* 16D8 80103ED8 C801B68F */  lw         $s6, 0x1C8($sp)
    /* 16DC 80103EDC C401B58F */  lw         $s5, 0x1C4($sp)
    /* 16E0 80103EE0 C001B48F */  lw         $s4, 0x1C0($sp)
    /* 16E4 80103EE4 BC01B38F */  lw         $s3, 0x1BC($sp)
    /* 16E8 80103EE8 B801B28F */  lw         $s2, 0x1B8($sp)
    /* 16EC 80103EEC B401B18F */  lw         $s1, 0x1B4($sp)
    /* 16F0 80103EF0 B001B08F */  lw         $s0, 0x1B0($sp)
    /* 16F4 80103EF4 0800E003 */  jr         $ra
    /* 16F8 80103EF8 D801BD27 */   addiu     $sp, $sp, 0x1D8
endlabel _sortWeaponsByStat
