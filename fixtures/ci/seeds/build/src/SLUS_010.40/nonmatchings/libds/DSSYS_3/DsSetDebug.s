nonmatching DsSetDebug, 0x14

glabel DsSetDebug
    /* 162E8 80025AE8 0380023C */  lui        $v0, %hi(D_80032204)
    /* 162EC 80025AEC 0422428C */  lw         $v0, %lo(D_80032204)($v0)
    /* 162F0 80025AF0 0380013C */  lui        $at, %hi(D_80032204)
    /* 162F4 80025AF4 0800E003 */  jr         $ra
    /* 162F8 80025AF8 042224AC */   sw        $a0, %lo(D_80032204)($at)
endlabel DsSetDebug
