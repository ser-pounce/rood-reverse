nonmatching func_800734C0, 0x4C

glabel func_800734C0
    /* ACC0 800734C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* ACC4 800734C4 1000B0AF */  sw         $s0, 0x10($sp)
    /* ACC8 800734C8 21800000 */  addu       $s0, $zero, $zero
    /* ACCC 800734CC 1400BFAF */  sw         $ra, 0x14($sp)
  .L800734D0:
    /* ACD0 800734D0 7179020C */  jal        func_8009E5C4
    /* ACD4 800734D4 21200002 */   addu      $a0, $s0, $zero
    /* ACD8 800734D8 01001026 */  addiu      $s0, $s0, 0x1
    /* ACDC 800734DC 1000022A */  slti       $v0, $s0, 0x10
    /* ACE0 800734E0 FBFF4014 */  bnez       $v0, .L800734D0
    /* ACE4 800734E4 21200000 */   addu      $a0, $zero, $zero
    /* ACE8 800734E8 2BF0010C */  jal        func_8007C0AC
    /* ACEC 800734EC 02000524 */   addiu     $a1, $zero, 0x2
    /* ACF0 800734F0 0F80033C */  lui        $v1, %hi(D_800F196C)
    /* ACF4 800734F4 1400BF8F */  lw         $ra, 0x14($sp)
    /* ACF8 800734F8 1000B08F */  lw         $s0, 0x10($sp)
    /* ACFC 800734FC 0A000224 */  addiu      $v0, $zero, 0xA
    /* AD00 80073500 6C1962AC */  sw         $v0, %lo(D_800F196C)($v1)
    /* AD04 80073504 0800E003 */  jr         $ra
    /* AD08 80073508 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800734C0
