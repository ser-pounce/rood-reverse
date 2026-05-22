nonmatching StopCARD2, 0xC

glabel StopCARD2
    /* 1F6A4 8002EEA4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 1F6A8 8002EEA8 08004001 */  jr         $t2
    /* 1F6AC 8002EEAC 4C000924 */   addiu     $t1, $zero, 0x4C
endlabel StopCARD2
    /* 1F6B0 8002EEB0 00000000 */  nop
