nonmatching SetVoiceSampleRate, 0x18

glabel SetVoiceSampleRate
    /* 43A0 80013BA0 801F023C */  lui        $v0, (0x1F801C04 >> 16)
    /* 43A4 80013BA4 041C4234 */  ori        $v0, $v0, (0x1F801C04 & 0xFFFF)
    /* 43A8 80013BA8 00210400 */  sll        $a0, $a0, 4
    /* 43AC 80013BAC 21208200 */  addu       $a0, $a0, $v0
    /* 43B0 80013BB0 0800E003 */  jr         $ra
    /* 43B4 80013BB4 000085A4 */   sh        $a1, 0x0($a0)
endlabel SetVoiceSampleRate
