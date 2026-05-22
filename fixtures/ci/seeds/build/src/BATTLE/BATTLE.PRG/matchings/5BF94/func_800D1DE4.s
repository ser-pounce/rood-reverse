nonmatching func_800D1DE4, 0x18

glabel func_800D1DE4
    /* 695E4 800D1DE4 0F80033C */  lui        $v1, %hi(D_800F5518)
    /* 695E8 800D1DE8 18556290 */  lbu        $v0, %lo(D_800F5518)($v1)
    /* 695EC 800D1DEC 00000000 */  nop
    /* 695F0 800D1DF0 25104400 */  or         $v0, $v0, $a0
    /* 695F4 800D1DF4 0800E003 */  jr         $ra
    /* 695F8 800D1DF8 185562A0 */   sb        $v0, %lo(D_800F5518)($v1)
endlabel func_800D1DE4
