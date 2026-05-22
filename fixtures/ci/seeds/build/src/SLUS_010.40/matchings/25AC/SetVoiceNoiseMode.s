nonmatching SetVoiceNoiseMode, 0x1C

glabel SetVoiceNoiseMode
    /* 4320 80013B20 801F013C */  lui        $at, (0x1F801D94 >> 16)
    /* 4324 80013B24 941D24A4 */  sh         $a0, (0x1F801D94 & 0xFFFF)($at)
    /* 4328 80013B28 02240400 */  srl        $a0, $a0, 16
    /* 432C 80013B2C 801F013C */  lui        $at, (0x1F801D96 >> 16)
    /* 4330 80013B30 961D24A4 */  sh         $a0, (0x1F801D96 & 0xFFFF)($at)
    /* 4334 80013B34 0800E003 */  jr         $ra
    /* 4338 80013B38 00000000 */   nop
endlabel SetVoiceNoiseMode
