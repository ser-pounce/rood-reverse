nonmatching func_80083D2C, 0x50

glabel func_80083D2C
    /* 1B52C 80083D2C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B530 80083D30 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B534 80083D34 2180C000 */  addu       $s0, $a2, $zero
    /* 1B538 80083D38 11000424 */  addiu      $a0, $zero, 0x11
    /* 1B53C 80083D3C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B540 80083D40 0804020C */  jal        func_80081020
    /* 1B544 80083D44 21280002 */   addu      $a1, $s0, $zero
    /* 1B548 80083D48 08004010 */  beqz       $v0, .L80083D6C
    /* 1B54C 80083D4C 00000000 */   nop
    /* 1B550 80083D50 FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B554 80083D54 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B558 80083D58 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B55C 80083D5C 24186200 */  and        $v1, $v1, $v0
    /* 1B560 80083D60 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 1B564 80083D64 25186200 */  or         $v1, $v1, $v0
    /* 1B568 80083D68 1C0003AE */  sw         $v1, 0x1C($s0)
  .L80083D6C:
    /* 1B56C 80083D6C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B570 80083D70 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B574 80083D74 0800E003 */  jr         $ra
    /* 1B578 80083D78 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083D2C
