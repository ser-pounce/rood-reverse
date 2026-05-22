nonmatching func_800840EC, 0x50

glabel func_800840EC
    /* 1B8EC 800840EC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B8F0 800840F0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B8F4 800840F4 2180C000 */  addu       $s0, $a2, $zero
    /* 1B8F8 800840F8 10000424 */  addiu      $a0, $zero, 0x10
    /* 1B8FC 800840FC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B900 80084100 3304020C */  jal        func_800810CC
    /* 1B904 80084104 21280002 */   addu      $a1, $s0, $zero
    /* 1B908 80084108 08004010 */  beqz       $v0, .L8008412C
    /* 1B90C 8008410C 00000000 */   nop
    /* 1B910 80084110 FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B914 80084114 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B918 80084118 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B91C 8008411C 24186200 */  and        $v1, $v1, $v0
    /* 1B920 80084120 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 1B924 80084124 25186200 */  or         $v1, $v1, $v0
    /* 1B928 80084128 1C0003AE */  sw         $v1, 0x1C($s0)
  .L8008412C:
    /* 1B92C 8008412C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B930 80084130 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B934 80084134 0800E003 */  jr         $ra
    /* 1B938 80084138 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800840EC
