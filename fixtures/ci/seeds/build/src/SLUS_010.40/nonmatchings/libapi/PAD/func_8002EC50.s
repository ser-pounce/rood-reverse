nonmatching func_8002EC50, 0x38

glabel func_8002EC50
    /* 1F450 8002EC50 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1F454 8002EC54 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1F458 8002EC58 5D9A000C */  jal        EnterCriticalSection
    /* 1F45C 8002EC5C 00000000 */   nop
    /* 1F460 8002EC60 0480053C */  lui        $a1, %hi(D_8003FEA8)
    /* 1F464 8002EC64 A8FEA524 */  addiu      $a1, $a1, %lo(D_8003FEA8)
    /* 1F468 8002EC68 A1B2000C */  jal        SysDeqIntRP
    /* 1F46C 8002EC6C 01000424 */   addiu     $a0, $zero, 0x1
    /* 1F470 8002EC70 619A000C */  jal        ExitCriticalSection
    /* 1F474 8002EC74 00000000 */   nop
    /* 1F478 8002EC78 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1F47C 8002EC7C 01000224 */  addiu      $v0, $zero, 0x1
    /* 1F480 8002EC80 0800E003 */  jr         $ra
    /* 1F484 8002EC84 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002EC50
