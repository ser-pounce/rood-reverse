nonmatching func_800A35A8, 0x138

glabel func_800A35A8
    /* 3ADA8 800A35A8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 3ADAC 800A35AC 2000B4AF */  sw         $s4, 0x20($sp)
    /* 3ADB0 800A35B0 02001424 */  addiu      $s4, $zero, 0x2
    /* 3ADB4 800A35B4 0F80023C */  lui        $v0, %hi(D_800F45E0)
    /* 3ADB8 800A35B8 2400B5AF */  sw         $s5, 0x24($sp)
    /* 3ADBC 800A35BC E0455524 */  addiu      $s5, $v0, %lo(D_800F45E0)
    /* 3ADC0 800A35C0 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 3ADC4 800A35C4 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 3ADC8 800A35C8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3ADCC 800A35CC 08005324 */  addiu      $s3, $v0, 0x8
    /* 3ADD0 800A35D0 2800BFAF */  sw         $ra, 0x28($sp)
    /* 3ADD4 800A35D4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3ADD8 800A35D8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3ADDC 800A35DC 1000B0AF */  sw         $s0, 0x10($sp)
  .L800A35E0:
    /* 3ADE0 800A35E0 0000708E */  lw         $s0, 0x0($s3)
    /* 3ADE4 800A35E4 00000000 */  nop
    /* 3ADE8 800A35E8 2F000012 */  beqz       $s0, .L800A36A8
    /* 3ADEC 800A35EC 2000023C */   lui       $v0, (0x200000 >> 16)
    /* 3ADF0 800A35F0 0800038E */  lw         $v1, 0x8($s0)
    /* 3ADF4 800A35F4 00000000 */  nop
    /* 3ADF8 800A35F8 24106200 */  and        $v0, $v1, $v0
    /* 3ADFC 800A35FC 2A004014 */  bnez       $v0, .L800A36A8
    /* 3AE00 800A3600 00000000 */   nop
    /* 3AE04 800A3604 5D000292 */  lbu        $v0, 0x5D($s0)
    /* 3AE08 800A3608 00000000 */  nop
    /* 3AE0C 800A360C 0200422C */  sltiu      $v0, $v0, 0x2
    /* 3AE10 800A3610 25004010 */  beqz       $v0, .L800A36A8
    /* 3AE14 800A3614 0700023C */   lui       $v0, (0x70000 >> 16)
    /* 3AE18 800A3618 24106200 */  and        $v0, $v1, $v0
    /* 3AE1C 800A361C 22004014 */  bnez       $v0, .L800A36A8
    /* 3AE20 800A3620 00000000 */   nop
    /* 3AE24 800A3624 1C001286 */  lh         $s2, 0x1C($s0)
    /* 3AE28 800A3628 20001186 */  lh         $s1, 0x20($s0)
    /* 3AE2C 800A362C 21204002 */  addu       $a0, $s2, $zero
    /* 3AE30 800A3630 8936020C */  jal        func_8008DA24
    /* 3AE34 800A3634 21282002 */   addu      $a1, $s1, $zero
    /* 3AE38 800A3638 40240200 */  sll        $a0, $v0, 17
    /* 3AE3C 800A363C 43240400 */  sra        $a0, $a0, 17
    /* 3AE40 800A3640 21300000 */  addu       $a2, $zero, $zero
    /* 3AE44 800A3644 2128A002 */  addu       $a1, $s5, $zero
  .L800A3648:
    /* 3AE48 800A3648 0000A38C */  lw         $v1, 0x0($a1)
    /* 3AE4C 800A364C 00000000 */  nop
    /* 3AE50 800A3650 10006010 */  beqz       $v1, .L800A3694
    /* 3AE54 800A3654 00000000 */   nop
    /* 3AE58 800A3658 1C006284 */  lh         $v0, 0x1C($v1)
    /* 3AE5C 800A365C 00000000 */  nop
    /* 3AE60 800A3660 0C005214 */  bne        $v0, $s2, .L800A3694
    /* 3AE64 800A3664 00000000 */   nop
    /* 3AE68 800A3668 20006284 */  lh         $v0, 0x20($v1)
    /* 3AE6C 800A366C 00000000 */  nop
    /* 3AE70 800A3670 08005114 */  bne        $v0, $s1, .L800A3694
    /* 3AE74 800A3674 00000000 */   nop
    /* 3AE78 800A3678 1E006284 */  lh         $v0, 0x1E($v1)
    /* 3AE7C 800A367C 00000000 */  nop
    /* 3AE80 800A3680 80FF4324 */  addiu      $v1, $v0, -0x80
    /* 3AE84 800A3684 2A106400 */  slt        $v0, $v1, $a0
    /* 3AE88 800A3688 02004010 */  beqz       $v0, .L800A3694
    /* 3AE8C 800A368C 00000000 */   nop
    /* 3AE90 800A3690 21206000 */  addu       $a0, $v1, $zero
  .L800A3694:
    /* 3AE94 800A3694 0100C624 */  addiu      $a2, $a2, 0x1
    /* 3AE98 800A3698 1000C228 */  slti       $v0, $a2, 0x10
    /* 3AE9C 800A369C EAFF4014 */  bnez       $v0, .L800A3648
    /* 3AEA0 800A36A0 0400A524 */   addiu     $a1, $a1, 0x4
    /* 3AEA4 800A36A4 1E0004A6 */  sh         $a0, 0x1E($s0)
  .L800A36A8:
    /* 3AEA8 800A36A8 01009426 */  addiu      $s4, $s4, 0x1
    /* 3AEAC 800A36AC 1100822A */  slti       $v0, $s4, 0x11
    /* 3AEB0 800A36B0 CBFF4014 */  bnez       $v0, .L800A35E0
    /* 3AEB4 800A36B4 04007326 */   addiu     $s3, $s3, 0x4
    /* 3AEB8 800A36B8 2800BF8F */  lw         $ra, 0x28($sp)
    /* 3AEBC 800A36BC 2400B58F */  lw         $s5, 0x24($sp)
    /* 3AEC0 800A36C0 2000B48F */  lw         $s4, 0x20($sp)
    /* 3AEC4 800A36C4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3AEC8 800A36C8 1800B28F */  lw         $s2, 0x18($sp)
    /* 3AECC 800A36CC 1400B18F */  lw         $s1, 0x14($sp)
    /* 3AED0 800A36D0 1000B08F */  lw         $s0, 0x10($sp)
    /* 3AED4 800A36D4 3000BD27 */  addiu      $sp, $sp, 0x30
    /* 3AED8 800A36D8 0800E003 */  jr         $ra
    /* 3AEDC 800A36DC 00000000 */   nop
endlabel func_800A35A8
