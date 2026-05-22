nonmatching func_800464DC, 0x20

glabel func_800464DC
    /* 36CDC 800464DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 36CE0 800464E0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 36CE4 800464E4 CA4C000C */  jal        func_80013328
    /* 36CE8 800464E8 00000000 */   nop
    /* 36CEC 800464EC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 36CF0 800464F0 00000000 */  nop
    /* 36CF4 800464F4 0800E003 */  jr         $ra
    /* 36CF8 800464F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800464DC
