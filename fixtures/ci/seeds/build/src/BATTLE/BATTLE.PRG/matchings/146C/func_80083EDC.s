nonmatching func_80083EDC, 0x50

glabel func_80083EDC
    /* 1B6DC 80083EDC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B6E0 80083EE0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B6E4 80083EE4 2180C000 */  addu       $s0, $a2, $zero
    /* 1B6E8 80083EE8 10000424 */  addiu      $a0, $zero, 0x10
    /* 1B6EC 80083EEC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B6F0 80083EF0 0804020C */  jal        func_80081020
    /* 1B6F4 80083EF4 21280002 */   addu      $a1, $s0, $zero
    /* 1B6F8 80083EF8 08004010 */  beqz       $v0, .L80083F1C
    /* 1B6FC 80083EFC 00000000 */   nop
    /* 1B700 80083F00 FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B704 80083F04 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B708 80083F08 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B70C 80083F0C 24186200 */  and        $v1, $v1, $v0
    /* 1B710 80083F10 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 1B714 80083F14 25186200 */  or         $v1, $v1, $v0
    /* 1B718 80083F18 1C0003AE */  sw         $v1, 0x1C($s0)
  .L80083F1C:
    /* 1B71C 80083F1C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B720 80083F20 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B724 80083F24 0800E003 */  jr         $ra
    /* 1B728 80083F28 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80083EDC
