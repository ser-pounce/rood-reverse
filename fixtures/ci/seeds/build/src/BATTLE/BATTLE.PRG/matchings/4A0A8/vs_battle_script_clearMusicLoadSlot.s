nonmatching vs_battle_script_clearMusicLoadSlot, 0x28

glabel vs_battle_script_clearMusicLoadSlot
    /* 51F4C 800BA74C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51F50 800BA750 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51F54 800BA754 01008490 */  lbu        $a0, 0x1($a0)
    /* 51F58 800BA758 B214010C */  jal        vs_main_clearMusicLoadSlot
    /* 51F5C 800BA75C 00000000 */   nop
    /* 51F60 800BA760 01004238 */  xori       $v0, $v0, 0x1
    /* 51F64 800BA764 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51F68 800BA768 0100422C */  sltiu      $v0, $v0, 0x1
    /* 51F6C 800BA76C 0800E003 */  jr         $ra
    /* 51F70 800BA770 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_clearMusicLoadSlot
