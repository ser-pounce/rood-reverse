nonmatching DS_restart, 0x10

glabel DS_restart
    /* 15F58 80025758 01000224 */  addiu      $v0, $zero, 0x1
    /* 15F5C 8002575C 0380013C */  lui        $at, %hi(D_8003267C)
    /* 15F60 80025760 0800E003 */  jr         $ra
    /* 15F64 80025764 7C2622AC */   sw        $v0, %lo(D_8003267C)($at)
endlabel DS_restart
