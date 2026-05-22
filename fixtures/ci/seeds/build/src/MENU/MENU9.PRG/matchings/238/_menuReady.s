nonmatching _menuReady, 0x20

glabel _menuReady
    /* 7D8 80102FD8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7DC 80102FDC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7E0 80102FE0 74EA030C */  jal        vs_mainmenu_ready
    /* 7E4 80102FE4 00000000 */   nop
    /* 7E8 80102FE8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7EC 80102FEC 00000000 */  nop
    /* 7F0 80102FF0 0800E003 */  jr         $ra
    /* 7F4 80102FF4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _menuReady
