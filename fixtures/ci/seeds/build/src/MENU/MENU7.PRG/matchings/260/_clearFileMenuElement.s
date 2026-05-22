nonmatching _clearFileMenuElement, 0x44

glabel _clearFileMenuElement
    /* 26C0 80104EC0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 26C4 80104EC4 40100400 */  sll        $v0, $a0, 1
    /* 26C8 80104EC8 21104400 */  addu       $v0, $v0, $a0
    /* 26CC 80104ECC 80100200 */  sll        $v0, $v0, 2
    /* 26D0 80104ED0 21104400 */  addu       $v0, $v0, $a0
    /* 26D4 80104ED4 80100200 */  sll        $v0, $v0, 2
    /* 26D8 80104ED8 1180043C */  lui        $a0, %hi(_fileMenuElements)
    /* 26DC 80104EDC 50AE8424 */  addiu      $a0, $a0, %lo(_fileMenuElements)
    /* 26E0 80104EE0 21204400 */  addu       $a0, $v0, $a0
    /* 26E4 80104EE4 21280000 */  addu       $a1, $zero, $zero
    /* 26E8 80104EE8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 26EC 80104EEC AD9B000C */  jal        memset
    /* 26F0 80104EF0 34000624 */   addiu     $a2, $zero, 0x34
    /* 26F4 80104EF4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 26F8 80104EF8 00000000 */  nop
    /* 26FC 80104EFC 0800E003 */  jr         $ra
    /* 2700 80104F00 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _clearFileMenuElement
