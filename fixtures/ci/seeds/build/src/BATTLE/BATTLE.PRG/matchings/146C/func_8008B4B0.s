nonmatching func_8008B4B0, 0xC

glabel func_8008B4B0
    /* 22CB0 8008B4B0 0F80023C */  lui        $v0, %hi(D_800F1BB6)
    /* 22CB4 8008B4B4 0800E003 */  jr         $ra
    /* 22CB8 8008B4B8 B61B40A4 */   sh        $zero, %lo(D_800F1BB6)($v0)
endlabel func_8008B4B0
