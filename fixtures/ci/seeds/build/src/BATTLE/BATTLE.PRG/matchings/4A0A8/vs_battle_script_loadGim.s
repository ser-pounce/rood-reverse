nonmatching vs_battle_script_loadGim, 0x3C

glabel vs_battle_script_loadGim
    /* 4E7D8 800B6FD8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4E7DC 800B6FDC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4E7E0 800B6FE0 21808000 */  addu       $s0, $a0, $zero
    /* 4E7E4 800B6FE4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4E7E8 800B6FE8 80FF020C */  jal        vs_battle_getShort
    /* 4E7EC 800B6FEC 01000426 */   addiu     $a0, $s0, 0x1
    /* 4E7F0 800B6FF0 00140200 */  sll        $v0, $v0, 16
    /* 4E7F4 800B6FF4 03000592 */  lbu        $a1, 0x3($s0)
    /* 4E7F8 800B6FF8 0C21030C */  jal        vs_battle_loadGim
    /* 4E7FC 800B6FFC 03240200 */   sra       $a0, $v0, 16
    /* 4E800 800B7000 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4E804 800B7004 1000B08F */  lw         $s0, 0x10($sp)
    /* 4E808 800B7008 21100000 */  addu       $v0, $zero, $zero
    /* 4E80C 800B700C 0800E003 */  jr         $ra
    /* 4E810 800B7010 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_loadGim
