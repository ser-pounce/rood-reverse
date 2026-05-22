nonmatching SoundVM_FE10_unk, 0x20

glabel SoundVM_FE10_unk
    /* CE6C 8001C66C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* CE70 8001C670 0000838C */  lw         $v1, 0x0($a0)
    /* CE74 8001C674 2078458C */  lw         $a1, %lo(g_pActiveMusicConfig)($v0)
    /* CE78 8001C678 00006290 */  lbu        $v0, 0x0($v1)
    /* CE7C 8001C67C 01006324 */  addiu      $v1, $v1, 0x1
    /* CE80 8001C680 4800A2AC */  sw         $v0, 0x48($a1)
    /* CE84 8001C684 0800E003 */  jr         $ra
    /* CE88 8001C688 000083AC */   sw        $v1, 0x0($a0)
endlabel SoundVM_FE10_unk
