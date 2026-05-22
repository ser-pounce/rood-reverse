/* Handwritten function */
nonmatching __SN_ENTRY_POINT, 0xA8

glabel __SN_ENTRY_POINT
    /* FD44 8001F544 0380023C */  lui        $v0, %hi(__ra_temp)
    /* FD48 8001F548 78364224 */  addiu      $v0, $v0, %lo(__ra_temp)
    /* FD4C 8001F54C 0480033C */  lui        $v1, %hi(D_800401A8)
    /* FD50 8001F550 A8016324 */  addiu      $v1, $v1, %lo(D_800401A8)
  .L8001F554:
    /* FD54 8001F554 000040AC */  sw         $zero, 0x0($v0)
    /* FD58 8001F558 04004224 */  addiu      $v0, $v0, 0x4
    /* FD5C 8001F55C 2B084300 */  sltu       $at, $v0, $v1
    /* FD60 8001F560 FCFF2014 */  bnez       $at, .L8001F554
    /* FD64 8001F564 00000000 */   nop
    /* FD68 8001F568 0580023C */  lui        $v0, %hi(_ramsize)
    /* FD6C 8001F56C 3891428C */  lw         $v0, %lo(_ramsize)($v0)
    /* FD70 8001F570 00000000 */  nop
    /* FD74 8001F574 F8FF4220 */  addi       $v0, $v0, -0x8 /* handwritten instruction */
    /* FD78 8001F578 0080083C */  lui        $t0, %hi(D_80000004)
    /* FD7C 8001F57C 25E84800 */  or         $sp, $v0, $t0
    /* FD80 8001F580 0480043C */  lui        $a0, %hi(D_800401A8)
    /* FD84 8001F584 A8018424 */  addiu      $a0, $a0, %lo(D_800401A8)
    /* FD88 8001F588 C0200400 */  sll        $a0, $a0, 3
    /* FD8C 8001F58C C2200400 */  srl        $a0, $a0, 3
    /* FD90 8001F590 0580033C */  lui        $v1, %hi(_stacksize)
    /* FD94 8001F594 3C91638C */  lw         $v1, %lo(_stacksize)($v1)
    /* FD98 8001F598 00000000 */  nop
    /* FD9C 8001F59C 23284300 */  subu       $a1, $v0, $v1
    /* FDA0 8001F5A0 2328A400 */  subu       $a1, $a1, $a0
    /* FDA4 8001F5A4 0380013C */  lui        $at, %hi(__heapsize)
    /* FDA8 8001F5A8 B80F25AC */  sw         $a1, %lo(__heapsize)($at)
    /* FDAC 8001F5AC 25208800 */  or         $a0, $a0, $t0
    /* FDB0 8001F5B0 0380013C */  lui        $at, %hi(__heapbase)
    /* FDB4 8001F5B4 B40F24AC */  sw         $a0, %lo(__heapbase)($at)
    /* FDB8 8001F5B8 0380013C */  lui        $at, %hi(__ra_temp)
    /* FDBC 8001F5BC 78363FAC */  sw         $ra, %lo(__ra_temp)($at)
    /* FDC0 8001F5C0 03801C3C */  lui        $gp, %hi(_gp)
    /* FDC4 8001F5C4 74369C27 */  addiu      $gp, $gp, %lo(_gp)
    /* FDC8 8001F5C8 21F0A003 */  addu       $fp, $sp, $zero
    /* FDCC 8001F5CC 199A000C */  jal        InitHeap
    /* FDD0 8001F5D0 04008420 */   addi      $a0, $a0, %lo(D_80000004) /* handwritten instruction */
    /* FDD4 8001F5D4 03801F3C */  lui        $ra, %hi(__ra_temp)
    /* FDD8 8001F5D8 7836FF8F */  lw         $ra, %lo(__ra_temp)($ra)
    /* FDDC 8001F5DC 00000000 */  nop
    /* FDE0 8001F5E0 0E0B010C */  jal        vs_main_exec
    /* FDE4 8001F5E4 00000000 */   nop
    /* FDE8 8001F5E8 4D000000 */  break      0, 1
endlabel __SN_ENTRY_POINT
