nonmatching StopPAD2, 0xC

glabel StopPAD2
    /* 1F554 8002ED54 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 1F558 8002ED58 08004001 */  jr         $t2
    /* 1F55C 8002ED5C 14000924 */   addiu     $t1, $zero, 0x14
endlabel StopPAD2
    /* 1F560 8002ED60 00000000 */  nop
