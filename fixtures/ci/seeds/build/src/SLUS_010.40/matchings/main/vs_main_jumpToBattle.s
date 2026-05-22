nonmatching vs_main_jumpToBattle, 0xC4

glabel vs_main_jumpToBattle
    /* 32C20 80042420 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 32C24 80042424 21200000 */  addu       $a0, $zero, $zero
    /* 32C28 80042428 1400BFAF */  sw         $ra, 0x14($sp)
    /* 32C2C 8004242C 94A1000C */  jal        DrawSync
    /* 32C30 80042430 1000B0AF */   sw        $s0, 0x10($sp)
    /* 32C34 80042434 94A1000C */  jal        DrawSync
    /* 32C38 80042438 21200000 */   addu      $a0, $zero, $zero
    /* 32C3C 8004243C 6EA1000C */  jal        SetDispMask
    /* 32C40 80042440 21200000 */   addu      $a0, $zero, $zero
    /* 32C44 80042444 21200000 */  addu       $a0, $zero, $zero
    /* 32C48 80042448 21288000 */  addu       $a1, $a0, $zero
    /* 32C4C 8004244C C80C010C */  jal        padSetActData
    /* 32C50 80042450 21308000 */   addu      $a2, $a0, $zero
    /* 32C54 80042454 21200000 */  addu       $a0, $zero, $zero
    /* 32C58 80042458 01000524 */  addiu      $a1, $zero, 0x1
    /* 32C5C 8004245C C80C010C */  jal        padSetActData
    /* 32C60 80042460 21308000 */   addu      $a2, $a0, $zero
    /* 32C64 80042464 21200000 */  addu       $a0, $zero, $zero
    /* 32C68 80042468 0680103C */  lui        $s0, %hi(vs_main_padBuffer)
    /* 32C6C 8004246C F0DF1026 */  addiu      $s0, $s0, %lo(vs_main_padBuffer)
    /* 32C70 80042470 940C010C */  jal        vs_main_padConnect
    /* 32C74 80042474 21280002 */   addu      $a1, $s0, $zero
    /* 32C78 80042478 10000424 */  addiu      $a0, $zero, 0x10
    /* 32C7C 8004247C 940C010C */  jal        vs_main_padConnect
    /* 32C80 80042480 22000526 */   addiu     $a1, $s0, 0x22
    /* 32C84 80042484 B5A0000C */  jal        ResetGraph
    /* 32C88 80042488 03000424 */   addiu     $a0, $zero, 0x3
    /* 32C8C 8004248C DE4A000C */  jal        func_80012B78
    /* 32C90 80042490 00000000 */   nop
    /* 32C94 80042494 E64A000C */  jal        func_80012B98
    /* 32C98 80042498 00000000 */   nop
    /* 32C9C 8004249C 0948000C */  jal        func_80012024
    /* 32CA0 800424A0 00000000 */   nop
    /* 32CA4 800424A4 AF4B000C */  jal        func_80012EBC
    /* 32CA8 800424A8 00000000 */   nop
    /* 32CAC 800424AC 2F08010C */  jal        _displayLoadingScreen
    /* 32CB0 800424B0 00000000 */   nop
    /* 32CB4 800424B4 9307010C */  jal        func_80041E4C
    /* 32CB8 800424B8 00000000 */   nop
    /* 32CBC 800424BC 0580033C */  lui        $v1, %hi(vs_main_startState)
    /* 32CC0 800424C0 01000224 */  addiu      $v0, $zero, 0x1
    /* 32CC4 800424C4 0680043C */  lui        $a0, %hi(sp)
    /* 32CC8 800424C8 D0DF8424 */  addiu      $a0, $a0, %lo(sp)
    /* 32CCC 800424CC B142000C */  jal        vs_overlay_jumpToBattle
    /* 32CD0 800424D0 700462AC */   sw        $v0, %lo(vs_main_startState)($v1)
    /* 32CD4 800424D4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 32CD8 800424D8 1000B08F */  lw         $s0, 0x10($sp)
    /* 32CDC 800424DC 0800E003 */  jr         $ra
    /* 32CE0 800424E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_main_jumpToBattle
