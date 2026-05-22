nonmatching func_8008D3E8, 0x18

glabel func_8008D3E8
    /* 24BE8 8008D3E8 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x8C)
    /* 24BEC 8008D3EC 841C428C */  lw         $v0, %lo(vs_battle_roomData + 0x8C)($v0)
    /* 24BF0 8008D3F0 00000000 */  nop
    /* 24BF4 8008D3F4 31004290 */  lbu        $v0, 0x31($v0)
    /* 24BF8 8008D3F8 0800E003 */  jr         $ra
    /* 24BFC 8008D3FC 00000000 */   nop
endlabel func_8008D3E8
