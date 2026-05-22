nonmatching DsQueueLen, 0x10

glabel DsQueueLen
    /* 14C7C 8002447C 0480023C */  lui        $v0, %hi(D_80039DB8)
    /* 14C80 80024480 B89D428C */  lw         $v0, %lo(D_80039DB8)($v0)
    /* 14C84 80024484 0800E003 */  jr         $ra
    /* 14C88 80024488 00000000 */   nop
endlabel DsQueueLen
