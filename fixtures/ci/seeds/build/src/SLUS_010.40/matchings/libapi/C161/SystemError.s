nonmatching SystemError, 0xC

glabel SystemError
    /* 170B4 800268B4 A0000A24 */  addiu      $t2, $zero, 0xA0
    /* 170B8 800268B8 08004001 */  jr         $t2
    /* 170BC 800268BC A1000924 */   addiu     $t1, $zero, 0xA1
endlabel SystemError
    /* 170C0 800268C0 00000000 */  nop
