nonmatching SetTile, 0x14

glabel SetTile
    /* 1BE44 8002B644 03000224 */  addiu      $v0, $zero, 0x3
    /* 1BE48 8002B648 030082A0 */  sb         $v0, 0x3($a0)
    /* 1BE4C 8002B64C 60000224 */  addiu      $v0, $zero, 0x60
    /* 1BE50 8002B650 0800E003 */  jr         $ra
    /* 1BE54 8002B654 070082A0 */   sb        $v0, 0x7($a0)
endlabel SetTile
    /* 1BE58 8002B658 00000000 */  nop
    /* 1BE5C 8002B65C 00000000 */  nop
    /* 1BE60 8002B660 00000000 */  nop
