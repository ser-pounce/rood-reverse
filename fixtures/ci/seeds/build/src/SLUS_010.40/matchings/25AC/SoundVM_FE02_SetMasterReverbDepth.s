nonmatching SoundVM_FE02_SetMasterReverbDepth, 0x48

glabel SoundVM_FE02_SetMasterReverbDepth
    /* BB34 8001B334 0380033C */  lui        $v1, %hi(g_pActiveMusicConfig)
    /* BB38 8001B338 2078678C */  lw         $a3, %lo(g_pActiveMusicConfig)($v1)
    /* BB3C 8001B33C 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* BB40 8001B340 0000828C */  lw         $v0, 0x0($a0)
    /* BB44 8001B344 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* BB48 8001B348 01004580 */  lb         $a1, 0x1($v0)
    /* BB4C 8001B34C 00004690 */  lbu        $a2, 0x0($v0)
    /* BB50 8001B350 02004224 */  addiu      $v0, $v0, 0x2
    /* BB54 8001B354 000082AC */  sw         $v0, 0x0($a0)
    /* BB58 8001B358 6A00E0A4 */  sh         $zero, 0x6A($a3)
    /* BB5C 8001B35C 0800628C */  lw         $v0, 0x8($v1)
    /* BB60 8001B360 002D0500 */  sll        $a1, $a1, 20
    /* BB64 8001B364 00330600 */  sll        $a2, $a2, 12
    /* BB68 8001B368 2528A600 */  or         $a1, $a1, $a2
    /* BB6C 8001B36C 80004234 */  ori        $v0, $v0, 0x80
    /* BB70 8001B370 080062AC */  sw         $v0, 0x8($v1)
    /* BB74 8001B374 0800E003 */  jr         $ra
    /* BB78 8001B378 5800E5AC */   sw        $a1, 0x58($a3)
endlabel SoundVM_FE02_SetMasterReverbDepth
