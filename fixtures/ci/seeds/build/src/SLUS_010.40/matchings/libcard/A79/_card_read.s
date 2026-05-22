nonmatching _card_read, 0xC

glabel _card_read
    /* 1FD14 8002F514 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 1FD18 8002F518 08004001 */  jr         $t2
    /* 1FD1C 8002F51C 4F000924 */   addiu     $t1, $zero, 0x4F
endlabel _card_read
    /* 1FD20 8002F520 00000000 */  nop
