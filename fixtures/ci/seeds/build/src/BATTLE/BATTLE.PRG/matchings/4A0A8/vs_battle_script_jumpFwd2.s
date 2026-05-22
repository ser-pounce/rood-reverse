nonmatching vs_battle_script_jumpFwd2, 0x34

glabel vs_battle_script_jumpFwd2
    /* 50390 800B8B90 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 50394 800B8B94 1000B0AF */  sw         $s0, 0x10($sp)
    /* 50398 800B8B98 21808000 */  addu       $s0, $a0, $zero
    /* 5039C 800B8B9C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 503A0 800B8BA0 80FF020C */  jal        vs_battle_getShort
    /* 503A4 800B8BA4 01000426 */   addiu     $a0, $s0, 0x1
    /* 503A8 800B8BA8 00140200 */  sll        $v0, $v0, 16
    /* 503AC 800B8BAC 03140200 */  sra        $v0, $v0, 16
    /* 503B0 800B8BB0 21100202 */  addu       $v0, $s0, $v0
    /* 503B4 800B8BB4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 503B8 800B8BB8 1000B08F */  lw         $s0, 0x10($sp)
    /* 503BC 800B8BBC 0800E003 */  jr         $ra
    /* 503C0 800B8BC0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_jumpFwd2
