nonmatching write, 0xC

glabel write
    /* 171B4 800269B4 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 171B8 800269B8 08004001 */  jr         $t2
    /* 171BC 800269BC 35000924 */   addiu     $t1, $zero, 0x35
endlabel write
    /* 171C0 800269C0 00000000 */  nop
