nonmatching DS_ready_callback, 0xC

glabel DS_ready_callback
    /* 150E0 800248E0 0480013C */  lui        $at, %hi(D_80039E58)
    /* 150E4 800248E4 0800E003 */  jr         $ra
    /* 150E8 800248E8 589E24AC */   sw        $a0, %lo(D_80039E58)($at)
endlabel DS_ready_callback
