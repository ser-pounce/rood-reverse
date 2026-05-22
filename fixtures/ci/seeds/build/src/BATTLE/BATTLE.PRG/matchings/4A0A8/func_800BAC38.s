nonmatching func_800BAC38, 0x24

glabel func_800BAC38
    /* 52438 800BAC38 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5243C 800BAC3C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 52440 800BAC40 01008490 */  lbu        $a0, 0x1($a0)
    /* 52444 800BAC44 5236020C */  jal        vs_battle_setDoorEntered2
    /* 52448 800BAC48 00000000 */   nop
    /* 5244C 800BAC4C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 52450 800BAC50 21100000 */  addu       $v0, $zero, $zero
    /* 52454 800BAC54 0800E003 */  jr         $ra
    /* 52458 800BAC58 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BAC38
