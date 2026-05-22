nonmatching func_8008B8F8, 0x68

glabel func_8008B8F8
    /* 230F8 8008B8F8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 230FC 8008B8FC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 23100 8008B900 21808000 */  addu       $s0, $a0, $zero
    /* 23104 8008B904 0B000012 */  beqz       $s0, .L8008B934
    /* 23108 8008B908 1400BFAF */   sw        $ra, 0x14($sp)
    /* 2310C 8008B90C 0F80043C */  lui        $a0, %hi(D_800F1CC8)
    /* 23110 8008B910 C81C8424 */  addiu      $a0, $a0, %lo(D_800F1CC8)
    /* 23114 8008B914 21280002 */  addu       $a1, $s0, $zero
    /* 23118 8008B918 2C24010C */  jal        vs_main_memcpy
    /* 2311C 8008B91C 0C000624 */   addiu     $a2, $zero, 0xC
    /* 23120 8008B920 08000492 */  lbu        $a0, 0x8($s0)
    /* 23124 8008B924 2036020C */  jal        _getDoorId
    /* 23128 8008B928 00000000 */   nop
    /* 2312C 8008B92C 532E0208 */  j          .L8008B94C
    /* 23130 8008B930 0F80033C */   lui       $v1, %hi(vs_battle_doorEntered)
  .L8008B934:
    /* 23134 8008B934 0F80043C */  lui        $a0, %hi(D_800F1CC8)
    /* 23138 8008B938 C81C8424 */  addiu      $a0, $a0, %lo(D_800F1CC8)
    /* 2313C 8008B93C 4424010C */  jal        vs_main_bzero
    /* 23140 8008B940 0C000524 */   addiu     $a1, $zero, 0xC
    /* 23144 8008B944 0F80033C */  lui        $v1, %hi(vs_battle_doorEntered)
    /* 23148 8008B948 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8008B94C:
    /* 2314C 8008B94C BE1B62A4 */  sh         $v0, %lo(vs_battle_doorEntered)($v1)
    /* 23150 8008B950 1400BF8F */  lw         $ra, 0x14($sp)
    /* 23154 8008B954 1000B08F */  lw         $s0, 0x10($sp)
    /* 23158 8008B958 0800E003 */  jr         $ra
    /* 2315C 8008B95C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008B8F8
