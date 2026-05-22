nonmatching func_80096254, 0x28

glabel func_80096254
    /* 2DA54 80096254 FFFF8230 */  andi       $v0, $a0, 0xFFFF
    /* 2DA58 80096258 FFFFA330 */  andi       $v1, $a1, 0xFFFF
    /* 2DA5C 8009625C 21104300 */  addu       $v0, $v0, $v1
    /* 2DA60 80096260 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 2DA64 80096264 03240400 */  sra        $a0, $a0, 16
    /* 2DA68 80096268 032C0500 */  sra        $a1, $a1, 16
    /* 2DA6C 8009626C 21208500 */  addu       $a0, $a0, $a1
    /* 2DA70 80096270 00240400 */  sll        $a0, $a0, 16
    /* 2DA74 80096274 0800E003 */  jr         $ra
    /* 2DA78 80096278 25104400 */   or        $v0, $v0, $a0
endlabel func_80096254
