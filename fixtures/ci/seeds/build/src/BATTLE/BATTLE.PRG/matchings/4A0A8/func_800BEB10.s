nonmatching func_800BEB10, 0x24

glabel func_800BEB10
    /* 56310 800BEB10 0F80023C */  lui        $v0, %hi(D_800F4BE0)
    /* 56314 800BEB14 0F80043C */  lui        $a0, %hi(_evtFile)
    /* 56318 800BEB18 E04B4394 */  lhu        $v1, %lo(D_800F4BE0)($v0)
    /* 5631C 800BEB1C 524C8294 */  lhu        $v0, %lo(_evtFile)($a0)
    /* 56320 800BEB20 001B0300 */  sll        $v1, $v1, 12
    /* 56324 800BEB24 25104300 */  or         $v0, $v0, $v1
    /* 56328 800BEB28 00140200 */  sll        $v0, $v0, 16
    /* 5632C 800BEB2C 0800E003 */  jr         $ra
    /* 56330 800BEB30 03140200 */   sra       $v0, $v0, 16
endlabel func_800BEB10
