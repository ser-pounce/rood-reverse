nonmatching func_8008404C, 0x50

glabel func_8008404C
    /* 1B84C 8008404C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B850 80084050 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1B854 80084054 2180C000 */  addu       $s0, $a2, $zero
    /* 1B858 80084058 0D000424 */  addiu      $a0, $zero, 0xD
    /* 1B85C 8008405C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1B860 80084060 3304020C */  jal        func_800810CC
    /* 1B864 80084064 21280002 */   addu      $a1, $s0, $zero
    /* 1B868 80084068 08004010 */  beqz       $v0, .L8008408C
    /* 1B86C 8008406C 00000000 */   nop
    /* 1B870 80084070 FCFF023C */  lui        $v0, (0xFFFCFFFF >> 16)
    /* 1B874 80084074 1C00038E */  lw         $v1, 0x1C($s0)
    /* 1B878 80084078 FFFF4234 */  ori        $v0, $v0, (0xFFFCFFFF & 0xFFFF)
    /* 1B87C 8008407C 24186200 */  and        $v1, $v1, $v0
    /* 1B880 80084080 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 1B884 80084084 25186200 */  or         $v1, $v1, $v0
    /* 1B888 80084088 1C0003AE */  sw         $v1, 0x1C($s0)
  .L8008408C:
    /* 1B88C 8008408C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1B890 80084090 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B894 80084094 0800E003 */  jr         $ra
    /* 1B898 80084098 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008404C
