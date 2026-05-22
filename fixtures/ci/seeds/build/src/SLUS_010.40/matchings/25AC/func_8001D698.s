nonmatching func_8001D698, 0x20

glabel func_8001D698
    /* DE98 8001D698 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DE9C 8001D69C 1000BFAF */  sw         $ra, 0x10($sp)
    /* DEA0 8001D6A0 5373000C */  jal        IRQCallbackProc
    /* DEA4 8001D6A4 00000000 */   nop
    /* DEA8 8001D6A8 1000BF8F */  lw         $ra, 0x10($sp)
    /* DEAC 8001D6AC 00000000 */  nop
    /* DEB0 8001D6B0 0800E003 */  jr         $ra
    /* DEB4 8001D6B4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001D698
