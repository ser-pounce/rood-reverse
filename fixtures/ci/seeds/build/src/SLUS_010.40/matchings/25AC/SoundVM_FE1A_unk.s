nonmatching SoundVM_FE1A_unk, 0x14

glabel SoundVM_FE1A_unk
    /* BEE4 8001B6E4 3400828C */  lw         $v0, 0x34($a0)
    /* BEE8 8001B6E8 00000000 */  nop
    /* BEEC 8001B6EC 40004234 */  ori        $v0, $v0, 0x40
    /* BEF0 8001B6F0 0800E003 */  jr         $ra
    /* BEF4 8001B6F4 340082AC */   sw        $v0, 0x34($a0)
endlabel SoundVM_FE1A_unk
