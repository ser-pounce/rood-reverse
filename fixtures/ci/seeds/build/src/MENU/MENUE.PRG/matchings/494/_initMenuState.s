nonmatching _initMenuState, 0x6C

glabel _initMenuState
    /* 8A4 801030A4 0680023C */  lui        $v0, %hi(D_80060021)
    /* 8A8 801030A8 21004290 */  lbu        $v0, %lo(D_80060021)($v0)
    /* 8AC 801030AC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 8B0 801030B0 05004014 */  bnez       $v0, .L801030C8
    /* 8B4 801030B4 1000BFAF */   sw        $ra, 0x10($sp)
    /* 8B8 801030B8 0F80043C */  lui        $a0, %hi(vs_battle_manualDisplayState)
    /* 8BC 801030BC C81B8424 */  addiu      $a0, $a0, %lo(vs_battle_manualDisplayState)
    /* 8C0 801030C0 4424010C */  jal        vs_main_bzero
    /* 8C4 801030C4 24000524 */   addiu     $a1, $zero, 0x24
  .L801030C8:
    /* 8C8 801030C8 1D000424 */  addiu      $a0, $zero, 0x1D
    /* 8CC 801030CC 03000524 */  addiu      $a1, $zero, 0x3
    /* 8D0 801030D0 FCF7010C */  jal        func_8007DFF0
    /* 8D4 801030D4 05000624 */   addiu     $a2, $zero, 0x5
    /* 8D8 801030D8 01000224 */  addiu      $v0, $zero, 0x1
    /* 8DC 801030DC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 8E0 801030E0 1080033C */  lui        $v1, %hi(_showMenuState)
    /* 8E4 801030E4 405260AC */  sw         $zero, %lo(_showMenuState)($v1)
    /* 8E8 801030E8 1080033C */  lui        $v1, %hi(_scrollPosition)
    /* 8EC 801030EC 445260AC */  sw         $zero, %lo(_scrollPosition)($v1)
    /* 8F0 801030F0 1080033C */  lui        $v1, %hi(_lineCount)
    /* 8F4 801030F4 485260AC */  sw         $zero, %lo(_lineCount)($v1)
    /* 8F8 801030F8 1080033C */  lui        $v1, %hi(_helpText)
    /* 8FC 801030FC 545260AC */  sw         $zero, %lo(_helpText)($v1)
    /* 900 80103100 1080033C */  lui        $v1, %hi(_helpAssets)
    /* 904 80103104 585260AC */  sw         $zero, %lo(_helpAssets)($v1)
    /* 908 80103108 0800E003 */  jr         $ra
    /* 90C 8010310C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _initMenuState
