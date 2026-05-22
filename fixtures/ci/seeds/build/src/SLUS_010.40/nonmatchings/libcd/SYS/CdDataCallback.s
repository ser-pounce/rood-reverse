nonmatching CdDataCallback, 0x24

glabel CdDataCallback
    /* 1117C 8002097C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 11180 80020980 1000BFAF */  sw         $ra, 0x10($sp)
    /* 11184 80020984 21288000 */  addu       $a1, $a0, $zero
    /* 11188 80020988 4D7E000C */  jal        DMACallback
    /* 1118C 8002098C 03000424 */   addiu     $a0, $zero, 0x3
    /* 11190 80020990 1000BF8F */  lw         $ra, 0x10($sp)
    /* 11194 80020994 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 11198 80020998 0800E003 */  jr         $ra
    /* 1119C 8002099C 00000000 */   nop
endlabel CdDataCallback
