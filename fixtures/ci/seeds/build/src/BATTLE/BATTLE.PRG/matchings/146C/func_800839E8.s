nonmatching func_800839E8, 0x50

glabel func_800839E8
    /* 1B1E8 800839E8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B1EC 800839EC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B1F0 800839F0 2180C000 */  addu       $s0, $a2, $zero
    /* 1B1F4 800839F4 07000424 */  addiu      $a0, $zero, 0x7
    /* 1B1F8 800839F8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B1FC 800839FC 0804020C */  jal        func_80081020
    /* 1B200 80083A00 21280002 */   addu      $a1, $s0, $zero
    /* 1B204 80083A04 08004010 */  beqz       $v0, .L80083A28
    /* 1B208 80083A08 00000000 */   nop
    /* 1B20C 80083A0C FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B210 80083A10 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B214 80083A14 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B218 80083A18 24186200 */  and        $v1, $v1, $v0
    /* 1B21C 80083A1C 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 1B220 80083A20 25186200 */  or         $v1, $v1, $v0
    /* 1B224 80083A24 1C0003AE */  sw         $v1, 0x1C($s0)
  .L80083A28:
    /* 1B228 80083A28 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B22C 80083A2C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B230 80083A30 0800E003 */  jr         $ra
    /* 1B234 80083A34 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800839E8
