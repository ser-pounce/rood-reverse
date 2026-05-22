nonmatching SoundVM_A7_DecreaseOctave, 0x18

glabel SoundVM_A7_DecreaseOctave
    /* C0F8 8001B8F8 94008294 */  lhu        $v0, 0x94($a0)
    /* C0FC 8001B8FC 00000000 */  nop
    /* C100 8001B900 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* C104 8001B904 0F004230 */  andi       $v0, $v0, 0xF
    /* C108 8001B908 0800E003 */  jr         $ra
    /* C10C 8001B90C 940082A4 */   sh        $v0, 0x94($a0)
endlabel SoundVM_A7_DecreaseOctave
