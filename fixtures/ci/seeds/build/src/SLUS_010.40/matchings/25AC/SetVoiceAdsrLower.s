nonmatching SetVoiceAdsrLower, 0x18

glabel SetVoiceAdsrLower
    /* 43F0 80013BF0 801F023C */  lui        $v0, (0x1F801C08 >> 16)
    /* 43F4 80013BF4 081C4234 */  ori        $v0, $v0, (0x1F801C08 & 0xFFFF)
    /* 43F8 80013BF8 00210400 */  sll        $a0, $a0, 4
    /* 43FC 80013BFC 21208200 */  addu       $a0, $a0, $v0
    /* 4400 80013C00 0800E003 */  jr         $ra
    /* 4404 80013C04 000085A4 */   sh        $a1, 0x0($a0)
endlabel SetVoiceAdsrLower
