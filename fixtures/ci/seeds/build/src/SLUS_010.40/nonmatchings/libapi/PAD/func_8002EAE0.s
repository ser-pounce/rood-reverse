nonmatching func_8002EAE0, 0x90

glabel func_8002EAE0
    /* 1F2E0 8002EAE0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1F2E4 8002EAE4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1F2E8 8002EAE8 21808000 */  addu       $s0, $a0, $zero
    /* 1F2EC 8002EAEC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1F2F0 8002EAF0 2188A000 */  addu       $s1, $a1, $zero
    /* 1F2F4 8002EAF4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1F2F8 8002EAF8 2190C000 */  addu       $s2, $a2, $zero
    /* 1F2FC 8002EAFC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1F300 8002EB00 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1F304 8002EB04 85BB000C */  jal        _remove_ChgclrPAD
    /* 1F308 8002EB08 2198E000 */   addu      $s3, $a3, $zero
    /* 1F30C 8002EB0C 5D9A000C */  jal        EnterCriticalSection
    /* 1F310 8002EB10 00000000 */   nop
    /* 1F314 8002EB14 67BB000C */  jal        _patch_pad
    /* 1F318 8002EB18 00000000 */   nop
    /* 1F31C 8002EB1C 619A000C */  jal        ExitCriticalSection
    /* 1F320 8002EB20 00000000 */   nop
    /* 1F324 8002EB24 819A000C */  jal        ChangeClearPAD
    /* 1F328 8002EB28 21200000 */   addu      $a0, $zero, $zero
    /* 1F32C 8002EB2C F6BA000C */  jal        func_8002EBD8
    /* 1F330 8002EB30 00000000 */   nop
    /* 1F334 8002EB34 21200002 */  addu       $a0, $s0, $zero
    /* 1F338 8002EB38 21282002 */  addu       $a1, $s1, $zero
    /* 1F33C 8002EB3C 21304002 */  addu       $a2, $s2, $zero
    /* 1F340 8002EB40 4DBB000C */  jal        InitPAD2
    /* 1F344 8002EB44 21386002 */   addu      $a3, $s3, $zero
    /* 1F348 8002EB48 01000224 */  addiu      $v0, $zero, 0x1
    /* 1F34C 8002EB4C 0380013C */  lui        $at, %hi(D_80033664)
    /* 1F350 8002EB50 643622AC */  sw         $v0, %lo(D_80033664)($at)
    /* 1F354 8002EB54 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1F358 8002EB58 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1F35C 8002EB5C 1800B28F */  lw         $s2, 0x18($sp)
    /* 1F360 8002EB60 1400B18F */  lw         $s1, 0x14($sp)
    /* 1F364 8002EB64 1000B08F */  lw         $s0, 0x10($sp)
    /* 1F368 8002EB68 0800E003 */  jr         $ra
    /* 1F36C 8002EB6C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8002EAE0
