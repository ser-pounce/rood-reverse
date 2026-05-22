nonmatching func_800BFE34, 0x1C

glabel func_800BFE34
    /* 57634 800BFE34 0F80023C */  lui        $v0, %hi(D_800E9C30)
    /* 57638 800BFE38 00008390 */  lbu        $v1, 0x0($a0)
    /* 5763C 800BFE3C 309C4224 */  addiu      $v0, $v0, %lo(D_800E9C30)
    /* 57640 800BFE40 21186200 */  addu       $v1, $v1, $v0
    /* 57644 800BFE44 00006290 */  lbu        $v0, 0x0($v1)
    /* 57648 800BFE48 0800E003 */  jr         $ra
    /* 5764C 800BFE4C 00000000 */   nop
endlabel func_800BFE34
