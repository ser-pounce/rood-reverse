nonmatching SetPolyFT4, 0x14

glabel SetPolyFT4
    /* 1BDC4 8002B5C4 09000224 */  addiu      $v0, $zero, 0x9
    /* 1BDC8 8002B5C8 030082A0 */  sb         $v0, 0x3($a0)
    /* 1BDCC 8002B5CC 2C000224 */  addiu      $v0, $zero, 0x2C
    /* 1BDD0 8002B5D0 0800E003 */  jr         $ra
    /* 1BDD4 8002B5D4 070082A0 */   sb        $v0, 0x7($a0)
endlabel SetPolyFT4
    /* 1BDD8 8002B5D8 00000000 */  nop
    /* 1BDDC 8002B5DC 00000000 */  nop
    /* 1BDE0 8002B5E0 00000000 */  nop
