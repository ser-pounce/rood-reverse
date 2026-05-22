nonmatching func_8007DE88, 0x20

glabel func_8007DE88
    /* 15688 8007DE88 0F80033C */  lui        $v1, %hi(D_800F1A30)
    /* 1568C 8007DE8C 301A628C */  lw         $v0, %lo(D_800F1A30)($v1)
    /* 15690 8007DE90 00000000 */  nop
    /* 15694 8007DE94 000082AC */  sw         $v0, 0x0($a0)
    /* 15698 8007DE98 301A628C */  lw         $v0, %lo(D_800F1A30)($v1)
    /* 1569C 8007DE9C 080080AC */  sw         $zero, 0x8($a0)
    /* 156A0 8007DEA0 0800E003 */  jr         $ra
    /* 156A4 8007DEA4 040082AC */   sw        $v0, 0x4($a0)
endlabel func_8007DE88
