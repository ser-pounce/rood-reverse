nonmatching func_800FDB60, 0x4C

glabel func_800FDB60
    /* 4360 800FDB60 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4364 800FDB64 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 4368 800FDB68 A1244490 */  lbu        $a0, %lo(D_801024A1)($v0)
    /* 436C 800FDB6C 1080023C */  lui        $v0, %hi(vs_mainMenu_grips)
    /* 4370 800FDB70 0F80033C */  lui        $v1, %hi(vs_battle_stringBuf)
    /* 4374 800FDB74 1000A527 */  addiu      $a1, $sp, 0x10
    /* 4378 800FDB78 6024428C */  lw         $v0, %lo(vs_mainMenu_grips)($v0)
    /* 437C 800FDB7C 8C4E678C */  lw         $a3, %lo(vs_battle_stringBuf)($v1)
    /* 4380 800FDB80 1800A627 */  addiu      $a2, $sp, 0x18
    /* 4384 800FDB84 2000BFAF */  sw         $ra, 0x20($sp)
    /* 4388 800FDB88 00210400 */  sll        $a0, $a0, 4
    /* 438C 800FDB8C F0FF8424 */  addiu      $a0, $a0, -0x10
    /* 4390 800FDB90 03F3030C */  jal        vs_mainMenu_setUiGrip
    /* 4394 800FDB94 21204400 */   addu      $a0, $v0, $a0
    /* 4398 800FDB98 1400A28F */  lw         $v0, 0x14($sp)
    /* 439C 800FDB9C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 43A0 800FDBA0 00000000 */  nop
    /* 43A4 800FDBA4 0800E003 */  jr         $ra
    /* 43A8 800FDBA8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800FDB60
