nonmatching func_80025D84, 0x34

glabel func_80025D84
    /* 16584 80025D84 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16588 80025D88 FF008430 */  andi       $a0, $a0, 0xFF
    /* 1658C 80025D8C 02000224 */  addiu      $v0, $zero, 0x2
    /* 16590 80025D90 05008214 */  bne        $a0, $v0, .L80025DA8
    /* 16594 80025D94 1000BFAF */   sw        $ra, 0x10($sp)
    /* 16598 80025D98 0280043C */  lui        $a0, %hi(func_80025DB8)
    /* 1659C 80025D9C B85D8424 */  addiu      $a0, $a0, %lo(func_80025DB8)
    /* 165A0 80025DA0 9998000C */  jal        DsStartReadySystem
    /* 165A4 80025DA4 FFFF0524 */   addiu     $a1, $zero, -0x1
  .L80025DA8:
    /* 165A8 80025DA8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 165AC 80025DAC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 165B0 80025DB0 0800E003 */  jr         $ra
    /* 165B4 80025DB4 00000000 */   nop
endlabel func_80025D84
