nonmatching SetVoiceRepeatAddr, 0x1C

glabel SetVoiceRepeatAddr
    /* 43D4 80013BD4 801F023C */  lui        $v0, (0x1F801C0E >> 16)
    /* 43D8 80013BD8 0E1C4234 */  ori        $v0, $v0, (0x1F801C0E & 0xFFFF)
    /* 43DC 80013BDC 00210400 */  sll        $a0, $a0, 4
    /* 43E0 80013BE0 21208200 */  addu       $a0, $a0, $v0
    /* 43E4 80013BE4 C2280500 */  srl        $a1, $a1, 3
    /* 43E8 80013BE8 0800E003 */  jr         $ra
    /* 43EC 80013BEC 000085A4 */   sh        $a1, 0x0($a0)
endlabel SetVoiceRepeatAddr
