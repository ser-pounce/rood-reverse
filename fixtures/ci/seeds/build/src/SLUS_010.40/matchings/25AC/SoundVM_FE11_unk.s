nonmatching SoundVM_FE11_unk, 0x10

glabel SoundVM_FE11_unk
    /* CE8C 8001C68C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* CE90 8001C690 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* CE94 8001C694 0800E003 */  jr         $ra
    /* CE98 8001C698 480040AC */   sw        $zero, 0x48($v0)
endlabel SoundVM_FE11_unk
