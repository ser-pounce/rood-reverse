nonmatching vs_main_enableReset, 0xC

glabel vs_main_enableReset
    /* 33494 80042C94 0580023C */  lui        $v0, %hi(_resetEnabled)
    /* 33498 80042C98 0800E003 */  jr         $ra
    /* 3349C 80042C9C 885C44AC */   sw        $a0, %lo(_resetEnabled)($v0)
endlabel vs_main_enableReset
