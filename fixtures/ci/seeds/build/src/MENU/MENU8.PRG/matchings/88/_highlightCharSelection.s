nonmatching _highlightCharSelection, 0x6C

glabel _highlightCharSelection
    /* 1EF0 801046F0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1EF4 801046F4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1EF8 801046F8 21808000 */  addu       $s0, $a0, $zero
    /* 1EFC 801046FC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1F00 80104700 40880500 */  sll        $s1, $a1, 1
    /* 1F04 80104704 21882502 */  addu       $s1, $s1, $a1
    /* 1F08 80104708 80881100 */  sll        $s1, $s1, 2
    /* 1F0C 8010470C 80002426 */  addiu      $a0, $s1, 0x80
    /* 1F10 80104710 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1F14 80104714 00910600 */  sll        $s2, $a2, 4
    /* 1F18 80104718 4C004526 */  addiu      $a1, $s2, 0x4C
    /* 1F1C 8010471C 0A000624 */  addiu      $a2, $zero, 0xA
    /* 1F20 80104720 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1F24 80104724 9411040C */  jal        _highlightSelection
    /* 1F28 80104728 12000724 */   addiu     $a3, $zero, 0x12
    /* 1F2C 8010472C 21200002 */  addu       $a0, $s0, $zero
    /* 1F30 80104730 70003126 */  addiu      $s1, $s1, 0x70
    /* 1F34 80104734 42005226 */  addiu      $s2, $s2, 0x42
    /* 1F38 80104738 00941200 */  sll        $s2, $s2, 16
    /* 1F3C 8010473C 37FF030C */  jal        func_800FFCDC
    /* 1F40 80104740 25283202 */   or        $a1, $s1, $s2
    /* 1F44 80104744 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1F48 80104748 1800B28F */  lw         $s2, 0x18($sp)
    /* 1F4C 8010474C 1400B18F */  lw         $s1, 0x14($sp)
    /* 1F50 80104750 1000B08F */  lw         $s0, 0x10($sp)
    /* 1F54 80104754 0800E003 */  jr         $ra
    /* 1F58 80104758 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _highlightCharSelection
