nonmatching SetVoiceAdsrSustainLevel, 0x28

glabel SetVoiceAdsrSustainLevel
    /* 4478 80013C78 801F023C */  lui        $v0, (0x1F801C08 >> 16)
    /* 447C 80013C7C 081C4234 */  ori        $v0, $v0, (0x1F801C08 & 0xFFFF)
    /* 4480 80013C80 00210400 */  sll        $a0, $a0, 4
    /* 4484 80013C84 21208200 */  addu       $a0, $a0, $v0
    /* 4488 80013C88 00008294 */  lhu        $v0, 0x0($a0)
    /* 448C 80013C8C 00000000 */  nop
    /* 4490 80013C90 F0FF4230 */  andi       $v0, $v0, 0xFFF0
    /* 4494 80013C94 25104500 */  or         $v0, $v0, $a1
    /* 4498 80013C98 0800E003 */  jr         $ra
    /* 449C 80013C9C 000082A4 */   sh        $v0, 0x0($a0)
endlabel SetVoiceAdsrSustainLevel
