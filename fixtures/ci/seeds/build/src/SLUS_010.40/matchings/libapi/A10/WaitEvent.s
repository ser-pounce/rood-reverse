nonmatching WaitEvent, 0xC

glabel WaitEvent
    /* 170F4 800268F4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 170F8 800268F8 08004001 */  jr         $t2
    /* 170FC 800268FC 0A000924 */   addiu     $t1, $zero, 0xA
endlabel WaitEvent
    /* 17100 80026900 00000000 */  nop
