nonmatching _playMenuLeaveSfx, 0x24

glabel _playMenuLeaveSfx
    /* 2B0 80068AB0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2B4 80068AB4 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 2B8 80068AB8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2BC 80068ABC 6216010C */  jal        vs_main_playSfxDefault
    /* 2C0 80068AC0 06000524 */   addiu     $a1, $zero, 0x6
    /* 2C4 80068AC4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2C8 80068AC8 00000000 */  nop
    /* 2CC 80068ACC 0800E003 */  jr         $ra
    /* 2D0 80068AD0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _playMenuLeaveSfx
