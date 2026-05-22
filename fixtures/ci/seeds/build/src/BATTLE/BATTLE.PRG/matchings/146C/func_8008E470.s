nonmatching func_8008E470, 0x10

glabel func_8008E470
    /* 25C70 8008E470 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0xB0)
    /* 25C74 8008E474 A81C428C */  lw         $v0, %lo(vs_battle_roomData + 0xB0)($v0)
    /* 25C78 8008E478 0800E003 */  jr         $ra
    /* 25C7C 8008E47C 0100422C */   sltiu     $v0, $v0, 0x1
endlabel func_8008E470
