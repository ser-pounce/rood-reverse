nonmatching vs_battle_script_freeMusic, 0x34

glabel vs_battle_script_freeMusic
    /* 51DB4 800BA5B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51DB8 800BA5B8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51DBC 800BA5BC 01008490 */  lbu        $a0, 0x1($a0)
    /* 51DC0 800BA5C0 1015010C */  jal        vs_main_freeMusic
    /* 51DC4 800BA5C4 00000000 */   nop
    /* 51DC8 800BA5C8 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 51DCC 800BA5CC 2C4C4290 */  lbu        $v0, %lo(D_800F4C2C)($v0)
    /* 51DD0 800BA5D0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51DD4 800BA5D4 02004238 */  xori       $v0, $v0, 0x2
    /* 51DD8 800BA5D8 0100422C */  sltiu      $v0, $v0, 0x1
    /* 51DDC 800BA5DC 80100200 */  sll        $v0, $v0, 2
    /* 51DE0 800BA5E0 0800E003 */  jr         $ra
    /* 51DE4 800BA5E4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_freeMusic
