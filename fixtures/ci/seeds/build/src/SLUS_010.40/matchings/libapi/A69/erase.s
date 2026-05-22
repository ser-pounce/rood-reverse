nonmatching erase, 0xC

glabel erase
    /* 171F4 800269F4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 171F8 800269F8 08004001 */  jr         $t2
    /* 171FC 800269FC 45000924 */   addiu     $t1, $zero, 0x45
endlabel erase
    /* 17200 80026A00 00000000 */  nop
