nonmatching SetVoiceKeyOn, 0x1C

glabel SetVoiceKeyOn
    /* 42CC 80013ACC 801F013C */  lui        $at, (0x1F801D88 >> 16)
    /* 42D0 80013AD0 881D24A4 */  sh         $a0, (0x1F801D88 & 0xFFFF)($at)
    /* 42D4 80013AD4 02240400 */  srl        $a0, $a0, 16
    /* 42D8 80013AD8 801F013C */  lui        $at, (0x1F801D8A >> 16)
    /* 42DC 80013ADC 8A1D24A4 */  sh         $a0, (0x1F801D8A & 0xFFFF)($at)
    /* 42E0 80013AE0 0800E003 */  jr         $ra
    /* 42E4 80013AE4 00000000 */   nop
endlabel SetVoiceKeyOn
