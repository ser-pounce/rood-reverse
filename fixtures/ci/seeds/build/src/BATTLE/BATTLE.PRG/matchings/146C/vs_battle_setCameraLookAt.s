nonmatching vs_battle_setCameraLookAt, 0x28

glabel vs_battle_setCameraLookAt
    /* 1246C 8007AC6C 801F033C */  lui        $v1, %hi(D_1F800000)
    /* 12470 8007AC70 0000828C */  lw         $v0, 0x0($a0)
    /* 12474 8007AC74 00006324 */  addiu      $v1, $v1, %lo(D_1F800000)
    /* 12478 8007AC78 440062AC */  sw         $v0, 0x44($v1)
    /* 1247C 8007AC7C 0400828C */  lw         $v0, 0x4($a0)
    /* 12480 8007AC80 00000000 */  nop
    /* 12484 8007AC84 480062AC */  sw         $v0, 0x48($v1)
    /* 12488 8007AC88 0800828C */  lw         $v0, 0x8($a0)
    /* 1248C 8007AC8C 0800E003 */  jr         $ra
    /* 12490 8007AC90 4C0062AC */   sw        $v0, 0x4C($v1)
endlabel vs_battle_setCameraLookAt
