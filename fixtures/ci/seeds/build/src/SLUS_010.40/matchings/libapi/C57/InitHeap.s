nonmatching InitHeap, 0xC

glabel InitHeap
    /* 17064 80026864 A0000A24 */  addiu      $t2, $zero, 0xA0
    /* 17068 80026868 08004001 */  jr         $t2
    /* 1706C 8002686C 39000924 */   addiu     $t1, $zero, 0x39
endlabel InitHeap
    /* 17070 80026870 00000000 */  nop
