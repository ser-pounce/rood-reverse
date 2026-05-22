nonmatching func_800A9D90, 0xA8

glabel func_800A9D90
    /* 41590 800A9D90 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 41594 800A9D94 0F80033C */  lui        $v1, %hi(D_800F4538)
    /* 41598 800A9D98 38456324 */  addiu      $v1, $v1, %lo(D_800F4538)
    /* 4159C 800A9D9C 80100400 */  sll        $v0, $a0, 2
    /* 415A0 800A9DA0 21104300 */  addu       $v0, $v0, $v1
    /* 415A4 800A9DA4 2000BFAF */  sw         $ra, 0x20($sp)
    /* 415A8 800A9DA8 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 415AC 800A9DAC 1800B0AF */  sw         $s0, 0x18($sp)
    /* 415B0 800A9DB0 0000518C */  lw         $s1, 0x0($v0)
    /* 415B4 800A9DB4 0000A294 */  lhu        $v0, 0x0($a1)
    /* 415B8 800A9DB8 1C002396 */  lhu        $v1, 0x1C($s1)
    /* 415BC 800A9DBC 00000000 */  nop
    /* 415C0 800A9DC0 23104300 */  subu       $v0, $v0, $v1
    /* 415C4 800A9DC4 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 415C8 800A9DC8 0200A294 */  lhu        $v0, 0x2($a1)
    /* 415CC 800A9DCC 1E002396 */  lhu        $v1, 0x1E($s1)
    /* 415D0 800A9DD0 00000000 */  nop
    /* 415D4 800A9DD4 23104300 */  subu       $v0, $v0, $v1
    /* 415D8 800A9DD8 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 415DC 800A9DDC 0400A294 */  lhu        $v0, 0x4($a1)
    /* 415E0 800A9DE0 20002396 */  lhu        $v1, 0x20($s1)
    /* 415E4 800A9DE4 2138C000 */  addu       $a3, $a2, $zero
    /* 415E8 800A9DE8 23104300 */  subu       $v0, $v0, $v1
    /* 415EC 800A9DEC 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 415F0 800A9DF0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 415F4 800A9DF4 0500E214 */  bne        $a3, $v0, .L800A9E0C
    /* 415F8 800A9DF8 1000A527 */   addiu     $a1, $sp, 0x10
    /* 415FC 800A9DFC A6A9020C */  jal        func_800AA698
    /* 41600 800A9E00 21304000 */   addu      $a2, $v0, $zero
    /* 41604 800A9E04 88A70208 */  j          .L800A9E20
    /* 41608 800A9E08 00000000 */   nop
  .L800A9E0C:
    /* 4160C 800A9E0C C2053096 */  lhu        $s0, 0x5C2($s1)
    /* 41610 800A9E10 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 41614 800A9E14 A6A9020C */  jal        func_800AA698
    /* 41618 800A9E18 C20527A6 */   sh        $a3, 0x5C2($s1)
    /* 4161C 800A9E1C C20530A6 */  sh         $s0, 0x5C2($s1)
  .L800A9E20:
    /* 41620 800A9E20 2000BF8F */  lw         $ra, 0x20($sp)
    /* 41624 800A9E24 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 41628 800A9E28 1800B08F */  lw         $s0, 0x18($sp)
    /* 4162C 800A9E2C 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 41630 800A9E30 0800E003 */  jr         $ra
    /* 41634 800A9E34 00000000 */   nop
endlabel func_800A9D90
