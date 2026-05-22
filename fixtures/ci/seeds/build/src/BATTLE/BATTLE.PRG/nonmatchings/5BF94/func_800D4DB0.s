nonmatching func_800D4DB0, 0xAC

glabel func_800D4DB0
    /* 6C5B0 800D4DB0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C5B4 800D4DB4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C5B8 800D4DB8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6C5BC 800D4DBC 5C54030C */  jal        func_800D5170
    /* 6C5C0 800D4DC0 21808000 */   addu      $s0, $a0, $zero
    /* 6C5C4 800D4DC4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 6C5C8 800D4DC8 21100202 */  addu       $v0, $s0, $v0
    /* 6C5CC 800D4DCC 0400038E */  lw         $v1, 0x4($s0)
    /* 6C5D0 800D4DD0 10004590 */  lbu        $a1, 0x10($v0)
    /* 6C5D4 800D4DD4 19006014 */  bnez       $v1, .L800D4E3C
    /* 6C5D8 800D4DD8 21200002 */   addu      $a0, $s0, $zero
    /* 6C5DC 800D4DDC FF00A330 */  andi       $v1, $a1, 0xFF
    /* 6C5E0 800D4DE0 0400622C */  sltiu      $v0, $v1, 0x4
    /* 6C5E4 800D4DE4 15004010 */  beqz       $v0, .L800D4E3C
    /* 6C5E8 800D4DE8 0F80023C */   lui       $v0, %hi(D_800F569C)
    /* 6C5EC 800D4DEC 9C56448C */  lw         $a0, %lo(D_800F569C)($v0)
    /* 6C5F0 800D4DF0 00000000 */  nop
    /* 6C5F4 800D4DF4 B400828C */  lw         $v0, 0xB4($a0)
    /* 6C5F8 800D4DF8 00000000 */  nop
    /* 6C5FC 800D4DFC 21104300 */  addu       $v0, $v0, $v1
    /* 6C600 800D4E00 16004390 */  lbu        $v1, 0x16($v0)
    /* 6C604 800D4E04 00000000 */  nop
    /* 6C608 800D4E08 0B006010 */  beqz       $v1, .L800D4E38
    /* 6C60C 800D4E0C 00000000 */   nop
    /* 6C610 800D4E10 BC00828C */  lw         $v0, 0xBC($a0)
    /* 6C614 800D4E14 00000000 */  nop
    /* 6C618 800D4E18 08004010 */  beqz       $v0, .L800D4E3C
    /* 6C61C 800D4E1C 21200002 */   addu      $a0, $s0, $zero
    /* 6C620 800D4E20 0000428C */  lw         $v0, 0x0($v0)
    /* 6C624 800D4E24 00000000 */  nop
    /* 6C628 800D4E28 2A106200 */  slt        $v0, $v1, $v0
    /* 6C62C 800D4E2C 04004010 */  beqz       $v0, .L800D4E40
    /* 6C630 800D4E30 FF00A530 */   andi      $a1, $a1, 0xFF
    /* 6C634 800D4E34 FFFF6524 */  addiu      $a1, $v1, -0x1
  .L800D4E38:
    /* 6C638 800D4E38 21200002 */  addu       $a0, $s0, $zero
  .L800D4E3C:
    /* 6C63C 800D4E3C FF00A530 */  andi       $a1, $a1, 0xFF
  .L800D4E40:
    /* 6C640 800D4E40 6955030C */  jal        func_800D55A4
    /* 6C644 800D4E44 21300000 */   addu      $a2, $zero, $zero
    /* 6C648 800D4E48 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6C64C 800D4E4C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C650 800D4E50 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C654 800D4E54 0800E003 */  jr         $ra
    /* 6C658 800D4E58 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D4DB0
