nonmatching SoundVM_D5_DisablePlaybackRateSidechain, 0x14

glabel SoundVM_D5_DisablePlaybackRateSidechain
    /* D390 8001CB90 3400828C */  lw         $v0, 0x34($a0)
    /* D394 8001CB94 EFFF0324 */  addiu      $v1, $zero, -0x11
    /* D398 8001CB98 24104300 */  and        $v0, $v0, $v1
    /* D39C 8001CB9C 0800E003 */  jr         $ra
    /* D3A0 8001CBA0 340082AC */   sw        $v0, 0x34($a0)
endlabel SoundVM_D5_DisablePlaybackRateSidechain
