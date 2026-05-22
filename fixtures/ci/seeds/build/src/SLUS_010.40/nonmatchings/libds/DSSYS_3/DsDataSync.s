nonmatching DsDataSync, 0x20

glabel DsDataSync
    /* 16144 80025944 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16148 80025948 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1614C 8002594C 3D87000C */  jal        CD_datasync
    /* 16150 80025950 00000000 */   nop
    /* 16154 80025954 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16158 80025958 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1615C 8002595C 0800E003 */  jr         $ra
    /* 16160 80025960 00000000 */   nop
endlabel DsDataSync
