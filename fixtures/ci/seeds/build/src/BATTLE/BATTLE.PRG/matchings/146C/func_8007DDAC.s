nonmatching func_8007DDAC, 0xC

glabel func_8007DDAC
    /* 155AC 8007DDAC 0F80023C */  lui        $v0, %hi(D_800F1A2C)
    /* 155B0 8007DDB0 0800E003 */  jr         $ra
    /* 155B4 8007DDB4 2C1A44A4 */   sh        $a0, %lo(D_800F1A2C)($v0)
endlabel func_8007DDAC
