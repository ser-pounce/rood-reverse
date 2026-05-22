nonmatching SpuSetCommonMasterVolume, 0x1C

glabel SpuSetCommonMasterVolume
    /* F4A4 8001ECA4 FF7F8430 */  andi       $a0, $a0, 0x7FFF
    /* F4A8 8001ECA8 0380023C */  lui        $v0, %hi(D_80030860)
    /* F4AC 8001ECAC 6008428C */  lw         $v0, %lo(D_80030860)($v0)
    /* F4B0 8001ECB0 FF7FA530 */  andi       $a1, $a1, 0x7FFF
    /* F4B4 8001ECB4 800144A4 */  sh         $a0, 0x180($v0)
    /* F4B8 8001ECB8 0800E003 */  jr         $ra
    /* F4BC 8001ECBC 820145A4 */   sh        $a1, 0x182($v0)
endlabel SpuSetCommonMasterVolume
    /* F4C0 8001ECC0 00000000 */  nop
