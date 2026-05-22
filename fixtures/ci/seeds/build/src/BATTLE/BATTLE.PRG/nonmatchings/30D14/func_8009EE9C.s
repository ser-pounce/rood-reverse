nonmatching func_8009EE9C, 0x150

glabel func_8009EE9C
    /* 3669C 8009EE9C C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 366A0 8009EEA0 2800B2AF */  sw         $s2, 0x28($sp)
    /* 366A4 8009EEA4 21908000 */  addu       $s2, $a0, $zero
    /* 366A8 8009EEA8 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 366AC 8009EEAC 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 366B0 8009EEB0 80181200 */  sll        $v1, $s2, 2
    /* 366B4 8009EEB4 21186200 */  addu       $v1, $v1, $v0
    /* 366B8 8009EEB8 3000BFAF */  sw         $ra, 0x30($sp)
    /* 366BC 8009EEBC 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 366C0 8009EEC0 2400B1AF */  sw         $s1, 0x24($sp)
    /* 366C4 8009EEC4 2000B0AF */  sw         $s0, 0x20($sp)
    /* 366C8 8009EEC8 0000708C */  lw         $s0, 0x0($v1)
    /* 366CC 8009EECC 00000000 */  nop
    /* 366D0 8009EED0 0800038E */  lw         $v1, 0x8($s0)
    /* 366D4 8009EED4 8000023C */  lui        $v0, (0x800000 >> 16)
    /* 366D8 8009EED8 24106200 */  and        $v0, $v1, $v0
    /* 366DC 8009EEDC 2C004010 */  beqz       $v0, .L8009EF90
    /* 366E0 8009EEE0 2198A000 */   addu      $s3, $a1, $zero
    /* 366E4 8009EEE4 0F000292 */  lbu        $v0, 0xF($s0)
    /* 366E8 8009EEE8 00000000 */  nop
    /* 366EC 8009EEEC 0A004010 */  beqz       $v0, .L8009EF18
    /* 366F0 8009EEF0 6000023C */   lui       $v0, (0x600000 >> 16)
    /* 366F4 8009EEF4 24106200 */  and        $v0, $v1, $v0
    /* 366F8 8009EEF8 25004014 */  bnez       $v0, .L8009EF90
    /* 366FC 8009EEFC 0700023C */   lui       $v0, (0x70000 >> 16)
    /* 36700 8009EF00 24186200 */  and        $v1, $v1, $v0
    /* 36704 8009EF04 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 36708 8009EF08 21006210 */  beq        $v1, $v0, .L8009EF90
    /* 3670C 8009EF0C 0300023C */   lui       $v0, (0x30000 >> 16)
    /* 36710 8009EF10 1F006210 */  beq        $v1, $v0, .L8009EF90
    /* 36714 8009EF14 00000000 */   nop
  .L8009EF18:
    /* 36718 8009EF18 3C060296 */  lhu        $v0, 0x63C($s0)
    /* 3671C 8009EF1C 00000000 */  nop
    /* 36720 8009EF20 8000422C */  sltiu      $v0, $v0, 0x80
    /* 36724 8009EF24 08004010 */  beqz       $v0, .L8009EF48
    /* 36728 8009EF28 21200002 */   addu      $a0, $s0, $zero
    /* 3672C 8009EF2C 6078020C */  jal        func_8009E180
    /* 36730 8009EF30 21286002 */   addu      $a1, $s3, $zero
    /* 36734 8009EF34 08001124 */  addiu      $s1, $zero, 0x8
    /* 36738 8009EF38 3E0002A6 */  sh         $v0, 0x3E($s0)
    /* 3673C 8009EF3C 04000224 */  addiu      $v0, $zero, 0x4
    /* 36740 8009EF40 D37B0208 */  j          .L8009EF4C
    /* 36744 8009EF44 180002A6 */   sh        $v0, 0x18($s0)
  .L8009EF48:
    /* 36748 8009EF48 04001124 */  addiu      $s1, $zero, 0x4
  .L8009EF4C:
    /* 3674C 8009EF4C 21200002 */  addu       $a0, $s0, $zero
    /* 36750 8009EF50 8A78020C */  jal        func_8009E228
    /* 36754 8009EF54 21286002 */   addu      $a1, $s3, $zero
    /* 36758 8009EF58 21184000 */  addu       $v1, $v0, $zero
    /* 3675C 8009EF5C 1CFF6228 */  slti       $v0, $v1, -0xE4
    /* 36760 8009EF60 05004014 */  bnez       $v0, .L8009EF78
    /* 36764 8009EF64 4F000524 */   addiu     $a1, $zero, 0x4F
    /* 36768 8009EF68 AC006228 */  slti       $v0, $v1, 0xAC
    /* 3676C 8009EF6C 02004014 */  bnez       $v0, .L8009EF78
    /* 36770 8009EF70 50000524 */   addiu     $a1, $zero, 0x50
    /* 36774 8009EF74 51000524 */  addiu      $a1, $zero, 0x51
  .L8009EF78:
    /* 36778 8009EF78 21204002 */  addu       $a0, $s2, $zero
    /* 3677C 8009EF7C 21300000 */  addu       $a2, $zero, $zero
    /* 36780 8009EF80 8180020C */  jal        func_800A0204
    /* 36784 8009EF84 21382002 */   addu      $a3, $s1, $zero
    /* 36788 8009EF88 4E7F020C */  jal        func_8009FD38
    /* 3678C 8009EF8C 21200002 */   addu      $a0, $s0, $zero
  .L8009EF90:
    /* 36790 8009EF90 0F000292 */  lbu        $v0, 0xF($s0)
    /* 36794 8009EF94 00000000 */  nop
    /* 36798 8009EF98 0A004014 */  bnez       $v0, .L8009EFC4
    /* 3679C 8009EF9C 0700023C */   lui       $v0, (0x70000 >> 16)
    /* 367A0 8009EFA0 0800048E */  lw         $a0, 0x8($s0)
    /* 367A4 8009EFA4 0300033C */  lui        $v1, (0x30000 >> 16)
    /* 367A8 8009EFA8 24108200 */  and        $v0, $a0, $v0
    /* 367AC 8009EFAC 04004310 */  beq        $v0, $v1, .L8009EFC0
    /* 367B0 8009EFB0 F8FF023C */   lui       $v0, (0xFFF8FFFF >> 16)
    /* 367B4 8009EFB4 FFFF4234 */  ori        $v0, $v0, (0xFFF8FFFF & 0xFFFF)
    /* 367B8 8009EFB8 24108200 */  and        $v0, $a0, $v0
    /* 367BC 8009EFBC 080002AE */  sw         $v0, 0x8($s0)
  .L8009EFC0:
    /* 367C0 8009EFC0 110000A2 */  sb         $zero, 0x11($s0)
  .L8009EFC4:
    /* 367C4 8009EFC4 13B2010C */  jal        func_8006C84C
    /* 367C8 8009EFC8 21204002 */   addu      $a0, $s2, $zero
    /* 367CC 8009EFCC 3000BF8F */  lw         $ra, 0x30($sp)
    /* 367D0 8009EFD0 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 367D4 8009EFD4 2800B28F */  lw         $s2, 0x28($sp)
    /* 367D8 8009EFD8 2400B18F */  lw         $s1, 0x24($sp)
    /* 367DC 8009EFDC 2000B08F */  lw         $s0, 0x20($sp)
    /* 367E0 8009EFE0 3800BD27 */  addiu      $sp, $sp, 0x38
    /* 367E4 8009EFE4 0800E003 */  jr         $ra
    /* 367E8 8009EFE8 00000000 */   nop
endlabel func_8009EE9C
