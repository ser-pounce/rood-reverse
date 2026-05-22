nonmatching func_8007C4D4, 0xC

glabel func_8007C4D4
    /* 13CD4 8007C4D4 0F80023C */  lui        $v0, %hi(D_800F19A0)
    /* 13CD8 8007C4D8 0800E003 */  jr         $ra
    /* 13CDC 8007C4DC A01940AC */   sw        $zero, %lo(D_800F19A0)($v0)
endlabel func_8007C4D4
