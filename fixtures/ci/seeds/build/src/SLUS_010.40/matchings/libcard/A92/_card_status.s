nonmatching _card_status, 0xC

glabel _card_status
    /* 1FD24 8002F524 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 1FD28 8002F528 08004001 */  jr         $t2
    /* 1FD2C 8002F52C 5C000924 */   addiu     $t1, $zero, 0x5C
endlabel _card_status
    /* 1FD30 8002F530 00000000 */  nop
