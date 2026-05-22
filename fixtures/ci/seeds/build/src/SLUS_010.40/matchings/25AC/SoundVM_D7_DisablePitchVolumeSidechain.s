nonmatching SoundVM_D7_DisablePitchVolumeSidechain, 0x14

glabel SoundVM_D7_DisablePitchVolumeSidechain
    /* D3B8 8001CBB8 3400828C */  lw         $v0, 0x34($a0)
    /* D3BC 8001CBBC DFFF0324 */  addiu      $v1, $zero, -0x21
    /* D3C0 8001CBC0 24104300 */  and        $v0, $v0, $v1
    /* D3C4 8001CBC4 0800E003 */  jr         $ra
    /* D3C8 8001CBC8 340082AC */   sw        $v0, 0x34($a0)
endlabel SoundVM_D7_DisablePitchVolumeSidechain
