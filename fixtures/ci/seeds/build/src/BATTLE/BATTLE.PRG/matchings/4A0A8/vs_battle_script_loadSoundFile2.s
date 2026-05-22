nonmatching vs_battle_script_loadSoundFile2, 0x24

glabel vs_battle_script_loadSoundFile2
    /* 51F74 800BA774 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51F78 800BA778 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51F7C 800BA77C 01008490 */  lbu        $a0, 0x1($a0)
    /* 51F80 800BA780 DC19010C */  jal        vs_main_loadSoundFile
    /* 51F84 800BA784 00000000 */   nop
    /* 51F88 800BA788 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51F8C 800BA78C 21100000 */  addu       $v0, $zero, $zero
    /* 51F90 800BA790 0800E003 */  jr         $ra
    /* 51F94 800BA794 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_loadSoundFile2
