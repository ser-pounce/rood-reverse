nonmatching func_800B7428, 0x68

glabel func_800B7428
    /* 4EC28 800B7428 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 4EC2C 800B742C 2800B0AF */  sw         $s0, 0x28($sp)
    /* 4EC30 800B7430 21808000 */  addu       $s0, $a0, $zero
    /* 4EC34 800B7434 01000426 */  addiu      $a0, $s0, 0x1
    /* 4EC38 800B7438 3000BFAF */  sw         $ra, 0x30($sp)
    /* 4EC3C 800B743C 80FF020C */  jal        vs_battle_getShort
    /* 4EC40 800B7440 2C00B1AF */   sw        $s1, 0x2C($sp)
    /* 4EC44 800B7444 FFFF4430 */  andi       $a0, $v0, 0xFFFF
    /* 4EC48 800B7448 A3ED020C */  jal        func_800BB68C
    /* 4EC4C 800B744C 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4EC50 800B7450 01001124 */  addiu      $s1, $zero, 0x1
  .L800B7454:
    /* 4EC54 800B7454 E2ED020C */  jal        func_800BB788
    /* 4EC58 800B7458 1000A427 */   addiu     $a0, $sp, 0x10
    /* 4EC5C 800B745C FFFF4430 */  andi       $a0, $v0, 0xFFFF
    /* 4EC60 800B7460 06009110 */  beq        $a0, $s1, .L800B747C
    /* 4EC64 800B7464 21100000 */   addu      $v0, $zero, $zero
    /* 4EC68 800B7468 03000592 */  lbu        $a1, 0x3($s0)
    /* 4EC6C 800B746C D2F0010C */  jal        func_8007C348
    /* 4EC70 800B7470 00000000 */   nop
    /* 4EC74 800B7474 15DD0208 */  j          .L800B7454
    /* 4EC78 800B7478 00000000 */   nop
  .L800B747C:
    /* 4EC7C 800B747C 3000BF8F */  lw         $ra, 0x30($sp)
    /* 4EC80 800B7480 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 4EC84 800B7484 2800B08F */  lw         $s0, 0x28($sp)
    /* 4EC88 800B7488 0800E003 */  jr         $ra
    /* 4EC8C 800B748C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_800B7428
