nonmatching SetLineF2, 0x14

glabel SetLineF2
    /* 1BE64 8002B664 03000224 */  addiu      $v0, $zero, 0x3
    /* 1BE68 8002B668 030082A0 */  sb         $v0, 0x3($a0)
    /* 1BE6C 8002B66C 40000224 */  addiu      $v0, $zero, 0x40
    /* 1BE70 8002B670 0800E003 */  jr         $ra
    /* 1BE74 8002B674 070082A0 */   sb        $v0, 0x7($a0)
endlabel SetLineF2
    /* 1BE78 8002B678 00000000 */  nop
    /* 1BE7C 8002B67C 00000000 */  nop
    /* 1BE80 8002B680 00000000 */  nop
