nonmatching SoundVM_A5_SetOctave, 0x1C

glabel SoundVM_A5_SetOctave
    /* C0C4 8001B8C4 0000828C */  lw         $v0, 0x0($a0)
    /* C0C8 8001B8C8 00000000 */  nop
    /* C0CC 8001B8CC 00004390 */  lbu        $v1, 0x0($v0)
    /* C0D0 8001B8D0 01004224 */  addiu      $v0, $v0, 0x1
    /* C0D4 8001B8D4 000082AC */  sw         $v0, 0x0($a0)
    /* C0D8 8001B8D8 0800E003 */  jr         $ra
    /* C0DC 8001B8DC 940083A4 */   sh        $v1, 0x94($a0)
endlabel SoundVM_A5_SetOctave
