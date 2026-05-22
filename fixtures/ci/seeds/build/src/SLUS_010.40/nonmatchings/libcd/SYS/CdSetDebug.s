nonmatching CdSetDebug, 0x14

glabel CdSetDebug
    /* 10C7C 8002047C 0380023C */  lui        $v0, %hi(D_80032204)
    /* 10C80 80020480 0422428C */  lw         $v0, %lo(D_80032204)($v0)
    /* 10C84 80020484 0380013C */  lui        $at, %hi(D_80032204)
    /* 10C88 80020488 0800E003 */  jr         $ra
    /* 10C8C 8002048C 042224AC */   sw        $a0, %lo(D_80032204)($at)
endlabel CdSetDebug
