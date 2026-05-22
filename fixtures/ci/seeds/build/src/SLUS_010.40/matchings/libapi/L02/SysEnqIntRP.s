nonmatching SysEnqIntRP, 0xC

glabel SysEnqIntRP
    /* 1D274 8002CA74 C0000A24 */  addiu      $t2, $zero, 0xC0
    /* 1D278 8002CA78 08004001 */  jr         $t2
    /* 1D27C 8002CA7C 02000924 */   addiu     $t1, $zero, 0x2
endlabel SysEnqIntRP
    /* 1D280 8002CA80 00000000 */  nop
