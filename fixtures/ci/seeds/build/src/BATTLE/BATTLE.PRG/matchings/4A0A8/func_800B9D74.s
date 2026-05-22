nonmatching func_800B9D74, 0x40

glabel func_800B9D74
    /* 51574 800B9D74 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51578 800B9D78 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5157C 800B9D7C 21808000 */  addu       $s0, $a0, $zero
    /* 51580 800B9D80 1400BFAF */  sw         $ra, 0x14($sp)
    /* 51584 800B9D84 80FF020C */  jal        vs_battle_getShort
    /* 51588 800B9D88 01000426 */   addiu     $a0, $s0, 0x1
    /* 5158C 800B9D8C 94FF020C */  jal        func_800BFE50
    /* 51590 800B9D90 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 51594 800B9D94 03000592 */  lbu        $a1, 0x3($s0)
    /* 51598 800B9D98 DFB0020C */  jal        func_800AC37C
    /* 5159C 800B9D9C 21204000 */   addu      $a0, $v0, $zero
    /* 515A0 800B9DA0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 515A4 800B9DA4 1000B08F */  lw         $s0, 0x10($sp)
    /* 515A8 800B9DA8 21100000 */  addu       $v0, $zero, $zero
    /* 515AC 800B9DAC 0800E003 */  jr         $ra
    /* 515B0 800B9DB0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9D74
