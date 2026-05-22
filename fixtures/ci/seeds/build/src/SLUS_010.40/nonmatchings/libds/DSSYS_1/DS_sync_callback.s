nonmatching DS_sync_callback, 0xC

glabel DS_sync_callback
    /* 150D4 800248D4 0480013C */  lui        $at, %hi(D_80039E54)
    /* 150D8 800248D8 0800E003 */  jr         $ra
    /* 150DC 800248DC 549E24AC */   sw        $a0, %lo(D_80039E54)($at)
endlabel DS_sync_callback
