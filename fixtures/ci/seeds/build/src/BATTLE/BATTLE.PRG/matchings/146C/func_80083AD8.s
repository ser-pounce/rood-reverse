nonmatching func_80083AD8, 0x50

glabel func_80083AD8
    /* 1B2D8 80083AD8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B2DC 80083ADC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B2E0 80083AE0 2180C000 */  addu       $s0, $a2, $zero
    /* 1B2E4 80083AE4 04000424 */  addiu      $a0, $zero, 0x4
    /* 1B2E8 80083AE8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B2EC 80083AEC 0804020C */  jal        func_80081020
    /* 1B2F0 80083AF0 21280002 */   addu      $a1, $s0, $zero
    /* 1B2F4 80083AF4 08004010 */  beqz       $v0, .L80083B18
    /* 1B2F8 80083AF8 00000000 */   nop
    /* 1B2FC 80083AFC FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B300 80083B00 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B304 80083B04 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B308 80083B08 24186200 */  and        $v1, $v1, $v0
    /* 1B30C 80083B0C 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 1B310 80083B10 25186200 */  or         $v1, $v1, $v0
    /* 1B314 80083B14 1C0003AE */  sw         $v1, 0x1C($s0)
  .L80083B18:
    /* 1B318 80083B18 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B31C 80083B1C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B320 80083B20 0800E003 */  jr         $ra
    /* 1B324 80083B24 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083AD8
