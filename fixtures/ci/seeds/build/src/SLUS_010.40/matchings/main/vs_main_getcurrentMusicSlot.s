nonmatching vs_main_getcurrentMusicSlot, 0x10

glabel vs_main_getcurrentMusicSlot
    /* 358D4 800450D4 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 358D8 800450D8 38E0428C */  lw         $v0, %lo(vs_main_soundData)($v0)
    /* 358DC 800450DC 0800E003 */  jr         $ra
    /* 358E0 800450E0 00000000 */   nop
endlabel vs_main_getcurrentMusicSlot
