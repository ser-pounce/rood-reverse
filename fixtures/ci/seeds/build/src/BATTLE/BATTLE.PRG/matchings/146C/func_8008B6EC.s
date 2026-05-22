nonmatching func_8008B6EC, 0x10

glabel func_8008B6EC
    /* 22EEC 8008B6EC 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x6C)
    /* 22EF0 8008B6F0 641C428C */  lw         $v0, %lo(vs_battle_roomData + 0x6C)($v0)
    /* 22EF4 8008B6F4 0800E003 */  jr         $ra
    /* 22EF8 8008B6F8 00000000 */   nop
endlabel func_8008B6EC
