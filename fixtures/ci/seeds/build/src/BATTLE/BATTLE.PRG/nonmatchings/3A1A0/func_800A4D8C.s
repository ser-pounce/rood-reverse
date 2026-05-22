nonmatching func_800A4D8C, 0xDC

glabel func_800A4D8C
    /* 3C58C 800A4D8C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3C590 800A4D90 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3C594 800A4D94 21800000 */  addu       $s0, $zero, $zero
    /* 3C598 800A4D98 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3C59C 800A4D9C 0680123C */  lui        $s2, %hi(vs_gametime_tickspeed)
    /* 3C5A0 800A4DA0 0F80023C */  lui        $v0, %hi(D_800F45E0)
    /* 3C5A4 800A4DA4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3C5A8 800A4DA8 E0455124 */  addiu      $s1, $v0, %lo(D_800F45E0)
    /* 3C5AC 800A4DAC 1C00BFAF */  sw         $ra, 0x1C($sp)
  .L800A4DB0:
    /* 3C5B0 800A4DB0 0000248E */  lw         $a0, 0x0($s1)
    /* 3C5B4 800A4DB4 00000000 */  nop
    /* 3C5B8 800A4DB8 0B008010 */  beqz       $a0, .L800A4DE8
    /* 3C5BC 800A4DBC 00000000 */   nop
    /* 3C5C0 800A4DC0 00008290 */  lbu        $v0, 0x0($a0)
    /* 3C5C4 800A4DC4 00000000 */  nop
    /* 3C5C8 800A4DC8 07004010 */  beqz       $v0, .L800A4DE8
    /* 3C5CC 800A4DCC 00000000 */   nop
    /* 3C5D0 800A4DD0 4CE2458E */  lw         $a1, %lo(vs_gametime_tickspeed)($s2)
    /* 3C5D4 800A4DD4 00000000 */  nop
    /* 3C5D8 800A4DD8 C2170500 */  srl        $v0, $a1, 31
    /* 3C5DC 800A4DDC 2128A200 */  addu       $a1, $a1, $v0
    /* 3C5E0 800A4DE0 42C2020C */  jal        func_800B0908
    /* 3C5E4 800A4DE4 43280500 */   sra       $a1, $a1, 1
  .L800A4DE8:
    /* 3C5E8 800A4DE8 01001026 */  addiu      $s0, $s0, 0x1
    /* 3C5EC 800A4DEC 1000022A */  slti       $v0, $s0, 0x10
    /* 3C5F0 800A4DF0 EFFF4014 */  bnez       $v0, .L800A4DB0
    /* 3C5F4 800A4DF4 04003126 */   addiu     $s1, $s1, 0x4
    /* 3C5F8 800A4DF8 21800000 */  addu       $s0, $zero, $zero
    /* 3C5FC 800A4DFC 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 3C600 800A4E00 38455124 */  addiu      $s1, $v0, %lo(D_800F4538)
  .L800A4E04:
    /* 3C604 800A4E04 0000228E */  lw         $v0, 0x0($s1)
    /* 3C608 800A4E08 00000000 */  nop
    /* 3C60C 800A4E0C 08004010 */  beqz       $v0, .L800A4E30
    /* 3C610 800A4E10 00000000 */   nop
    /* 3C614 800A4E14 0800428C */  lw         $v0, 0x8($v0)
    /* 3C618 800A4E18 00000000 */  nop
    /* 3C61C 800A4E1C 01004230 */  andi       $v0, $v0, 0x1
    /* 3C620 800A4E20 03004014 */  bnez       $v0, .L800A4E30
    /* 3C624 800A4E24 00000000 */   nop
    /* 3C628 800A4E28 9A93020C */  jal        func_800A4E68
    /* 3C62C 800A4E2C 21200002 */   addu      $a0, $s0, $zero
  .L800A4E30:
    /* 3C630 800A4E30 01001026 */  addiu      $s0, $s0, 0x1
    /* 3C634 800A4E34 1100022A */  slti       $v0, $s0, 0x11
    /* 3C638 800A4E38 F2FF4014 */  bnez       $v0, .L800A4E04
    /* 3C63C 800A4E3C 04003126 */   addiu     $s1, $s1, 0x4
    /* 3C640 800A4E40 0F80033C */  lui        $v1, %hi(D_800F4B18)
    /* 3C644 800A4E44 01000224 */  addiu      $v0, $zero, 0x1
    /* 3C648 800A4E48 184B62A0 */  sb         $v0, %lo(D_800F4B18)($v1)
    /* 3C64C 800A4E4C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3C650 800A4E50 1800B28F */  lw         $s2, 0x18($sp)
    /* 3C654 800A4E54 1400B18F */  lw         $s1, 0x14($sp)
    /* 3C658 800A4E58 1000B08F */  lw         $s0, 0x10($sp)
    /* 3C65C 800A4E5C 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 3C660 800A4E60 0800E003 */  jr         $ra
    /* 3C664 800A4E64 00000000 */   nop
endlabel func_800A4D8C
