nonmatching _playMenuSelectSfx, 0x24

glabel _playMenuSelectSfx
    /* 28C 80068A8C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 290 80068A90 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 294 80068A94 1000BFAF */  sw         $ra, 0x10($sp)
    /* 298 80068A98 6216010C */  jal        vs_main_playSfxDefault
    /* 29C 80068A9C 05000524 */   addiu     $a1, $zero, 0x5
    /* 2A0 80068AA0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2A4 80068AA4 00000000 */  nop
    /* 2A8 80068AA8 0800E003 */  jr         $ra
    /* 2AC 80068AAC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _playMenuSelectSfx
