nonmatching func_8008B320, 0x70

glabel func_8008B320
    /* 22B20 8008B320 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 22B24 8008B324 21280000 */  addu       $a1, $zero, $zero
    /* 22B28 8008B328 2130A000 */  addu       $a2, $a1, $zero
    /* 22B2C 8008B32C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 22B30 8008B330 0F80103C */  lui        $s0, %hi(D_800F1BA8)
    /* 22B34 8008B334 A81B048E */  lw         $a0, %lo(D_800F1BA8)($s0)
    /* 22B38 8008B338 1400BFAF */  sw         $ra, 0x14($sp)
    /* 22B3C 8008B33C 9922010C */  jal        vs_main_loadClut
    /* 22B40 8008B340 00010724 */   addiu     $a3, $zero, 0x100
    /* 22B44 8008B344 01000524 */  addiu      $a1, $zero, 0x1
    /* 22B48 8008B348 21300000 */  addu       $a2, $zero, $zero
    /* 22B4C 8008B34C A81B048E */  lw         $a0, %lo(D_800F1BA8)($s0)
    /* 22B50 8008B350 00010724 */  addiu      $a3, $zero, 0x100
    /* 22B54 8008B354 9922010C */  jal        vs_main_loadClut
    /* 22B58 8008B358 00028424 */   addiu     $a0, $a0, 0x200
    /* 22B5C 8008B35C 02000524 */  addiu      $a1, $zero, 0x2
    /* 22B60 8008B360 21300000 */  addu       $a2, $zero, $zero
    /* 22B64 8008B364 A81B048E */  lw         $a0, %lo(D_800F1BA8)($s0)
    /* 22B68 8008B368 00010724 */  addiu      $a3, $zero, 0x100
    /* 22B6C 8008B36C 9922010C */  jal        vs_main_loadClut
    /* 22B70 8008B370 00048424 */   addiu     $a0, $a0, 0x400
    /* 22B74 8008B374 A81B048E */  lw         $a0, %lo(D_800F1BA8)($s0)
    /* 22B78 8008B378 5866020C */  jal        func_80099960
    /* 22B7C 8008B37C 00068424 */   addiu     $a0, $a0, 0x600
    /* 22B80 8008B380 1400BF8F */  lw         $ra, 0x14($sp)
    /* 22B84 8008B384 1000B08F */  lw         $s0, 0x10($sp)
    /* 22B88 8008B388 0800E003 */  jr         $ra
    /* 22B8C 8008B38C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008B320
