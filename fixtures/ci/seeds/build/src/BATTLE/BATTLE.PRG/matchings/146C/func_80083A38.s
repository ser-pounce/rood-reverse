nonmatching func_80083A38, 0x50

glabel func_80083A38
    /* 1B238 80083A38 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B23C 80083A3C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B240 80083A40 2180C000 */  addu       $s0, $a2, $zero
    /* 1B244 80083A44 09000424 */  addiu      $a0, $zero, 0x9
    /* 1B248 80083A48 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B24C 80083A4C 0804020C */  jal        func_80081020
    /* 1B250 80083A50 21280002 */   addu      $a1, $s0, $zero
    /* 1B254 80083A54 08004010 */  beqz       $v0, .L80083A78
    /* 1B258 80083A58 00000000 */   nop
    /* 1B25C 80083A5C FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B260 80083A60 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B264 80083A64 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B268 80083A68 24186200 */  and        $v1, $v1, $v0
    /* 1B26C 80083A6C 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 1B270 80083A70 25186200 */  or         $v1, $v1, $v0
    /* 1B274 80083A74 1C0003AE */  sw         $v1, 0x1C($s0)
  .L80083A78:
    /* 1B278 80083A78 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B27C 80083A7C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B280 80083A80 0800E003 */  jr         $ra
    /* 1B284 80083A84 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083A38
