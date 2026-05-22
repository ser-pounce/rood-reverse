nonmatching func_800B83D4, 0x64

glabel func_800B83D4
    /* 4FBD4 800B83D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4FBD8 800B83D8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4FBDC 800B83DC 21808000 */  addu       $s0, $a0, $zero
    /* 4FBE0 800B83E0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4FBE4 800B83E4 80FF020C */  jal        vs_battle_getShort
    /* 4FBE8 800B83E8 01000426 */   addiu     $a0, $s0, 0x1
    /* 4FBEC 800B83EC 94FF020C */  jal        func_800BFE50
    /* 4FBF0 800B83F0 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4FBF4 800B83F4 0F80043C */  lui        $a0, %hi(D_800E9B58)
    /* 4FBF8 800B83F8 589B8424 */  addiu      $a0, $a0, %lo(D_800E9B58)
    /* 4FBFC 800B83FC 06000692 */  lbu        $a2, 0x6($s0)
    /* 4FC00 800B8400 03000592 */  lbu        $a1, 0x3($s0)
    /* 4FC04 800B8404 04000792 */  lbu        $a3, 0x4($s0)
    /* 4FC08 800B8408 82190600 */  srl        $v1, $a2, 6
    /* 4FC0C 800B840C 21186400 */  addu       $v1, $v1, $a0
    /* 4FC10 800B8410 21204000 */  addu       $a0, $v0, $zero
    /* 4FC14 800B8414 00006390 */  lbu        $v1, 0x0($v1)
    /* 4FC18 800B8418 3F00C630 */  andi       $a2, $a2, 0x3F
    /* 4FC1C 800B841C 8681020C */  jal        func_800A0618
    /* 4FC20 800B8420 21286500 */   addu      $a1, $v1, $a1
    /* 4FC24 800B8424 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4FC28 800B8428 1000B08F */  lw         $s0, 0x10($sp)
    /* 4FC2C 800B842C 21100000 */  addu       $v0, $zero, $zero
    /* 4FC30 800B8430 0800E003 */  jr         $ra
    /* 4FC34 800B8434 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B83D4
