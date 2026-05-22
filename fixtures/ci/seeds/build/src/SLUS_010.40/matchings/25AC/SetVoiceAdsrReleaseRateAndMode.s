nonmatching SetVoiceAdsrReleaseRateAndMode, 0x30

glabel SetVoiceAdsrReleaseRateAndMode
    /* 44D4 80013CD4 801F023C */  lui        $v0, (0x1F801C0A >> 16)
    /* 44D8 80013CD8 0A1C4234 */  ori        $v0, $v0, (0x1F801C0A & 0xFFFF)
    /* 44DC 80013CDC 00210400 */  sll        $a0, $a0, 4
    /* 44E0 80013CE0 21208200 */  addu       $a0, $a0, $v0
    /* 44E4 80013CE4 82300600 */  srl        $a2, $a2, 2
    /* 44E8 80013CE8 40310600 */  sll        $a2, $a2, 5
    /* 44EC 80013CEC 00008294 */  lhu        $v0, 0x0($a0)
    /* 44F0 80013CF0 2530C500 */  or         $a2, $a2, $a1
    /* 44F4 80013CF4 C0FF4230 */  andi       $v0, $v0, 0xFFC0
    /* 44F8 80013CF8 25104600 */  or         $v0, $v0, $a2
    /* 44FC 80013CFC 0800E003 */  jr         $ra
    /* 4500 80013D00 000082A4 */   sh        $v0, 0x0($a0)
endlabel SetVoiceAdsrReleaseRateAndMode
