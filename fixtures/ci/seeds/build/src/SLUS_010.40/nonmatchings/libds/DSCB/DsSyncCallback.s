nonmatching DsSyncCallback, 0x14

glabel DsSyncCallback
    /* 17004 80026804 0480033C */  lui        $v1, %hi(D_80039E60)
    /* 17008 80026808 609E6324 */  addiu      $v1, $v1, %lo(D_80039E60)
    /* 1700C 8002680C 0000628C */  lw         $v0, 0x0($v1)
    /* 17010 80026810 0800E003 */  jr         $ra
    /* 17014 80026814 000064AC */   sw        $a0, 0x0($v1)
endlabel DsSyncCallback
