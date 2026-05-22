nonmatching func_800B9670, 0x40

glabel func_800B9670
    /* 50E70 800B9670 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 50E74 800B9674 1000B0AF */  sw         $s0, 0x10($sp)
    /* 50E78 800B9678 21808000 */  addu       $s0, $a0, $zero
    /* 50E7C 800B967C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 50E80 800B9680 80FF020C */  jal        vs_battle_getShort
    /* 50E84 800B9684 01000426 */   addiu     $a0, $s0, 0x1
    /* 50E88 800B9688 94FF020C */  jal        func_800BFE50
    /* 50E8C 800B968C FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 50E90 800B9690 03000592 */  lbu        $a1, 0x3($s0)
    /* 50E94 800B9694 FA75020C */  jal        func_8009D7E8
    /* 50E98 800B9698 21204000 */   addu      $a0, $v0, $zero
    /* 50E9C 800B969C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 50EA0 800B96A0 1000B08F */  lw         $s0, 0x10($sp)
    /* 50EA4 800B96A4 21100000 */  addu       $v0, $zero, $zero
    /* 50EA8 800B96A8 0800E003 */  jr         $ra
    /* 50EAC 800B96AC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9670
