nonmatching DisablePAD, 0x14

glabel DisablePAD
    /* 1F588 8002ED88 0480093C */  lui        $t1, %hi(jtbl_8003FEC4)
    /* 1F58C 8002ED8C C4FE298D */  lw         $t1, %lo(jtbl_8003FEC4)($t1)
    /* 1F590 8002ED90 00000000 */  nop
    /* 1F594 8002ED94 08002001 */  jr         $t1
    /* 1F598 8002ED98 00000000 */   nop
endlabel DisablePAD
