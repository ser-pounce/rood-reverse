nonmatching SpuSetReverbModeDepth, 0x28

glabel SpuSetReverbModeDepth
    /* FD04 8001F504 0380023C */  lui        $v0, %hi(D_80030860)
    /* FD08 8001F508 6008428C */  lw         $v0, %lo(D_80030860)($v0)
    /* FD0C 8001F50C 00000000 */  nop
    /* FD10 8001F510 840144A4 */  sh         $a0, 0x184($v0)
    /* FD14 8001F514 860145A4 */  sh         $a1, 0x186($v0)
    /* FD18 8001F518 0380023C */  lui        $v0, %hi(D_80030808)
    /* FD1C 8001F51C 08084224 */  addiu      $v0, $v0, %lo(D_80030808)
    /* FD20 8001F520 000044A4 */  sh         $a0, 0x0($v0)
    /* FD24 8001F524 0800E003 */  jr         $ra
    /* FD28 8001F528 020045A4 */   sh        $a1, 0x2($v0)
endlabel SpuSetReverbModeDepth
    /* FD2C 8001F52C 00000000 */  nop
    /* FD30 8001F530 00000000 */  nop
