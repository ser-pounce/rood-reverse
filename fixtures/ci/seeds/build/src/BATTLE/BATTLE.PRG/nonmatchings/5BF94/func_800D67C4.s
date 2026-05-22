nonmatching func_800D67C4, 0x9C

glabel func_800D67C4
    /* 6DFC4 800D67C4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6DFC8 800D67C8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6DFCC 800D67CC 2188A000 */  addu       $s1, $a1, $zero
    /* 6DFD0 800D67D0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6DFD4 800D67D4 0F80103C */  lui        $s0, %hi(D_800F5520)
    /* 6DFD8 800D67D8 20551026 */  addiu      $s0, $s0, %lo(D_800F5520)
    /* 6DFDC 800D67DC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6DFE0 800D67E0 C646030C */  jal        func_800D1B18
    /* 6DFE4 800D67E4 21200002 */   addu      $a0, $s0, $zero
    /* 6DFE8 800D67E8 40001026 */  addiu      $s0, $s0, 0x40
    /* 6DFEC 800D67EC 0F80023C */  lui        $v0, %hi(D_800F55A8)
    /* 6DFF0 800D67F0 A8554224 */  addiu      $v0, $v0, %lo(D_800F55A8)
    /* 6DFF4 800D67F4 40004324 */  addiu      $v1, $v0, 0x40
  .L800D67F8:
    /* 6DFF8 800D67F8 0000468C */  lw         $a2, 0x0($v0)
    /* 6DFFC 800D67FC 0400478C */  lw         $a3, 0x4($v0)
    /* 6E000 800D6800 0800488C */  lw         $t0, 0x8($v0)
    /* 6E004 800D6804 0C00498C */  lw         $t1, 0xC($v0)
    /* 6E008 800D6808 000006AE */  sw         $a2, 0x0($s0)
    /* 6E00C 800D680C 040007AE */  sw         $a3, 0x4($s0)
    /* 6E010 800D6810 080008AE */  sw         $t0, 0x8($s0)
    /* 6E014 800D6814 0C0009AE */  sw         $t1, 0xC($s0)
    /* 6E018 800D6818 10004224 */  addiu      $v0, $v0, 0x10
    /* 6E01C 800D681C F6FF4314 */  bne        $v0, $v1, .L800D67F8
    /* 6E020 800D6820 10001026 */   addiu     $s0, $s0, 0x10
    /* 6E024 800D6824 0F80023C */  lui        $v0, %hi(D_800F54D0)
    /* 6E028 800D6828 D05440A4 */  sh         $zero, %lo(D_800F54D0)($v0)
    /* 6E02C 800D682C FF002232 */  andi       $v0, $s1, 0xFF
    /* 6E030 800D6830 02004014 */  bnez       $v0, .L800D683C
    /* 6E034 800D6834 0F80033C */   lui       $v1, %hi(D_800F55A0)
    /* 6E038 800D6838 01001124 */  addiu      $s1, $zero, 0x1
  .L800D683C:
    /* 6E03C 800D683C FF002232 */  andi       $v0, $s1, 0xFF
    /* 6E040 800D6840 02000424 */  addiu      $a0, $zero, 0x2
    /* 6E044 800D6844 8847030C */  jal        func_800D1E20
    /* 6E048 800D6848 A05562A4 */   sh        $v0, %lo(D_800F55A0)($v1)
    /* 6E04C 800D684C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6E050 800D6850 1400B18F */  lw         $s1, 0x14($sp)
    /* 6E054 800D6854 1000B08F */  lw         $s0, 0x10($sp)
    /* 6E058 800D6858 0800E003 */  jr         $ra
    /* 6E05C 800D685C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D67C4
