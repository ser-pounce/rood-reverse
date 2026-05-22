nonmatching func_800BBE04, 0xC

glabel func_800BBE04
    /* 53604 800BBE04 0F80023C */  lui        $v0, %hi(D_800F4BA0)
    /* 53608 800BBE08 0800E003 */  jr         $ra
    /* 5360C 800BBE0C A04B44A0 */   sb        $a0, %lo(D_800F4BA0)($v0)
endlabel func_800BBE04
