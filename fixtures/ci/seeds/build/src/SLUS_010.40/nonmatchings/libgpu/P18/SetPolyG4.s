nonmatching SetPolyG4, 0x14

glabel SetPolyG4
    /* 1BDE4 8002B5E4 08000224 */  addiu      $v0, $zero, 0x8
    /* 1BDE8 8002B5E8 030082A0 */  sb         $v0, 0x3($a0)
    /* 1BDEC 8002B5EC 38000224 */  addiu      $v0, $zero, 0x38
    /* 1BDF0 8002B5F0 0800E003 */  jr         $ra
    /* 1BDF4 8002B5F4 070082A0 */   sb        $v0, 0x7($a0)
endlabel SetPolyG4
    /* 1BDF8 8002B5F8 00000000 */  nop
    /* 1BDFC 8002B5FC 00000000 */  nop
    /* 1BE00 8002B600 00000000 */  nop
