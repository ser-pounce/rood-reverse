nonmatching SetVoiceAdsrUpper, 0x18

glabel SetVoiceAdsrUpper
    /* 4408 80013C08 801F023C */  lui        $v0, (0x1F801C0A >> 16)
    /* 440C 80013C0C 0A1C4234 */  ori        $v0, $v0, (0x1F801C0A & 0xFFFF)
    /* 4410 80013C10 00210400 */  sll        $a0, $a0, 4
    /* 4414 80013C14 21208200 */  addu       $a0, $a0, $v0
    /* 4418 80013C18 0800E003 */  jr         $ra
    /* 441C 80013C1C 000085A4 */   sh        $a1, 0x0($a0)
endlabel SetVoiceAdsrUpper
