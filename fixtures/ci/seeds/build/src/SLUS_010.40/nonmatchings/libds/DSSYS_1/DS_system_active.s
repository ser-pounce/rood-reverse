nonmatching DS_system_active, 0x10

glabel DS_system_active
    /* 15F68 80025768 0380023C */  lui        $v0, %hi(D_8003267C)
    /* 15F6C 8002576C 7C26428C */  lw         $v0, %lo(D_8003267C)($v0)
    /* 15F70 80025770 0800E003 */  jr         $ra
    /* 15F74 80025774 00000000 */   nop
endlabel DS_system_active
