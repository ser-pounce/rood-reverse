nonmatching vs_mainMenu_initSetWeaponGemMenu, 0x1F4

glabel vs_mainMenu_initSetWeaponGemMenu
    /* 2D10 800FC510 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 2D14 800FC514 3800B4AF */  sw         $s4, 0x38($sp)
    /* 2D18 800FC518 21A08000 */  addu       $s4, $a0, $zero
    /* 2D1C 800FC51C 3000B2AF */  sw         $s2, 0x30($sp)
    /* 2D20 800FC520 21900000 */  addu       $s2, $zero, $zero
    /* 2D24 800FC524 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 2D28 800FC528 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 2D2C 800FC52C 21A8C000 */  addu       $s5, $a2, $zero
    /* 2D30 800FC530 1080023C */  lui        $v0, %hi(vs_mainMenu_weapons)
    /* 2D34 800FC534 40290500 */  sll        $a1, $a1, 5
    /* 2D38 800FC538 7024428C */  lw         $v0, %lo(vs_mainMenu_weapons)($v0)
    /* 2D3C 800FC53C E0FFA524 */  addiu      $a1, $a1, -0x20
    /* 2D40 800FC540 4000BFAF */  sw         $ra, 0x40($sp)
    /* 2D44 800FC544 3400B3AF */  sw         $s3, 0x34($sp)
    /* 2D48 800FC548 2800B0AF */  sw         $s0, 0x28($sp)
    /* 2D4C 800FC54C 21404500 */  addu       $t0, $v0, $a1
    /* 2D50 800FC550 1080023C */  lui        $v0, %hi(vs_mainMenu_grips)
    /* 2D54 800FC554 02000391 */  lbu        $v1, 0x2($t0)
    /* 2D58 800FC558 6024468C */  lw         $a2, %lo(vs_mainMenu_grips)($v0)
    /* 2D5C 800FC55C 00210300 */  sll        $a0, $v1, 4
    /* 2D60 800FC560 21108600 */  addu       $v0, $a0, $a2
    /* 2D64 800FC564 01000324 */  addiu      $v1, $zero, 0x1
    /* 2D68 800FC568 F4FF4590 */  lbu        $a1, -0xC($v0)
    /* 2D6C 800FC56C 12008316 */  bne        $s4, $v1, .L800FC5B8
    /* 2D70 800FC570 9E001124 */   addiu     $s1, $zero, 0x9E
    /* 2D74 800FC574 1800A527 */  addiu      $a1, $sp, 0x18
    /* 2D78 800FC578 2000A627 */  addiu      $a2, $sp, 0x20
    /* 2D7C 800FC57C 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 2D80 800FC580 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 2D84 800FC584 01000291 */  lbu        $v0, 0x1($t0)
    /* 2D88 800FC588 1080033C */  lui        $v1, %hi(vs_mainMenu_blades)
    /* 2D8C 800FC58C 40200200 */  sll        $a0, $v0, 1
    /* 2D90 800FC590 21208200 */  addu       $a0, $a0, $v0
    /* 2D94 800FC594 80200400 */  sll        $a0, $a0, 2
    /* 2D98 800FC598 23208200 */  subu       $a0, $a0, $v0
    /* 2D9C 800FC59C 80200400 */  sll        $a0, $a0, 2
    /* 2DA0 800FC5A0 6424628C */  lw         $v0, %lo(vs_mainMenu_blades)($v1)
    /* 2DA4 800FC5A4 D4FF8424 */  addiu      $a0, $a0, -0x2C
    /* 2DA8 800FC5A8 A9F2030C */  jal        vs_mainMenu_setUiBlade
    /* 2DAC 800FC5AC 21204400 */   addu      $a0, $v0, $a0
    /* 2DB0 800FC5B0 97F10308 */  j          .L800FC65C
    /* 2DB4 800FC5B4 0A009026 */   addiu     $s0, $s4, 0xA
  .L800FC5B8:
    /* 2DB8 800FC5B8 02000224 */  addiu      $v0, $zero, 0x2
    /* 2DBC 800FC5BC 09008216 */  bne        $s4, $v0, .L800FC5E4
    /* 2DC0 800FC5C0 F0FF8424 */   addiu     $a0, $a0, -0x10
    /* 2DC4 800FC5C4 2120C400 */  addu       $a0, $a2, $a0
    /* 2DC8 800FC5C8 1800A527 */  addiu      $a1, $sp, 0x18
    /* 2DCC 800FC5CC 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 2DD0 800FC5D0 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 2DD4 800FC5D4 03F3030C */  jal        vs_mainMenu_setUiGrip
    /* 2DD8 800FC5D8 2000A627 */   addiu     $a2, $sp, 0x20
    /* 2DDC 800FC5DC 97F10308 */  j          .L800FC65C
    /* 2DE0 800FC5E0 0A009026 */   addiu     $s0, $s4, 0xA
  .L800FC5E4:
    /* 2DE4 800FC5E4 FDFF9126 */  addiu      $s1, $s4, -0x3
    /* 2DE8 800FC5E8 2A102502 */  slt        $v0, $s1, $a1
    /* 2DEC 800FC5EC 19004010 */  beqz       $v0, .L800FC654
    /* 2DF0 800FC5F0 1080023C */   lui       $v0, %hi(vs_mainMenu_itemHelp)
    /* 2DF4 800FC5F4 4025428C */  lw         $v0, %lo(vs_mainMenu_itemHelp)($v0)
    /* 2DF8 800FC5F8 0058033C */  lui        $v1, (0x58000000 >> 16)
    /* 2DFC 800FC5FC 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 2E00 800FC600 2000A3AF */  sw         $v1, 0x20($sp)
    /* 2E04 800FC604 16684224 */  addiu      $v0, $v0, 0x6816
    /* 2E08 800FC608 1800A2AF */  sw         $v0, 0x18($sp)
    /* 2E0C 800FC60C 21101101 */  addu       $v0, $t0, $s1
    /* 2E10 800FC610 04004390 */  lbu        $v1, 0x4($v0)
    /* 2E14 800FC614 00000000 */  nop
    /* 2E18 800FC618 0C006010 */  beqz       $v1, .L800FC64C
    /* 2E1C 800FC61C 1800A527 */   addiu     $a1, $sp, 0x18
    /* 2E20 800FC620 2000A627 */  addiu      $a2, $sp, 0x20
    /* 2E24 800FC624 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 2E28 800FC628 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 2E2C 800FC62C 1080023C */  lui        $v0, %hi(vs_mainMenu_gems)
    /* 2E30 800FC630 C0200300 */  sll        $a0, $v1, 3
    /* 2E34 800FC634 23208300 */  subu       $a0, $a0, $v1
    /* 2E38 800FC638 80200400 */  sll        $a0, $a0, 2
    /* 2E3C 800FC63C 5824428C */  lw         $v0, %lo(vs_mainMenu_gems)($v0)
    /* 2E40 800FC640 E4FF8424 */  addiu      $a0, $a0, -0x1C
    /* 2E44 800FC644 38F4030C */  jal        vs_mainMenu_setUiGem
    /* 2E48 800FC648 21204400 */   addu      $a0, $v0, $a0
  .L800FC64C:
    /* 2E4C 800FC64C 96F10308 */  j          .L800FC658
    /* 2E50 800FC650 97001124 */   addiu     $s1, $zero, 0x97
  .L800FC654:
    /* 2E54 800FC654 21880000 */  addu       $s1, $zero, $zero
  .L800FC658:
    /* 2E58 800FC658 0A009026 */  addiu      $s0, $s4, 0xA
  .L800FC65C:
    /* 2E5C 800FC65C E4FE030C */  jal        vs_mainMenu_deactivateMenuItem
    /* 2E60 800FC660 21200002 */   addu      $a0, $s0, $zero
    /* 2E64 800FC664 1D002012 */  beqz       $s1, .L800FC6DC
    /* 2E68 800FC668 21200002 */   addu      $a0, $s0, $zero
    /* 2E6C 800FC66C 40011324 */  addiu      $s3, $zero, 0x140
    /* 2E70 800FC670 23807102 */  subu       $s0, $s3, $s1
    /* 2E74 800FC674 21280002 */  addu       $a1, $s0, $zero
    /* 2E78 800FC678 00311400 */  sll        $a2, $s4, 4
    /* 2E7C 800FC67C 1200C624 */  addiu      $a2, $a2, 0x12
    /* 2E80 800FC680 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2E84 800FC684 1800A28F */  lw         $v0, 0x18($sp)
    /* 2E88 800FC688 21382002 */  addu       $a3, $s1, $zero
    /* 2E8C 800FC68C 9723030C */  jal        vs_battle_setMenuItem
    /* 2E90 800FC690 1400A2AF */   sw        $v0, 0x14($sp)
    /* 2E94 800FC694 21904000 */  addu       $s2, $v0, $zero
    /* 2E98 800FC698 1C00A38F */  lw         $v1, 0x1C($sp)
    /* 2E9C 800FC69C 0100A232 */  andi       $v0, $s5, 0x1
    /* 2EA0 800FC6A0 0100632C */  sltiu      $v1, $v1, 0x1
    /* 2EA4 800FC6A4 05004010 */  beqz       $v0, .L800FC6BC
    /* 2EA8 800FC6A8 070043A2 */   sb        $v1, 0x7($s2)
    /* 2EAC 800FC6AC 02000224 */  addiu      $v0, $zero, 0x2
    /* 2EB0 800FC6B0 140053A6 */  sh         $s3, 0x14($s2)
    /* 2EB4 800FC6B4 000042A2 */  sb         $v0, 0x0($s2)
    /* 2EB8 800FC6B8 180050A6 */  sh         $s0, 0x18($s2)
  .L800FC6BC:
    /* 2EBC 800FC6BC 2000A28F */  lw         $v0, 0x20($sp)
    /* 2EC0 800FC6C0 00000000 */  nop
    /* 2EC4 800FC6C4 82160200 */  srl        $v0, $v0, 26
    /* 2EC8 800FC6C8 090042A2 */  sb         $v0, 0x9($s2)
    /* 2ECC 800FC6CC 2200A297 */  lhu        $v0, 0x22($sp)
    /* 2ED0 800FC6D0 00000000 */  nop
    /* 2ED4 800FC6D4 07004230 */  andi       $v0, $v0, 0x7
    /* 2ED8 800FC6D8 0C0042A2 */  sb         $v0, 0xC($s2)
  .L800FC6DC:
    /* 2EDC 800FC6DC 21104002 */  addu       $v0, $s2, $zero
    /* 2EE0 800FC6E0 4000BF8F */  lw         $ra, 0x40($sp)
    /* 2EE4 800FC6E4 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 2EE8 800FC6E8 3800B48F */  lw         $s4, 0x38($sp)
    /* 2EEC 800FC6EC 3400B38F */  lw         $s3, 0x34($sp)
    /* 2EF0 800FC6F0 3000B28F */  lw         $s2, 0x30($sp)
    /* 2EF4 800FC6F4 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 2EF8 800FC6F8 2800B08F */  lw         $s0, 0x28($sp)
    /* 2EFC 800FC6FC 0800E003 */  jr         $ra
    /* 2F00 800FC700 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel vs_mainMenu_initSetWeaponGemMenu
