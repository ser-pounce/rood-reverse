nonmatching SetPolyF4, 0x14

glabel SetPolyF4
    /* 1BDA4 8002B5A4 05000224 */  addiu      $v0, $zero, 0x5
    /* 1BDA8 8002B5A8 030082A0 */  sb         $v0, 0x3($a0)
    /* 1BDAC 8002B5AC 28000224 */  addiu      $v0, $zero, 0x28
    /* 1BDB0 8002B5B0 0800E003 */  jr         $ra
    /* 1BDB4 8002B5B4 070082A0 */   sb        $v0, 0x7($a0)
endlabel SetPolyF4
    /* 1BDB8 8002B5B8 00000000 */  nop
    /* 1BDBC 8002B5BC 00000000 */  nop
    /* 1BDC0 8002B5C0 00000000 */  nop
