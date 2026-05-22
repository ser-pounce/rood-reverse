nonmatching SoundVM_DB_DisablePortamento, 0x8

glabel SoundVM_DB_DisablePortamento
    /* C3D0 8001BBD0 0800E003 */  jr         $ra
    /* C3D4 8001BBD4 9A0080A4 */   sh        $zero, 0x9A($a0)
endlabel SoundVM_DB_DisablePortamento
