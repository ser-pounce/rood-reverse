nonmatching printf, 0xC

glabel printf
    /* 176E4 80026EE4 A0000A24 */  addiu      $t2, $zero, 0xA0
    /* 176E8 80026EE8 08004001 */  jr         $t2
    /* 176EC 80026EEC 3F000924 */   addiu     $t1, $zero, 0x3F
endlabel printf
    /* 176F0 80026EF0 00000000 */  nop
