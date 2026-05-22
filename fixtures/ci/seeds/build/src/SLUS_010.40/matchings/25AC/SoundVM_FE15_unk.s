nonmatching SoundVM_FE15_unk, 0x38

glabel SoundVM_FE15_unk
    /* D17C 8001C97C 0380033C */  lui        $v1, %hi(g_pActiveMusicConfig)
    /* D180 8001C980 0000828C */  lw         $v0, 0x0($a0)
    /* D184 8001C984 2078658C */  lw         $a1, %lo(g_pActiveMusicConfig)($v1)
    /* D188 8001C988 00004390 */  lbu        $v1, 0x0($v0)
    /* D18C 8001C98C 01004224 */  addiu      $v0, $v0, 0x1
    /* D190 8001C990 7800A3A4 */  sh         $v1, 0x78($a1)
    /* D194 8001C994 000082AC */  sw         $v0, 0x0($a0)
    /* D198 8001C998 00004390 */  lbu        $v1, 0x0($v0)
    /* D19C 8001C99C 01004224 */  addiu      $v0, $v0, 0x1
    /* D1A0 8001C9A0 7400A3A4 */  sh         $v1, 0x74($a1)
    /* D1A4 8001C9A4 000082AC */  sw         $v0, 0x0($a0)
    /* D1A8 8001C9A8 7A00A0A4 */  sh         $zero, 0x7A($a1)
    /* D1AC 8001C9AC 0800E003 */  jr         $ra
    /* D1B0 8001C9B0 7600A0A4 */   sh        $zero, 0x76($a1)
endlabel SoundVM_FE15_unk
