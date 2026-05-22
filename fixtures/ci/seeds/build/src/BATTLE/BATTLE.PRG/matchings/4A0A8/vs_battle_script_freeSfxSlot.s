nonmatching vs_battle_script_freeSfxSlot, 0x24

glabel vs_battle_script_freeSfxSlot
    /* 51C70 800BA470 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51C74 800BA474 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51C78 800BA478 01008490 */  lbu        $a0, 0x1($a0)
    /* 51C7C 800BA47C D917010C */  jal        vs_main_freeSfxQueueSlot
    /* 51C80 800BA480 00000000 */   nop
    /* 51C84 800BA484 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51C88 800BA488 2B100200 */  sltu       $v0, $zero, $v0
    /* 51C8C 800BA48C 0800E003 */  jr         $ra
    /* 51C90 800BA490 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_freeSfxSlot
