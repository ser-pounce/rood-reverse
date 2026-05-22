nonmatching SoundVM_A4_PitchBendSlide, 0x48

glabel SoundVM_A4_PitchBendSlide
    /* C350 8001BB50 0000828C */  lw         $v0, 0x0($a0)
    /* C354 8001BB54 00000000 */  nop
    /* C358 8001BB58 00004390 */  lbu        $v1, 0x0($v0)
    /* C35C 8001BB5C 01004224 */  addiu      $v0, $v0, 0x1
    /* C360 8001BB60 000082AC */  sw         $v0, 0x0($a0)
    /* C364 8001BB64 03006014 */  bnez       $v1, .L8001BB74
    /* C368 8001BB68 960083A4 */   sh        $v1, 0x96($a0)
    /* C36C 8001BB6C 00010224 */  addiu      $v0, $zero, 0x100
    /* C370 8001BB70 960082A4 */  sh         $v0, 0x96($a0)
  .L8001BB74:
    /* C374 8001BB74 0000828C */  lw         $v0, 0x0($a0)
    /* C378 8001BB78 00000000 */  nop
    /* C37C 8001BB7C 00004390 */  lbu        $v1, 0x0($v0)
    /* C380 8001BB80 01004224 */  addiu      $v0, $v0, 0x1
    /* C384 8001BB84 000082AC */  sw         $v0, 0x0($a0)
    /* C388 8001BB88 001E0300 */  sll        $v1, $v1, 24
    /* C38C 8001BB8C 031E0300 */  sra        $v1, $v1, 24
    /* C390 8001BB90 0800E003 */  jr         $ra
    /* C394 8001BB94 E80083A4 */   sh        $v1, 0xE8($a0)
endlabel SoundVM_A4_PitchBendSlide
