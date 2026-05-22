nonmatching func_80011FB4, 0x28

glabel func_80011FB4
    /* 27B4 80011FB4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 27B8 80011FB8 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 27BC 80011FBC C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 27C0 80011FC0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 27C4 80011FC4 0C63000C */  jal        func_80018C30
    /* 27C8 80011FC8 10000424 */   addiu     $a0, $zero, 0x10
    /* 27CC 80011FCC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 27D0 80011FD0 00000000 */  nop
    /* 27D4 80011FD4 0800E003 */  jr         $ra
    /* 27D8 80011FD8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80011FB4
