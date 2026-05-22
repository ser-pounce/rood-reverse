nonmatching func_801008B0, 0x18

glabel func_801008B0
    /* 70B0 801008B0 1080043C */  lui        $a0, %hi(_selectedRow)
    /* 70B4 801008B4 1080023C */  lui        $v0, %hi(D_801023DE)
    /* 70B8 801008B8 DE234390 */  lbu        $v1, %lo(D_801023DE)($v0)
    /* 70BC 801008BC D823828C */  lw         $v0, %lo(_selectedRow)($a0)
    /* 70C0 801008C0 0800E003 */  jr         $ra
    /* 70C4 801008C4 21104300 */   addu      $v0, $v0, $v1
endlabel func_801008B0
