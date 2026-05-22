nonmatching vs_battle_setDoorEntered, 0x18

glabel vs_battle_setDoorEntered
    /* 22368 8008AB68 0F80023C */  lui        $v0, %hi(vs_battle_doorEntered)
    /* 2236C 8008AB6C BE1B4290 */  lbu        $v0, %lo(vs_battle_doorEntered)($v0)
    /* 22370 8008AB70 0680033C */  lui        $v1, %hi(vs_main_stateFlags + 0x105)
    /* 22374 8008AB74 01004224 */  addiu      $v0, $v0, 0x1
    /* 22378 8008AB78 0800E003 */  jr         $ra
    /* 2237C 8008AB7C 9D1662A0 */   sb        $v0, %lo(vs_main_stateFlags + 0x105)($v1)
endlabel vs_battle_setDoorEntered
