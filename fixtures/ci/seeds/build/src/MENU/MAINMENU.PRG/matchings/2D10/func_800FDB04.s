nonmatching func_800FDB04, 0x5C

glabel func_800FDB04
    /* 4304 800FDB04 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4308 800FDB08 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 430C 800FDB0C 1080033C */  lui        $v1, %hi(vs_mainMenu_blades)
    /* 4310 800FDB10 1000A527 */  addiu      $a1, $sp, 0x10
    /* 4314 800FDB14 A1244290 */  lbu        $v0, %lo(D_801024A1)($v0)
    /* 4318 800FDB18 1800A627 */  addiu      $a2, $sp, 0x18
    /* 431C 800FDB1C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 4320 800FDB20 40200200 */  sll        $a0, $v0, 1
    /* 4324 800FDB24 21208200 */  addu       $a0, $a0, $v0
    /* 4328 800FDB28 80200400 */  sll        $a0, $a0, 2
    /* 432C 800FDB2C 23208200 */  subu       $a0, $a0, $v0
    /* 4330 800FDB30 80200400 */  sll        $a0, $a0, 2
    /* 4334 800FDB34 D4FF8424 */  addiu      $a0, $a0, -0x2C
    /* 4338 800FDB38 6424628C */  lw         $v0, %lo(vs_mainMenu_blades)($v1)
    /* 433C 800FDB3C 0F80033C */  lui        $v1, %hi(vs_battle_stringBuf)
    /* 4340 800FDB40 8C4E678C */  lw         $a3, %lo(vs_battle_stringBuf)($v1)
    /* 4344 800FDB44 A9F2030C */  jal        vs_mainMenu_setUiBlade
    /* 4348 800FDB48 21204400 */   addu      $a0, $v0, $a0
    /* 434C 800FDB4C 1400A28F */  lw         $v0, 0x14($sp)
    /* 4350 800FDB50 2000BF8F */  lw         $ra, 0x20($sp)
    /* 4354 800FDB54 00000000 */  nop
    /* 4358 800FDB58 0800E003 */  jr         $ra
    /* 435C 800FDB5C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800FDB04
