nonmatching func_8008B4C8, 0x10

glabel func_8008B4C8
    /* 22CC8 8008B4C8 0F80023C */  lui        $v0, %hi(D_800F1CD6)
    /* 22CCC 8008B4CC D61C44A0 */  sb         $a0, %lo(D_800F1CD6)($v0)
    /* 22CD0 8008B4D0 0800E003 */  jr         $ra
    /* 22CD4 8008B4D4 FF008230 */   andi      $v0, $a0, 0xFF
endlabel func_8008B4C8
