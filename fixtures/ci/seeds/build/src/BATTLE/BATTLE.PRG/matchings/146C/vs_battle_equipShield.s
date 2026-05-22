nonmatching vs_battle_equipShield, 0x58

glabel vs_battle_equipShield
    /* 2C60 8006B460 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2C64 8006B464 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2C68 8006B468 0F80103C */  lui        $s0, %hi(vs_battle_characterState)
    /* 2C6C 8006B46C FC19028E */  lw         $v0, %lo(vs_battle_characterState)($s0)
    /* 2C70 8006B470 21288000 */  addu       $a1, $a0, $zero
    /* 2C74 8006B474 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2C78 8006B478 3C00448C */  lw         $a0, 0x3C($v0)
    /* 2C7C 8006B47C 0BAC010C */  jal        vs_battle_applyShield
    /* 2C80 8006B480 D4018424 */   addiu     $a0, $a0, 0x1D4
    /* 2C84 8006B484 FC19028E */  lw         $v0, %lo(vs_battle_characterState)($s0)
    /* 2C88 8006B488 00000000 */  nop
    /* 2C8C 8006B48C 3C00448C */  lw         $a0, 0x3C($v0)
    /* 2C90 8006B490 83AC010C */  jal        vs_battle_nop0
    /* 2C94 8006B494 00000000 */   nop
    /* 2C98 8006B498 85AC010C */  jal        func_8006B214
    /* 2C9C 8006B49C 00000000 */   nop
    /* 2CA0 8006B4A0 B5AC010C */  jal        func_8006B2D4
    /* 2CA4 8006B4A4 00000000 */   nop
    /* 2CA8 8006B4A8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2CAC 8006B4AC 1000B08F */  lw         $s0, 0x10($sp)
    /* 2CB0 8006B4B0 0800E003 */  jr         $ra
    /* 2CB4 8006B4B4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_equipShield
