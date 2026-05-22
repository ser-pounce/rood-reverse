nonmatching DisableEvent, 0xC

glabel DisableEvent
    /* 17124 80026924 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 17128 80026928 08004001 */  jr         $t2
    /* 1712C 8002692C 0D000924 */   addiu     $t1, $zero, 0xD
endlabel DisableEvent
    /* 17130 80026930 00000000 */  nop
