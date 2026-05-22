nonmatching _new_card, 0xC

glabel _new_card
    /* 1F124 8002E924 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 1F128 8002E928 08004001 */  jr         $t2
    /* 1F12C 8002E92C 50000924 */   addiu     $t1, $zero, 0x50
endlabel _new_card
    /* 1F130 8002E930 00000000 */  nop
