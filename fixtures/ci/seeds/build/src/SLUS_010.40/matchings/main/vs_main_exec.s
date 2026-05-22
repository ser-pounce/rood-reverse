nonmatching vs_main_exec, 0x3C

glabel vs_main_exec
    /* 33438 80042C38 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3343C 80042C3C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 33440 80042C40 7B7D000C */  jal        __main
    /* 33444 80042C44 00000000 */   nop
    /* 33448 80042C48 660A010C */  jal        func_80042998
    /* 3344C 80042C4C 00000000 */   nop
    /* 33450 80042C50 0580043C */  lui        $a0, %hi(sp2)
    /* 33454 80042C54 A942000C */  jal        vs_overlay_getSp
    /* 33458 80042C58 74048424 */   addiu     $a0, $a0, %lo(sp2)
    /* 3345C 80042C5C EB0A010C */  jal        func_80042BAC
    /* 33460 80042C60 00000000 */   nop
    /* 33464 80042C64 1000BF8F */  lw         $ra, 0x10($sp)
    /* 33468 80042C68 00000000 */  nop
    /* 3346C 80042C6C 0800E003 */  jr         $ra
    /* 33470 80042C70 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_main_exec
