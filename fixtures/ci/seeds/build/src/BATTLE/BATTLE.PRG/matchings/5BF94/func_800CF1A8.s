nonmatching func_800CF1A8, 0x70

glabel func_800CF1A8
    /* 669A8 800CF1A8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 669AC 800CF1AC 0F80023C */  lui        $v0, %hi(D_800F53B8)
    /* 669B0 800CF1B0 21200000 */  addu       $a0, $zero, $zero
    /* 669B4 800CF1B4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 669B8 800CF1B8 B853508C */  lw         $s0, %lo(D_800F53B8)($v0)
    /* 669BC 800CF1BC 01000524 */  addiu      $a1, $zero, 0x1
    /* 669C0 800CF1C0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 669C4 800CF1C4 290D010C */  jal        func_800434A4
    /* 669C8 800CF1C8 1400B1AF */   sw        $s1, 0x14($sp)
    /* 669CC 800CF1CC 0D000012 */  beqz       $s0, .L800CF204
    /* 669D0 800CF1D0 00000000 */   nop
  .L800CF1D4:
    /* 669D4 800CF1D4 4C0D048E */  lw         $a0, 0xD4C($s0)
    /* 669D8 800CF1D8 0000118E */  lw         $s1, 0x0($s0)
    /* 669DC 800CF1DC 04008010 */  beqz       $a0, .L800CF1F0
    /* 669E0 800CF1E0 00000000 */   nop
    /* 669E4 800CF1E4 180F010C */  jal        vs_main_freeHeapR
    /* 669E8 800CF1E8 00000000 */   nop
    /* 669EC 800CF1EC 4C0D00AE */  sw         $zero, 0xD4C($s0)
  .L800CF1F0:
    /* 669F0 800CF1F0 3D3A030C */  jal        func_800CE8F4
    /* 669F4 800CF1F4 21200002 */   addu      $a0, $s0, $zero
    /* 669F8 800CF1F8 21802002 */  addu       $s0, $s1, $zero
    /* 669FC 800CF1FC F5FF0016 */  bnez       $s0, .L800CF1D4
    /* 66A00 800CF200 00000000 */   nop
  .L800CF204:
    /* 66A04 800CF204 1800BF8F */  lw         $ra, 0x18($sp)
    /* 66A08 800CF208 1400B18F */  lw         $s1, 0x14($sp)
    /* 66A0C 800CF20C 1000B08F */  lw         $s0, 0x10($sp)
    /* 66A10 800CF210 0800E003 */  jr         $ra
    /* 66A14 800CF214 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800CF1A8
