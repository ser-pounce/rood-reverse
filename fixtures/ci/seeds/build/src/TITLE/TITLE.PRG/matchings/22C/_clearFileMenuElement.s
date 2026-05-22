nonmatching _clearFileMenuElement, 0x44

glabel _clearFileMenuElement
    /* 2778 8006AF78 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 277C 8006AF7C 40100400 */  sll        $v0, $a0, 1
    /* 2780 8006AF80 21104400 */  addu       $v0, $v0, $a0
    /* 2784 8006AF84 80100200 */  sll        $v0, $v0, 2
    /* 2788 8006AF88 21104400 */  addu       $v0, $v0, $a0
    /* 278C 8006AF8C 80100200 */  sll        $v0, $v0, 2
    /* 2790 8006AF90 0E80043C */  lui        $a0, %hi(_fileMenuElements)
    /* 2794 8006AF94 18EB8424 */  addiu      $a0, $a0, %lo(_fileMenuElements)
    /* 2798 8006AF98 21204400 */  addu       $a0, $v0, $a0
    /* 279C 8006AF9C 21280000 */  addu       $a1, $zero, $zero
    /* 27A0 8006AFA0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 27A4 8006AFA4 AD9B000C */  jal        memset
    /* 27A8 8006AFA8 34000624 */   addiu     $a2, $zero, 0x34
    /* 27AC 8006AFAC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 27B0 8006AFB0 00000000 */  nop
    /* 27B4 8006AFB4 0800E003 */  jr         $ra
    /* 27B8 8006AFB8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _clearFileMenuElement
