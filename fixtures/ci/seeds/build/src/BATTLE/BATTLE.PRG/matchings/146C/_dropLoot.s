nonmatching _dropLoot, 0x1A0

glabel _dropLoot
    /* 3664 8006BE64 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 3668 8006BE68 2400B5AF */  sw         $s5, 0x24($sp)
    /* 366C 8006BE6C 21A88000 */  addu       $s5, $a0, $zero
    /* 3670 8006BE70 2800BFAF */  sw         $ra, 0x28($sp)
    /* 3674 8006BE74 2000B4AF */  sw         $s4, 0x20($sp)
    /* 3678 8006BE78 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 367C 8006BE7C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3680 8006BE80 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3684 8006BE84 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3688 8006BE88 3C00B28E */  lw         $s2, 0x3C($s5)
    /* 368C 8006BE8C 8F0F010C */  jal        vs_main_allocHeapR
    /* 3690 8006BE90 28020424 */   addiu     $a0, $zero, 0x228
    /* 3694 8006BE94 21884000 */  addu       $s1, $v0, $zero
    /* 3698 8006BE98 51002012 */  beqz       $s1, .L8006BFE0
    /* 369C 8006BE9C 00000000 */   nop
    /* 36A0 8006BEA0 21202002 */  addu       $a0, $s1, $zero
    /* 36A4 8006BEA4 4424010C */  jal        vs_main_bzero
    /* 36A8 8006BEA8 28020524 */   addiu     $a1, $zero, 0x228
    /* 36AC 8006BEAC 08002426 */  addiu      $a0, $s1, 0x8
    /* 36B0 8006BEB0 C3AE010C */  jal        _dropWeaponRand
    /* 36B4 8006BEB4 3C004526 */   addiu     $a1, $s2, 0x3C
    /* 36B8 8006BEB8 F8002426 */  addiu      $a0, $s1, 0xF8
    /* 36BC 8006BEBC D4014526 */  addiu      $a1, $s2, 0x1D4
    /* 36C0 8006BEC0 21A00000 */  addu       $s4, $zero, $zero
    /* 36C4 8006BEC4 0400238E */  lw         $v1, 0x4($s1)
    /* 36C8 8006BEC8 98031324 */  addiu      $s3, $zero, 0x398
    /* 36CC 8006BECC 25186200 */  or         $v1, $v1, $v0
    /* 36D0 8006BED0 FBAE010C */  jal        _dropShieldRand
    /* 36D4 8006BED4 040023AE */   sw        $v1, 0x4($s1)
    /* 36D8 8006BED8 D0012426 */  addiu      $a0, $s1, 0x1D0
    /* 36DC 8006BEDC 0400238E */  lw         $v1, 0x4($s1)
    /* 36E0 8006BEE0 38034526 */  addiu      $a1, $s2, 0x338
    /* 36E4 8006BEE4 25186200 */  or         $v1, $v1, $v0
    /* 36E8 8006BEE8 2CAF010C */  jal        _dropAccessoryRand
    /* 36EC 8006BEEC 040023AE */   sw        $v1, 0x4($s1)
    /* 36F0 8006BEF0 0400238E */  lw         $v1, 0x4($s1)
    /* 36F4 8006BEF4 21804002 */  addu       $s0, $s2, $zero
    /* 36F8 8006BEF8 25186200 */  or         $v1, $v1, $v0
    /* 36FC 8006BEFC 040023AE */  sw         $v1, 0x4($s1)
  .L8006BF00:
    /* 3700 8006BF00 B8030296 */  lhu        $v0, 0x3B8($s0)
    /* 3704 8006BF04 00000000 */  nop
    /* 3708 8006BF08 08004010 */  beqz       $v0, .L8006BF2C
    /* 370C 8006BF0C 78012426 */   addiu     $a0, $s1, 0x178
    /* 3710 8006BF10 21285302 */  addu       $a1, $s2, $s3
    /* 3714 8006BF14 45AF010C */  jal        _dropArmorRand
    /* 3718 8006BF18 2000A524 */   addiu     $a1, $a1, 0x20
    /* 371C 8006BF1C 0400238E */  lw         $v1, 0x4($s1)
    /* 3720 8006BF20 00000000 */  nop
    /* 3724 8006BF24 25186200 */  or         $v1, $v1, $v0
    /* 3728 8006BF28 040023AE */  sw         $v1, 0x4($s1)
  .L8006BF2C:
    /* 372C 8006BF2C DC007326 */  addiu      $s3, $s3, 0xDC
    /* 3730 8006BF30 01009426 */  addiu      $s4, $s4, 0x1
    /* 3734 8006BF34 0600822A */  slti       $v0, $s4, 0x6
    /* 3738 8006BF38 F1FF4014 */  bnez       $v0, .L8006BF00
    /* 373C 8006BF3C DC001026 */   addiu     $s0, $s0, 0xDC
    /* 3740 8006BF40 08003026 */  addiu      $s0, $s1, 0x8
    /* 3744 8006BF44 21200002 */  addu       $a0, $s0, $zero
    /* 3748 8006BF48 68AF010C */  jal        _dropMisc
    /* 374C 8006BF4C 58094526 */   addiu     $a1, $s2, 0x958
    /* 3750 8006BF50 21200002 */  addu       $a0, $s0, $zero
    /* 3754 8006BF54 0400238E */  lw         $v1, 0x4($s1)
    /* 3758 8006BF58 60094526 */  addiu      $a1, $s2, 0x960
    /* 375C 8006BF5C 25186200 */  or         $v1, $v1, $v0
    /* 3760 8006BF60 7CAF010C */  jal        _dropMiscRand
    /* 3764 8006BF64 040023AE */   sw        $v1, 0x4($s1)
    /* 3768 8006BF68 0400238E */  lw         $v1, 0x4($s1)
    /* 376C 8006BF6C 00000000 */  nop
    /* 3770 8006BF70 25186200 */  or         $v1, $v1, $v0
    /* 3774 8006BF74 18006010 */  beqz       $v1, .L8006BFD8
    /* 3778 8006BF78 040023AE */   sw        $v1, 0x4($s1)
    /* 377C 8006BF7C 0F80023C */  lui        $v0, %hi(_lootListHead)
    /* 3780 8006BF80 0019438C */  lw         $v1, %lo(_lootListHead)($v0)
    /* 3784 8006BF84 00000000 */  nop
    /* 3788 8006BF88 0B006010 */  beqz       $v1, .L8006BFB8
    /* 378C 8006BF8C 01000424 */   addiu     $a0, $zero, 0x1
    /* 3790 8006BF90 0400A58E */  lw         $a1, 0x4($s5)
  .L8006BF94:
    /* 3794 8006BF94 0400628C */  lw         $v0, 0x4($v1)
    /* 3798 8006BF98 00000000 */  nop
    /* 379C 8006BF9C 02004514 */  bne        $v0, $a1, .L8006BFA8
    /* 37A0 8006BFA0 00000000 */   nop
    /* 37A4 8006BFA4 21200000 */  addu       $a0, $zero, $zero
  .L8006BFA8:
    /* 37A8 8006BFA8 0000638C */  lw         $v1, 0x0($v1)
    /* 37AC 8006BFAC 00000000 */  nop
    /* 37B0 8006BFB0 F8FF6014 */  bnez       $v1, .L8006BF94
    /* 37B4 8006BFB4 00000000 */   nop
  .L8006BFB8:
    /* 37B8 8006BFB8 07008010 */  beqz       $a0, .L8006BFD8
    /* 37BC 8006BFBC 0F80023C */   lui       $v0, %hi(_lootListHead)
    /* 37C0 8006BFC0 0400A38E */  lw         $v1, 0x4($s5)
    /* 37C4 8006BFC4 0019448C */  lw         $a0, %lo(_lootListHead)($v0)
    /* 37C8 8006BFC8 001951AC */  sw         $s1, %lo(_lootListHead)($v0)
    /* 37CC 8006BFCC 040023AE */  sw         $v1, 0x4($s1)
    /* 37D0 8006BFD0 F8AF0108 */  j          .L8006BFE0
    /* 37D4 8006BFD4 000024AE */   sw        $a0, 0x0($s1)
  .L8006BFD8:
    /* 37D8 8006BFD8 180F010C */  jal        vs_main_freeHeapR
    /* 37DC 8006BFDC 21202002 */   addu      $a0, $s1, $zero
  .L8006BFE0:
    /* 37E0 8006BFE0 2800BF8F */  lw         $ra, 0x28($sp)
    /* 37E4 8006BFE4 2400B58F */  lw         $s5, 0x24($sp)
    /* 37E8 8006BFE8 2000B48F */  lw         $s4, 0x20($sp)
    /* 37EC 8006BFEC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 37F0 8006BFF0 1800B28F */  lw         $s2, 0x18($sp)
    /* 37F4 8006BFF4 1400B18F */  lw         $s1, 0x14($sp)
    /* 37F8 8006BFF8 1000B08F */  lw         $s0, 0x10($sp)
    /* 37FC 8006BFFC 0800E003 */  jr         $ra
    /* 3800 8006C000 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _dropLoot
