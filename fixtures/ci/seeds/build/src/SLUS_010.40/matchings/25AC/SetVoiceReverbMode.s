nonmatching SetVoiceReverbMode, 0x1C

glabel SetVoiceReverbMode
    /* 4304 80013B04 801F013C */  lui        $at, (0x1F801D98 >> 16)
    /* 4308 80013B08 981D24A4 */  sh         $a0, (0x1F801D98 & 0xFFFF)($at)
    /* 430C 80013B0C 02240400 */  srl        $a0, $a0, 16
    /* 4310 80013B10 801F013C */  lui        $at, (0x1F801D9A >> 16)
    /* 4314 80013B14 9A1D24A4 */  sh         $a0, (0x1F801D9A & 0xFFFF)($at)
    /* 4318 80013B18 0800E003 */  jr         $ra
    /* 431C 80013B1C 00000000 */   nop
endlabel SetVoiceReverbMode
