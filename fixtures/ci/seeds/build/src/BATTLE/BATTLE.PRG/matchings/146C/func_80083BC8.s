nonmatching func_80083BC8, 0x50

glabel func_80083BC8
    /* 1B3C8 80083BC8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B3CC 80083BCC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B3D0 80083BD0 2180C000 */  addu       $s0, $a2, $zero
    /* 1B3D4 80083BD4 0A000424 */  addiu      $a0, $zero, 0xA
    /* 1B3D8 80083BD8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B3DC 80083BDC 0804020C */  jal        func_80081020
    /* 1B3E0 80083BE0 21280002 */   addu      $a1, $s0, $zero
    /* 1B3E4 80083BE4 08004010 */  beqz       $v0, .L80083C08
    /* 1B3E8 80083BE8 00000000 */   nop
    /* 1B3EC 80083BEC FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B3F0 80083BF0 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B3F4 80083BF4 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B3F8 80083BF8 24186200 */  and        $v1, $v1, $v0
    /* 1B3FC 80083BFC 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 1B400 80083C00 25186200 */  or         $v1, $v1, $v0
    /* 1B404 80083C04 1C0003AE */  sw         $v1, 0x1C($s0)
  .L80083C08:
    /* 1B408 80083C08 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B40C 80083C0C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B410 80083C10 0800E003 */  jr         $ra
    /* 1B414 80083C14 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083BC8
