nonmatching func_800F9AB8, 0x20

glabel func_800F9AB8
    /* 2B8 800F9AB8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2BC 800F9ABC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2C0 800F9AC0 6C65020C */  jal        vs_battle_getEmptyObjectDataSlot
    /* 2C4 800F9AC4 00000000 */   nop
    /* 2C8 800F9AC8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2CC 800F9ACC 00000000 */  nop
    /* 2D0 800F9AD0 0800E003 */  jr         $ra
    /* 2D4 800F9AD4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800F9AB8
