nonmatching func_800C05B4, 0x38

glabel func_800C05B4
    /* 57DB4 800C05B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 57DB8 800C05B8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 57DBC 800C05BC 0F80103C */  lui        $s0, %hi(D_800EB9B8)
    /* 57DC0 800C05C0 B8B9048E */  lw         $a0, %lo(D_800EB9B8)($s0)
    /* 57DC4 800C05C4 00000000 */  nop
    /* 57DC8 800C05C8 04008010 */  beqz       $a0, .L800C05DC
    /* 57DCC 800C05CC 1400BFAF */   sw        $ra, 0x14($sp)
    /* 57DD0 800C05D0 540F010C */  jal        vs_main_freeHeap
    /* 57DD4 800C05D4 00000000 */   nop
    /* 57DD8 800C05D8 B8B900AE */  sw         $zero, %lo(D_800EB9B8)($s0)
  .L800C05DC:
    /* 57DDC 800C05DC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 57DE0 800C05E0 1000B08F */  lw         $s0, 0x10($sp)
    /* 57DE4 800C05E4 0800E003 */  jr         $ra
    /* 57DE8 800C05E8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800C05B4
