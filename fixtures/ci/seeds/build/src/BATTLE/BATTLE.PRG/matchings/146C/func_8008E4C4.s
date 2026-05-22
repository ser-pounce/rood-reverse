nonmatching func_8008E4C4, 0x18

glabel func_8008E4C4
    /* 25CC4 8008E4C4 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x8C)
    /* 25CC8 8008E4C8 841C428C */  lw         $v0, %lo(vs_battle_roomData + 0x8C)($v0)
    /* 25CCC 8008E4CC 00000000 */  nop
    /* 25CD0 8008E4D0 32004290 */  lbu        $v0, 0x32($v0)
    /* 25CD4 8008E4D4 0800E003 */  jr         $ra
    /* 25CD8 8008E4D8 00000000 */   nop
endlabel func_8008E4C4
