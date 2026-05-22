nonmatching func_80102FAC, 0x20

glabel func_80102FAC
    /* 7AC 80102FAC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7B0 80102FB0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7B4 80102FB4 74EA030C */  jal        vs_mainmenu_ready
    /* 7B8 80102FB8 00000000 */   nop
    /* 7BC 80102FBC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7C0 80102FC0 00000000 */  nop
    /* 7C4 80102FC4 0800E003 */  jr         $ra
    /* 7C8 80102FC8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102FAC
