nonmatching func_8009DD00, 0xF4

glabel func_8009DD00
    /* 35500 8009DD00 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 35504 8009DD04 2000B2AF */  sw         $s2, 0x20($sp)
    /* 35508 8009DD08 21908000 */  addu       $s2, $a0, $zero
    /* 3550C 8009DD0C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 35510 8009DD10 2188A000 */  addu       $s1, $a1, $zero
    /* 35514 8009DD14 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 35518 8009DD18 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 3551C 8009DD1C 80101200 */  sll        $v0, $s2, 2
    /* 35520 8009DD20 21104300 */  addu       $v0, $v0, $v1
    /* 35524 8009DD24 2800BFAF */  sw         $ra, 0x28($sp)
    /* 35528 8009DD28 2400B3AF */  sw         $s3, 0x24($sp)
    /* 3552C 8009DD2C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 35530 8009DD30 0000508C */  lw         $s0, 0x0($v0)
    /* 35534 8009DD34 00000000 */  nop
    /* 35538 8009DD38 26000012 */  beqz       $s0, .L8009DDD4
    /* 3553C 8009DD3C 2198C000 */   addu      $s3, $a2, $zero
    /* 35540 8009DD40 6078020C */  jal        func_8009E180
    /* 35544 8009DD44 21200002 */   addu      $a0, $s0, $zero
    /* 35548 8009DD48 3E0002A6 */  sh         $v0, 0x3E($s0)
    /* 3554C 8009DD4C 3C060296 */  lhu        $v0, 0x63C($s0)
    /* 35550 8009DD50 0A000324 */  addiu      $v1, $zero, 0xA
    /* 35554 8009DD54 8100422C */  sltiu      $v0, $v0, 0x81
    /* 35558 8009DD58 03004014 */  bnez       $v0, .L8009DD68
    /* 3555C 8009DD5C 180003A6 */   sh        $v1, 0x18($s0)
    /* 35560 8009DD60 14000224 */  addiu      $v0, $zero, 0x14
    /* 35564 8009DD64 180002A6 */  sh         $v0, 0x18($s0)
  .L8009DD68:
    /* 35568 8009DD68 21200002 */  addu       $a0, $s0, $zero
    /* 3556C 8009DD6C 8A78020C */  jal        func_8009E228
    /* 35570 8009DD70 21282002 */   addu      $a1, $s1, $zero
    /* 35574 8009DD74 21184000 */  addu       $v1, $v0, $zero
    /* 35578 8009DD78 1CFF6228 */  slti       $v0, $v1, -0xE4
    /* 3557C 8009DD7C 0F004014 */  bnez       $v0, .L8009DDBC
    /* 35580 8009DD80 48000524 */   addiu     $a1, $zero, 0x48
    /* 35584 8009DD84 AC006228 */  slti       $v0, $v1, 0xAC
    /* 35588 8009DD88 0C004014 */  bnez       $v0, .L8009DDBC
    /* 3558C 8009DD8C 49000524 */   addiu     $a1, $zero, 0x49
    /* 35590 8009DD90 01036228 */  slti       $v0, $v1, 0x301
    /* 35594 8009DD94 09004014 */  bnez       $v0, .L8009DDBC
    /* 35598 8009DD98 4A000524 */   addiu     $a1, $zero, 0x4A
    /* 3559C 8009DD9C 08006016 */  bnez       $s3, .L8009DDC0
    /* 355A0 8009DDA0 21204002 */   addu      $a0, $s2, $zero
    /* 355A4 8009DDA4 E6060396 */  lhu        $v1, 0x6E6($s0)
    /* 355A8 8009DDA8 28000224 */  addiu      $v0, $zero, 0x28
    /* 355AC 8009DDAC 05006214 */  bne        $v1, $v0, .L8009DDC4
    /* 355B0 8009DDB0 21300000 */   addu      $a2, $zero, $zero
    /* 355B4 8009DDB4 71770208 */  j          .L8009DDC4
    /* 355B8 8009DDB8 4E000524 */   addiu     $a1, $zero, 0x4E
  .L8009DDBC:
    /* 355BC 8009DDBC 21204002 */  addu       $a0, $s2, $zero
  .L8009DDC0:
    /* 355C0 8009DDC0 21300000 */  addu       $a2, $zero, $zero
  .L8009DDC4:
    /* 355C4 8009DDC4 8180020C */  jal        func_800A0204
    /* 355C8 8009DDC8 06000724 */   addiu     $a3, $zero, 0x6
    /* 355CC 8009DDCC 4E7F020C */  jal        func_8009FD38
    /* 355D0 8009DDD0 21200002 */   addu      $a0, $s0, $zero
  .L8009DDD4:
    /* 355D4 8009DDD4 2800BF8F */  lw         $ra, 0x28($sp)
    /* 355D8 8009DDD8 2400B38F */  lw         $s3, 0x24($sp)
    /* 355DC 8009DDDC 2000B28F */  lw         $s2, 0x20($sp)
    /* 355E0 8009DDE0 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 355E4 8009DDE4 1800B08F */  lw         $s0, 0x18($sp)
    /* 355E8 8009DDE8 3000BD27 */  addiu      $sp, $sp, 0x30
    /* 355EC 8009DDEC 0800E003 */  jr         $ra
    /* 355F0 8009DDF0 00000000 */   nop
endlabel func_8009DD00
