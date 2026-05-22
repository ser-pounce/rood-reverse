nonmatching DsGetSector2, 0x20

glabel DsGetSector2
    /* 16124 80025924 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16128 80025928 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1612C 8002592C D787000C */  jal        CD_getsector2
    /* 16130 80025930 00000000 */   nop
    /* 16134 80025934 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16138 80025938 0100422C */  sltiu      $v0, $v0, 0x1
    /* 1613C 8002593C 0800E003 */  jr         $ra
    /* 16140 80025940 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel DsGetSector2
