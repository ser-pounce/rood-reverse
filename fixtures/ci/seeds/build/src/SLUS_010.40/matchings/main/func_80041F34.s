nonmatching func_80041F34, 0x90

glabel func_80041F34
    /* 32734 80041F34 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 32738 80041F38 0300033C */  lui        $v1, (0x3E800 >> 16)
    /* 3273C 80041F3C 00E86334 */  ori        $v1, $v1, (0x3E800 & 0xFFFF)
    /* 32740 80041F40 0800023C */  lui        $v0, (0x87800 >> 16)
    /* 32744 80041F44 00784234 */  ori        $v0, $v0, (0x87800 & 0xFFFF)
    /* 32748 80041F48 1000A427 */  addiu      $a0, $sp, 0x10
    /* 3274C 80041F4C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 32750 80041F50 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 32754 80041F54 1800B0AF */  sw         $s0, 0x18($sp)
    /* 32758 80041F58 1000A3AF */  sw         $v1, 0x10($sp)
    /* 3275C 80041F5C C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 32760 80041F60 1400A2AF */   sw        $v0, 0x14($sp)
    /* 32764 80041F64 21804000 */  addu       $s0, $v0, $zero
    /* 32768 80041F68 0180023C */  lui        $v0, %hi(vs_overlay_slots)
    /* 3276C 80041F6C 0000458C */  lw         $a1, %lo(vs_overlay_slots)($v0)
    /* 32770 80041F70 FD12010C */  jal        vs_main_cdEnqueuePriority
    /* 32774 80041F74 21200002 */   addu      $a0, $s0, $zero
    /* 32778 80041F78 00000386 */  lh         $v1, 0x0($s0)
    /* 3277C 80041F7C 04000224 */  addiu      $v0, $zero, 0x4
    /* 32780 80041F80 07006210 */  beq        $v1, $v0, .L80041FA0
    /* 32784 80041F84 21884000 */   addu      $s1, $v0, $zero
  .L80041F88:
    /* 32788 80041F88 8709010C */  jal        vs_main_gametimeUpdate
    /* 3278C 80041F8C 21200000 */   addu      $a0, $zero, $zero
    /* 32790 80041F90 00000286 */  lh         $v0, 0x0($s0)
    /* 32794 80041F94 00000000 */  nop
    /* 32798 80041F98 FBFF5114 */  bne        $v0, $s1, .L80041F88
    /* 3279C 80041F9C 00000000 */   nop
  .L80041FA0:
    /* 327A0 80041FA0 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 327A4 80041FA4 21200002 */   addu      $a0, $s0, $zero
    /* 327A8 80041FA8 1D0B010C */  jal        vs_main_wait
    /* 327AC 80041FAC 00000000 */   nop
    /* 327B0 80041FB0 2000BF8F */  lw         $ra, 0x20($sp)
    /* 327B4 80041FB4 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 327B8 80041FB8 1800B08F */  lw         $s0, 0x18($sp)
    /* 327BC 80041FBC 0800E003 */  jr         $ra
    /* 327C0 80041FC0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80041F34
