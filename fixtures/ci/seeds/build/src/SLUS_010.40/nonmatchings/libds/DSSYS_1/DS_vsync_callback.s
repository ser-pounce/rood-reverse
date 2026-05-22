nonmatching DS_vsync_callback, 0xC

glabel DS_vsync_callback
    /* 150C8 800248C8 0480013C */  lui        $at, %hi(D_80039E50)
    /* 150CC 800248CC 0800E003 */  jr         $ra
    /* 150D0 800248D0 509E24AC */   sw        $a0, %lo(D_80039E50)($at)
endlabel DS_vsync_callback
