nonmatching SoundVM_A3_ChannelMasterVolume, 0x28

glabel SoundVM_A3_ChannelMasterVolume
    /* BCEC 8001B4EC 0000828C */  lw         $v0, 0x0($a0)
    /* BCF0 8001B4F0 F800838C */  lw         $v1, 0xF8($a0)
    /* BCF4 8001B4F4 00004590 */  lbu        $a1, 0x0($v0)
    /* BCF8 8001B4F8 01004224 */  addiu      $v0, $v0, 0x1
    /* BCFC 8001B4FC 03006334 */  ori        $v1, $v1, 0x3
    /* BD00 8001B500 000082AC */  sw         $v0, 0x0($a0)
    /* BD04 8001B504 F80083AC */  sw         $v1, 0xF8($a0)
    /* BD08 8001B508 002A0500 */  sll        $a1, $a1, 8
    /* BD0C 8001B50C 0800E003 */  jr         $ra
    /* BD10 8001B510 820085A4 */   sh        $a1, 0x82($a0)
endlabel SoundVM_A3_ChannelMasterVolume
