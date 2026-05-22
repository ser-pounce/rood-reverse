nonmatching vs_main_setClutState, 0xC

glabel vs_main_setClutState
    /* 397EC 80048FEC 0580023C */  lui        $v0, %hi(_clutState + 0x2)
    /* 397F0 80048FF0 0800E003 */  jr         $ra
    /* 397F4 80048FF4 5A5D44A4 */   sh        $a0, %lo(_clutState + 0x2)($v0)
endlabel vs_main_setClutState
