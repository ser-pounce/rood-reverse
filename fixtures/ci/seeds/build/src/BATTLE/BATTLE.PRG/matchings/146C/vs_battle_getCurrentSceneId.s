nonmatching vs_battle_getCurrentSceneId, 0x18

glabel vs_battle_getCurrentSceneId
    /* 24C00 8008D400 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x8C)
    /* 24C04 8008D404 841C428C */  lw         $v0, %lo(vs_battle_roomData + 0x8C)($v0)
    /* 24C08 8008D408 00000000 */  nop
    /* 24C0C 8008D40C 50004284 */  lh         $v0, 0x50($v0)
    /* 24C10 8008D410 0800E003 */  jr         $ra
    /* 24C14 8008D414 00000000 */   nop
endlabel vs_battle_getCurrentSceneId
