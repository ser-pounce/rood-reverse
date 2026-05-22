nonmatching setjmp, 0xC

glabel setjmp
    /* 17664 80026E64 A0000A24 */  addiu      $t2, $zero, 0xA0
    /* 17668 80026E68 08004001 */  jr         $t2
    /* 1766C 80026E6C 13000924 */   addiu     $t1, $zero, 0x13
endlabel setjmp
    /* 17670 80026E70 00000000 */  nop
