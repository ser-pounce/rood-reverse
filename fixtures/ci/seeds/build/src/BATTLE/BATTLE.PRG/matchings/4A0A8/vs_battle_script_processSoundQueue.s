nonmatching vs_battle_script_processSoundQueue, 0x24

glabel vs_battle_script_processSoundQueue
    /* 51F98 800BA798 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51F9C 800BA79C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51FA0 800BA7A0 E819010C */  jal        vs_main_processSoundQueue
    /* 51FA4 800BA7A4 00000000 */   nop
    /* 51FA8 800BA7A8 01004238 */  xori       $v0, $v0, 0x1
    /* 51FAC 800BA7AC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51FB0 800BA7B0 0100422C */  sltiu      $v0, $v0, 0x1
    /* 51FB4 800BA7B4 0800E003 */  jr         $ra
    /* 51FB8 800BA7B8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_processSoundQueue
