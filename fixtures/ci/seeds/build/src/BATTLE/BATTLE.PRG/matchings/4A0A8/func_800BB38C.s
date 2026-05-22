nonmatching func_800BB38C, 0x30

glabel func_800BB38C
    /* 52B8C 800BB38C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52B90 800BB390 1000BFAF */  sw         $ra, 0x10($sp)
    /* 52B94 800BB394 80FF020C */  jal        vs_battle_getShort
    /* 52B98 800BB398 01008424 */   addiu     $a0, $a0, 0x1
    /* 52B9C 800BB39C 94FF020C */  jal        func_800BFE50
    /* 52BA0 800BB3A0 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 52BA4 800BB3A4 84EF020C */  jal        func_800BBE10
    /* 52BA8 800BB3A8 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 52BAC 800BB3AC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 52BB0 800BB3B0 21100000 */  addu       $v0, $zero, $zero
    /* 52BB4 800BB3B4 0800E003 */  jr         $ra
    /* 52BB8 800BB3B8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BB38C
