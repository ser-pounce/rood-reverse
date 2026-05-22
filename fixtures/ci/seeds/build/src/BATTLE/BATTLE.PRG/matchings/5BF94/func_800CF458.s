nonmatching func_800CF458, 0x20

glabel func_800CF458
    /* 66C58 800CF458 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 66C5C 800CF45C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 66C60 800CF460 863C030C */  jal        func_800CF218
    /* 66C64 800CF464 00000000 */   nop
    /* 66C68 800CF468 1000BF8F */  lw         $ra, 0x10($sp)
    /* 66C6C 800CF46C FF004230 */  andi       $v0, $v0, 0xFF
    /* 66C70 800CF470 0800E003 */  jr         $ra
    /* 66C74 800CF474 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CF458
