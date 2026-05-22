nonmatching vs_battle_script_jumpFwd, 0x34

glabel vs_battle_script_jumpFwd
    /* 5035C 800B8B5C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 50360 800B8B60 1000B0AF */  sw         $s0, 0x10($sp)
    /* 50364 800B8B64 21808000 */  addu       $s0, $a0, $zero
    /* 50368 800B8B68 1400BFAF */  sw         $ra, 0x14($sp)
    /* 5036C 800B8B6C 80FF020C */  jal        vs_battle_getShort
    /* 50370 800B8B70 01000426 */   addiu     $a0, $s0, 0x1
    /* 50374 800B8B74 00140200 */  sll        $v0, $v0, 16
    /* 50378 800B8B78 03140200 */  sra        $v0, $v0, 16
    /* 5037C 800B8B7C 21100202 */  addu       $v0, $s0, $v0
    /* 50380 800B8B80 1400BF8F */  lw         $ra, 0x14($sp)
    /* 50384 800B8B84 1000B08F */  lw         $s0, 0x10($sp)
    /* 50388 800B8B88 0800E003 */  jr         $ra
    /* 5038C 800B8B8C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_jumpFwd
