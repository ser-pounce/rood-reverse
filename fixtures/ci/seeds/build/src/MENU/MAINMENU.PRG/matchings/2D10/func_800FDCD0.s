nonmatching func_800FDCD0, 0x54

glabel func_800FDCD0
    /* 44D0 800FDCD0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 44D4 800FDCD4 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 44D8 800FDCD8 1080033C */  lui        $v1, %hi(vs_mainMenu_armor)
    /* 44DC 800FDCDC 1000A527 */  addiu      $a1, $sp, 0x10
    /* 44E0 800FDCE0 A1244290 */  lbu        $v0, %lo(D_801024A1)($v0)
    /* 44E4 800FDCE4 1800A627 */  addiu      $a2, $sp, 0x18
    /* 44E8 800FDCE8 2000BFAF */  sw         $ra, 0x20($sp)
    /* 44EC 800FDCEC 80200200 */  sll        $a0, $v0, 2
    /* 44F0 800FDCF0 21208200 */  addu       $a0, $a0, $v0
    /* 44F4 800FDCF4 C0200400 */  sll        $a0, $a0, 3
    /* 44F8 800FDCF8 D8FF8424 */  addiu      $a0, $a0, -0x28
    /* 44FC 800FDCFC 6824628C */  lw         $v0, %lo(vs_mainMenu_armor)($v1)
    /* 4500 800FDD00 0F80033C */  lui        $v1, %hi(vs_battle_stringBuf)
    /* 4504 800FDD04 8C4E678C */  lw         $a3, %lo(vs_battle_stringBuf)($v1)
    /* 4508 800FDD08 21F4030C */  jal        vs_mainMenu_initUiArmor
    /* 450C 800FDD0C 21204400 */   addu      $a0, $v0, $a0
    /* 4510 800FDD10 1400A28F */  lw         $v0, 0x14($sp)
    /* 4514 800FDD14 2000BF8F */  lw         $ra, 0x20($sp)
    /* 4518 800FDD18 00000000 */  nop
    /* 451C 800FDD1C 0800E003 */  jr         $ra
    /* 4520 800FDD20 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800FDCD0
