nonmatching func_800D6554, 0x20

glabel func_800D6554
    /* 6DD54 800D6554 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6DD58 800D6558 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6DD5C 800D655C 94B3010C */  jal        func_8006CE50
    /* 6DD60 800D6560 00000000 */   nop
    /* 6DD64 800D6564 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6DD68 800D6568 00000000 */  nop
    /* 6DD6C 800D656C 0800E003 */  jr         $ra
    /* 6DD70 800D6570 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D6554
