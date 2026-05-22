nonmatching _stepTowardTarget, 0xE4

glabel _stepTowardTarget
    /* 56FC 8006DEFC C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 5700 8006DF00 2138A000 */  addu       $a3, $a1, $zero
    /* 5704 8006DF04 2800A527 */  addiu      $a1, $sp, 0x28
    /* 5708 8006DF08 1000A6AF */  sw         $a2, 0x10($sp)
    /* 570C 8006DF0C 1800A627 */  addiu      $a2, $sp, 0x18
    /* 5710 8006DF10 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 5714 8006DF14 E6B6010C */  jal        _computeStepAndDisplacement
    /* 5718 8006DF18 3800B0AF */   sw        $s0, 0x38($sp)
    /* 571C 8006DF1C 13004010 */  beqz       $v0, .L8006DF6C
    /* 5720 8006DF20 801F103C */   lui       $s0, %hi(D_1F800000)
    /* 5724 8006DF24 00001026 */  addiu      $s0, $s0, %lo(D_1F800000)
    /* 5728 8006DF28 4400048E */  lw         $a0, 0x44($s0)
    /* 572C 8006DF2C 2800A58F */  lw         $a1, 0x28($sp)
    /* 5730 8006DF30 1800A68F */  lw         $a2, 0x18($sp)
    /* 5734 8006DF34 5FB6010C */  jal        _addMinDelta
    /* 5738 8006DF38 00000000 */   nop
    /* 573C 8006DF3C 4C00048E */  lw         $a0, 0x4C($s0)
    /* 5740 8006DF40 3000A58F */  lw         $a1, 0x30($sp)
    /* 5744 8006DF44 2000A68F */  lw         $a2, 0x20($sp)
    /* 5748 8006DF48 5FB6010C */  jal        _addMinDelta
    /* 574C 8006DF4C 440002AE */   sw        $v0, 0x44($s0)
    /* 5750 8006DF50 4800048E */  lw         $a0, 0x48($s0)
    /* 5754 8006DF54 2C00A58F */  lw         $a1, 0x2C($sp)
    /* 5758 8006DF58 1C00A68F */  lw         $a2, 0x1C($sp)
    /* 575C 8006DF5C 5FB6010C */  jal        _addMinDelta
    /* 5760 8006DF60 4C0002AE */   sw        $v0, 0x4C($s0)
    /* 5764 8006DF64 ECB70108 */  j          .L8006DFB0
    /* 5768 8006DF68 480002AE */   sw        $v0, 0x48($s0)
  .L8006DF6C:
    /* 576C 8006DF6C 00001026 */  addiu      $s0, $s0, %lo(D_1F800000)
    /* 5770 8006DF70 4400048E */  lw         $a0, 0x44($s0)
    /* 5774 8006DF74 2800A58F */  lw         $a1, 0x28($sp)
    /* 5778 8006DF78 1800A68F */  lw         $a2, 0x18($sp)
    /* 577C 8006DF7C 71B6010C */  jal        _add_min
    /* 5780 8006DF80 00000000 */   nop
    /* 5784 8006DF84 4C00048E */  lw         $a0, 0x4C($s0)
    /* 5788 8006DF88 3000A58F */  lw         $a1, 0x30($sp)
    /* 578C 8006DF8C 2000A68F */  lw         $a2, 0x20($sp)
    /* 5790 8006DF90 71B6010C */  jal        _add_min
    /* 5794 8006DF94 440002AE */   sw        $v0, 0x44($s0)
    /* 5798 8006DF98 4800048E */  lw         $a0, 0x48($s0)
    /* 579C 8006DF9C 2C00A58F */  lw         $a1, 0x2C($sp)
    /* 57A0 8006DFA0 1C00A68F */  lw         $a2, 0x1C($sp)
    /* 57A4 8006DFA4 71B6010C */  jal        _add_min
    /* 57A8 8006DFA8 4C0002AE */   sw        $v0, 0x4C($s0)
    /* 57AC 8006DFAC 480002AE */  sw         $v0, 0x48($s0)
  .L8006DFB0:
    /* 57B0 8006DFB0 801F023C */  lui        $v0, %hi(D_1F800000)
    /* 57B4 8006DFB4 00004324 */  addiu      $v1, $v0, %lo(D_1F800000)
    /* 57B8 8006DFB8 4800628C */  lw         $v0, 0x48($v1)
    /* 57BC 8006DFBC 00000000 */  nop
    /* 57C0 8006DFC0 02004018 */  blez       $v0, .L8006DFCC
    /* 57C4 8006DFC4 0F80023C */   lui       $v0, %hi(D_800F19F8)
    /* 57C8 8006DFC8 480060AC */  sw         $zero, 0x48($v1)
  .L8006DFCC:
    /* 57CC 8006DFCC F819428C */  lw         $v0, %lo(D_800F19F8)($v0)
    /* 57D0 8006DFD0 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 57D4 8006DFD4 3800B08F */  lw         $s0, 0x38($sp)
    /* 57D8 8006DFD8 0800E003 */  jr         $ra
    /* 57DC 8006DFDC 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel _stepTowardTarget
