nonmatching func_800B92A0, 0x30

glabel func_800B92A0
    /* 50AA0 800B92A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 50AA4 800B92A4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 50AA8 800B92A8 80FF020C */  jal        vs_battle_getShort
    /* 50AAC 800B92AC 01008424 */   addiu     $a0, $a0, 0x1
    /* 50AB0 800B92B0 94FF020C */  jal        func_800BFE50
    /* 50AB4 800B92B4 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 50AB8 800B92B8 A3F0010C */  jal        func_8007C28C
    /* 50ABC 800B92BC 21204000 */   addu      $a0, $v0, $zero
    /* 50AC0 800B92C0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 50AC4 800B92C4 21100000 */  addu       $v0, $zero, $zero
    /* 50AC8 800B92C8 0800E003 */  jr         $ra
    /* 50ACC 800B92CC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B92A0
