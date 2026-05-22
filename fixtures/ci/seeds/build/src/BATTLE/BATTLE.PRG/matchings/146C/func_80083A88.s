nonmatching func_80083A88, 0x50

glabel func_80083A88
    /* 1B288 80083A88 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B28C 80083A8C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B290 80083A90 2180C000 */  addu       $s0, $a2, $zero
    /* 1B294 80083A94 13000424 */  addiu      $a0, $zero, 0x13
    /* 1B298 80083A98 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B29C 80083A9C 0804020C */  jal        func_80081020
    /* 1B2A0 80083AA0 21280002 */   addu      $a1, $s0, $zero
    /* 1B2A4 80083AA4 08004010 */  beqz       $v0, .L80083AC8
    /* 1B2A8 80083AA8 00000000 */   nop
    /* 1B2AC 80083AAC FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B2B0 80083AB0 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B2B4 80083AB4 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B2B8 80083AB8 24186200 */  and        $v1, $v1, $v0
    /* 1B2BC 80083ABC 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 1B2C0 80083AC0 25186200 */  or         $v1, $v1, $v0
    /* 1B2C4 80083AC4 1C0003AE */  sw         $v1, 0x1C($s0)
  .L80083AC8:
    /* 1B2C8 80083AC8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B2CC 80083ACC 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B2D0 80083AD0 0800E003 */  jr         $ra
    /* 1B2D4 80083AD4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083A88
