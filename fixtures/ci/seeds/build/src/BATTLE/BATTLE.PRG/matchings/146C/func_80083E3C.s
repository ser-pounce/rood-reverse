nonmatching func_80083E3C, 0x50

glabel func_80083E3C
    /* 1B63C 80083E3C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B640 80083E40 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B644 80083E44 2180C000 */  addu       $s0, $a2, $zero
    /* 1B648 80083E48 0E000424 */  addiu      $a0, $zero, 0xE
    /* 1B64C 80083E4C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B650 80083E50 0804020C */  jal        func_80081020
    /* 1B654 80083E54 21280002 */   addu      $a1, $s0, $zero
    /* 1B658 80083E58 08004010 */  beqz       $v0, .L80083E7C
    /* 1B65C 80083E5C 00000000 */   nop
    /* 1B660 80083E60 FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B664 80083E64 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B668 80083E68 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B66C 80083E6C 24186200 */  and        $v1, $v1, $v0
    /* 1B670 80083E70 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 1B674 80083E74 25186200 */  or         $v1, $v1, $v0
    /* 1B678 80083E78 1C0003AE */  sw         $v1, 0x1C($s0)
  .L80083E7C:
    /* 1B67C 80083E7C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B680 80083E80 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B684 80083E84 0800E003 */  jr         $ra
    /* 1B688 80083E88 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083E3C
