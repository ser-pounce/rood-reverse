nonmatching GPU_cw, 0xC

glabel GPU_cw
    /* 1BA04 8002B204 A0000A24 */  addiu      $t2, $zero, 0xA0
    /* 1BA08 8002B208 08004001 */  jr         $t2
    /* 1BA0C 8002B20C 49000924 */   addiu     $t1, $zero, 0x49
endlabel GPU_cw
    /* 1BA10 8002B210 00000000 */  nop
