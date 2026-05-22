nonmatching SetVoiceAdsrSustainRateAndDirection, 0x34

glabel SetVoiceAdsrSustainRateAndDirection
    /* 44A0 80013CA0 801F023C */  lui        $v0, (0x1F801C0A >> 16)
    /* 44A4 80013CA4 0A1C4234 */  ori        $v0, $v0, (0x1F801C0A & 0xFFFF)
    /* 44A8 80013CA8 00210400 */  sll        $a0, $a0, 4
    /* 44AC 80013CAC 21208200 */  addu       $a0, $a0, $v0
    /* 44B0 80013CB0 42300600 */  srl        $a2, $a2, 1
    /* 44B4 80013CB4 80330600 */  sll        $a2, $a2, 14
    /* 44B8 80013CB8 80290500 */  sll        $a1, $a1, 6
    /* 44BC 80013CBC 00008294 */  lhu        $v0, 0x0($a0)
    /* 44C0 80013CC0 2530C500 */  or         $a2, $a2, $a1
    /* 44C4 80013CC4 3F004230 */  andi       $v0, $v0, 0x3F
    /* 44C8 80013CC8 25104600 */  or         $v0, $v0, $a2
    /* 44CC 80013CCC 0800E003 */  jr         $ra
    /* 44D0 80013CD0 000082A4 */   sh        $v0, 0x0($a0)
endlabel SetVoiceAdsrSustainRateAndDirection
