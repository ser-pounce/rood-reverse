nonmatching StopPAD, 0x38

glabel StopPAD
    /* 1F3A0 8002EBA0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1F3A4 8002EBA4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1F3A8 8002EBA8 62BB000C */  jal        DisablePAD
    /* 1F3AC 8002EBAC 00000000 */   nop
    /* 1F3B0 8002EBB0 55BB000C */  jal        StopPAD2
    /* 1F3B4 8002EBB4 00000000 */   nop
    /* 1F3B8 8002EBB8 14BB000C */  jal        func_8002EC50
    /* 1F3BC 8002EBBC 00000000 */   nop
    /* 1F3C0 8002EBC0 0380013C */  lui        $at, %hi(D_80033664)
    /* 1F3C4 8002EBC4 643620AC */  sw         $zero, %lo(D_80033664)($at)
    /* 1F3C8 8002EBC8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1F3CC 8002EBCC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1F3D0 8002EBD0 0800E003 */  jr         $ra
    /* 1F3D4 8002EBD4 00000000 */   nop
endlabel StopPAD
