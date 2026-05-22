nonmatching CdGetSector2, 0x20

glabel CdGetSector2
    /* 1115C 8002095C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 11160 80020960 1000BFAF */  sw         $ra, 0x10($sp)
    /* 11164 80020964 D787000C */  jal        CD_getsector2
    /* 11168 80020968 00000000 */   nop
    /* 1116C 8002096C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 11170 80020970 0100422C */  sltiu      $v0, $v0, 0x1
    /* 11174 80020974 0800E003 */  jr         $ra
    /* 11178 80020978 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel CdGetSector2
