nonmatching vs_battle_script_loadSoundFile, 0x40

glabel vs_battle_script_loadSoundFile
    /* 51CEC 800BA4EC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51CF0 800BA4F0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 51CF4 800BA4F4 4124020C */  jal        func_80089104
    /* 51CF8 800BA4F8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 51CFC 800BA4FC 00840200 */  sll        $s0, $v0, 16
    /* 51D00 800BA500 03841000 */  sra        $s0, $s0, 16
    /* 51D04 800BA504 21200002 */  addu       $a0, $s0, $zero
    /* 51D08 800BA508 4414010C */  jal        vs_main_loadMusicSlot
    /* 51D0C 800BA50C 03000524 */   addiu     $a1, $zero, 0x3
    /* 51D10 800BA510 DC19010C */  jal        vs_main_loadSoundFile
    /* 51D14 800BA514 21200002 */   addu      $a0, $s0, $zero
    /* 51D18 800BA518 1400BF8F */  lw         $ra, 0x14($sp)
    /* 51D1C 800BA51C 1000B08F */  lw         $s0, 0x10($sp)
    /* 51D20 800BA520 21100000 */  addu       $v0, $zero, $zero
    /* 51D24 800BA524 0800E003 */  jr         $ra
    /* 51D28 800BA528 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_loadSoundFile
