nonmatching func_8009D208, 0x68

glabel func_8009D208
    /* 34A08 8009D208 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 34A0C 8009D20C 0F80023C */  lui        $v0, %hi(D_800F244F)
    /* 34A10 8009D210 4F244224 */  addiu      $v0, $v0, %lo(D_800F244F)
    /* 34A14 8009D214 1000B0AF */  sw         $s0, 0x10($sp)
    /* 34A18 8009D218 21808200 */  addu       $s0, $a0, $v0
    /* 34A1C 8009D21C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 34A20 8009D220 00000292 */  lbu        $v0, 0x0($s0)
    /* 34A24 8009D224 00000000 */  nop
    /* 34A28 8009D228 0C004010 */  beqz       $v0, .L8009D25C
    /* 34A2C 8009D22C 21100000 */   addu      $v0, $zero, $zero
    /* 34A30 8009D230 ABAC020C */  jal        func_800AB2AC
    /* 34A34 8009D234 FFFF8424 */   addiu     $a0, $a0, -0x1
    /* 34A38 8009D238 00000492 */  lbu        $a0, 0x0($s0)
    /* 34A3C 8009D23C 01000524 */  addiu      $a1, $zero, 0x1
    /* 34A40 8009D240 2AF8010C */  jal        func_8007E0A8
    /* 34A44 8009D244 04000624 */   addiu     $a2, $zero, 0x4
    /* 34A48 8009D248 03004014 */  bnez       $v0, .L8009D258
    /* 34A4C 8009D24C 21100000 */   addu      $v0, $zero, $zero
    /* 34A50 8009D250 97740208 */  j          .L8009D25C
    /* 34A54 8009D254 FDFF0224 */   addiu     $v0, $zero, -0x3
  .L8009D258:
    /* 34A58 8009D258 000000A2 */  sb         $zero, 0x0($s0)
  .L8009D25C:
    /* 34A5C 8009D25C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 34A60 8009D260 1000B08F */  lw         $s0, 0x10($sp)
    /* 34A64 8009D264 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 34A68 8009D268 0800E003 */  jr         $ra
    /* 34A6C 8009D26C 00000000 */   nop
endlabel func_8009D208
