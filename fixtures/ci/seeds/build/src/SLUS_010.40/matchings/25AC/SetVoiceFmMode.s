nonmatching SetVoiceFmMode, 0x1C

glabel SetVoiceFmMode
    /* 433C 80013B3C 801F013C */  lui        $at, (0x1F801D90 >> 16)
    /* 4340 80013B40 901D24A4 */  sh         $a0, (0x1F801D90 & 0xFFFF)($at)
    /* 4344 80013B44 02240400 */  srl        $a0, $a0, 16
    /* 4348 80013B48 801F013C */  lui        $at, (0x1F801D92 >> 16)
    /* 434C 80013B4C 921D24A4 */  sh         $a0, (0x1F801D92 & 0xFFFF)($at)
    /* 4350 80013B50 0800E003 */  jr         $ra
    /* 4354 80013B54 00000000 */   nop
endlabel SetVoiceFmMode
