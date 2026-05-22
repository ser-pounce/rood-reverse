nonmatching SoundVM_E0_unk, 0x14

glabel SoundVM_E0_unk
    /* D484 8001CC84 3400828C */  lw         $v0, 0x34($a0)
    /* D488 8001CC88 1000033C */  lui        $v1, (0x100000 >> 16)
    /* D48C 8001CC8C 25104300 */  or         $v0, $v0, $v1
    /* D490 8001CC90 0800E003 */  jr         $ra
    /* D494 8001CC94 340082AC */   sw        $v0, 0x34($a0)
endlabel SoundVM_E0_unk
