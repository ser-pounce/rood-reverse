nonmatching func_8008413C, 0x50

glabel func_8008413C
    /* 1B93C 8008413C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B940 80084140 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B944 80084144 2180C000 */  addu       $s0, $a2, $zero
    /* 1B948 80084148 0F000424 */  addiu      $a0, $zero, 0xF
    /* 1B94C 8008414C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B950 80084150 3304020C */  jal        func_800810CC
    /* 1B954 80084154 21280002 */   addu      $a1, $s0, $zero
    /* 1B958 80084158 08004010 */  beqz       $v0, .L8008417C
    /* 1B95C 8008415C 00000000 */   nop
    /* 1B960 80084160 FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B964 80084164 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B968 80084168 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B96C 8008416C 24186200 */  and        $v1, $v1, $v0
    /* 1B970 80084170 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 1B974 80084174 25186200 */  or         $v1, $v1, $v0
    /* 1B978 80084178 1C0003AE */  sw         $v1, 0x1C($s0)
  .L8008417C:
    /* 1B97C 8008417C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B980 80084180 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B984 80084184 0800E003 */  jr         $ra
    /* 1B988 80084188 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008413C
