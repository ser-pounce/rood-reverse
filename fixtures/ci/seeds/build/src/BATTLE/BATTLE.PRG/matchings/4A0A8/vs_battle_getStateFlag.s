nonmatching vs_battle_getStateFlag, 0x20

glabel vs_battle_getStateFlag
    /* 563F4 800BEBF4 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 563F8 800BEBF8 98154224 */  addiu      $v0, $v0, %lo(vs_main_stateFlags)
    /* 563FC 800BEBFC 00240400 */  sll        $a0, $a0, 16
    /* 56400 800BEC00 03240400 */  sra        $a0, $a0, 16
    /* 56404 800BEC04 21208200 */  addu       $a0, $a0, $v0
    /* 56408 800BEC08 00008290 */  lbu        $v0, 0x0($a0)
    /* 5640C 800BEC0C 0800E003 */  jr         $ra
    /* 56410 800BEC10 00000000 */   nop
endlabel vs_battle_getStateFlag
