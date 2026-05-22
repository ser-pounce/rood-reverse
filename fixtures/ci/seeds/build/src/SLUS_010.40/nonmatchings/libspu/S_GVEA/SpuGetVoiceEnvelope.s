nonmatching SpuGetVoiceEnvelope, 0x1C

glabel SpuGetVoiceEnvelope
    /* F484 8001EC84 0380023C */  lui        $v0, %hi(D_80030860)
    /* F488 8001EC88 6008428C */  lw         $v0, %lo(D_80030860)($v0)
    /* F48C 8001EC8C 00210400 */  sll        $a0, $a0, 4
    /* F490 8001EC90 21208200 */  addu       $a0, $a0, $v0
    /* F494 8001EC94 0C008294 */  lhu        $v0, 0xC($a0)
    /* F498 8001EC98 0800E003 */  jr         $ra
    /* F49C 8001EC9C 0000A2A4 */   sh        $v0, 0x0($a1)
endlabel SpuGetVoiceEnvelope
    /* F4A0 8001ECA0 00000000 */  nop
