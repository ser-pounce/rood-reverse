nonmatching SoundVM_FE0F_Return, 0xC

glabel SoundVM_FE0F_Return
    /* BCE0 8001B4E0 1400828C */  lw         $v0, 0x14($a0)
    /* BCE4 8001B4E4 0800E003 */  jr         $ra
    /* BCE8 8001B4E8 000082AC */   sw        $v0, 0x0($a0)
endlabel SoundVM_FE0F_Return
