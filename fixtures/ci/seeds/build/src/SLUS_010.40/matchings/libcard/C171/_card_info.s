nonmatching _card_info, 0xC

glabel _card_info
    /* 1F0B4 8002E8B4 A0000A24 */  addiu      $t2, $zero, 0xA0
    /* 1F0B8 8002E8B8 08004001 */  jr         $t2
    /* 1F0BC 8002E8BC AB000924 */   addiu     $t1, $zero, 0xAB
endlabel _card_info
    /* 1F0C0 8002E8C0 00000000 */  nop
