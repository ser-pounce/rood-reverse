nonmatching InitCARD2, 0xC

glabel InitCARD2
    /* 1F684 8002EE84 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 1F688 8002EE88 08004001 */  jr         $t2
    /* 1F68C 8002EE8C 4A000924 */   addiu     $t1, $zero, 0x4A
endlabel InitCARD2
    /* 1F690 8002EE90 00000000 */  nop
