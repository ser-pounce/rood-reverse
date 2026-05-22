nonmatching func_8007C404, 0x20

glabel func_8007C404
    /* 13C04 8007C404 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 13C08 8007C408 1000BFAF */  sw         $ra, 0x10($sp)
    /* 13C0C 8007C40C 3927020C */  jal        func_80089CE4
    /* 13C10 8007C410 00000000 */   nop
    /* 13C14 8007C414 1000BF8F */  lw         $ra, 0x10($sp)
    /* 13C18 8007C418 00000000 */  nop
    /* 13C1C 8007C41C 0800E003 */  jr         $ra
    /* 13C20 8007C420 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007C404
