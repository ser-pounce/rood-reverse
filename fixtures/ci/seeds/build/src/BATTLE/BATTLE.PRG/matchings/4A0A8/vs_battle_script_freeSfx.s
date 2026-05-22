nonmatching vs_battle_script_freeSfx, 0x34

glabel vs_battle_script_freeSfx
    /* 51C94 800BA494 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51C98 800BA498 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51C9C 800BA49C 01008490 */  lbu        $a0, 0x1($a0)
    /* 51CA0 800BA4A0 3018010C */  jal        vs_main_freeSfx
    /* 51CA4 800BA4A4 00000000 */   nop
    /* 51CA8 800BA4A8 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 51CAC 800BA4AC 2C4C4290 */  lbu        $v0, %lo(D_800F4C2C)($v0)
    /* 51CB0 800BA4B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51CB4 800BA4B4 02004238 */  xori       $v0, $v0, 0x2
    /* 51CB8 800BA4B8 0100422C */  sltiu      $v0, $v0, 0x1
    /* 51CBC 800BA4BC 80100200 */  sll        $v0, $v0, 2
    /* 51CC0 800BA4C0 0800E003 */  jr         $ra
    /* 51CC4 800BA4C4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_freeSfx
