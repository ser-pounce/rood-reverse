nonmatching func_8009CFA0, 0x10

glabel func_8009CFA0
    /* 347A0 8009CFA0 0F80023C */  lui        $v0, %hi(D_800E8F2C)
    /* 347A4 8009CFA4 2C8F4290 */  lbu        $v0, %lo(D_800E8F2C)($v0)
    /* 347A8 8009CFA8 0800E003 */  jr         $ra
    /* 347AC 8009CFAC 01004224 */   addiu     $v0, $v0, 0x1
endlabel func_8009CFA0
