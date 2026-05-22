nonmatching CdLastPos, 0xC

glabel CdLastPos
    /* 10BE4 800203E4 0380023C */  lui        $v0, %hi(D_80032214)
    /* 10BE8 800203E8 0800E003 */  jr         $ra
    /* 10BEC 800203EC 14224224 */   addiu     $v0, $v0, %lo(D_80032214)
endlabel CdLastPos
