nonmatching DsGetSector, 0x20

glabel DsGetSector
    /* 16104 80025904 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16108 80025908 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1610C 8002590C 9787000C */  jal        CD_getsector
    /* 16110 80025910 00000000 */   nop
    /* 16114 80025914 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16118 80025918 0100422C */  sltiu      $v0, $v0, 0x1
    /* 1611C 8002591C 0800E003 */  jr         $ra
    /* 16120 80025920 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel DsGetSector
