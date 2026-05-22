nonmatching func_80042998, 0xCC

glabel func_80042998
    /* 33198 80042998 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3319C 8004299C 21200000 */  addu       $a0, $zero, $zero
    /* 331A0 800429A0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 331A4 800429A4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 331A8 800429A8 D580000C */  jal        SetVideoMode
    /* 331AC 800429AC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 331B0 800429B0 6EA1000C */  jal        SetDispMask
    /* 331B4 800429B4 21200000 */   addu      $a0, $zero, $zero
    /* 331B8 800429B8 357E000C */  jal        ResetCallback
    /* 331BC 800429BC 0680103C */   lui       $s0, %hi(vs_main_padBuffer)
    /* 331C0 800429C0 B5A0000C */  jal        ResetGraph
    /* 331C4 800429C4 21200000 */   addu      $a0, $zero, $zero
    /* 331C8 800429C8 12A1000C */  jal        SetGraphDebug
    /* 331CC 800429CC 21200000 */   addu      $a0, $zero, $zero
    /* 331D0 800429D0 4DBA000C */  jal        InitCARD
    /* 331D4 800429D4 21200000 */   addu      $a0, $zero, $zero
    /* 331D8 800429D8 71BA000C */  jal        StartCARD
    /* 331DC 800429DC F0DF1026 */   addiu     $s0, $s0, %lo(vs_main_padBuffer)
    /* 331E0 800429E0 219A000C */  jal        _bu_init
    /* 331E4 800429E4 22001126 */   addiu     $s1, $s0, 0x22
    /* 331E8 800429E8 21200002 */  addu       $a0, $s0, $zero
    /* 331EC 800429EC 31B7000C */  jal        PadInitDirect
    /* 331F0 800429F0 21282002 */   addu      $a1, $s1, $zero
    /* 331F4 800429F4 21200000 */  addu       $a0, $zero, $zero
    /* 331F8 800429F8 0D0C010C */  jal        _padResetDefaults
    /* 331FC 800429FC 21280002 */   addu      $a1, $s0, $zero
    /* 33200 80042A00 10000424 */  addiu      $a0, $zero, 0x10
    /* 33204 80042A04 0D0C010C */  jal        _padResetDefaults
    /* 33208 80042A08 21282002 */   addu      $a1, $s1, $zero
    /* 3320C 80042A0C 01AE000C */  jal        PadStartCom
    /* 33210 80042A10 00000000 */   nop
    /* 33214 80042A14 FC0B010C */  jal        _unlockPadModeSwitch
    /* 33218 80042A18 00000000 */   nop
    /* 3321C 80042A1C 9A0D010C */  jal        vs_main_resetPadAct
    /* 33220 80042A20 00000000 */   nop
    /* 33224 80042A24 7179000C */  jal        SsUtReverbOff
    /* 33228 80042A28 00000000 */   nop
    /* 3322C 80042A2C 318E000C */  jal        DsInit
    /* 33230 80042A30 00000000 */   nop
    /* 33234 80042A34 D309010C */  jal        _initRand
    /* 33238 80042A38 00000000 */   nop
    /* 3323C 80042A3C 0580033C */  lui        $v1, %hi(_resetEnabled)
    /* 33240 80042A40 1800BF8F */  lw         $ra, 0x18($sp)
    /* 33244 80042A44 1400B18F */  lw         $s1, 0x14($sp)
    /* 33248 80042A48 1000B08F */  lw         $s0, 0x10($sp)
    /* 3324C 80042A4C 01000224 */  addiu      $v0, $zero, 0x1
    /* 33250 80042A50 885C62AC */  sw         $v0, %lo(_resetEnabled)($v1)
    /* 33254 80042A54 0680023C */  lui        $v0, %hi(vs_main_saveGameClearData)
    /* 33258 80042A58 14E240AC */  sw         $zero, %lo(vs_main_saveGameClearData)($v0)
    /* 3325C 80042A5C 0800E003 */  jr         $ra
    /* 33260 80042A60 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80042998
