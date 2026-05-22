nonmatching ReadInitPadFlag, 0x10

glabel ReadInitPadFlag
    /* 1F240 8002EA40 0380023C */  lui        $v0, %hi(D_80033664)
    /* 1F244 8002EA44 6436428C */  lw         $v0, %lo(D_80033664)($v0)
    /* 1F248 8002EA48 0800E003 */  jr         $ra
    /* 1F24C 8002EA4C 00000000 */   nop
endlabel ReadInitPadFlag
