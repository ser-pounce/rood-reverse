nonmatching func_8002A2F8, 0x14

glabel func_8002A2F8
    /* 1AAF8 8002A2F8 0480023C */  lui        $v0, %hi(D_8003E2F8)
    /* 1AAFC 8002A2FC 21104400 */  addu       $v0, $v0, $a0
    /* 1AB00 8002A300 F8E24290 */  lbu        $v0, %lo(D_8003E2F8)($v0)
    /* 1AB04 8002A304 0800E003 */  jr         $ra
    /* 1AB08 8002A308 00000000 */   nop
endlabel func_8002A2F8
