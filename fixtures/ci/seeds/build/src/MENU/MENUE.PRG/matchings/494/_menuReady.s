nonmatching _menuReady, 0x20

glabel _menuReady
    /* 6BC 80102EBC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C0 80102EC0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6C4 80102EC4 74EA030C */  jal        vs_mainmenu_ready
    /* 6C8 80102EC8 00000000 */   nop
    /* 6CC 80102ECC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6D0 80102ED0 00000000 */  nop
    /* 6D4 80102ED4 0800E003 */  jr         $ra
    /* 6D8 80102ED8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _menuReady
