nonmatching vs_battle_script_loadMusicSlot, 0x2C

glabel vs_battle_script_loadMusicSlot
    /* 51D88 800BA588 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51D8C 800BA58C 21108000 */  addu       $v0, $a0, $zero
    /* 51D90 800BA590 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51D94 800BA594 01004490 */  lbu        $a0, 0x1($v0)
    /* 51D98 800BA598 02004590 */  lbu        $a1, 0x2($v0)
    /* 51D9C 800BA59C 4414010C */  jal        vs_main_loadMusicSlot
    /* 51DA0 800BA5A0 00000000 */   nop
    /* 51DA4 800BA5A4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51DA8 800BA5A8 21100000 */  addu       $v0, $zero, $zero
    /* 51DAC 800BA5AC 0800E003 */  jr         $ra
    /* 51DB0 800BA5B0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_loadMusicSlot
