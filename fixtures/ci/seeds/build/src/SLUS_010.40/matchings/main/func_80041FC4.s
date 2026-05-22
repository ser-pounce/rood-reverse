nonmatching func_80041FC4, 0x90

glabel func_80041FC4
    /* 327C4 80041FC4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 327C8 80041FC8 0400033C */  lui        $v1, (0x41AC8 >> 16)
    /* 327CC 80041FCC C81A6334 */  ori        $v1, $v1, (0x41AC8 & 0xFFFF)
    /* 327D0 80041FD0 0700023C */  lui        $v0, (0x74000 >> 16)
    /* 327D4 80041FD4 00404234 */  ori        $v0, $v0, (0x74000 & 0xFFFF)
    /* 327D8 80041FD8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 327DC 80041FDC 2000BFAF */  sw         $ra, 0x20($sp)
    /* 327E0 80041FE0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 327E4 80041FE4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 327E8 80041FE8 1000A3AF */  sw         $v1, 0x10($sp)
    /* 327EC 80041FEC C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 327F0 80041FF0 1400A2AF */   sw        $v0, 0x14($sp)
    /* 327F4 80041FF4 21804000 */  addu       $s0, $v0, $zero
    /* 327F8 80041FF8 0180023C */  lui        $v0, %hi(vs_overlay_slots)
    /* 327FC 80041FFC 0000458C */  lw         $a1, %lo(vs_overlay_slots)($v0)
    /* 32800 80042000 FD12010C */  jal        vs_main_cdEnqueuePriority
    /* 32804 80042004 21200002 */   addu      $a0, $s0, $zero
    /* 32808 80042008 00000386 */  lh         $v1, 0x0($s0)
    /* 3280C 8004200C 04000224 */  addiu      $v0, $zero, 0x4
    /* 32810 80042010 07006210 */  beq        $v1, $v0, .L80042030
    /* 32814 80042014 21884000 */   addu      $s1, $v0, $zero
  .L80042018:
    /* 32818 80042018 8709010C */  jal        vs_main_gametimeUpdate
    /* 3281C 8004201C 21200000 */   addu      $a0, $zero, $zero
    /* 32820 80042020 00000286 */  lh         $v0, 0x0($s0)
    /* 32824 80042024 00000000 */  nop
    /* 32828 80042028 FBFF5114 */  bne        $v0, $s1, .L80042018
    /* 3282C 8004202C 00000000 */   nop
  .L80042030:
    /* 32830 80042030 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 32834 80042034 21200002 */   addu      $a0, $s0, $zero
    /* 32838 80042038 1D0B010C */  jal        vs_main_wait
    /* 3283C 8004203C 00000000 */   nop
    /* 32840 80042040 2000BF8F */  lw         $ra, 0x20($sp)
    /* 32844 80042044 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 32848 80042048 1800B08F */  lw         $s0, 0x18($sp)
    /* 3284C 8004204C 0800E003 */  jr         $ra
    /* 32850 80042050 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80041FC4
