nonmatching func_800C16DC, 0x20

glabel func_800C16DC
    /* 58EDC 800C16DC 0F80023C */  lui        $v0, %hi(D_800EB9B8)
    /* 58EE0 800C16E0 B8B9428C */  lw         $v0, %lo(D_800EB9B8)($v0)
    /* 58EE4 800C16E4 00000000 */  nop
    /* 58EE8 800C16E8 02004010 */  beqz       $v0, .L800C16F4
    /* 58EEC 800C16EC 00000000 */   nop
    /* 58EF0 800C16F0 2C0040A0 */  sb         $zero, 0x2C($v0)
  .L800C16F4:
    /* 58EF4 800C16F4 0800E003 */  jr         $ra
    /* 58EF8 800C16F8 00000000 */   nop
endlabel func_800C16DC
