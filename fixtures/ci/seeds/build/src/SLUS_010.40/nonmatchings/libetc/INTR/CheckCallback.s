nonmatching CheckCallback, 0x10

glabel CheckCallback
    /* 10228 8001FA28 0380023C */  lui        $v0, %hi(D_8003104E)
    /* 1022C 8001FA2C 4E104294 */  lhu        $v0, %lo(D_8003104E)($v0)
    /* 10230 8001FA30 0800E003 */  jr         $ra
    /* 10234 8001FA34 00000000 */   nop
endlabel CheckCallback
