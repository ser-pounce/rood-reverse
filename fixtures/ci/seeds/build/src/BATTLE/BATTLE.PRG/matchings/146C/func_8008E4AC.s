nonmatching func_8008E4AC, 0x18

glabel func_8008E4AC
    /* 25CAC 8008E4AC 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x8C)
    /* 25CB0 8008E4B0 841C428C */  lw         $v0, %lo(vs_battle_roomData + 0x8C)($v0)
    /* 25CB4 8008E4B4 00000000 */  nop
    /* 25CB8 8008E4B8 56004284 */  lh         $v0, 0x56($v0)
    /* 25CBC 8008E4BC 0800E003 */  jr         $ra
    /* 25CC0 8008E4C0 00000000 */   nop
endlabel func_8008E4AC
