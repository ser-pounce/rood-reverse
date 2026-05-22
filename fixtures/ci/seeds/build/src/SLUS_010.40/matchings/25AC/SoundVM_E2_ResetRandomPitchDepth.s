nonmatching SoundVM_E2_ResetRandomPitchDepth, 0x8

glabel SoundVM_E2_ResetRandomPitchDepth
    /* D524 8001CD24 0800E003 */  jr         $ra
    /* D528 8001CD28 D20080A4 */   sh        $zero, 0xD2($a0)
endlabel SoundVM_E2_ResetRandomPitchDepth
