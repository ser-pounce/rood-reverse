nonmatching SetVoiceKeyOff, 0x1C

glabel SetVoiceKeyOff
    /* 42E8 80013AE8 801F013C */  lui        $at, (0x1F801D8C >> 16)
    /* 42EC 80013AEC 8C1D24A4 */  sh         $a0, (0x1F801D8C & 0xFFFF)($at)
    /* 42F0 80013AF0 02240400 */  srl        $a0, $a0, 16
    /* 42F4 80013AF4 801F013C */  lui        $at, (0x1F801D8E >> 16)
    /* 42F8 80013AF8 8E1D24A4 */  sh         $a0, (0x1F801D8E & 0xFFFF)($at)
    /* 42FC 80013AFC 0800E003 */  jr         $ra
    /* 4300 80013B00 00000000 */   nop
endlabel SetVoiceKeyOff
