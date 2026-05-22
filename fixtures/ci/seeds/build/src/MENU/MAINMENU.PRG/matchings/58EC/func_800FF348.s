nonmatching func_800FF348, 0x18

glabel func_800FF348
    /* 5B48 800FF348 1080043C */  lui        $a0, %hi(D_801022CC)
    /* 5B4C 800FF34C 1080023C */  lui        $v0, %hi(D_801022D2)
    /* 5B50 800FF350 D2224390 */  lbu        $v1, %lo(D_801022D2)($v0)
    /* 5B54 800FF354 CC22828C */  lw         $v0, %lo(D_801022CC)($a0)
    /* 5B58 800FF358 0800E003 */  jr         $ra
    /* 5B5C 800FF35C 21104300 */   addu      $v0, $v0, $v1
endlabel func_800FF348
