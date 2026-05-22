nonmatching func_800C06E0, 0x20

glabel func_800C06E0
    /* 57EE0 800C06E0 0F80023C */  lui        $v0, %hi(D_800EB9B8)
    /* 57EE4 800C06E4 B8B9428C */  lw         $v0, %lo(D_800EB9B8)($v0)
    /* 57EE8 800C06E8 00000000 */  nop
    /* 57EEC 800C06EC 02004010 */  beqz       $v0, .L800C06F8
    /* 57EF0 800C06F0 00000000 */   nop
    /* 57EF4 800C06F4 000040A0 */  sb         $zero, 0x0($v0)
  .L800C06F8:
    /* 57EF8 800C06F8 0800E003 */  jr         $ra
    /* 57EFC 800C06FC 00000000 */   nop
endlabel func_800C06E0
