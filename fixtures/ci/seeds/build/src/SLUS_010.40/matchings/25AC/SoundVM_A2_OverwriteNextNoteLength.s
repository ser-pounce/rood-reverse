nonmatching SoundVM_A2_OverwriteNextNoteLength, 0x28

glabel SoundVM_A2_OverwriteNextNoteLength
    /* D0BC 8001C8BC 0000828C */  lw         $v0, 0x0($a0)
    /* D0C0 8001C8C0 00000000 */  nop
    /* D0C4 8001C8C4 00004390 */  lbu        $v1, 0x0($v0)
    /* D0C8 8001C8C8 01004224 */  addiu      $v0, $v0, 0x1
    /* D0CC 8001C8CC 000082AC */  sw         $v0, 0x0($a0)
    /* D0D0 8001C8D0 D60080A4 */  sh         $zero, 0xD6($a0)
    /* D0D4 8001C8D4 680083A4 */  sh         $v1, 0x68($a0)
    /* D0D8 8001C8D8 660083A4 */  sh         $v1, 0x66($a0)
    /* D0DC 8001C8DC 0800E003 */  jr         $ra
    /* D0E0 8001C8E0 D40083A4 */   sh        $v1, 0xD4($a0)
endlabel SoundVM_A2_OverwriteNextNoteLength
