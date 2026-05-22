nonmatching _playNewGameSfx, 0x3C

glabel _playNewGameSfx
    /* 22C 80068A2C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 230 80068A30 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 234 80068A34 1000BFAF */  sw         $ra, 0x10($sp)
    /* 238 80068A38 6216010C */  jal        vs_main_playSfxDefault
    /* 23C 80068A3C 01000524 */   addiu     $a1, $zero, 0x1
    /* 240 80068A40 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 244 80068A44 6216010C */  jal        vs_main_playSfxDefault
    /* 248 80068A48 02000524 */   addiu     $a1, $zero, 0x2
    /* 24C 80068A4C 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 250 80068A50 6216010C */  jal        vs_main_playSfxDefault
    /* 254 80068A54 03000524 */   addiu     $a1, $zero, 0x3
    /* 258 80068A58 1000BF8F */  lw         $ra, 0x10($sp)
    /* 25C 80068A5C 00000000 */  nop
    /* 260 80068A60 0800E003 */  jr         $ra
    /* 264 80068A64 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _playNewGameSfx
