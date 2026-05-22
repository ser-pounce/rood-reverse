nonmatching FlushCache, 0xC

glabel FlushCache
    /* 17074 80026874 A0000A24 */  addiu      $t2, $zero, 0xA0
    /* 17078 80026878 08004001 */  jr         $t2
    /* 1707C 8002687C 44000924 */   addiu     $t1, $zero, 0x44
endlabel FlushCache
    /* 17080 80026880 00000000 */  nop
