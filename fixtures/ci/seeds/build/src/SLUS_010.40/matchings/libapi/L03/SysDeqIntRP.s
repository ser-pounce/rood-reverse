nonmatching SysDeqIntRP, 0xC

glabel SysDeqIntRP
    /* 1D284 8002CA84 C0000A24 */  addiu      $t2, $zero, 0xC0
    /* 1D288 8002CA88 08004001 */  jr         $t2
    /* 1D28C 8002CA8C 03000924 */   addiu     $t1, $zero, 0x3
endlabel SysDeqIntRP
    /* 1D290 8002CA90 00000000 */  nop
