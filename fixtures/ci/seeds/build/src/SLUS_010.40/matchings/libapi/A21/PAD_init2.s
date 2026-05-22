nonmatching PAD_init2, 0xC

glabel PAD_init2
    /* 1F564 8002ED64 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 1F568 8002ED68 08004001 */  jr         $t2
    /* 1F56C 8002ED6C 15000924 */   addiu     $t1, $zero, 0x15
endlabel PAD_init2
    /* 1F570 8002ED70 00000000 */  nop
