nonmatching func_800FFBA8, 0x20

glabel func_800FFBA8
    /* 63A8 800FFBA8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 63AC 800FFBAC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 63B0 800FFBB0 1934030C */  jal        vs_battle_dismissTextBox
    /* 63B4 800FFBB4 07000424 */   addiu     $a0, $zero, 0x7
    /* 63B8 800FFBB8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 63BC 800FFBBC 00000000 */  nop
    /* 63C0 800FFBC0 0800E003 */  jr         $ra
    /* 63C4 800FFBC4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800FFBA8
