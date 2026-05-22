nonmatching SoundVM_E1_SetRandomPitchDepth, 0x1C

glabel SoundVM_E1_SetRandomPitchDepth
    /* D508 8001CD08 0000828C */  lw         $v0, 0x0($a0)
    /* D50C 8001CD0C 00000000 */  nop
    /* D510 8001CD10 00004390 */  lbu        $v1, 0x0($v0)
    /* D514 8001CD14 01004224 */  addiu      $v0, $v0, 0x1
    /* D518 8001CD18 000082AC */  sw         $v0, 0x0($a0)
    /* D51C 8001CD1C 0800E003 */  jr         $ra
    /* D520 8001CD20 D20083A4 */   sh        $v1, 0xD2($a0)
endlabel SoundVM_E1_SetRandomPitchDepth
