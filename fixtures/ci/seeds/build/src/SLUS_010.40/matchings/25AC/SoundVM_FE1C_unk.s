nonmatching SoundVM_FE1C_unk, 0x30

glabel SoundVM_FE1C_unk
    /* D498 8001CC98 0000828C */  lw         $v0, 0x0($a0)
    /* D49C 8001CC9C 00000000 */  nop
    /* D4A0 8001CCA0 00004390 */  lbu        $v1, 0x0($v0)
    /* D4A4 8001CCA4 01004224 */  addiu      $v0, $v0, 0x1
    /* D4A8 8001CCA8 000082AC */  sw         $v0, 0x0($a0)
    /* D4AC 8001CCAC 0380043C */  lui        $a0, %hi(g_pActiveMusicConfig)
    /* D4B0 8001CCB0 0380023C */  lui        $v0, %hi(D_8002F66C)
    /* D4B4 8001CCB4 6CF64224 */  addiu      $v0, $v0, %lo(D_8002F66C)
    /* D4B8 8001CCB8 2078848C */  lw         $a0, %lo(g_pActiveMusicConfig)($a0)
    /* D4BC 8001CCBC 21186200 */  addu       $v1, $v1, $v0
    /* D4C0 8001CCC0 0800E003 */  jr         $ra
    /* D4C4 8001CCC4 440083AC */   sw        $v1, 0x44($a0)
endlabel SoundVM_FE1C_unk
