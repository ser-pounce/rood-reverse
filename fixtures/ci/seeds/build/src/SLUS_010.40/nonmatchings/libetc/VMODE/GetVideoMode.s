nonmatching GetVideoMode, 0x10

glabel GetVideoMode
    /* 10B68 80020368 0380023C */  lui        $v0, %hi(D_80032154)
    /* 10B6C 8002036C 5421428C */  lw         $v0, %lo(D_80032154)($v0)
    /* 10B70 80020370 0800E003 */  jr         $ra
    /* 10B74 80020374 00000000 */   nop
endlabel GetVideoMode
    /* 10B78 80020378 00000000 */  nop
    /* 10B7C 8002037C 00000000 */  nop
    /* 10B80 80020380 00000000 */  nop
