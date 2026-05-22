nonmatching vs_main_loadSoundFile, 0x30

glabel vs_main_loadSoundFile
    /* 36F70 80046770 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 36F74 80046774 0580023C */  lui        $v0, %hi(_soundFileMap)
    /* 36F78 80046778 B0B14224 */  addiu      $v0, $v0, %lo(_soundFileMap)
    /* 36F7C 8004677C 21208200 */  addu       $a0, $a0, $v0
    /* 36F80 80046780 1000BFAF */  sw         $ra, 0x10($sp)
    /* 36F84 80046784 00008490 */  lbu        $a0, 0x0($a0)
    /* 36F88 80046788 9E19010C */  jal        _loadSoundFile
    /* 36F8C 8004678C 00000000 */   nop
    /* 36F90 80046790 1000BF8F */  lw         $ra, 0x10($sp)
    /* 36F94 80046794 00000000 */  nop
    /* 36F98 80046798 0800E003 */  jr         $ra
    /* 36F9C 8004679C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_main_loadSoundFile
