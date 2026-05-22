nonmatching func_80083998, 0x50

glabel func_80083998
    /* 1B198 80083998 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B19C 8008399C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B1A0 800839A0 2180C000 */  addu       $s0, $a2, $zero
    /* 1B1A4 800839A4 05000424 */  addiu      $a0, $zero, 0x5
    /* 1B1A8 800839A8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B1AC 800839AC 0804020C */  jal        func_80081020
    /* 1B1B0 800839B0 21280002 */   addu      $a1, $s0, $zero
    /* 1B1B4 800839B4 08004010 */  beqz       $v0, .L800839D8
    /* 1B1B8 800839B8 00000000 */   nop
    /* 1B1BC 800839BC FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B1C0 800839C0 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B1C4 800839C4 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B1C8 800839C8 24186200 */  and        $v1, $v1, $v0
    /* 1B1CC 800839CC 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 1B1D0 800839D0 25186200 */  or         $v1, $v1, $v0
    /* 1B1D4 800839D4 1C0003AE */  sw         $v1, 0x1C($s0)
  .L800839D8:
    /* 1B1D8 800839D8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B1DC 800839DC 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B1E0 800839E0 0800E003 */  jr         $ra
    /* 1B1E4 800839E4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083998
