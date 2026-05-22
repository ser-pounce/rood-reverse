nonmatching func_8007C31C, 0x2C

glabel func_8007C31C
    /* 13B1C 8007C31C 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 13B20 8007C320 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 13B24 8007C324 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 13B28 8007C328 1000BFAF */  sw         $ra, 0x10($sp)
    /* 13B2C 8007C32C 3C00458C */  lw         $a1, 0x3C($v0)
    /* 13B30 8007C330 D519020C */  jal        func_80086754
    /* 13B34 8007C334 21200000 */   addu      $a0, $zero, $zero
    /* 13B38 8007C338 1000BF8F */  lw         $ra, 0x10($sp)
    /* 13B3C 8007C33C 00000000 */  nop
    /* 13B40 8007C340 0800E003 */  jr         $ra
    /* 13B44 8007C344 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007C31C
