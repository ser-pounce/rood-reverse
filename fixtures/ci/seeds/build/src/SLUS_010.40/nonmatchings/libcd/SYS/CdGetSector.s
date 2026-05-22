nonmatching CdGetSector, 0x20

glabel CdGetSector
    /* 1113C 8002093C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 11140 80020940 1000BFAF */  sw         $ra, 0x10($sp)
    /* 11144 80020944 9787000C */  jal        CD_getsector
    /* 11148 80020948 00000000 */   nop
    /* 1114C 8002094C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 11150 80020950 0100422C */  sltiu      $v0, $v0, 0x1
    /* 11154 80020954 0800E003 */  jr         $ra
    /* 11158 80020958 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel CdGetSector
