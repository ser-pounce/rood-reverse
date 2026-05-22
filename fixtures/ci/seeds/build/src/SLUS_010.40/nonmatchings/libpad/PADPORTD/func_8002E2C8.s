nonmatching func_8002E2C8, 0x38

glabel func_8002E2C8
    /* 1EAC8 8002E2C8 21280000 */  addu       $a1, $zero, $zero
    /* 1EACC 8002E2CC 10000624 */  addiu      $a2, $zero, 0x10
    /* 1EAD0 8002E2D0 0480033C */  lui        $v1, %hi(D_8003FCC0)
    /* 1EAD4 8002E2D4 C0FC6324 */  addiu      $v1, $v1, %lo(D_8003FCC0)
  .L8002E2D8:
    /* 1EAD8 8002E2D8 07008310 */  beq        $a0, $v1, .L8002E2F8
    /* 1EADC 8002E2DC 2110C000 */   addu      $v0, $a2, $zero
    /* 1EAE0 8002E2E0 1000C624 */  addiu      $a2, $a2, 0x10
    /* 1EAE4 8002E2E4 0100A524 */  addiu      $a1, $a1, 0x1
    /* 1EAE8 8002E2E8 0200A228 */  slti       $v0, $a1, 0x2
    /* 1EAEC 8002E2EC FAFF4014 */  bnez       $v0, .L8002E2D8
    /* 1EAF0 8002E2F0 F0006324 */   addiu     $v1, $v1, 0xF0
    /* 1EAF4 8002E2F4 FF000224 */  addiu      $v0, $zero, 0xFF
  .L8002E2F8:
    /* 1EAF8 8002E2F8 0800E003 */  jr         $ra
    /* 1EAFC 8002E2FC 00000000 */   nop
endlabel func_8002E2C8
