nonmatching func_8007FD74, 0x4C

glabel func_8007FD74
    /* 17574 8007FD74 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 17578 8007FD78 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1757C 8007FD7C 2180A000 */  addu       $s0, $a1, $zero
    /* 17580 8007FD80 1400BFAF */  sw         $ra, 0x14($sp)
    /* 17584 8007FD84 2CFD010C */  jal        func_8007F4B0
    /* 17588 8007FD88 1E000424 */   addiu     $a0, $zero, 0x1E
    /* 1758C 8007FD8C 07004014 */  bnez       $v0, .L8007FDAC
    /* 17590 8007FD90 00000000 */   nop
    /* 17594 8007FD94 46FD010C */  jal        _getEnemyClass
    /* 17598 8007FD98 21200002 */   addu      $a0, $s0, $zero
    /* 1759C 8007FD9C 21204000 */  addu       $a0, $v0, $zero
    /* 175A0 8007FDA0 02000324 */  addiu      $v1, $zero, 0x2
    /* 175A4 8007FDA4 02008314 */  bne        $a0, $v1, .L8007FDB0
    /* 175A8 8007FDA8 01000224 */   addiu     $v0, $zero, 0x1
  .L8007FDAC:
    /* 175AC 8007FDAC 21100000 */  addu       $v0, $zero, $zero
  .L8007FDB0:
    /* 175B0 8007FDB0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 175B4 8007FDB4 1000B08F */  lw         $s0, 0x10($sp)
    /* 175B8 8007FDB8 0800E003 */  jr         $ra
    /* 175BC 8007FDBC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007FD74
