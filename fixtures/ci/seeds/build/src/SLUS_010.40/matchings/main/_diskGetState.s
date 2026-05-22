nonmatching _diskGetState, 0x10

glabel _diskGetState
    /* 34B10 80044310 0580023C */  lui        $v0, %hi(vs_main_disk)
    /* 34B14 80044314 105D4290 */  lbu        $v0, %lo(vs_main_disk)($v0)
    /* 34B18 80044318 0800E003 */  jr         $ra
    /* 34B1C 8004431C 00000000 */   nop
endlabel _diskGetState
