nonmatching vs_main_playSfxDefault, 0x24

glabel vs_main_playSfxDefault
    /* 36188 80045988 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3618C 8004598C 80000624 */  addiu      $a2, $zero, 0x80
    /* 36190 80045990 1000BFAF */  sw         $ra, 0x10($sp)
    /* 36194 80045994 D515010C */  jal        vs_main_playSfx
    /* 36198 80045998 7F000724 */   addiu     $a3, $zero, 0x7F
    /* 3619C 8004599C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 361A0 800459A0 00000000 */  nop
    /* 361A4 800459A4 0800E003 */  jr         $ra
    /* 361A8 800459A8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_main_playSfxDefault
