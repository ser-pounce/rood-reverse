nonmatching _card_write, 0xC

glabel _card_write
    /* 1F114 8002E914 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 1F118 8002E918 08004001 */  jr         $t2
    /* 1F11C 8002E91C 4E000924 */   addiu     $t1, $zero, 0x4E
endlabel _card_write
    /* 1F120 8002E920 00000000 */  nop
