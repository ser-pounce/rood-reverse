nonmatching vs_main_setMonoSound, 0x20

glabel vs_main_setMonoSound
    /* 370BC 800468BC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 370C0 800468C0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 370C4 800468C4 0349000C */  jal        vs_sound_setMonoSound
    /* 370C8 800468C8 00000000 */   nop
    /* 370CC 800468CC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 370D0 800468D0 00000000 */  nop
    /* 370D4 800468D4 0800E003 */  jr         $ra
    /* 370D8 800468D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_main_setMonoSound
