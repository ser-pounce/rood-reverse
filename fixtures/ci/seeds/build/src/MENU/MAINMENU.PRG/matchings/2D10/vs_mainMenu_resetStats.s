nonmatching vs_mainMenu_resetStats, 0x50

glabel vs_mainMenu_resetStats
    /* 3A20 800FD220 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3A24 800FD224 1080043C */  lui        $a0, %hi(vs_mainMenu_equipmentStats)
    /* 3A28 800FD228 C0248424 */  addiu      $a0, $a0, %lo(vs_mainMenu_equipmentStats)
    /* 3A2C 800FD22C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3A30 800FD230 0733030C */  jal        vs_battle_rMemzero
    /* 3A34 800FD234 80000524 */   addiu     $a1, $zero, 0x80
    /* 3A38 800FD238 21200000 */  addu       $a0, $zero, $zero
    /* 3A3C 800FD23C 21288000 */  addu       $a1, $a0, $zero
    /* 3A40 800FD240 21308000 */  addu       $a2, $a0, $zero
    /* 3A44 800FD244 82F0030C */  jal        vs_mainMenu_setDpPp
    /* 3A48 800FD248 21388000 */   addu      $a3, $a0, $zero
    /* 3A4C 800FD24C 21200000 */  addu       $a0, $zero, $zero
    /* 3A50 800FD250 21288000 */  addu       $a1, $a0, $zero
    /* 3A54 800FD254 21308000 */  addu       $a2, $a0, $zero
    /* 3A58 800FD258 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 3A5C 800FD25C 01000724 */   addiu     $a3, $zero, 0x1
    /* 3A60 800FD260 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3A64 800FD264 00000000 */  nop
    /* 3A68 800FD268 0800E003 */  jr         $ra
    /* 3A6C 800FD26C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_mainMenu_resetStats
