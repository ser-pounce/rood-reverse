nonmatching func_8009CE9C, 0x104

glabel func_8009CE9C
    /* 3469C 8009CE9C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 346A0 8009CEA0 2000B4AF */  sw         $s4, 0x20($sp)
    /* 346A4 8009CEA4 21A08000 */  addu       $s4, $a0, $zero
    /* 346A8 8009CEA8 FFFF8226 */  addiu      $v0, $s4, -0x1
    /* 346AC 8009CEAC 0300422C */  sltiu      $v0, $v0, 0x3
    /* 346B0 8009CEB0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 346B4 8009CEB4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 346B8 8009CEB8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 346BC 8009CEBC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 346C0 8009CEC0 03004014 */  bnez       $v0, .L8009CED0
    /* 346C4 8009CEC4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 346C8 8009CEC8 DF730208 */  j          .L8009CF7C
    /* 346CC 8009CECC FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8009CED0:
    /* 346D0 8009CED0 21900000 */  addu       $s2, $zero, $zero
    /* 346D4 8009CED4 FF001324 */  addiu      $s3, $zero, 0xFF
    /* 346D8 8009CED8 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 346DC 8009CEDC 38455124 */  addiu      $s1, $v0, %lo(D_800F4538)
  .L8009CEE0:
    /* 346E0 8009CEE0 0000308E */  lw         $s0, 0x0($s1)
    /* 346E4 8009CEE4 00000000 */  nop
    /* 346E8 8009CEE8 1C000012 */  beqz       $s0, .L8009CF5C
    /* 346EC 8009CEEC 0F80023C */   lui       $v0, %hi(D_800E8F2C)
    /* 346F0 8009CEF0 2C8F4290 */  lbu        $v0, %lo(D_800E8F2C)($v0)
    /* 346F4 8009CEF4 00000000 */  nop
    /* 346F8 8009CEF8 21100202 */  addu       $v0, $s0, $v0
    /* 346FC 8009CEFC 3E184290 */  lbu        $v0, 0x183E($v0)
    /* 34700 8009CF00 00000000 */  nop
    /* 34704 8009CF04 15005310 */  beq        $v0, $s3, .L8009CF5C
    /* 34708 8009CF08 21101402 */   addu      $v0, $s0, $s4
    /* 3470C 8009CF0C 3D184290 */  lbu        $v0, 0x183D($v0)
    /* 34710 8009CF10 00000000 */  nop
    /* 34714 8009CF14 11005314 */  bne        $v0, $s3, .L8009CF5C
    /* 34718 8009CF18 00000000 */   nop
    /* 3471C 8009CF1C 0D180292 */  lbu        $v0, 0x180D($s0)
    /* 34720 8009CF20 00000000 */  nop
    /* 34724 8009CF24 0200422C */  sltiu      $v0, $v0, 0x2
    /* 34728 8009CF28 04004014 */  bnez       $v0, .L8009CF3C
    /* 3472C 8009CF2C 21200002 */   addu      $a0, $s0, $zero
    /* 34730 8009CF30 21280000 */  addu       $a1, $zero, $zero
    /* 34734 8009CF34 26AC020C */  jal        func_800AB098
    /* 34738 8009CF38 2130A000 */   addu      $a2, $a1, $zero
  .L8009CF3C:
    /* 3473C 8009CF3C 11180292 */  lbu        $v0, 0x1811($s0)
    /* 34740 8009CF40 00000000 */  nop
    /* 34744 8009CF44 0200422C */  sltiu      $v0, $v0, 0x2
    /* 34748 8009CF48 04004014 */  bnez       $v0, .L8009CF5C
    /* 3474C 8009CF4C 21200002 */   addu      $a0, $s0, $zero
    /* 34750 8009CF50 01000524 */  addiu      $a1, $zero, 0x1
    /* 34754 8009CF54 26AC020C */  jal        func_800AB098
    /* 34758 8009CF58 21300000 */   addu      $a2, $zero, $zero
  .L8009CF5C:
    /* 3475C 8009CF5C 01005226 */  addiu      $s2, $s2, 0x1
    /* 34760 8009CF60 1100422A */  slti       $v0, $s2, 0x11
    /* 34764 8009CF64 DEFF4014 */  bnez       $v0, .L8009CEE0
    /* 34768 8009CF68 04003126 */   addiu     $s1, $s1, 0x4
    /* 3476C 8009CF6C 0F80033C */  lui        $v1, %hi(D_800E8F2C)
    /* 34770 8009CF70 FFFF8226 */  addiu      $v0, $s4, -0x1
    /* 34774 8009CF74 2C8F62A0 */  sb         $v0, %lo(D_800E8F2C)($v1)
    /* 34778 8009CF78 21100000 */  addu       $v0, $zero, $zero
  .L8009CF7C:
    /* 3477C 8009CF7C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 34780 8009CF80 2000B48F */  lw         $s4, 0x20($sp)
    /* 34784 8009CF84 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 34788 8009CF88 1800B28F */  lw         $s2, 0x18($sp)
    /* 3478C 8009CF8C 1400B18F */  lw         $s1, 0x14($sp)
    /* 34790 8009CF90 1000B08F */  lw         $s0, 0x10($sp)
    /* 34794 8009CF94 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 34798 8009CF98 0800E003 */  jr         $ra
    /* 3479C 8009CF9C 00000000 */   nop
endlabel func_8009CE9C
