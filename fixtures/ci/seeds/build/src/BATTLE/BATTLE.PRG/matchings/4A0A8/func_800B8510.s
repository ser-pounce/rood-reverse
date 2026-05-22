nonmatching func_800B8510, 0x80

glabel func_800B8510
    /* 4FD10 800B8510 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4FD14 800B8514 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4FD18 800B8518 21888000 */  addu       $s1, $a0, $zero
    /* 4FD1C 800B851C 03002426 */  addiu      $a0, $s1, 0x3
    /* 4FD20 800B8520 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4FD24 800B8524 80FF020C */  jal        vs_battle_getShort
    /* 4FD28 800B8528 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4FD2C 800B852C 94FF020C */  jal        func_800BFE50
    /* 4FD30 800B8530 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4FD34 800B8534 01002426 */  addiu      $a0, $s1, 0x1
    /* 4FD38 800B8538 80FF020C */  jal        vs_battle_getShort
    /* 4FD3C 800B853C 21804000 */   addu      $s0, $v0, $zero
    /* 4FD40 800B8540 94FF020C */  jal        func_800BFE50
    /* 4FD44 800B8544 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4FD48 800B8548 21204000 */  addu       $a0, $v0, $zero
    /* 4FD4C 800B854C 00200224 */  addiu      $v0, $zero, 0x2000
    /* 4FD50 800B8550 02000212 */  beq        $s0, $v0, .L800B855C
    /* 4FD54 800B8554 FEFF0524 */   addiu     $a1, $zero, -0x2
    /* 4FD58 800B8558 21280002 */  addu       $a1, $s0, $zero
  .L800B855C:
    /* 4FD5C 800B855C 05002292 */  lbu        $v0, 0x5($s1)
    /* 4FD60 800B8560 00000000 */  nop
    /* 4FD64 800B8564 02004010 */  beqz       $v0, .L800B8570
    /* 4FD68 800B8568 00100724 */   addiu     $a3, $zero, 0x1000
    /* 4FD6C 800B856C 21384000 */  addu       $a3, $v0, $zero
  .L800B8570:
    /* 4FD70 800B8570 187F020C */  jal        func_8009FC60
    /* 4FD74 800B8574 21300000 */   addu      $a2, $zero, $zero
    /* 4FD78 800B8578 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4FD7C 800B857C 1400B18F */  lw         $s1, 0x14($sp)
    /* 4FD80 800B8580 1000B08F */  lw         $s0, 0x10($sp)
    /* 4FD84 800B8584 21100000 */  addu       $v0, $zero, $zero
    /* 4FD88 800B8588 0800E003 */  jr         $ra
    /* 4FD8C 800B858C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800B8510
