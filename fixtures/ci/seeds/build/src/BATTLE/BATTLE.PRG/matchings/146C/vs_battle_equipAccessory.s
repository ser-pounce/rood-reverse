nonmatching vs_battle_equipAccessory, 0x58

glabel vs_battle_equipAccessory
    /* 2D24 8006B524 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2D28 8006B528 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2D2C 8006B52C 0F80103C */  lui        $s0, %hi(vs_battle_characterState)
    /* 2D30 8006B530 FC19028E */  lw         $v0, %lo(vs_battle_characterState)($s0)
    /* 2D34 8006B534 21288000 */  addu       $a1, $a0, $zero
    /* 2D38 8006B538 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2D3C 8006B53C 3C00448C */  lw         $a0, 0x3C($v0)
    /* 2D40 8006B540 65AC010C */  jal        vs_battle_applyAccessory
    /* 2D44 8006B544 38038424 */   addiu     $a0, $a0, 0x338
    /* 2D48 8006B548 FC19028E */  lw         $v0, %lo(vs_battle_characterState)($s0)
    /* 2D4C 8006B54C 00000000 */  nop
    /* 2D50 8006B550 3C00448C */  lw         $a0, 0x3C($v0)
    /* 2D54 8006B554 83AC010C */  jal        vs_battle_nop0
    /* 2D58 8006B558 00000000 */   nop
    /* 2D5C 8006B55C 85AC010C */  jal        func_8006B214
    /* 2D60 8006B560 00000000 */   nop
    /* 2D64 8006B564 B5AC010C */  jal        func_8006B2D4
    /* 2D68 8006B568 00000000 */   nop
    /* 2D6C 8006B56C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2D70 8006B570 1000B08F */  lw         $s0, 0x10($sp)
    /* 2D74 8006B574 0800E003 */  jr         $ra
    /* 2D78 8006B578 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_equipAccessory
