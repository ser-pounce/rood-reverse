nonmatching vs_battle_getCameraLookAt, 0x2C

glabel vs_battle_getCameraLookAt
    /* 12440 8007AC40 801F023C */  lui        $v0, %hi(D_1F800000)
    /* 12444 8007AC44 00004224 */  addiu      $v0, $v0, %lo(D_1F800000)
    /* 12448 8007AC48 4400438C */  lw         $v1, 0x44($v0)
    /* 1244C 8007AC4C 00000000 */  nop
    /* 12450 8007AC50 000083AC */  sw         $v1, 0x0($a0)
    /* 12454 8007AC54 4800438C */  lw         $v1, 0x48($v0)
    /* 12458 8007AC58 00000000 */  nop
    /* 1245C 8007AC5C 040083AC */  sw         $v1, 0x4($a0)
    /* 12460 8007AC60 4C00428C */  lw         $v0, 0x4C($v0)
    /* 12464 8007AC64 0800E003 */  jr         $ra
    /* 12468 8007AC68 080082AC */   sw        $v0, 0x8($a0)
endlabel vs_battle_getCameraLookAt
