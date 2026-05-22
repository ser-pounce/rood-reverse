nonmatching func_80104AF8, 0x48

glabel func_80104AF8
    /* 22F8 80104AF8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 22FC 80104AFC 801F043C */  lui        $a0, (0x1F800034 >> 16)
    /* 2300 80104B00 34008434 */  ori        $a0, $a0, (0x1F800034 & 0xFFFF)
    /* 2304 80104B04 1180053C */  lui        $a1, %hi(D_8010A480)
    /* 2308 80104B08 80A4A524 */  addiu      $a1, $a1, %lo(D_8010A480)
    /* 230C 80104B0C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2310 80104B10 2C24010C */  jal        vs_main_memcpy
    /* 2314 80104B14 10000624 */   addiu     $a2, $zero, 0x10
    /* 2318 80104B18 801F043C */  lui        $a0, (0x1F800054 >> 16)
    /* 231C 80104B1C 54008434 */  ori        $a0, $a0, (0x1F800054 & 0xFFFF)
    /* 2320 80104B20 1180053C */  lui        $a1, %hi(D_8010A490)
    /* 2324 80104B24 90A4A524 */  addiu      $a1, $a1, %lo(D_8010A490)
    /* 2328 80104B28 2C24010C */  jal        vs_main_memcpy
    /* 232C 80104B2C 10000624 */   addiu     $a2, $zero, 0x10
    /* 2330 80104B30 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2334 80104B34 00000000 */  nop
    /* 2338 80104B38 0800E003 */  jr         $ra
    /* 233C 80104B3C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80104AF8
