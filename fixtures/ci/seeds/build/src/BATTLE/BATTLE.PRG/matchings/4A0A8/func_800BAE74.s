nonmatching func_800BAE74, 0x2C

glabel func_800BAE74
    /* 52674 800BAE74 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52678 800BAE78 1000BFAF */  sw         $ra, 0x10($sp)
    /* 5267C 800BAE7C 80FF020C */  jal        vs_battle_getShort
    /* 52680 800BAE80 01008424 */   addiu     $a0, $a0, 0x1
    /* 52684 800BAE84 00140200 */  sll        $v0, $v0, 16
    /* 52688 800BAE88 E732030C */  jal        vs_battle_decreaseMiscCount
    /* 5268C 800BAE8C 03240200 */   sra       $a0, $v0, 16
    /* 52690 800BAE90 1000BF8F */  lw         $ra, 0x10($sp)
    /* 52694 800BAE94 21100000 */  addu       $v0, $zero, $zero
    /* 52698 800BAE98 0800E003 */  jr         $ra
    /* 5269C 800BAE9C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BAE74
