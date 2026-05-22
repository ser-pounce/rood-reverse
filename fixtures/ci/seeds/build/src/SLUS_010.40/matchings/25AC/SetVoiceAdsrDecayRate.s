nonmatching SetVoiceAdsrDecayRate, 0x28

glabel SetVoiceAdsrDecayRate
    /* 4450 80013C50 801F023C */  lui        $v0, (0x1F801C08 >> 16)
    /* 4454 80013C54 081C4234 */  ori        $v0, $v0, (0x1F801C08 & 0xFFFF)
    /* 4458 80013C58 00210400 */  sll        $a0, $a0, 4
    /* 445C 80013C5C 21208200 */  addu       $a0, $a0, $v0
    /* 4460 80013C60 00008294 */  lhu        $v0, 0x0($a0)
    /* 4464 80013C64 00290500 */  sll        $a1, $a1, 4
    /* 4468 80013C68 0FFF4230 */  andi       $v0, $v0, 0xFF0F
    /* 446C 80013C6C 25104500 */  or         $v0, $v0, $a1
    /* 4470 80013C70 0800E003 */  jr         $ra
    /* 4474 80013C74 000082A4 */   sh        $v0, 0x0($a0)
endlabel SetVoiceAdsrDecayRate
