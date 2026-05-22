nonmatching vs_sound_spuTransferring, 0x10

glabel vs_sound_spuTransferring
    /* 3404 80012C04 0380023C */  lui        $v0, %hi(_isSpuTransfer)
    /* 3408 80012C08 F077428C */  lw         $v0, %lo(_isSpuTransfer)($v0)
    /* 340C 80012C0C 0800E003 */  jr         $ra
    /* 3410 80012C10 00000000 */   nop
endlabel vs_sound_spuTransferring
