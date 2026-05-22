nonmatching SetVoiceAdsrAttackRateAndMode, 0x30

glabel SetVoiceAdsrAttackRateAndMode
    /* 4420 80013C20 801F023C */  lui        $v0, (0x1F801C08 >> 16)
    /* 4424 80013C24 081C4234 */  ori        $v0, $v0, (0x1F801C08 & 0xFFFF)
    /* 4428 80013C28 00210400 */  sll        $a0, $a0, 4
    /* 442C 80013C2C 21208200 */  addu       $a0, $a0, $v0
    /* 4430 80013C30 82300600 */  srl        $a2, $a2, 2
    /* 4434 80013C34 C0330600 */  sll        $a2, $a2, 15
    /* 4438 80013C38 002A0500 */  sll        $a1, $a1, 8
    /* 443C 80013C3C 00008290 */  lbu        $v0, 0x0($a0)
    /* 4440 80013C40 2530C500 */  or         $a2, $a2, $a1
    /* 4444 80013C44 25104600 */  or         $v0, $v0, $a2
    /* 4448 80013C48 0800E003 */  jr         $ra
    /* 444C 80013C4C 000082A4 */   sh        $v0, 0x0($a0)
endlabel SetVoiceAdsrAttackRateAndMode
