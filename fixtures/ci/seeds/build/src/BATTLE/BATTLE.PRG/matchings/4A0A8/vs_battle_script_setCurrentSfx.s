nonmatching vs_battle_script_setCurrentSfx, 0x24

glabel vs_battle_script_setCurrentSfx
    /* 51CC8 800BA4C8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51CCC 800BA4CC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51CD0 800BA4D0 01008490 */  lbu        $a0, 0x1($a0)
    /* 51CD4 800BA4D4 2118010C */  jal        vs_main_setCurrentSfx
    /* 51CD8 800BA4D8 00000000 */   nop
    /* 51CDC 800BA4DC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51CE0 800BA4E0 21100000 */  addu       $v0, $zero, $zero
    /* 51CE4 800BA4E4 0800E003 */  jr         $ra
    /* 51CE8 800BA4E8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_setCurrentSfx
