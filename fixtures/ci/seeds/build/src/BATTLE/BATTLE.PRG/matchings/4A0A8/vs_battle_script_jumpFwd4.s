nonmatching vs_battle_script_jumpFwd4, 0x34

glabel vs_battle_script_jumpFwd4
    /* 5051C 800B8D1C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 50520 800B8D20 1000B0AF */  sw         $s0, 0x10($sp)
    /* 50524 800B8D24 21808000 */  addu       $s0, $a0, $zero
    /* 50528 800B8D28 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5052C 800B8D2C 80FF020C */  jal        vs_battle_getShort
    /* 50530 800B8D30 01000426 */   addiu     $a0, $s0, 0x1
    /* 50534 800B8D34 00140200 */  sll        $v0, $v0, 16
    /* 50538 800B8D38 03140200 */  sra        $v0, $v0, 16
    /* 5053C 800B8D3C 21100202 */  addu       $v0, $s0, $v0
    /* 50540 800B8D40 1400BF8F */  lw         $ra, 0x14($sp)
    /* 50544 800B8D44 1000B08F */  lw         $s0, 0x10($sp)
    /* 50548 800B8D48 0800E003 */  jr         $ra
    /* 5054C 800B8D4C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_jumpFwd4
