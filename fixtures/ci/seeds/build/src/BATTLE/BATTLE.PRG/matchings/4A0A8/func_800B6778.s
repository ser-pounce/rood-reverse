nonmatching func_800B6778, 0xF0

glabel func_800B6778
    /* 4DF78 800B6778 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4DF7C 800B677C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4DF80 800B6780 21808000 */  addu       $s0, $a0, $zero
    /* 4DF84 800B6784 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4DF88 800B6788 21880000 */  addu       $s1, $zero, $zero
    /* 4DF8C 800B678C 0F80023C */  lui        $v0, %hi(D_800E9BE0)
    /* 4DF90 800B6790 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4DF94 800B6794 E09B5224 */  addiu      $s2, $v0, %lo(D_800E9BE0)
    /* 4DF98 800B6798 2000BFAF */  sw         $ra, 0x20($sp)
    /* 4DF9C 800B679C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 4DFA0 800B67A0 00111100 */  sll        $v0, $s1, 4
  .L800B67A4:
    /* 4DFA4 800B67A4 08004234 */  ori        $v0, $v0, 0x8
    /* 4DFA8 800B67A8 010042A2 */  sb         $v0, 0x1($s2)
    /* 4DFAC 800B67AC 21204002 */  addu       $a0, $s2, $zero
    /* 4DFB0 800B67B0 16E7020C */  jal        func_800B9C58
    /* 4DFB4 800B67B4 21280000 */   addu      $a1, $zero, $zero
    /* 4DFB8 800B67B8 01002226 */  addiu      $v0, $s1, 0x1
    /* 4DFBC 800B67BC 21884000 */  addu       $s1, $v0, $zero
    /* 4DFC0 800B67C0 00140200 */  sll        $v0, $v0, 16
    /* 4DFC4 800B67C4 03140200 */  sra        $v0, $v0, 16
    /* 4DFC8 800B67C8 03004228 */  slti       $v0, $v0, 0x3
    /* 4DFCC 800B67CC F5FF4014 */  bnez       $v0, .L800B67A4
    /* 4DFD0 800B67D0 00111100 */   sll       $v0, $s1, 4
    /* 4DFD4 800B67D4 37AB020C */  jal        func_800AACDC
    /* 4DFD8 800B67D8 00000000 */   nop
    /* 4DFDC 800B67DC 00000392 */  lbu        $v1, 0x0($s0)
    /* 4DFE0 800B67E0 0F000224 */  addiu      $v0, $zero, 0xF
    /* 4DFE4 800B67E4 14006210 */  beq        $v1, $v0, .L800B6838
    /* 4DFE8 800B67E8 0F80133C */   lui       $s3, %hi(D_800E9BE8)
    /* 4DFEC 800B67EC 0F80023C */  lui        $v0, %hi(D_800E9C30)
    /* 4DFF0 800B67F0 309C5224 */  addiu      $s2, $v0, %lo(D_800E9C30)
    /* 4DFF4 800B67F4 0F001124 */  addiu      $s1, $zero, 0xF
    /* 4DFF8 800B67F8 21200002 */  addu       $a0, $s0, $zero
  .L800B67FC:
    /* 4DFFC 800B67FC E89B6526 */  addiu      $a1, $s3, %lo(D_800E9BE8)
    /* 4E000 800B6800 019E000C */  jal        memcmp
    /* 4E004 800B6804 04000624 */   addiu     $a2, $zero, 0x4
    /* 4E008 800B6808 0E004010 */  beqz       $v0, .L800B6844
    /* 4E00C 800B680C A8000424 */   addiu     $a0, $zero, 0xA8
    /* 4E010 800B6810 00000292 */  lbu        $v0, 0x0($s0)
    /* 4E014 800B6814 00000000 */  nop
    /* 4E018 800B6818 21105200 */  addu       $v0, $v0, $s2
    /* 4E01C 800B681C 00004290 */  lbu        $v0, 0x0($v0)
    /* 4E020 800B6820 00000000 */  nop
    /* 4E024 800B6824 21800202 */  addu       $s0, $s0, $v0
    /* 4E028 800B6828 00000292 */  lbu        $v0, 0x0($s0)
    /* 4E02C 800B682C 00000000 */  nop
    /* 4E030 800B6830 F2FF5114 */  bne        $v0, $s1, .L800B67FC
    /* 4E034 800B6834 21200002 */   addu      $a0, $s0, $zero
  .L800B6838:
    /* 4E038 800B6838 9C4E020C */  jal        func_80093A70
    /* 4E03C 800B683C 00000000 */   nop
    /* 4E040 800B6840 A8000424 */  addiu      $a0, $zero, 0xA8
  .L800B6844:
    /* 4E044 800B6844 05FB020C */  jal        vs_battle_setStateFlag
    /* 4E048 800B6848 21280000 */   addu      $a1, $zero, $zero
    /* 4E04C 800B684C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 4E050 800B6850 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 4E054 800B6854 1800B28F */  lw         $s2, 0x18($sp)
    /* 4E058 800B6858 1400B18F */  lw         $s1, 0x14($sp)
    /* 4E05C 800B685C 1000B08F */  lw         $s0, 0x10($sp)
    /* 4E060 800B6860 0800E003 */  jr         $ra
    /* 4E064 800B6864 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800B6778
