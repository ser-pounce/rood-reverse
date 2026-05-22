nonmatching DsMix, 0x20

glabel DsMix
    /* 160E4 800258E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 160E8 800258E8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 160EC 800258EC 1F86000C */  jal        CD_vol
    /* 160F0 800258F0 00000000 */   nop
    /* 160F4 800258F4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 160F8 800258F8 01000224 */  addiu      $v0, $zero, 0x1
    /* 160FC 800258FC 0800E003 */  jr         $ra
    /* 16100 80025900 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel DsMix
