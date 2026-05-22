nonmatching DsReadCallback, 0x14

glabel DsReadCallback
    /* 16874 80026074 0380023C */  lui        $v0, %hi(D_800327F8)
    /* 16878 80026078 F827428C */  lw         $v0, %lo(D_800327F8)($v0)
    /* 1687C 8002607C 0380013C */  lui        $at, %hi(D_800327F8)
    /* 16880 80026080 0800E003 */  jr         $ra
    /* 16884 80026084 F82724AC */   sw        $a0, %lo(D_800327F8)($at)
endlabel DsReadCallback
