nonmatching ER_clear, 0x50

glabel ER_clear
    /* 16FAC 800267AC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16FB0 800267B0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 16FB4 800267B4 0380103C */  lui        $s0, %hi(D_80032824)
    /* 16FB8 800267B8 24281026 */  addiu      $s0, $s0, %lo(D_80032824)
    /* 16FBC 800267BC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 16FC0 800267C0 0000038E */  lw         $v1, 0x0($s0)
    /* 16FC4 800267C4 01000224 */  addiu      $v0, $zero, 0x1
    /* 16FC8 800267C8 07006214 */  bne        $v1, $v0, .L800267E8
    /* 16FCC 800267CC 00000000 */   nop
    /* 16FD0 800267D0 F4FF048E */  lw         $a0, -0xC($s0)
    /* 16FD4 800267D4 069A000C */  jal        DsReadyCallback
    /* 16FD8 800267D8 00000000 */   nop
    /* 16FDC 800267DC F8FF048E */  lw         $a0, -0x8($s0)
    /* 16FE0 800267E0 0B9A000C */  jal        DsStartCallback
    /* 16FE4 800267E4 00000000 */   nop
  .L800267E8:
    /* 16FE8 800267E8 000000AE */  sw         $zero, 0x0($s0)
    /* 16FEC 800267EC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 16FF0 800267F0 1000B08F */  lw         $s0, 0x10($sp)
    /* 16FF4 800267F4 0800E003 */  jr         $ra
    /* 16FF8 800267F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel ER_clear
    /* 16FFC 800267FC 00000000 */  nop
    /* 17000 80026800 00000000 */  nop
