nonmatching ReturnFromException, 0xC

glabel ReturnFromException
    /* 17134 80026934 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 17138 80026938 08004001 */  jr         $t2
    /* 1713C 8002693C 17000924 */   addiu     $t1, $zero, 0x17
endlabel ReturnFromException
    /* 17140 80026940 00000000 */  nop
