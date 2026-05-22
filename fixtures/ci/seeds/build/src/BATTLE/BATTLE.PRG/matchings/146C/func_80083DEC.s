nonmatching func_80083DEC, 0x50

glabel func_80083DEC
    /* 1B5EC 80083DEC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B5F0 80083DF0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B5F4 80083DF4 2180C000 */  addu       $s0, $a2, $zero
    /* 1B5F8 80083DF8 0D000424 */  addiu      $a0, $zero, 0xD
    /* 1B5FC 80083DFC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B600 80083E00 0804020C */  jal        func_80081020
    /* 1B604 80083E04 21280002 */   addu      $a1, $s0, $zero
    /* 1B608 80083E08 08004010 */  beqz       $v0, .L80083E2C
    /* 1B60C 80083E0C 00000000 */   nop
    /* 1B610 80083E10 FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B614 80083E14 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B618 80083E18 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B61C 80083E1C 24186200 */  and        $v1, $v1, $v0
    /* 1B620 80083E20 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 1B624 80083E24 25186200 */  or         $v1, $v1, $v0
    /* 1B628 80083E28 1C0003AE */  sw         $v1, 0x1C($s0)
  .L80083E2C:
    /* 1B62C 80083E2C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B630 80083E30 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B634 80083E34 0800E003 */  jr         $ra
    /* 1B638 80083E38 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083DEC
