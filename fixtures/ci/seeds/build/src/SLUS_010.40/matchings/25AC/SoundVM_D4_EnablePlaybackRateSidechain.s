nonmatching SoundVM_D4_EnablePlaybackRateSidechain, 0x14

glabel SoundVM_D4_EnablePlaybackRateSidechain
    /* D37C 8001CB7C 3400828C */  lw         $v0, 0x34($a0)
    /* D380 8001CB80 00000000 */  nop
    /* D384 8001CB84 10004234 */  ori        $v0, $v0, 0x10
    /* D388 8001CB88 0800E003 */  jr         $ra
    /* D38C 8001CB8C 340082AC */   sw        $v0, 0x34($a0)
endlabel SoundVM_D4_EnablePlaybackRateSidechain
