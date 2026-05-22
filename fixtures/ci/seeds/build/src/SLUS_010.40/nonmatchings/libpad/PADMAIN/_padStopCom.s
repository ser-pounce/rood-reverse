nonmatching _padStopCom, 0x44

glabel _padStopCom
    /* 1C8C0 8002C0C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C8C4 8002C0C4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1C8C8 8002C0C8 5D9A000C */  jal        EnterCriticalSection
    /* 1C8CC 8002C0CC 00000000 */   nop
    /* 1C8D0 8002C0D0 03000424 */  addiu      $a0, $zero, 0x3
    /* 1C8D4 8002C0D4 859A000C */  jal        ChangeClearRCnt
    /* 1C8D8 8002C0D8 01000524 */   addiu     $a1, $zero, 0x1
    /* 1C8DC 8002C0DC 0480053C */  lui        $a1, %hi(D_8003FC00)
    /* 1C8E0 8002C0E0 00FCA524 */  addiu      $a1, $a1, %lo(D_8003FC00)
    /* 1C8E4 8002C0E4 A1B2000C */  jal        SysDeqIntRP
    /* 1C8E8 8002C0E8 02000424 */   addiu     $a0, $zero, 0x2
    /* 1C8EC 8002C0EC 619A000C */  jal        ExitCriticalSection
    /* 1C8F0 8002C0F0 00000000 */   nop
    /* 1C8F4 8002C0F4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1C8F8 8002C0F8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1C8FC 8002C0FC 0800E003 */  jr         $ra
    /* 1C900 8002C100 00000000 */   nop
endlabel _padStopCom
