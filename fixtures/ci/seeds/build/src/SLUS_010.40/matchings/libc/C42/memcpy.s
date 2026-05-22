nonmatching memcpy, 0xC

glabel memcpy
    /* 176A4 80026EA4 A0000A24 */  addiu      $t2, $zero, 0xA0
    /* 176A8 80026EA8 08004001 */  jr         $t2
    /* 176AC 80026EAC 2A000924 */   addiu     $t1, $zero, 0x2A
endlabel memcpy
    /* 176B0 80026EB0 00000000 */  nop
