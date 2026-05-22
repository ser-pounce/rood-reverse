nonmatching SetSprt, 0x14

glabel SetSprt
    /* 1BE24 8002B624 04000224 */  addiu      $v0, $zero, 0x4
    /* 1BE28 8002B628 030082A0 */  sb         $v0, 0x3($a0)
    /* 1BE2C 8002B62C 64000224 */  addiu      $v0, $zero, 0x64
    /* 1BE30 8002B630 0800E003 */  jr         $ra
    /* 1BE34 8002B634 070082A0 */   sb        $v0, 0x7($a0)
endlabel SetSprt
    /* 1BE38 8002B638 00000000 */  nop
    /* 1BE3C 8002B63C 00000000 */  nop
    /* 1BE40 8002B640 00000000 */  nop
