nonmatching func_80083B78, 0x50

glabel func_80083B78
    /* 1B378 80083B78 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B37C 80083B7C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B380 80083B80 2180C000 */  addu       $s0, $a2, $zero
    /* 1B384 80083B84 08000424 */  addiu      $a0, $zero, 0x8
    /* 1B388 80083B88 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B38C 80083B8C 0804020C */  jal        func_80081020
    /* 1B390 80083B90 21280002 */   addu      $a1, $s0, $zero
    /* 1B394 80083B94 08004010 */  beqz       $v0, .L80083BB8
    /* 1B398 80083B98 00000000 */   nop
    /* 1B39C 80083B9C FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B3A0 80083BA0 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B3A4 80083BA4 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B3A8 80083BA8 24186200 */  and        $v1, $v1, $v0
    /* 1B3AC 80083BAC 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 1B3B0 80083BB0 25186200 */  or         $v1, $v1, $v0
    /* 1B3B4 80083BB4 1C0003AE */  sw         $v1, 0x1C($s0)
  .L80083BB8:
    /* 1B3B8 80083BB8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B3BC 80083BBC 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B3C0 80083BC0 0800E003 */  jr         $ra
    /* 1B3C4 80083BC4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083B78
