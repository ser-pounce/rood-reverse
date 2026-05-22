nonmatching PAD_init, 0x90

glabel PAD_init
    /* 1F250 8002EA50 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1F254 8002EA54 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1F258 8002EA58 21808000 */  addu       $s0, $a0, $zero
    /* 1F25C 8002EA5C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1F260 8002EA60 2188A000 */  addu       $s1, $a1, $zero
    /* 1F264 8002EA64 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1F268 8002EA68 2190C000 */  addu       $s2, $a2, $zero
    /* 1F26C 8002EA6C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1F270 8002EA70 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1F274 8002EA74 85BB000C */  jal        _remove_ChgclrPAD
    /* 1F278 8002EA78 2198E000 */   addu      $s3, $a3, $zero
    /* 1F27C 8002EA7C 5D9A000C */  jal        EnterCriticalSection
    /* 1F280 8002EA80 00000000 */   nop
    /* 1F284 8002EA84 67BB000C */  jal        _patch_pad
    /* 1F288 8002EA88 00000000 */   nop
    /* 1F28C 8002EA8C 619A000C */  jal        ExitCriticalSection
    /* 1F290 8002EA90 00000000 */   nop
    /* 1F294 8002EA94 819A000C */  jal        ChangeClearPAD
    /* 1F298 8002EA98 21200000 */   addu      $a0, $zero, $zero
    /* 1F29C 8002EA9C F6BA000C */  jal        func_8002EBD8
    /* 1F2A0 8002EAA0 00000000 */   nop
    /* 1F2A4 8002EAA4 21200002 */  addu       $a0, $s0, $zero
    /* 1F2A8 8002EAA8 21282002 */  addu       $a1, $s1, $zero
    /* 1F2AC 8002EAAC 21304002 */  addu       $a2, $s2, $zero
    /* 1F2B0 8002EAB0 59BB000C */  jal        PAD_init2
    /* 1F2B4 8002EAB4 21386002 */   addu      $a3, $s3, $zero
    /* 1F2B8 8002EAB8 01000224 */  addiu      $v0, $zero, 0x1
    /* 1F2BC 8002EABC 0380013C */  lui        $at, %hi(D_80033664)
    /* 1F2C0 8002EAC0 643622AC */  sw         $v0, %lo(D_80033664)($at)
    /* 1F2C4 8002EAC4 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1F2C8 8002EAC8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1F2CC 8002EACC 1800B28F */  lw         $s2, 0x18($sp)
    /* 1F2D0 8002EAD0 1400B18F */  lw         $s1, 0x14($sp)
    /* 1F2D4 8002EAD4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1F2D8 8002EAD8 0800E003 */  jr         $ra
    /* 1F2DC 8002EADC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel PAD_init
