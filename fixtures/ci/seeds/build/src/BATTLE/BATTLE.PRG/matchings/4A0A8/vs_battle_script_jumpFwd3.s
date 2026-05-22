nonmatching vs_battle_script_jumpFwd3, 0x34

glabel vs_battle_script_jumpFwd3
    /* 504E8 800B8CE8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 504EC 800B8CEC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 504F0 800B8CF0 21808000 */  addu       $s0, $a0, $zero
    /* 504F4 800B8CF4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 504F8 800B8CF8 80FF020C */  jal        vs_battle_getShort
    /* 504FC 800B8CFC 01000426 */   addiu     $a0, $s0, 0x1
    /* 50500 800B8D00 00140200 */  sll        $v0, $v0, 16
    /* 50504 800B8D04 03140200 */  sra        $v0, $v0, 16
    /* 50508 800B8D08 21100202 */  addu       $v0, $s0, $v0
    /* 5050C 800B8D0C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 50510 800B8D10 1000B08F */  lw         $s0, 0x10($sp)
    /* 50514 800B8D14 0800E003 */  jr         $ra
    /* 50518 800B8D18 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_jumpFwd3
