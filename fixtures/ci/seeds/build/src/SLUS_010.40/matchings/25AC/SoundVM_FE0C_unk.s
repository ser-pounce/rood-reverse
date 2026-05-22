nonmatching SoundVM_FE0C_unk, 0x20

glabel SoundVM_FE0C_unk
    /* BF0C 8001B70C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* BF10 8001B710 0000838C */  lw         $v1, 0x0($a0)
    /* BF14 8001B714 2078458C */  lw         $a1, %lo(g_pActiveMusicConfig)($v0)
    /* BF18 8001B718 00006290 */  lbu        $v0, 0x0($v1)
    /* BF1C 8001B71C 01006324 */  addiu      $v1, $v1, 0x1
    /* BF20 8001B720 3400A2AC */  sw         $v0, 0x34($a1)
    /* BF24 8001B724 0800E003 */  jr         $ra
    /* BF28 8001B728 000083AC */   sw        $v1, 0x0($a0)
endlabel SoundVM_FE0C_unk
