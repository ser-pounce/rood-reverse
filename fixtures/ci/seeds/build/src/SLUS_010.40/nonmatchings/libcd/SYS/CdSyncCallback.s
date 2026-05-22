nonmatching CdSyncCallback, 0x14

glabel CdSyncCallback
    /* 10D38 80020538 0380023C */  lui        $v0, %hi(D_800321FC)
    /* 10D3C 8002053C FC21428C */  lw         $v0, %lo(D_800321FC)($v0)
    /* 10D40 80020540 0380013C */  lui        $at, %hi(D_800321FC)
    /* 10D44 80020544 0800E003 */  jr         $ra
    /* 10D48 80020548 FC2124AC */   sw        $a0, %lo(D_800321FC)($at)
endlabel CdSyncCallback
