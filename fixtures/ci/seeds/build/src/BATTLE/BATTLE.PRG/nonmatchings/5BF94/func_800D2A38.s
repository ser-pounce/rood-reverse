nonmatching func_800D2A38, 0xA4

glabel func_800D2A38
    /* 6A238 800D2A38 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6A23C 800D2A3C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6A240 800D2A40 21808000 */  addu       $s0, $a0, $zero
    /* 6A244 800D2A44 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6A248 800D2A48 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6A24C 800D2A4C 2400028E */  lw         $v0, 0x24($s0)
    /* 6A250 800D2A50 0400033C */  lui        $v1, (0x40000 >> 16)
    /* 6A254 800D2A54 24104300 */  and        $v0, $v0, $v1
    /* 6A258 800D2A58 06004010 */  beqz       $v0, .L800D2A74
    /* 6A25C 800D2A5C 2188A000 */   addu      $s1, $a1, $zero
    /* 6A260 800D2A60 2C000426 */  addiu      $a0, $s0, 0x2C
    /* 6A264 800D2A64 4205010C */  jal        ApplyRotMatrix
    /* 6A268 800D2A68 34000526 */   addiu     $a1, $s0, 0x34
    /* 6A26C 800D2A6C A34A0308 */  j          .L800D2A8C
    /* 6A270 800D2A70 00000000 */   nop
  .L800D2A74:
    /* 6A274 800D2A74 2C000286 */  lh         $v0, 0x2C($s0)
    /* 6A278 800D2A78 2E000386 */  lh         $v1, 0x2E($s0)
    /* 6A27C 800D2A7C 30000486 */  lh         $a0, 0x30($s0)
    /* 6A280 800D2A80 340002AE */  sw         $v0, 0x34($s0)
    /* 6A284 800D2A84 380003AE */  sw         $v1, 0x38($s0)
    /* 6A288 800D2A88 3C0004AE */  sw         $a0, 0x3C($s0)
  .L800D2A8C:
    /* 6A28C 800D2A8C 3400028E */  lw         $v0, 0x34($s0)
    /* 6A290 800D2A90 9800038E */  lw         $v1, 0x98($s0)
    /* 6A294 800D2A94 00130200 */  sll        $v0, $v0, 12
    /* 6A298 800D2A98 21186200 */  addu       $v1, $v1, $v0
    /* 6A29C 800D2A9C 0C0023AE */  sw         $v1, 0xC($s1)
    /* 6A2A0 800D2AA0 3800028E */  lw         $v0, 0x38($s0)
    /* 6A2A4 800D2AA4 9C00038E */  lw         $v1, 0x9C($s0)
    /* 6A2A8 800D2AA8 00130200 */  sll        $v0, $v0, 12
    /* 6A2AC 800D2AAC 21186200 */  addu       $v1, $v1, $v0
    /* 6A2B0 800D2AB0 100023AE */  sw         $v1, 0x10($s1)
    /* 6A2B4 800D2AB4 3C00028E */  lw         $v0, 0x3C($s0)
    /* 6A2B8 800D2AB8 A000038E */  lw         $v1, 0xA0($s0)
    /* 6A2BC 800D2ABC 00130200 */  sll        $v0, $v0, 12
    /* 6A2C0 800D2AC0 21186200 */  addu       $v1, $v1, $v0
    /* 6A2C4 800D2AC4 140023AE */  sw         $v1, 0x14($s1)
    /* 6A2C8 800D2AC8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6A2CC 800D2ACC 1400B18F */  lw         $s1, 0x14($sp)
    /* 6A2D0 800D2AD0 1000B08F */  lw         $s0, 0x10($sp)
    /* 6A2D4 800D2AD4 0800E003 */  jr         $ra
    /* 6A2D8 800D2AD8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D2A38
