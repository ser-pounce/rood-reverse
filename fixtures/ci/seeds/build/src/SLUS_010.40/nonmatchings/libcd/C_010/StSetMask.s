nonmatching StSetMask, 0x1C

glabel StSetMask
    /* 12D44 80022544 0480013C */  lui        $at, %hi(D_80039C40)
    /* 12D48 80022548 409C24AC */  sw         $a0, %lo(D_80039C40)($at)
    /* 12D4C 8002254C 0480013C */  lui        $at, %hi(D_80039C1C)
    /* 12D50 80022550 1C9C25AC */  sw         $a1, %lo(D_80039C1C)($at)
    /* 12D54 80022554 0480013C */  lui        $at, %hi(D_80039C3C)
    /* 12D58 80022558 0800E003 */  jr         $ra
    /* 12D5C 8002255C 3C9C26AC */   sw        $a2, %lo(D_80039C3C)($at)
endlabel StSetMask
    /* 12D60 80022560 00000000 */  nop
