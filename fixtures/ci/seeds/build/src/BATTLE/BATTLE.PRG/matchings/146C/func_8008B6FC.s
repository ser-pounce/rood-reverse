nonmatching func_8008B6FC, 0x10

glabel func_8008B6FC
    /* 22EFC 8008B6FC 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x78)
    /* 22F00 8008B700 701C428C */  lw         $v0, %lo(vs_battle_roomData + 0x78)($v0)
    /* 22F04 8008B704 0800E003 */  jr         $ra
    /* 22F08 8008B708 00000000 */   nop
endlabel func_8008B6FC
