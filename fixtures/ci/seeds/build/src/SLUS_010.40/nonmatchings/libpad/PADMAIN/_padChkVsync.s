nonmatching _padChkVsync, 0x14

glabel _padChkVsync
    /* 1C7E0 8002BFE0 0380023C */  lui        $v0, %hi(D_80033604)
    /* 1C7E4 8002BFE4 0436428C */  lw         $v0, %lo(D_80033604)($v0)
    /* 1C7E8 8002BFE8 0380013C */  lui        $at, %hi(D_80033604)
    /* 1C7EC 8002BFEC 0800E003 */  jr         $ra
    /* 1C7F0 8002BFF0 043620AC */   sw        $zero, %lo(D_80033604)($at)
endlabel _padChkVsync
