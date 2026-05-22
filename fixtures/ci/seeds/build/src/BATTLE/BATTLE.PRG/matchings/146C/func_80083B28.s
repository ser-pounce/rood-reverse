nonmatching func_80083B28, 0x50

glabel func_80083B28
    /* 1B328 80083B28 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B32C 80083B2C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B330 80083B30 2180C000 */  addu       $s0, $a2, $zero
    /* 1B334 80083B34 06000424 */  addiu      $a0, $zero, 0x6
    /* 1B338 80083B38 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B33C 80083B3C 0804020C */  jal        func_80081020
    /* 1B340 80083B40 21280002 */   addu      $a1, $s0, $zero
    /* 1B344 80083B44 08004010 */  beqz       $v0, .L80083B68
    /* 1B348 80083B48 00000000 */   nop
    /* 1B34C 80083B4C FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B350 80083B50 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B354 80083B54 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B358 80083B58 24186200 */  and        $v1, $v1, $v0
    /* 1B35C 80083B5C 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 1B360 80083B60 25186200 */  or         $v1, $v1, $v0
    /* 1B364 80083B64 1C0003AE */  sw         $v1, 0x1C($s0)
  .L80083B68:
    /* 1B368 80083B68 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B36C 80083B6C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B370 80083B70 0800E003 */  jr         $ra
    /* 1B374 80083B74 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083B28
