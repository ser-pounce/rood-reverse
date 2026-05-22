nonmatching SpuGetReverbModeType, 0x10

glabel SpuGetReverbModeType
    /* FD34 8001F534 0380023C */  lui        $v0, %hi(D_80030804)
    /* FD38 8001F538 0408428C */  lw         $v0, %lo(D_80030804)($v0)
    /* FD3C 8001F53C 0800E003 */  jr         $ra
    /* FD40 8001F540 000082AC */   sw        $v0, 0x0($a0)
endlabel SpuGetReverbModeType
