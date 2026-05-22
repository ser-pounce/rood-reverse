nonmatching func_800CB550, 0x10

glabel func_800CB550
    /* 62D50 800CB550 0F80033C */  lui        $v1, %hi(D_800F4E90)
    /* 62D54 800CB554 01000224 */  addiu      $v0, $zero, 0x1
    /* 62D58 800CB558 0800E003 */  jr         $ra
    /* 62D5C 800CB55C 904E62A0 */   sb        $v0, %lo(D_800F4E90)($v1)
endlabel func_800CB550
