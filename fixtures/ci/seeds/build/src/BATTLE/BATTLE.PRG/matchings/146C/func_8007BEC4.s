nonmatching func_8007BEC4, 0x20

glabel func_8007BEC4
    /* 136C4 8007BEC4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 136C8 8007BEC8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 136CC 8007BECC DD3B030C */  jal        func_800CEF74
    /* 136D0 8007BED0 00000000 */   nop
    /* 136D4 8007BED4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 136D8 8007BED8 00000000 */  nop
    /* 136DC 8007BEDC 0800E003 */  jr         $ra
    /* 136E0 8007BEE0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007BEC4
