nonmatching func_80083C68, 0x50

glabel func_80083C68
    /* 1B468 80083C68 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B46C 80083C6C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B470 80083C70 2180C000 */  addu       $s0, $a2, $zero
    /* 1B474 80083C74 0B000424 */  addiu      $a0, $zero, 0xB
    /* 1B478 80083C78 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B47C 80083C7C 0804020C */  jal        func_80081020
    /* 1B480 80083C80 21280002 */   addu      $a1, $s0, $zero
    /* 1B484 80083C84 08004010 */  beqz       $v0, .L80083CA8
    /* 1B488 80083C88 00000000 */   nop
    /* 1B48C 80083C8C FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B490 80083C90 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B494 80083C94 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B498 80083C98 24186200 */  and        $v1, $v1, $v0
    /* 1B49C 80083C9C 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 1B4A0 80083CA0 25186200 */  or         $v1, $v1, $v0
    /* 1B4A4 80083CA4 1C0003AE */  sw         $v1, 0x1C($s0)
  .L80083CA8:
    /* 1B4A8 80083CA8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B4AC 80083CAC 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B4B0 80083CB0 0800E003 */  jr         $ra
    /* 1B4B4 80083CB4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083C68
