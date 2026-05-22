nonmatching _padSetAct, 0xC

glabel _padSetAct
    /* 1D294 8002CA94 280085AC */  sw         $a1, 0x28($a0)
    /* 1D298 8002CA98 0800E003 */  jr         $ra
    /* 1D29C 8002CA9C 340086A0 */   sb        $a2, 0x34($a0)
endlabel _padSetAct
