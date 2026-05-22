nonmatching func_800FDD78, 0x10

glabel func_800FDD78
    /* 4578 800FDD78 1080033C */  lui        $v1, %hi(D_801024B8)
    /* 457C 800FDD7C 09000224 */  addiu      $v0, $zero, 0x9
    /* 4580 800FDD80 0800E003 */  jr         $ra
    /* 4584 800FDD84 B82462A0 */   sb        $v0, %lo(D_801024B8)($v1)
endlabel func_800FDD78
