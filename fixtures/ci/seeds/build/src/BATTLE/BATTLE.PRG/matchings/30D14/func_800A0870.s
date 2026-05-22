nonmatching func_800A0870, 0xC

glabel func_800A0870
    /* 38070 800A0870 0F80023C */  lui        $v0, %hi(D_800E8FC0)
    /* 38074 800A0874 0800E003 */  jr         $ra
    /* 38078 800A0878 C08F44A0 */   sb        $a0, %lo(D_800E8FC0)($v0)
endlabel func_800A0870
