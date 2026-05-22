nonmatching vs_mainMenu_setStrIntAgi, 0x58

glabel vs_mainMenu_setStrIntAgi
    /* 2528 800FBD28 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 252C 800FBD2C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2530 800FBD30 1080103C */  lui        $s0, %hi(vs_mainMenu_strIntAgi)
    /* 2534 800FBD34 A82404A6 */  sh         $a0, %lo(vs_mainMenu_strIntAgi)($s0)
    /* 2538 800FBD38 21200000 */  addu       $a0, $zero, $zero
    /* 253C 800FBD3C A8241026 */  addiu      $s0, $s0, %lo(vs_mainMenu_strIntAgi)
    /* 2540 800FBD40 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2544 800FBD44 020005A6 */  sh         $a1, 0x2($s0)
    /* 2548 800FBD48 21288000 */  addu       $a1, $a0, $zero
    /* 254C 800FBD4C 040006A6 */  sh         $a2, 0x4($s0)
    /* 2550 800FBD50 21308000 */  addu       $a2, $a0, $zero
    /* 2554 800FBD54 060007A6 */  sh         $a3, 0x6($s0)
    /* 2558 800FBD58 43EF030C */  jal        vs_mainMenu_setRangeRisk
    /* 255C 800FBD5C 21388000 */   addu      $a3, $a0, $zero
    /* 2560 800FBD60 08000426 */  addiu      $a0, $s0, 0x8
    /* 2564 800FBD64 21280002 */  addu       $a1, $s0, $zero
    /* 2568 800FBD68 7800030C */  jal        vs_battle_memcpy
    /* 256C 800FBD6C 08000624 */   addiu     $a2, $zero, 0x8
    /* 2570 800FBD70 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2574 800FBD74 1000B08F */  lw         $s0, 0x10($sp)
    /* 2578 800FBD78 0800E003 */  jr         $ra
    /* 257C 800FBD7C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_mainMenu_setStrIntAgi
