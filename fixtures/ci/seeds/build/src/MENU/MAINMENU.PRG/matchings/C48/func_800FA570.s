nonmatching func_800FA570, 0x28

glabel func_800FA570
    /* D70 800FA570 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* D74 800FA574 1000BFAF */  sw         $ra, 0x10($sp)
    /* D78 800FA578 9F65020C */  jal        vs_battle_processObjectDataQueue
    /* D7C 800FA57C 00000000 */   nop
    /* D80 800FA580 6C65020C */  jal        vs_battle_getEmptyObjectDataSlot
    /* D84 800FA584 00000000 */   nop
    /* D88 800FA588 1000BF8F */  lw         $ra, 0x10($sp)
    /* D8C 800FA58C 00000000 */  nop
    /* D90 800FA590 0800E003 */  jr         $ra
    /* D94 800FA594 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800FA570
