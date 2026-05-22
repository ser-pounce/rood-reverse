nonmatching CdReadyCallback, 0x14

glabel CdReadyCallback
    /* 10D4C 8002054C 0380023C */  lui        $v0, %hi(D_80032200)
    /* 10D50 80020550 0022428C */  lw         $v0, %lo(D_80032200)($v0)
    /* 10D54 80020554 0380013C */  lui        $at, %hi(D_80032200)
    /* 10D58 80020558 0800E003 */  jr         $ra
    /* 10D5C 8002055C 002224AC */   sw        $a0, %lo(D_80032200)($at)
endlabel CdReadyCallback
