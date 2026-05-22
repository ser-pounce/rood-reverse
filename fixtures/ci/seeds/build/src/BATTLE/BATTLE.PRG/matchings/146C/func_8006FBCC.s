nonmatching func_8006FBCC, 0xF0

glabel func_8006FBCC
    /* 73CC 8006FBCC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 73D0 8006FBD0 2400B3AF */  sw         $s3, 0x24($sp)
    /* 73D4 8006FBD4 21988000 */  addu       $s3, $a0, $zero
    /* 73D8 8006FBD8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 73DC 8006FBDC 21800000 */  addu       $s0, $zero, $zero
    /* 73E0 8006FBE0 2000B2AF */  sw         $s2, 0x20($sp)
    /* 73E4 8006FBE4 0F80123C */  lui        $s2, %hi(D_800F19CC)
    /* 73E8 8006FBE8 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 73EC 8006FBEC 0001113C */  lui        $s1, (0x1000000 >> 16)
    /* 73F0 8006FBF0 2800BFAF */  sw         $ra, 0x28($sp)
  .L8006FBF4:
    /* 73F4 8006FBF4 CC19428E */  lw         $v0, %lo(D_800F19CC)($s2)
    /* 73F8 8006FBF8 00000000 */  nop
    /* 73FC 8006FBFC 0C004290 */  lbu        $v0, 0xC($v0)
    /* 7400 8006FC00 00000000 */  nop
    /* 7404 8006FC04 0D000212 */  beq        $s0, $v0, .L8006FC3C
    /* 7408 8006FC08 00000000 */   nop
    /* 740C 8006FC0C F882020C */  jal        func_800A0BE0
    /* 7410 8006FC10 21200002 */   addu      $a0, $s0, $zero
    /* 7414 8006FC14 24105100 */  and        $v0, $v0, $s1
    /* 7418 8006FC18 08004014 */  bnez       $v0, .L8006FC3C
    /* 741C 8006FC1C 00000000 */   nop
    /* 7420 8006FC20 F882020C */  jal        func_800A0BE0
    /* 7424 8006FC24 21200002 */   addu      $a0, $s0, $zero
    /* 7428 8006FC28 01004230 */  andi       $v0, $v0, 0x1
    /* 742C 8006FC2C 03004010 */  beqz       $v0, .L8006FC3C
    /* 7430 8006FC30 00000000 */   nop
    /* 7434 8006FC34 7179020C */  jal        func_8009E5C4
    /* 7438 8006FC38 21200002 */   addu      $a0, $s0, $zero
  .L8006FC3C:
    /* 743C 8006FC3C 01001026 */  addiu      $s0, $s0, 0x1
    /* 7440 8006FC40 1000022A */  slti       $v0, $s0, 0x10
    /* 7444 8006FC44 EBFF4014 */  bnez       $v0, .L8006FBF4
    /* 7448 8006FC48 08000424 */   addiu     $a0, $zero, 0x8
    /* 744C 8006FC4C 04000524 */  addiu      $a1, $zero, 0x4
    /* 7450 8006FC50 21300000 */  addu       $a2, $zero, $zero
    /* 7454 8006FC54 2138C000 */  addu       $a3, $a2, $zero
    /* 7458 8006FC58 43EC010C */  jal        func_8007B10C
    /* 745C 8006FC5C 1000A0AF */   sw        $zero, 0x10($sp)
    /* 7460 8006FC60 94B0010C */  jal        func_8006C250
    /* 7464 8006FC64 00000000 */   nop
    /* 7468 8006FC68 FB23010C */  jal        vs_main_setClutState
    /* 746C 8006FC6C 01000424 */   addiu     $a0, $zero, 0x1
    /* 7470 8006FC70 2F2D020C */  jal        func_8008B4BC
    /* 7474 8006FC74 21200000 */   addu      $a0, $zero, $zero
    /* 7478 8006FC78 DC56020C */  jal        func_80095B70
    /* 747C 8006FC7C 21200000 */   addu      $a0, $zero, $zero
    /* 7480 8006FC80 0F80023C */  lui        $v0, %hi(D_800F18FC)
    /* 7484 8006FC84 0680033C */  lui        $v1, %hi(vs_gametime_tickspeed)
    /* 7488 8006FC88 FC1853AC */  sw         $s3, %lo(D_800F18FC)($v0)
    /* 748C 8006FC8C 02000224 */  addiu      $v0, $zero, 0x2
    /* 7490 8006FC90 4CE262AC */  sw         $v0, %lo(vs_gametime_tickspeed)($v1)
    /* 7494 8006FC94 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* 7498 8006FC98 2800BF8F */  lw         $ra, 0x28($sp)
    /* 749C 8006FC9C 2400B38F */  lw         $s3, 0x24($sp)
    /* 74A0 8006FCA0 2000B28F */  lw         $s2, 0x20($sp)
    /* 74A4 8006FCA4 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 74A8 8006FCA8 1800B08F */  lw         $s0, 0x18($sp)
    /* 74AC 8006FCAC 0B000224 */  addiu      $v0, $zero, 0xB
    /* 74B0 8006FCB0 F01862AC */  sw         $v0, %lo(_cameraMode)($v1)
    /* 74B4 8006FCB4 0800E003 */  jr         $ra
    /* 74B8 8006FCB8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8006FBCC
