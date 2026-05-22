nonmatching _card_load, 0xC

glabel _card_load
    /* 1F0C4 8002E8C4 A0000A24 */  addiu      $t2, $zero, 0xA0
    /* 1F0C8 8002E8C8 08004001 */  jr         $t2
    /* 1F0CC 8002E8CC AC000924 */   addiu     $t1, $zero, 0xAC
endlabel _card_load
    /* 1F0D0 8002E8D0 00000000 */  nop
