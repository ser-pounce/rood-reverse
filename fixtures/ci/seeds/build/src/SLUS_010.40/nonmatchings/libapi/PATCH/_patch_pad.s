/* Handwritten function */
nonmatching _patch_pad, 0x70

glabel _patch_pad
    /* 1F59C 8002ED9C 0480013C */  lui        $at, %hi(D_8003FEB8)
    /* 1F5A0 8002EDA0 B8FE3FAC */  sw         $ra, %lo(D_8003FEB8)($at)
    /* 1F5A4 8002EDA4 5D9A000C */  jal        EnterCriticalSection
    /* 1F5A8 8002EDA8 00000000 */   nop
    /* 1F5AC 8002EDAC 57000924 */  addiu      $t1, $zero, 0x57
    /* 1F5B0 8002EDB0 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 1F5B4 8002EDB4 09F84001 */  jalr       $t2
    /* 1F5B8 8002EDB8 00000000 */   nop
    /* 1F5BC 8002EDBC 6C01428C */  lw         $v0, 0x16C($v0)
    /* 1F5C0 8002EDC0 0B000924 */  addiu      $t1, $zero, 0xB
    /* 1F5C4 8002EDC4 84084320 */  addi       $v1, $v0, 0x884 /* handwritten instruction */
    /* 1F5C8 8002EDC8 0480013C */  lui        $at, %hi(jtbl_8003FEC0)
    /* 1F5CC 8002EDCC C0FE23AC */  sw         $v1, %lo(jtbl_8003FEC0)($at)
    /* 1F5D0 8002EDD0 94084320 */  addi       $v1, $v0, 0x894 /* handwritten instruction */
    /* 1F5D4 8002EDD4 0480013C */  lui        $at, %hi(jtbl_8003FEC4)
    /* 1F5D8 8002EDD8 C4FE23AC */  sw         $v1, %lo(jtbl_8003FEC4)($at)
  .L8002EDDC:
    /* 1F5DC 8002EDDC 940540AC */  sw         $zero, 0x594($v0)
    /* 1F5E0 8002EDE0 04004224 */  addiu      $v0, $v0, 0x4
    /* 1F5E4 8002EDE4 FFFF2925 */  addiu      $t1, $t1, -0x1
    /* 1F5E8 8002EDE8 FCFF2015 */  bnez       $t1, .L8002EDDC
    /* 1F5EC 8002EDEC 00000000 */   nop
    /* 1F5F0 8002EDF0 1D9A000C */  jal        FlushCache
    /* 1F5F4 8002EDF4 00000000 */   nop
    /* 1F5F8 8002EDF8 04801F3C */  lui        $ra, %hi(D_8003FEB8)
    /* 1F5FC 8002EDFC B8FEFF8F */  lw         $ra, %lo(D_8003FEB8)($ra)
    /* 1F600 8002EE00 00000000 */  nop
    /* 1F604 8002EE04 0800E003 */  jr         $ra
    /* 1F608 8002EE08 00000000 */   nop
endlabel _patch_pad
    /* 1F60C 8002EE0C 00000000 */  nop
    /* 1F610 8002EE10 00000000 */  nop
