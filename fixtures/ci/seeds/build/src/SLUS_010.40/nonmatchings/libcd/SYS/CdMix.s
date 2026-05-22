nonmatching CdMix, 0x20

glabel CdMix
    /* 1111C 8002091C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 11120 80020920 1000BFAF */  sw         $ra, 0x10($sp)
    /* 11124 80020924 1F86000C */  jal        CD_vol
    /* 11128 80020928 00000000 */   nop
    /* 1112C 8002092C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 11130 80020930 01000224 */  addiu      $v0, $zero, 0x1
    /* 11134 80020934 0800E003 */  jr         $ra
    /* 11138 80020938 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel CdMix
