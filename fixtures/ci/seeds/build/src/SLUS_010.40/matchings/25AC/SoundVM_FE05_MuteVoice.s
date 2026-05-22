nonmatching SoundVM_FE05_MuteVoice, 0x18

glabel SoundVM_FE05_MuteVoice
    /* D164 8001C964 3400828C */  lw         $v0, 0x34($a0)
    /* D168 8001C968 F7FF0324 */  addiu      $v1, $zero, -0x9
    /* D16C 8001C96C 0A0180A4 */  sh         $zero, 0x10A($a0)
    /* D170 8001C970 24104300 */  and        $v0, $v0, $v1
    /* D174 8001C974 0800E003 */  jr         $ra
    /* D178 8001C978 340082AC */   sw        $v0, 0x34($a0)
endlabel SoundVM_FE05_MuteVoice
