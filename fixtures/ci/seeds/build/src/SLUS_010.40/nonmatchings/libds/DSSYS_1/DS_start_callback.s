nonmatching DS_start_callback, 0xC

glabel DS_start_callback
    /* 150EC 800248EC 0480013C */  lui        $at, %hi(D_80039E5C)
    /* 150F0 800248F0 0800E003 */  jr         $ra
    /* 150F4 800248F4 5C9E24AC */   sw        $a0, %lo(D_80039E5C)($at)
endlabel DS_start_callback
