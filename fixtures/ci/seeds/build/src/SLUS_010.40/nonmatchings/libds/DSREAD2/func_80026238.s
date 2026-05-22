nonmatching func_80026238, 0x20

glabel func_80026238
    /* 16A38 80026238 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16A3C 8002623C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 16A40 80026240 5989000C */  jal        StCdInterrupt
    /* 16A44 80026244 00000000 */   nop
    /* 16A48 80026248 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16A4C 8002624C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 16A50 80026250 0800E003 */  jr         $ra
    /* 16A54 80026254 00000000 */   nop
endlabel func_80026238
    /* 16A58 80026258 00000000 */  nop
    /* 16A5C 8002625C 00000000 */  nop
    /* 16A60 80026260 00000000 */  nop
