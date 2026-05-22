nonmatching SetSprt8, 0x14

glabel SetSprt8
    /* 1BE04 8002B604 03000224 */  addiu      $v0, $zero, 0x3
    /* 1BE08 8002B608 030082A0 */  sb         $v0, 0x3($a0)
    /* 1BE0C 8002B60C 74000224 */  addiu      $v0, $zero, 0x74
    /* 1BE10 8002B610 0800E003 */  jr         $ra
    /* 1BE14 8002B614 070082A0 */   sb        $v0, 0x7($a0)
endlabel SetSprt8
    /* 1BE18 8002B618 00000000 */  nop
    /* 1BE1C 8002B61C 00000000 */  nop
    /* 1BE20 8002B620 00000000 */  nop
