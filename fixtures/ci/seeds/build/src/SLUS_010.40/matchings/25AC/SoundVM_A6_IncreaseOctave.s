nonmatching SoundVM_A6_IncreaseOctave, 0x18

glabel SoundVM_A6_IncreaseOctave
    /* C0E0 8001B8E0 94008294 */  lhu        $v0, 0x94($a0)
    /* C0E4 8001B8E4 00000000 */  nop
    /* C0E8 8001B8E8 01004224 */  addiu      $v0, $v0, 0x1
    /* C0EC 8001B8EC 0F004230 */  andi       $v0, $v0, 0xF
    /* C0F0 8001B8F0 0800E003 */  jr         $ra
    /* C0F4 8001B8F4 940082A4 */   sh        $v0, 0x94($a0)
endlabel SoundVM_A6_IncreaseOctave
