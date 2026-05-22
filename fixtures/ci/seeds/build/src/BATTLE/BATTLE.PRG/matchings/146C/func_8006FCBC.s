nonmatching func_8006FCBC, 0x50

glabel func_8006FCBC
    /* 74BC 8006FCBC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 74C0 8006FCC0 F0000524 */  addiu      $a1, $zero, 0xF0
    /* 74C4 8006FCC4 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* 74C8 8006FCC8 0F80023C */  lui        $v0, %hi(D_800F19CC)
    /* 74CC 8006FCCC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 74D0 8006FCD0 CC19508C */  lw         $s0, %lo(D_800F19CC)($v0)
    /* 74D4 8006FCD4 0A000224 */  addiu      $v0, $zero, 0xA
    /* 74D8 8006FCD8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 74DC 8006FCDC F01862AC */  sw         $v0, %lo(_cameraMode)($v1)
    /* 74E0 8006FCE0 54081026 */  addiu      $s0, $s0, 0x854
    /* 74E4 8006FCE4 04000492 */  lbu        $a0, 0x4($s0)
    /* 74E8 8006FCE8 4B85020C */  jal        func_800A152C
    /* 74EC 8006FCEC 21300000 */   addu      $a2, $zero, $zero
    /* 74F0 8006FCF0 04000492 */  lbu        $a0, 0x4($s0)
    /* 74F4 8006FCF4 29B1010C */  jal        func_8006C4A4
    /* 74F8 8006FCF8 21284000 */   addu      $a1, $v0, $zero
    /* 74FC 8006FCFC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 7500 8006FD00 1000B08F */  lw         $s0, 0x10($sp)
    /* 7504 8006FD04 0800E003 */  jr         $ra
    /* 7508 8006FD08 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006FCBC
