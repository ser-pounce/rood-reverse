nonmatching vs_battle_script_loadSfxSlot, 0x2C

glabel vs_battle_script_loadSfxSlot
    /* 51C44 800BA444 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51C48 800BA448 21108000 */  addu       $v0, $a0, $zero
    /* 51C4C 800BA44C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51C50 800BA450 01004490 */  lbu        $a0, 0x1($v0)
    /* 51C54 800BA454 02004590 */  lbu        $a1, 0x2($v0)
    /* 51C58 800BA458 7817010C */  jal        vs_main_loadSfxSlot
    /* 51C5C 800BA45C 00000000 */   nop
    /* 51C60 800BA460 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51C64 800BA464 21100000 */  addu       $v0, $zero, $zero
    /* 51C68 800BA468 0800E003 */  jr         $ra
    /* 51C6C 800BA46C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_loadSfxSlot
