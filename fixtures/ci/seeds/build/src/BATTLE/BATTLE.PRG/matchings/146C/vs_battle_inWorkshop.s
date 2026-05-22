nonmatching vs_battle_inWorkshop, 0x18

glabel vs_battle_inWorkshop
    /* 24BD0 8008D3D0 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x8C)
    /* 24BD4 8008D3D4 841C428C */  lw         $v0, %lo(vs_battle_roomData + 0x8C)($v0)
    /* 24BD8 8008D3D8 00000000 */  nop
    /* 24BDC 8008D3DC 30004290 */  lbu        $v0, 0x30($v0)
    /* 24BE0 8008D3E0 0800E003 */  jr         $ra
    /* 24BE4 8008D3E4 00000000 */   nop
endlabel vs_battle_inWorkshop
