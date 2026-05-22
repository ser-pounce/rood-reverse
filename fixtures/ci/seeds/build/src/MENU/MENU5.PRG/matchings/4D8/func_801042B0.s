nonmatching func_801042B0, 0xD4

glabel func_801042B0
    /* 1AB0 801042B0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1AB4 801042B4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1AB8 801042B8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1ABC 801042BC 211B040C */  jal        func_80106C84
    /* 1AC0 801042C0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1AC4 801042C4 801F113C */  lui        $s1, (0x1F800000 >> 16)
    /* 1AC8 801042C8 0000308E */  lw         $s0, (0x1F800000 & 0xFFFF)($s1)
    /* 1ACC 801042CC 01000524 */  addiu      $a1, $zero, 0x1
    /* 1AD0 801042D0 C5AD000C */  jal        SetDrawStp
    /* 1AD4 801042D4 21200002 */   addu      $a0, $s0, $zero
    /* 1AD8 801042D8 21280002 */  addu       $a1, $s0, $zero
    /* 1ADC 801042DC 0400248E */  lw         $a0, (0x1F800004 & 0xFFFF)($s1)
    /* 1AE0 801042E0 0C001026 */  addiu      $s0, $s0, 0xC
    /* 1AE4 801042E4 35AD000C */  jal        AddPrim
    /* 1AE8 801042E8 FC1F8424 */   addiu     $a0, $a0, 0x1FFC
    /* 1AEC 801042EC 0680033C */  lui        $v1, %hi(vs_main_stateFlags)
    /* 1AF0 801042F0 1180023C */  lui        $v0, %hi(_currentScene)
    /* 1AF4 801042F4 808D428C */  lw         $v0, %lo(_currentScene)($v0)
    /* 1AF8 801042F8 98156324 */  addiu      $v1, $v1, %lo(vs_main_stateFlags)
    /* 1AFC 801042FC 000030AE */  sw         $s0, (0x1F800000 & 0xFFFF)($s1)
    /* 1B00 80104300 21104300 */  addu       $v0, $v0, $v1
    /* 1B04 80104304 35014290 */  lbu        $v0, 0x135($v0)
    /* 1B08 80104308 00000000 */  nop
    /* 1B0C 8010430C 0C004010 */  beqz       $v0, .L80104340
    /* 1B10 80104310 00000000 */   nop
    /* 1B14 80104314 B819040C */  jal        _applyPalingScreenEffect
    /* 1B18 80104318 00000000 */   nop
    /* 1B1C 8010431C 21200000 */  addu       $a0, $zero, $zero
    /* 1B20 80104320 1180023C */  lui        $v0, %hi(D_80108CC4)
    /* 1B24 80104324 C48C4594 */  lhu        $a1, %lo(D_80108CC4)($v0)
    /* 1B28 80104328 C48C4224 */  addiu      $v0, $v0, %lo(D_80108CC4)
    /* 1B2C 8010432C 40280500 */  sll        $a1, $a1, 1
    /* 1B30 80104330 FC1A030C */  jal        vs_battle_setTextBox
    /* 1B34 80104334 2128A200 */   addu      $a1, $a1, $v0
    /* 1B38 80104338 DC100408 */  j          .L80104370
    /* 1B3C 8010433C 00000000 */   nop
  .L80104340:
    /* 1B40 80104340 E110040C */  jal        func_80104384
    /* 1B44 80104344 00000000 */   nop
    /* 1B48 80104348 9718040C */  jal        _darkenBackground
    /* 1B4C 8010434C 00000000 */   nop
    /* 1B50 80104350 1180023C */  lui        $v0, %hi(D_80108D88)
    /* 1B54 80104354 888D428C */  lw         $v0, %lo(D_80108D88)($v0)
    /* 1B58 80104358 00000000 */  nop
    /* 1B5C 8010435C 04004014 */  bnez       $v0, .L80104370
    /* 1B60 80104360 0F80023C */   lui       $v0, %hi(vs_battle_sceneBuffer)
    /* 1B64 80104364 C01B448C */  lw         $a0, %lo(vs_battle_sceneBuffer)($v0)
    /* 1B68 80104368 AC11040C */  jal        func_801046B0
    /* 1B6C 8010436C 00000000 */   nop
  .L80104370:
    /* 1B70 80104370 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1B74 80104374 1400B18F */  lw         $s1, 0x14($sp)
    /* 1B78 80104378 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B7C 8010437C 0800E003 */  jr         $ra
    /* 1B80 80104380 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_801042B0
