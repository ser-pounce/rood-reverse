nonmatching func_800C0738, 0x20

glabel func_800C0738
    /* 57F38 800C0738 0F80023C */  lui        $v0, %hi(D_800EB9B8)
    /* 57F3C 800C073C B8B9428C */  lw         $v0, %lo(D_800EB9B8)($v0)
    /* 57F40 800C0740 00000000 */  nop
    /* 57F44 800C0744 02004010 */  beqz       $v0, .L800C0750
    /* 57F48 800C0748 00000000 */   nop
    /* 57F4C 800C074C 100040A0 */  sb         $zero, 0x10($v0)
  .L800C0750:
    /* 57F50 800C0750 0800E003 */  jr         $ra
    /* 57F54 800C0754 00000000 */   nop
endlabel func_800C0738
