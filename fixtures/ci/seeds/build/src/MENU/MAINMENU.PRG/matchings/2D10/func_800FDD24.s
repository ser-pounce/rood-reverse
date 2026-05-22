nonmatching func_800FDD24, 0x54

glabel func_800FDD24
    /* 4524 800FDD24 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4528 800FDD28 1080023C */  lui        $v0, %hi(D_801024A1)
    /* 452C 800FDD2C 1080033C */  lui        $v1, %hi(vs_mainMenu_gems)
    /* 4530 800FDD30 1000A527 */  addiu      $a1, $sp, 0x10
    /* 4534 800FDD34 A1244290 */  lbu        $v0, %lo(D_801024A1)($v0)
    /* 4538 800FDD38 1800A627 */  addiu      $a2, $sp, 0x18
    /* 453C 800FDD3C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 4540 800FDD40 C0200200 */  sll        $a0, $v0, 3
    /* 4544 800FDD44 23208200 */  subu       $a0, $a0, $v0
    /* 4548 800FDD48 80200400 */  sll        $a0, $a0, 2
    /* 454C 800FDD4C E4FF8424 */  addiu      $a0, $a0, -0x1C
    /* 4550 800FDD50 5824628C */  lw         $v0, %lo(vs_mainMenu_gems)($v1)
    /* 4554 800FDD54 0F80033C */  lui        $v1, %hi(vs_battle_stringBuf)
    /* 4558 800FDD58 8C4E678C */  lw         $a3, %lo(vs_battle_stringBuf)($v1)
    /* 455C 800FDD5C 38F4030C */  jal        vs_mainMenu_setUiGem
    /* 4560 800FDD60 21204400 */   addu      $a0, $v0, $a0
    /* 4564 800FDD64 1400A28F */  lw         $v0, 0x14($sp)
    /* 4568 800FDD68 2000BF8F */  lw         $ra, 0x20($sp)
    /* 456C 800FDD6C 00000000 */  nop
    /* 4570 800FDD70 0800E003 */  jr         $ra
    /* 4574 800FDD74 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800FDD24
