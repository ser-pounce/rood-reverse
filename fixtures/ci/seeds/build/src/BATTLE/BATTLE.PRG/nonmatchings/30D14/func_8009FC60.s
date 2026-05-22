nonmatching func_8009FC60, 0xD8

glabel func_8009FC60
    /* 37460 8009FC60 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 37464 8009FC64 2000B2AF */  sw         $s2, 0x20($sp)
    /* 37468 8009FC68 2190A000 */  addu       $s2, $a1, $zero
    /* 3746C 8009FC6C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 37470 8009FC70 2188C000 */  addu       $s1, $a2, $zero
    /* 37474 8009FC74 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 37478 8009FC78 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 3747C 8009FC7C 80100400 */  sll        $v0, $a0, 2
    /* 37480 8009FC80 21104300 */  addu       $v0, $v0, $v1
    /* 37484 8009FC84 2800BFAF */  sw         $ra, 0x28($sp)
    /* 37488 8009FC88 2400B3AF */  sw         $s3, 0x24($sp)
    /* 3748C 8009FC8C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 37490 8009FC90 0000508C */  lw         $s0, 0x0($v0)
    /* 37494 8009FC94 00000000 */  nop
    /* 37498 8009FC98 03000016 */  bnez       $s0, .L8009FCA8
    /* 3749C 8009FC9C 2198E000 */   addu      $s3, $a3, $zero
    /* 374A0 8009FCA0 467F0208 */  j          .L8009FD18
    /* 374A4 8009FCA4 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8009FCA8:
    /* 374A8 8009FCA8 02000524 */  addiu      $a1, $zero, 0x2
    /* 374AC 8009FCAC 4B85020C */  jal        func_800A152C
    /* 374B0 8009FCB0 03000624 */   addiu     $a2, $zero, 0x3
    /* 374B4 8009FCB4 18004004 */  bltz       $v0, .L8009FD18
    /* 374B8 8009FCB8 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 374BC 8009FCBC 06002016 */  bnez       $s1, .L8009FCD8
    /* 374C0 8009FCC0 FC1712A2 */   sb        $s2, 0x17FC($s0)
    /* 374C4 8009FCC4 16000296 */  lhu        $v0, 0x16($s0)
    /* 374C8 8009FCC8 14000396 */  lhu        $v1, 0x14($s0)
    /* 374CC 8009FCCC F41702A6 */  sh         $v0, 0x17F4($s0)
    /* 374D0 8009FCD0 3E7F0208 */  j          .L8009FCF8
    /* 374D4 8009FCD4 F61703A6 */   sh        $v1, 0x17F6($s0)
  .L8009FCD8:
    /* 374D8 8009FCD8 0300228A */  lwl        $v0, 0x3($s1)
    /* 374DC 8009FCDC 0000229A */  lwr        $v0, 0x0($s1)
    /* 374E0 8009FCE0 0700238A */  lwl        $v1, 0x7($s1)
    /* 374E4 8009FCE4 0400239A */  lwr        $v1, 0x4($s1)
    /* 374E8 8009FCE8 F71702AA */  swl        $v0, 0x17F7($s0)
    /* 374EC 8009FCEC F41702BA */  swr        $v0, 0x17F4($s0)
    /* 374F0 8009FCF0 FB1703AA */  swl        $v1, 0x17FB($s0)
    /* 374F4 8009FCF4 F81703BA */  swr        $v1, 0x17F8($s0)
  .L8009FCF8:
    /* 374F8 8009FCF8 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 374FC 8009FCFC 05006216 */  bne        $s3, $v0, .L8009FD14
    /* 37500 8009FD00 21100000 */   addu      $v0, $zero, $zero
    /* 37504 8009FD04 4E7F020C */  jal        func_8009FD38
    /* 37508 8009FD08 21200002 */   addu      $a0, $s0, $zero
    /* 3750C 8009FD0C 467F0208 */  j          .L8009FD18
    /* 37510 8009FD10 21100000 */   addu      $v0, $zero, $zero
  .L8009FD14:
    /* 37514 8009FD14 FA1713A6 */  sh         $s3, 0x17FA($s0)
  .L8009FD18:
    /* 37518 8009FD18 2800BF8F */  lw         $ra, 0x28($sp)
    /* 3751C 8009FD1C 2400B38F */  lw         $s3, 0x24($sp)
    /* 37520 8009FD20 2000B28F */  lw         $s2, 0x20($sp)
    /* 37524 8009FD24 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 37528 8009FD28 1800B08F */  lw         $s0, 0x18($sp)
    /* 3752C 8009FD2C 3000BD27 */  addiu      $sp, $sp, 0x30
    /* 37530 8009FD30 0800E003 */  jr         $ra
    /* 37534 8009FD34 00000000 */   nop
endlabel func_8009FC60
