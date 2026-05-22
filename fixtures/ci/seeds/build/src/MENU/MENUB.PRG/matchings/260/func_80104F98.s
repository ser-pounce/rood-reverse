nonmatching func_80104F98, 0x1C

glabel func_80104F98
    /* 2798 80104F98 1180023C */  lui        $v0, %hi(D_8010A6B9)
    /* 279C 80104F9C B9A644A0 */  sb         $a0, %lo(D_8010A6B9)($v0)
    /* 27A0 80104FA0 1180023C */  lui        $v0, %hi(D_8010A6BA)
    /* 27A4 80104FA4 BAA644A0 */  sb         $a0, %lo(D_8010A6BA)($v0)
    /* 27A8 80104FA8 1180023C */  lui        $v0, %hi(D_8010A6BB)
    /* 27AC 80104FAC 0800E003 */  jr         $ra
    /* 27B0 80104FB0 BBA644A0 */   sb        $a0, %lo(D_8010A6BB)($v0)
endlabel func_80104F98
