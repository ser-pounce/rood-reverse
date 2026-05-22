nonmatching vs_main_wait, 0x20

glabel vs_main_wait
    /* 33474 80042C74 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 33478 80042C78 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3347C 80042C7C B542000C */  jal        vs_overlay_wait
    /* 33480 80042C80 00000000 */   nop
    /* 33484 80042C84 1000BF8F */  lw         $ra, 0x10($sp)
    /* 33488 80042C88 00000000 */  nop
    /* 3348C 80042C8C 0800E003 */  jr         $ra
    /* 33490 80042C90 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_main_wait
