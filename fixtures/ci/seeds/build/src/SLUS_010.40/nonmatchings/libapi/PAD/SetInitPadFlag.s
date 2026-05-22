nonmatching SetInitPadFlag, 0xC

glabel SetInitPadFlag
    /* 1F234 8002EA34 0380013C */  lui        $at, %hi(D_80033664)
    /* 1F238 8002EA38 0800E003 */  jr         $ra
    /* 1F23C 8002EA3C 643624AC */   sw        $a0, %lo(D_80033664)($at)
endlabel SetInitPadFlag
