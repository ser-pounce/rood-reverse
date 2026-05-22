nonmatching func_8008631C, 0x88

glabel func_8008631C
    /* 1DB1C 8008631C 90F7BD27 */  addiu      $sp, $sp, -0x870
    /* 1DB20 80086320 6408B1AF */  sw         $s1, 0x864($sp)
    /* 1DB24 80086324 21888000 */  addu       $s1, $a0, $zero
    /* 1DB28 80086328 6008B0AF */  sw         $s0, 0x860($sp)
    /* 1DB2C 8008632C 2180A000 */  addu       $s0, $a1, $zero
    /* 1DB30 80086330 5C00A6A3 */  sb         $a2, 0x5C($sp)
    /* 1DB34 80086334 1000A627 */  addiu      $a2, $sp, 0x10
    /* 1DB38 80086338 01000224 */  addiu      $v0, $zero, 0x1
    /* 1DB3C 8008633C 1000B1A7 */  sh         $s1, 0x10($sp)
    /* 1DB40 80086340 5400A0AF */  sw         $zero, 0x54($sp)
    /* 1DB44 80086344 1400B0A3 */  sb         $s0, 0x14($sp)
    /* 1DB48 80086348 5A00A2A7 */  sh         $v0, 0x5A($sp)
    /* 1DB4C 8008634C 9C00A0AF */  sw         $zero, 0x9C($sp)
    /* 1DB50 80086350 5D00A7A3 */  sb         $a3, 0x5D($sp)
    /* 1DB54 80086354 8008A58F */  lw         $a1, 0x880($sp)
    /* 1DB58 80086358 6808BFAF */  sw         $ra, 0x868($sp)
    /* 1DB5C 8008635C C416020C */  jal        func_80085B10
    /* 1DB60 80086360 21380000 */   addu      $a3, $zero, $zero
    /* 1DB64 80086364 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 1DB68 80086368 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 1DB6C 8008636C 80801000 */  sll        $s0, $s0, 2
    /* 1DB70 80086370 21800202 */  addu       $s0, $s0, $v0
    /* 1DB74 80086374 0000028E */  lw         $v0, 0x0($s0)
    /* 1DB78 80086378 21202002 */  addu       $a0, $s1, $zero
    /* 1DB7C 8008637C 3C00458C */  lw         $a1, 0x3C($v0)
    /* 1DB80 80086380 D315020C */  jal        func_8008574C
    /* 1DB84 80086384 21300000 */   addu      $a2, $zero, $zero
    /* 1DB88 80086388 00FF033C */  lui        $v1, (0xFF000000 >> 16)
    /* 1DB8C 8008638C 6808BF8F */  lw         $ra, 0x868($sp)
    /* 1DB90 80086390 6408B18F */  lw         $s1, 0x864($sp)
    /* 1DB94 80086394 6008B08F */  lw         $s0, 0x860($sp)
    /* 1DB98 80086398 24104300 */  and        $v0, $v0, $v1
    /* 1DB9C 8008639C 0800E003 */  jr         $ra
    /* 1DBA0 800863A0 7008BD27 */   addiu     $sp, $sp, 0x870
endlabel func_8008631C
