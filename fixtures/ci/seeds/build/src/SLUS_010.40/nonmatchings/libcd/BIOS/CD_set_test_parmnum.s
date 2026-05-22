nonmatching CD_set_test_parmnum, 0xC

glabel CD_set_test_parmnum
    /* 12848 80022048 0380013C */  lui        $at, %hi(D_800324A4)
    /* 1284C 8002204C 0800E003 */  jr         $ra
    /* 12850 80022050 A42424AC */   sw        $a0, %lo(D_800324A4)($at)
endlabel CD_set_test_parmnum
