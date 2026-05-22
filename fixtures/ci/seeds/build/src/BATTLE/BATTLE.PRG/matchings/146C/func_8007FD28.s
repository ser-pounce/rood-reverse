nonmatching func_8007FD28, 0x4C

glabel func_8007FD28
    /* 17528 8007FD28 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1752C 8007FD2C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 17530 8007FD30 2180A000 */  addu       $s0, $a1, $zero
    /* 17534 8007FD34 1400BFAF */  sw         $ra, 0x14($sp)
    /* 17538 8007FD38 2CFD010C */  jal        func_8007F4B0
    /* 1753C 8007FD3C 1E000424 */   addiu     $a0, $zero, 0x1E
    /* 17540 8007FD40 07004014 */  bnez       $v0, .L8007FD60
    /* 17544 8007FD44 00000000 */   nop
    /* 17548 8007FD48 46FD010C */  jal        _getEnemyClass
    /* 1754C 8007FD4C 21200002 */   addu      $a0, $s0, $zero
    /* 17550 8007FD50 21204000 */  addu       $a0, $v0, $zero
    /* 17554 8007FD54 02000324 */  addiu      $v1, $zero, 0x2
    /* 17558 8007FD58 02008310 */  beq        $a0, $v1, .L8007FD64
    /* 1755C 8007FD5C 01000224 */   addiu     $v0, $zero, 0x1
  .L8007FD60:
    /* 17560 8007FD60 21100000 */  addu       $v0, $zero, $zero
  .L8007FD64:
    /* 17564 8007FD64 1400BF8F */  lw         $ra, 0x14($sp)
    /* 17568 8007FD68 1000B08F */  lw         $s0, 0x10($sp)
    /* 1756C 8007FD6C 0800E003 */  jr         $ra
    /* 17570 8007FD70 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007FD28
