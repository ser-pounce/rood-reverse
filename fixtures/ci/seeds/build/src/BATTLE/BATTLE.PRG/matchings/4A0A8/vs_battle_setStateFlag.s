nonmatching vs_battle_setStateFlag, 0x1C

glabel vs_battle_setStateFlag
    /* 56414 800BEC14 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 56418 800BEC18 98154224 */  addiu      $v0, $v0, %lo(vs_main_stateFlags)
    /* 5641C 800BEC1C 00240400 */  sll        $a0, $a0, 16
    /* 56420 800BEC20 03240400 */  sra        $a0, $a0, 16
    /* 56424 800BEC24 21208200 */  addu       $a0, $a0, $v0
    /* 56428 800BEC28 0800E003 */  jr         $ra
    /* 5642C 800BEC2C 000085A0 */   sb        $a1, 0x0($a0)
endlabel vs_battle_setStateFlag
