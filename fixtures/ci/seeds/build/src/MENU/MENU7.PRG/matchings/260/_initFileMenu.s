nonmatching _initFileMenu, 0x60

glabel _initFileMenu
    /* 2558 80104D58 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 255C 80104D5C 1180023C */  lui        $v0, %hi(_memoryCardMessage)
    /* 2560 80104D60 A4B040AC */  sw         $zero, %lo(_memoryCardMessage)($v0)
    /* 2564 80104D64 1180023C */  lui        $v0, %hi(_selectCursorColor)
    /* 2568 80104D68 A9B040A0 */  sb         $zero, %lo(_selectCursorColor)($v0)
    /* 256C 80104D6C 1180023C */  lui        $v0, %hi(_selectCursorXy)
    /* 2570 80104D70 A0B040AC */  sw         $zero, %lo(_selectCursorXy)($v0)
    /* 2574 80104D74 1180023C */  lui        $v0, %hi(_fileProgressCounter)
    /* 2578 80104D78 4CAE40AC */  sw         $zero, %lo(_fileProgressCounter)($v0)
    /* 257C 80104D7C 1180023C */  lui        $v0, %hi(_fileMenuScreenFade)
    /* 2580 80104D80 1180033C */  lui        $v1, %hi(_fileProgressTarget)
    /* 2584 80104D84 AAB040A0 */  sb         $zero, %lo(_fileMenuScreenFade)($v0)
    /* 2588 80104D88 80010224 */  addiu      $v0, $zero, 0x180
    /* 258C 80104D8C 1180043C */  lui        $a0, %hi(_fileMenuElements)
    /* 2590 80104D90 50AE8424 */  addiu      $a0, $a0, %lo(_fileMenuElements)
    /* 2594 80104D94 21280000 */  addu       $a1, $zero, $zero
    /* 2598 80104D98 08020624 */  addiu      $a2, $zero, 0x208
    /* 259C 80104D9C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 25A0 80104DA0 AD9B000C */  jal        memset
    /* 25A4 80104DA4 46AE62A4 */   sh        $v0, %lo(_fileProgressTarget)($v1)
    /* 25A8 80104DA8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 25AC 80104DAC 00000000 */  nop
    /* 25B0 80104DB0 0800E003 */  jr         $ra
    /* 25B4 80104DB4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _initFileMenu
