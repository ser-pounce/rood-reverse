nonmatching SetVoiceStartAddr, 0x1C

glabel SetVoiceStartAddr
    /* 43B8 80013BB8 801F023C */  lui        $v0, (0x1F801C06 >> 16)
    /* 43BC 80013BBC 061C4234 */  ori        $v0, $v0, (0x1F801C06 & 0xFFFF)
    /* 43C0 80013BC0 00210400 */  sll        $a0, $a0, 4
    /* 43C4 80013BC4 21208200 */  addu       $a0, $a0, $v0
    /* 43C8 80013BC8 C2280500 */  srl        $a1, $a1, 3
    /* 43CC 80013BCC 0800E003 */  jr         $ra
    /* 43D0 80013BD0 000085A4 */   sh        $a1, 0x0($a0)
endlabel SetVoiceStartAddr
