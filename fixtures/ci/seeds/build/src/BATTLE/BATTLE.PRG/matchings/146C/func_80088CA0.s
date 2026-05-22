nonmatching func_80088CA0, 0xC

glabel func_80088CA0
    /* 204A0 80088CA0 0F80023C */  lui        $v0, %hi(D_800E8498)
    /* 204A4 80088CA4 0800E003 */  jr         $ra
    /* 204A8 80088CA8 988440AC */   sw        $zero, %lo(D_800E8498)($v0)
endlabel func_80088CA0
