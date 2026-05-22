nonmatching _playMenuChangeSfx, 0x24

glabel _playMenuChangeSfx
    /* 268 80068A68 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 26C 80068A6C 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 270 80068A70 1000BFAF */  sw         $ra, 0x10($sp)
    /* 274 80068A74 6216010C */  jal        vs_main_playSfxDefault
    /* 278 80068A78 04000524 */   addiu     $a1, $zero, 0x4
    /* 27C 80068A7C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 280 80068A80 00000000 */  nop
    /* 284 80068A84 0800E003 */  jr         $ra
    /* 288 80068A88 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _playMenuChangeSfx
