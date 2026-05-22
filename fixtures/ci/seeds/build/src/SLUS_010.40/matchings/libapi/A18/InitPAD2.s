nonmatching InitPAD2, 0xC

glabel InitPAD2
    /* 1F534 8002ED34 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 1F538 8002ED38 08004001 */  jr         $t2
    /* 1F53C 8002ED3C 12000924 */   addiu     $t1, $zero, 0x12
endlabel InitPAD2
    /* 1F540 8002ED40 00000000 */  nop
