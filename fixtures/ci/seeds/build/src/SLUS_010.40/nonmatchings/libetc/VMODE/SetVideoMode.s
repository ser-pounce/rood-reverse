nonmatching SetVideoMode, 0x14

glabel SetVideoMode
    /* 10B54 80020354 0380023C */  lui        $v0, %hi(D_80032154)
    /* 10B58 80020358 5421428C */  lw         $v0, %lo(D_80032154)($v0)
    /* 10B5C 8002035C 0380013C */  lui        $at, %hi(D_80032154)
    /* 10B60 80020360 0800E003 */  jr         $ra
    /* 10B64 80020364 542124AC */   sw        $a0, %lo(D_80032154)($at)
endlabel SetVideoMode
