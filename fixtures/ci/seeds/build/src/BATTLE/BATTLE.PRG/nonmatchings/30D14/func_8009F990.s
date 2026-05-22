nonmatching func_8009F990, 0x64

glabel func_8009F990
    /* 37190 8009F990 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 37194 8009F994 1400B1AF */  sw         $s1, 0x14($sp)
    /* 37198 8009F998 2188A000 */  addu       $s1, $a1, $zero
    /* 3719C 8009F99C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 371A0 8009F9A0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 371A4 8009F9A4 0B008214 */  bne        $a0, $v0, .L8009F9D4
    /* 371A8 8009F9A8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 371AC 8009F9AC 21800000 */  addu       $s0, $zero, $zero
    /* 371B0 8009F9B0 21200002 */  addu       $a0, $s0, $zero
  .L8009F9B4:
    /* 371B4 8009F9B4 7D7E020C */  jal        func_8009F9F4
    /* 371B8 8009F9B8 21282002 */   addu      $a1, $s1, $zero
    /* 371BC 8009F9BC 01001026 */  addiu      $s0, $s0, 0x1
    /* 371C0 8009F9C0 1100022A */  slti       $v0, $s0, 0x11
    /* 371C4 8009F9C4 FBFF4014 */  bnez       $v0, .L8009F9B4
    /* 371C8 8009F9C8 21200002 */   addu      $a0, $s0, $zero
    /* 371CC 8009F9CC 777E0208 */  j          .L8009F9DC
    /* 371D0 8009F9D0 00000000 */   nop
  .L8009F9D4:
    /* 371D4 8009F9D4 7D7E020C */  jal        func_8009F9F4
    /* 371D8 8009F9D8 21282002 */   addu      $a1, $s1, $zero
  .L8009F9DC:
    /* 371DC 8009F9DC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 371E0 8009F9E0 1400B18F */  lw         $s1, 0x14($sp)
    /* 371E4 8009F9E4 1000B08F */  lw         $s0, 0x10($sp)
    /* 371E8 8009F9E8 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 371EC 8009F9EC 0800E003 */  jr         $ra
    /* 371F0 8009F9F0 00000000 */   nop
endlabel func_8009F990
