nonmatching func_8002AB84, 0x34

glabel func_8002AB84
    /* 1B384 8002AB84 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B388 8002AB88 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1B38C 8002AB8C B17D000C */  jal        VSync
    /* 1B390 8002AB90 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 1B394 8002AB94 F0004224 */  addiu      $v0, $v0, 0xF0
    /* 1B398 8002AB98 0380013C */  lui        $at, %hi(D_80033580)
    /* 1B39C 8002AB9C 803522AC */  sw         $v0, %lo(D_80033580)($at)
    /* 1B3A0 8002ABA0 0380013C */  lui        $at, %hi(D_80033584)
    /* 1B3A4 8002ABA4 843520AC */  sw         $zero, %lo(D_80033584)($at)
    /* 1B3A8 8002ABA8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1B3AC 8002ABAC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1B3B0 8002ABB0 0800E003 */  jr         $ra
    /* 1B3B4 8002ABB4 00000000 */   nop
endlabel func_8002AB84
