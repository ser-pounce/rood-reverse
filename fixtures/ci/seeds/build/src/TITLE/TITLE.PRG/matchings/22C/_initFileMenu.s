nonmatching _initFileMenu, 0x60

glabel _initFileMenu
    /* 2610 8006AE10 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2614 8006AE14 0E80023C */  lui        $v0, %hi(_selectSaveMemoryCardMessage)
    /* 2618 8006AE18 6CED40AC */  sw         $zero, %lo(_selectSaveMemoryCardMessage)($v0)
    /* 261C 8006AE1C 0E80023C */  lui        $v0, %hi(_selectCursorColor)
    /* 2620 8006AE20 71ED40A0 */  sb         $zero, %lo(_selectCursorColor)($v0)
    /* 2624 8006AE24 0E80023C */  lui        $v0, %hi(_selectCursorXy)
    /* 2628 8006AE28 68ED40AC */  sw         $zero, %lo(_selectCursorXy)($v0)
    /* 262C 8006AE2C 0E80023C */  lui        $v0, %hi(_fileProgressCounter)
    /* 2630 8006AE30 14EB40AC */  sw         $zero, %lo(_fileProgressCounter)($v0)
    /* 2634 8006AE34 0E80023C */  lui        $v0, %hi(_fileMenuScreenFade)
    /* 2638 8006AE38 0E80033C */  lui        $v1, %hi(_fileProgressTarget)
    /* 263C 8006AE3C 72ED40A0 */  sb         $zero, %lo(_fileMenuScreenFade)($v0)
    /* 2640 8006AE40 80010224 */  addiu      $v0, $zero, 0x180
    /* 2644 8006AE44 0E80043C */  lui        $a0, %hi(_fileMenuElements)
    /* 2648 8006AE48 18EB8424 */  addiu      $a0, $a0, %lo(_fileMenuElements)
    /* 264C 8006AE4C 21280000 */  addu       $a1, $zero, $zero
    /* 2650 8006AE50 08020624 */  addiu      $a2, $zero, 0x208
    /* 2654 8006AE54 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2658 8006AE58 AD9B000C */  jal        memset
    /* 265C 8006AE5C 0EEB62A4 */   sh        $v0, %lo(_fileProgressTarget)($v1)
    /* 2660 8006AE60 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2664 8006AE64 00000000 */  nop
    /* 2668 8006AE68 0800E003 */  jr         $ra
    /* 266C 8006AE6C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _initFileMenu
